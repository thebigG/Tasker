[![Build Status](https://travis-ci.com/thebigG/Tasker.svg?branch=release)](https://travis-ci.com/thebigG/Tasker)
# Tasker

## Pitch

Many people(including us) have creative pursuits; projects we want to allocate time for; goals to accomplish. In our team, I write; Gem(a contributor to the project) plays music. It’s always been hard for us, and we suspect for many other people, to stay on task. More specifically, it’s even harder to keep track of one’s progress. The timers of our world—smartphones, desktops, etc—aren’t designed to accurately time the tasks we do.

One of the reasons for this is that human error is inevitable. A writer like myself may set the timer to 30 minutes, but halfway through the writing session, I might go make tea. If one is doing it right, making tea takes time. I forget to stop my timer, which is supposed to keep me attached to the keyboard for 30 minutes. In the meantime, while time runs out, I’m setting up the pot, waiting for it to boil, take my tea bag to dip in, fetch milk, make toast. When I come back to my novel, the timer ran out!

Even though my timer counted 30 minutes, I only did 15 minutes of writing. This is not ideal. Tasker aims to solve this problem, or at the very least make our timers more accurate (hence mitigating human errors) by binding our timers to hardware.

This means that while a session is opened in Tasker, it will be detecting hardware interaction. We **DO NOT** record keyboard strokes or sound. We buffer it temporarily and throw it away once we run it through some logic.

## How do I help?

**Please do not work on master. Always work on and push your changes to the release branch.**

Once you've tested your chnages on release branch locally, **let people know first** before merging onto master. The master branch should only have the last stable version of Tasker. 

Tasker is built using Qt 5 using c++. So you need to be comfortable using those technologies. If you aren't that's cool, we're still learning!

To get started I highly recommend these resources:

[Programming: Principles and Practice Using C++](https://www.amazon.com/Programming-Principles-Practice-Using-2nd/dp/0321992784/ref=sr_1_1?keywords=Programming%3A+Principles+and+Practice+Using+C%2B%2B&qid=1577916888&sr=8-1) 

[https://doc.qt.io/](https://doc.qt.io/) 

[https://www.youtube.com/user/TheChernoProject](https://www.youtube.com/user/TheChernoProject) 

[https://www.qt.io/download-qt-installer](https://www.qt.io/download-qt-installer) 




# How do I run tasker?
Look at the readme under the "bin" folder.


# Bugs
Being a complex API, Qt certainly has many quirks. The table below shows some known bugs, and the level of severity of these bugs.

Level 1= This bug is not critical. It is shipped in the current version of Tasker. These "bugs" don't really break  anything.

Level 2= This bug is somewhat critical. This might or might not be shipped in the Tasker executable. See details of these in the bug table.

Leve 3= This bug is a nasty one and SHOULD not be shipped in any version of Tasker.

|Bug Name   |Level   |Description  | Tested platform(s)  |
|---|---|---|--|
| Qt Leak  | 1  | If you run Tasker, under something like valgrind and you get something like "possibly/definitley" lost blocks/bytes on AND the function  stack trace  ends in some class like "ui_TimerWindowQWidget.h:", then you're probably fine. This has to do with Qt's shutdown cleanup libraries.  |  Linux Mint 19.2 Tina  base: Ubuntu 18.04 bionic    |
|Commitment padding   | 2  | This one also came from valgrind. If you see something like, "Syscall param write(buf) points to uninitialised byte(s)", it's probably not a big deal. As far as we know, this has to do with padding QDataStream adds when serializing. Still gonna consider this bug level 2 as we look into this further.  | Linux Mint 19.2 Tina  base: Ubuntu 18.04 bionic 	|
| libQt5Charts.so.5 missing  |1   | If you try to run Tasker and you see something like, "error while loading shared library: libQt5Charts.so.5...", then all this means is that your system is missing that qt Library. You can fix it by "apt-get --reinstall libqt5charts5" on your terminal. This is rare, but happens.  | Linux Mint 19.1 Tessa base: Ubuntu 18.04 bionnic	|
| libQt5Multimedia.so.5 missing  |1   | If you try to run Tasker and you see something like, "error while loading shared library: libQt5Multimedia.so.5...", then all this means is that your system is missing that qt Library. You can fix it by "apt-get --reinstall libqt5multimedia5" on your terminal. This is rare, but happens.  | Linux Mint 19.1 Tessa base: Ubuntu 18.04 bionnic	|


# Debugging

Tasker is built and baked into the Qt ecosystem. This is a design choice. Qt can be an intimidating framework to newcomers so before you start to debug make sure you are familiar with the Qt ecosystem, this includes the C++ API AND tools such as Qt Creator. 

By default the project is set up to print qDebug() statements only if your ennviroment is in "Debug" mode. If you switch to release/profile or any other mode that is not Debug, the qDebug statements are removed by Qt Creator when you build your executable:

<img src="Images/Debugging/Switch Profile.png" alt="" />


If you always want to see qDebug() messages, you can always comment out this line in the Tasker.pro file like this:

	#CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT

Once you comment that line(with a "#" like above) all of the qDebug statements will show up, even in release mode.


Tasker does have its own debug flag, it is called "\_\_TASKER_DEBUG\_\_". This flag is only active if you are in "Debug" mode. Under the hood this is just a macro that could be used like this in some debug situation:

	#ifdef __TASKER_DEBUG__
	#define SOME_DEBUG_MACRO CRAZY_MACRO_FUNC
	#endif

It's just a macro, don't abuse it please. 


