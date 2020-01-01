#Testing

Given that this started as a school project, we were required to write unit tests for our code. Each of the folders in this directory are unit tests that were made using Qt's unit testing framework. As of the moment, I'm not 100% sure if we'll keep on taking this approach as Tasker evloves. But IF we do keep on writing unit tests for Tasker, ALL and EVERY test should be under this folder.


#Performance
Given that Tasker is a complex application because it is using multiple threads that try their best to eliminate(or minimize) latency, we will be profiling CPU usage constantly so that Tasker's clock is as accurate as possible. We also understand that the average user doesn't have six or eight cores of compute power, we we'll try our best to keep Tasker performant and smooth even for users that have limited CPU resources. As of right now, we are only profiling linux. We will be using these linux results as a proxy for other platforms. We know that's not 100% accurate, but it's the best we can do right now. We will work on benchmarking in other platforms in the future. To look at CPU stats, flamegrapgs, etc. look at the "Perf" folder.