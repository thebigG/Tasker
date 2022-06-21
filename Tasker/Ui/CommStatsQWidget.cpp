#include "CommStatsQWidget.h"
#include "Timer.h"
#include "ui_CommStatsQWidget.h"
#include <CreateCommitmentQWidget.h>
#include <MainUi.h>
#include <QAbstractItemView>
#include <QDebug>
#include <UdataUtils.h>
#include <iostream>

using Engine::Hook;
using udata::Commitment;
using udata::Session;
using udata::User;

/**
 * @brief CommStatsQWidget::CommStatsQWidget
 * @param parent
 */
CommStatsQWidget::CommStatsQWidget(QWidget *parent)
: QWidget(parent), ui(new Ui::CommStatsQWidget) {
    ui->setupUi(this);
    initCommitmentsQTreeWidget();
    /*
     * Set up all necessary signals and slots for this class.
     */
    connect(ui->commitmentsQTreeWidget, &QTreeWidget::currentItemChanged, this,
            &CommStatsQWidget::currentCommitmentChangedSlot);
    connect(ui->prevSnaphot, &QPushButton::clicked, this, &CommStatsQWidget::previousSnapshot);
    connect(ui->nextSnapshot, &QPushButton::clicked, this, &CommStatsQWidget::nextSnapshot);
    this->ui->commitmentsQTreeWidget->setColumnWidth(
        0, this->ui->commitmentsQTreeWidget->size().width() - 100);
    connect(Engine::Timer::getInstance(), &Engine::Timer::stopTimer, this,
            &CommStatsQWidget::saveCurrentSession);
    connect(ui->commitmentsQTreeWidget, &QTreeWidget::itemDoubleClicked, this,
            &CommStatsQWidget::newSessionSlot);
    connect(&currentLiveSessionWidget, &LiveSession::liveStateChanged, this,
            &CommStatsQWidget::updateLiveSessionStateSlot);
    connect(&currentLiveSessionWidget, &LiveSession::sessionStarted, this, [&]() {
        setSelectable(false);
        updateCurrentLiveSessionCommitment();
        MainUI::getInstance()->updateActionStates();
    });
    /*
     * Allocate space in this string to avoid realocation on when updating
     */
    commitmentMetaDataText.reserve(100);
    commitmentMetaDataText.resize(100);
    beginDateText.resize(100);
    setSelectable(true);
    /*
     * Arrenge navigating buttons for our commitment snaphots.
     */
    static_cast<QGridLayout *>(this->ui->commStatsHubQWidget->layout())
        ->addWidget(this->ui->prevSnaphot, 0, 0);
    static_cast<QGridLayout *>(this->ui->commStatsHubQWidget->layout())->addWidget(&snapshot, 0, 1);
    static_cast<QGridLayout *>(this->ui->commStatsHubQWidget->layout())
        ->addWidget(&currentLiveSessionWidget, 2, 1);

    static_cast<QGridLayout *>(this->ui->commStatsHubQWidget->layout())
        ->addWidget(this->ui->CommitmentInfoStatsQWidget, 1, 1);

    /*
     * Assign the same color to our CommitmentInfoStats widget as the
     * CommitmentSnaphot chart to make things look uniform.
     */
    QPalette p = this->ui->CommitmentInfoStatsQWidget->palette();

    p.setColor(this->ui->CommitmentInfoStatsQWidget->backgroundRole(),
               snapshot.palette().color(QPalette::ColorRole::Background));
    this->ui->CommitmentInfoStatsQWidget->setAutoFillBackground(true);
    this->ui->CommitmentInfoStatsQWidget->setPalette(p);
    currentLiveSessionWidget.setAutoFillBackground(true);
    currentLiveSessionWidget.setPalette(p);
}

void CommStatsQWidget::newCommitmentSlot() {
    this->createCommimentWindow.show();
}
void CommStatsQWidget::editCommitmentSlot() {
    createCommimentWindow.editCommitment();
}
/**
 * @brief CommStatsQWidget::addCommitmentItem Adds a new commitment to the
 * backing store and to the QTreeView.
 * @param newCommitment the new commitment to add to the backing store.
 */
