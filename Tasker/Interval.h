#ifndef INTERVAL_H
#define INTERVAL_H

#include <cstdint>

namespace util {
struct CommitmentFrequency;
}

/**
 * @brief The util::CommitmentFrequency struct represents \
 * the time the user aims to spend per session(time) on each commitment \
 * AND how often they intend to spend that amount of time on each specific Task/Session of \
 * the commitment.
 *@note Beware that this struct DOES NOT strictly \
 * "define" whether the user has completed a "session" \
 * withtin a certain TimeWindow. \
 *For example; suppose Alice commits to write 30 minutes everyday.
 * In that case the struct would look like this
 * struct util:CommitmentFrequency
 * {
 * time = 1800 //30 minutes in seconds
 * Frequency  = 7 // In the case of twice a week, this value would be 2, 1 for once a week, etc.
 * }
 *Just because Alice specified the Frequency to be 7, it DOES NOT mean that there will 7
 * sessions. It just means that was Alice's optimal goal, and this can be displayed in the
 * viewer(UI) as one sees fit. There could very much be the case where Alice decides \
 * to do 14 sessions of 15 minutes(14x15=30x7). A TimeWindow(in the case of Alice a week) is \
 * is only considered accomplished(or closed if you will) when the total amount of \
 * time(in this case 210 minutes) is reached. Tasker should encourage the user to
 * commit to Frequency number of sessions per week(TimeWindow), BUT the user
 * may choose to "split" that time during the week into as many sessions as they see fit.
 * Hopefully that makes sense.
 * This struct, being a simple struct,
 * does NOT manage itself. The udata::Commitment class is the manager of this struct.
 */
struct util::CommitmentFrequency {
    long long time = 0; // in seconds
    long long Frequency = 0;
};

#endif // INTERVAL_H
