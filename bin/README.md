#Running Tasker

One of the major issues with running Tasker on linux is the fact that in linux one has run it under sudo. This is obviously a huge security hole. To mitigate the risks in linux, the proper way of doing it is to write an action policy for Tasker. Which is what I did. Of course, if you clone the repo you won't automatically have an action policy written to your linux desktop just by cloning the repo. Don't worry, I've automated most of the process!

Once you have the repo cloned, open your terminal and  follow these steps:

**1.** go to the bin folder:

	cd Tasker/bin

**2.** Generate the action sudo policy and copy it to the right directory on your linux distro by running this script:

	./init_policy.py
	
If it asks you for your sudo password, input the password and press enter.
 
 **Note:** You only have to step2 **once**, after the first time you shouldn't have to do it again.
 
 **3.** Run tasker by running this script:
 
	 ./run_tasker.sh

If the policy is setup correctly (which is step2) then your computer will prompt you to type your sudo password every time you run Tasker with the "run_tasker.sh" script.

**To avoid any issues** make sure you **always ** run Tasker through the "./run_tasker.sh" script. **Do not** run the binary directly. If you do, then the keyboard listener won't work.

There will always be an executable on the bin folder which is the "Tasker" file. Now, if you want to run your own Tasker binary because you recompiled a new version all you have to do is replace the old "Tasker" file with your new shiny recompiled one, and it should work just fine!

Bare in mind that for now I've tested this script only on Ubuntu-based distros.



