As of now, Tasker is not done yet.

You can run it, however, to play around with it!

The goal is to be able to support Windows, macOS and Linux.
Right now only there are only binaries for Linux(Ubuntu 18.04) and macOS X.
Just open up the binary under your platform's folder and you are all set. 


**macOS X**

1. brew install qt5
2. brew link qt5 --force

If you have issues loading the libraries in macOS X, just set the environment variable ` export DYLD_FRAMEWORK_PATH=/usr/local/Cellar/qt/5.14.1/lib/`

Your Qt path may not be EXACTLY like mine, so to get the one for your machine run ` brew list qt | grep /usr/local/Cellar/qt/*/lib/` and it will give you the exact path which will be almost exactly the same as mine except for the Qt version.

After setting the path, the binary should run :)

**NOTE**:This is a temporary fix that will only work for that shell session, meaning once you close the terminal you have to set the path again. 



In the future, I'll streamline this process and make it more user-friendly. But if you're not afraid of the terminal, this should be straight forward.