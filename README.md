# Tasker

## Pitch

Many people(including us) have creative pursuits; projects we want allocate time for; goals to accomplish. In our team, I write; Gem(a contributor to the project) plays music. It’s always been hard for us, and we suspect for many other people, to stay on task. More specifically, it’s even harder to keep track of one’s progress. The timers of our world—smartphones, desktops, etc—aren’t designed to accurately time the tasks we do.

One of the reasons for this is that human error is inevitable. A writer like myself may set the timer to 30 minutes, but halfway through the writing session, I might go make tea. If one is doing it right, making tea takes time. I forget to stop my timer, which is supposed to keep me attached to the keyboard for 30 minutes. In the meantime, while time runs out, I’m setting up the pot, waiting for it to boil, take my tea bag to dip in, fetch milk, make toast. When I come back to my novel, the timer ran out!

Even though my timer counted 30 minutes, I only did 15 minutes of writing. This is not ideal. Tasker aims to solve this problem, or at the very least make our timers more accurate (hence mitigating human errors) by binding our timers to hardware.

This means that while a session is opened in Tasker, it will be detecting hardware interaction. We **DO NOT** record keybaord strokes or sound. We buffer it temporarily and throw it away once we run it through some logic.

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
| Qt Leak  | 1  | If you run Tasker, under something like valgrind and you get something like "possibly/definitley" lost blocks/bytes on AND the function  stack trace  ends in some class like "ui_TimerWindowQWidget.h:" |  Linux Mint 19.2 Tina  base: Ubuntu 18.04 bionic    |
|Commitment padding   | 2  | This one also came from valgrind. If you see something like, "Syscall param write(buf) points to uninitialised byte(s)", it's probably not a big deal. As far as we know, this has to do with padding QDataStream adds when serializing. Still gonna consider this bug level 2 as we look into this further.  | Linux Mint 19.2 Tina  base: Ubuntu 18.04 bionic 	|
|   |   |   |	|


