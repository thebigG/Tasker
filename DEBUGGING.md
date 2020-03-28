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