void CommStatsQWidget::addCommitmentItem(udata::Commitment &newCommitment) {
    udata::User::getInstance()->addCommitment(newCommitment);
    ui->commitmentsQTreeWidget->addTopLevelItem(
        new QTreeWidgetItem(QStringList() << newCommitment.getName() << ""));
}
/**
 * @brief CommStatsQWidget::~CommStatsQWidget
 */
CommStatsQWidget::~CommStatsQWidget() {
    delete ui;
}

void CommStatsQWidget::deleteCommitmentSlot() {
    /*
     * If there are no commitments to delete, then there is nothing to delete.
     */
    if (User::getInstance()->getCommitments().isEmpty()) {
        return;
    }
    int tempIndex = selectedCommitmentIndex;
    /*
     * If we are deleting the last commitment, make sure we don't have an
     * off-by-one error :)
     */
    if (selectedCommitmentIndex == (User::getInstance()->getCommitments().size() - 1)) {
        selectedCommitmentIndex--;
    }
    User::getInstance()->getCommitments().removeAt(tempIndex);
    isDelete = true; // This is for the currentItemChanged signal, which gets
                     // emitted by delete keyword
    // I don't want to use delete, but it seems to be the only way to delete
    // these TreeWidget items
    delete ui->commitmentsQTreeWidget->takeTopLevelItem(tempIndex);
}
/**
 * @brief CommStatsQWidget::newSessionSlot gets triggered when a commitment item
 * gets double clicked on the Commitments Tree Widget and decides whether the
 * user is able to start a new session for that commitment or not.
 */
void CommStatsQWidget::newSessionSlot() {
    if (!User::getInstance()
             ->getCurrentCommitment()
             .getCommitmentWindows()
             .last()
             .sessions.isEmpty()) {
        if (QDate::currentDate() == User::getInstance()
                                        ->getCurrentCommitment()
                                        .getCommitmentWindows()
                                        .last()
                                        .sessions.last()
                                        .getDate()) {
            /**
             *@note Maybe show the user in the UI that they have added this
             *session already to this commitment today. It might be worth it to
             * consider a case where maybe a session was terminated prematurely
             * for whatever reason and the user might want to resume that
             * session even after closing Tasker, this is assuming that they
             * open Tasker the very same day again. Give this a lot of thought
             * as this could add clutter to the UI, which I don't want.
             */
            return;
        }
    }
    if (MainUI::getInstance()->newSessionActionState()) {
        //        this->getNewSessionQWidget().get
        this->getNewSessionQWidget().show();
    }
}
/**
 * @brief CommStatsQWidget::initCommitmentsQTreeWidget loads all of the
 * commitments from disk and adds them to commitmentsQTreeWidget.
 */
void CommStatsQWidget::initCommitmentsQTreeWidget() {
    for (auto commitment : User::getInstance()->getCommitments()) {
        /*
         * I did not want to use new, but have to because there does not seem to
         * be any other way of adding children to QTreeWidget. It should be ok
         * since QTreeWidget manages all of those pointers for us :).
         */
        QTreeWidgetItem *item =
            new QTreeWidgetItem(QStringList() << commitment.getName() << ": "
                                              << commitment.getDateStart().toString());

        ui->commitmentsQTreeWidget->addTopLevelItem(item);
    }
}
void CommStatsQWidget::itemDoubleClickedSlot(QTreeWidgetItem *item) {
    ui->commitmentsQTreeWidget->indexOfTopLevelItem(item);
    newSessionSlot();
}

void CommStatsQWidget::currentCommitmentChangedSlot(QTreeWidgetItem *current,
                                                    QTreeWidgetItem *previous) {
    if (!isSelectable) {
        return;
    }

    if (isDelete) {
        isDelete = false;
        return;
    }
    // update current commitment
    int currentIndex = 0;
    currentIndex = ui->commitmentsQTreeWidget->indexOfTopLevelItem(current);
    selectedCommitmentIndex = currentIndex;
    User::getInstance()->updateCurrentCommitment(selectedCommitmentIndex);

    // update meta data on meta data widget
    updateCommitmentInfoStatsQWidget();

    QVector<Commitment> &commitments = User::getInstance()->getCommitments();
    MainUI::getInstance()->updateActionStates();
    //
    if (!commitments.isEmpty()) {
        newPerfTimer.restart();
        /*reset the value of currentTimeWindow to the current time window
         * Since the currently selected commitment has changed
         *This usually means whatever TimeWindow(such as week) includes the
         *current date
         */
        currentTimeWindow =
            User::getInstance()->getCurrentCommitment().getCommitmentWindows().length() - 1;
        updateSnapshot();
        newPerfTimer.stop();
        qDebug() << "duration of chart update=" << newPerfTimer.duration << "milli/nanoseconds";
    }
}
NewSessionQWidget &CommStatsQWidget::getNewSessionQWidget() {
    return newSessionQWidget;
}
CreateCommitmentQWidget &CommStatsQWidget::getCreateCommitment() {
    return createCommimentWindow;
}
/**
 * @brief CommStatsQWidget::previousSnapshot Navigate to the previous commitment
 * snapshot.
 */
void CommStatsQWidget::previousSnapshot() {
    if (currentTimeWindow - 1 >= 0) {
        currentTimeWindow = currentTimeWindow - 1;
    } else {
        return;
    }
    updateSnapshot();
}
/**
 * @brief CommStatsQWidget::nextSnapshot navigate to the previous commitment
 * snapshot.
 */
void CommStatsQWidget::nextSnapshot() {
    if (User::getInstance()->getCommitments().isEmpty()) {
        return;
    }
    if (currentTimeWindow + 1 <
        User::getInstance()->getCurrentCommitment().getCommitmentWindows().length()) {
        currentTimeWindow = currentTimeWindow + 1;
    } else {
        return;
    }
    updateSnapshot();
}
/**
 * @brief CommStatsQWidget::updateSnapshot updates the current snapshot with new
 * data from the current TimeWindow.
 */
void CommStatsQWidget::updateSnapshot() {
    snapshot.update(User::getInstance()->getCurrentCommitment().getCommitmentWindows()[currentTimeWindow],
                    User::getInstance()->getCurrentCommitment().getType(),
                    User::getInstance()->getCurrentCommitment().getFrequency().goal);
}

void CommStatsQWidget::show() {
    QWidget::show();
}
/**
 * @brief CommStatsQWidget::saveCurrentSession
 * This function assumes that the currently selected session
 * is the same one that this new live session belongs to. As such it stores this
 * new live session to the commitment that is currently selected.
 * @note Any state regarding commitment snaphots and MainUI QActions are updated
 * on this function since the data changes those changes should be reflected in
 * the UI.
 */
void CommStatsQWidget::saveCurrentSession() {
    User::getInstance()->getCurrentCommitment().getCurrentTimeWindow().sessions.append(
        Engine::Timer::getInstance()->getCurrentSession());
    udata::UdataUtils::saveUserData(*User::getInstance());
    updateSnapshot();
    MainUI::getInstance()->updateActionStates();
}
/**
 * @brief CommStatsQWidget::updateCommitmentInfoStatsQWidget updates the meta
 * data about the selected commitment.
 */
void CommStatsQWidget::updateCommitmentInfoStatsQWidget() {
    commitmentMetaDataText.fill(' ');
    QString frequencyString{};
    if (User::getInstance()->getCurrentCommitment().getType() == udata::CommitmentType::WEEKLY) {

        frequencyString.append(", ");
        frequencyString.append(QString::number(
            User::getInstance()->getCurrentCommitment().getFrequency().frequency));
        frequencyString.append(" time(s) a week.");

    } else if (User::getInstance()->getCurrentCommitment().getType() ==
               udata::CommitmentType::EVERDAY) {
        frequencyString.append(", Everyday");

    } else {
        // Not supported at the moment
    }

    util::formatTime(commitmentMetaDataText,
                     User::getInstance()->getCurrentCommitment().getFrequency().goal,
                     frequencyString, 0);
    this->ui->goalQLabel->setText(commitmentMetaDataText);
    updateBeginDateQLabel();
    updateEndDateQLabel();
}
/**
 * @brief CommStatsQWidget::updateBeginDateQLabel Helper method for
 * updateCommitmentInfoStatsQWidget
 */
void CommStatsQWidget::updateBeginDateQLabel() {
    beginDateText.replace(20, beginDateText.length() - 20, ' ');
    QString startDateText{
        User::getInstance()->getCurrentCommitment().getDateStart().toString()
    };
    beginDateText.replace(20, startDateText.length(), startDateText);
    this->ui->beginDateQLabel->setText(beginDateText);
}
/**
 * @brief CommStatsQWidget::updateEndDateQLabel Helper method for
 * updateCommitmentInfoStatsQWidget
 */
void CommStatsQWidget::updateEndDateQLabel() {
    if (!User::getInstance()->getCurrentCommitment().hasEndDate()) {
        this->ui->endDateQLabel->setText("");
        return;
    }
    QString date{ User::getInstance()->getCurrentCommitment().getDateEnd().toString() };
    endDateText.replace(8, endDateText.length() - 8, ' ');
    endDateText.replace(8, date.length(), date);
    this->ui->endDateQLabel->setText(endDateText);
}
/**
 * @brief CommStatsQWidget::setSelectable sets whether or not the commitment
 * QTreeView is selctable or not. This is especially useful in the middle of a
 * session and we need to disable commitment slection.
 * @param toggle If true, the QTreeView for commitments will be rendered
 * unSeletable, meaning no other commitment can be selected aside the one that
 * is currently selected. Otherwise, any commitment can be selected.
 */
void CommStatsQWidget::setSelectable(bool toggle) {
    if (toggle) {
        this->ui->commitmentsQTreeWidget->setSelectionMode(
            QAbstractItemView::SelectionMode::SingleSelection); // single selection
        this->ui->commitmentsQTreeWidget->setFocusPolicy(Qt::StrongFocus); // strong focus
    } else {
        this->ui->commitmentsQTreeWidget->setSelectionMode(
            QAbstractItemView::SelectionMode::NoSelection);
        this->ui->commitmentsQTreeWidget->setFocusPolicy(Qt::NoFocus);
    }

    isSelectable = toggle;
}
/**
 * @brief CommStatsQWidget::updateLiveSessionStateSlot gets triggered every time
 * the state of a LiveSession changes.
 */
void CommStatsQWidget::updateLiveSessionStateSlot() {
    if (currentLiveSessionWidget.getCurrentState() == LiveSessionState::Paused) {
        setSelectable(true);
    } else if (currentLiveSessionWidget.getCurrentState() == LiveSessionState::Started) {
        this->ui->commitmentsQTreeWidget->setCurrentItem(
            this->ui->commitmentsQTreeWidget->topLevelItem(currentLiveSessionCommitment));
        setSelectable(false);
    } else if (currentLiveSessionWidget.getCurrentState() == LiveSessionState::Stopped) {
        setSelectable(true);
    }
    MainUI::getInstance()->updateActionStates();
}
void CommStatsQWidget::updateCurrentLiveSessionCommitment() {
    currentLiveSessionCommitment = selectedCommitmentIndex;
}
/**
 * @brief CommStatsQWidget::updateCurrentCommitment updates the meta data about
 * the currently selected commitment after editing it.
 */
void CommStatsQWidget::updateCurrentCommitment() {
    if (ui->commitmentsQTreeWidget->topLevelItem(selectedCommitmentIndex) != nullptr) {
        ui->commitmentsQTreeWidget->topLevelItem(selectedCommitmentIndex)
            ->setText(0, User::getInstance()->getCurrentCommitment().getName());
    } else {
        return;
    }
    updateCommitmentInfoStatsQWidget();
    updateSnapshot();
}
LiveSession const &CommStatsQWidget::getcurrentLiveSessionWidget() const {
    return currentLiveSessionWidget;
}
