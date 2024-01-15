# TempsReel

## Abstract
This project focuses on developing a multi-tasking application using FreeRTOS for embedded systems. Tasks with distinct functionalities operate independently, utilizing FreeRTOS queue's feature for efficient inter-task communication. The study explores the ordering of the fourth different task that are defined. Through case studies and performance evaluations, the project provides insights into how to schedule task efficiently. 

## Introduction
The code is an implementation of a simplistic Real Time Scheduler with four task having different execution time to simulate it. The task are design to simulate different events,temperature conversion, number multiplication, etc. The scheduling is donethrough the queue's feature of the FreeRTOS software that we use for the implementation.

## Method
### Code Breakdown
The code consist of a main function called ipsa_sched wose job is to initiate the system by creating the queue in which the task will be scheduled.
Then the four task are defined. We have :
- The print task. Its job is to print regularly a message stating that the system is working fine.
- The temperature conversion task. Its job is to take a set Fahrenheit temperature and convert it to Celsius
- The multiplication task. Its job is to multiply two set integer of high value.
- The Binary search task. Its job is to look for a set integer in a randomly generated array of size 50

### Task Scheduling
In the following paragraph we are going to define the priority of each task as well as their period. We will also introduce the execution time computed from a set of 10 trials to determine if the period was wisely chosen and to see if the four tasks are indeed shcedulabale using the formula studied in class

- Firstly, The print task will have top priority as it is the one that state if the system is "operational". Its period will be of 1 second. After ten iterations, I calculated an approximative execution time of 25.749 milliseconds
- Secondly the Binary Search will have the second highest priority but with a period of 4 seconds to compensate for its execution time that should be the longest. After a batch of ten tests, I calculated the execution time to be 28.589 milliseconds
- Thirdly the multplication task will have the third highest priority. Its period will be of 3 seconds. After the batch of tests, I computed an average execution time of 22.567 milliseconds
- Lastly, the temperature conversion task will have the lowest priority and a period time of 2 seconds. After the ten tests, the averrage execution time computed was of 23.584 milliseconds.
  
Now, to study the schedulablity of the four tasks, we use the following formula :
$$\ \sum_{i=1}^n \frac{C_i}{T_i} \le 1 $$

By replacing the expression with or four tasks and their period and their maximum execution time, we get :
$$\ \frac{25.749 \times 10^{-3}}{1} + \frac{28.589  \times 10^{-3}}{2} + \frac{22.567 \times 10^{-3}}{3} + \frac{23.584  \times 10^{-3}}{4} \le 1 $$
$$\ \iff 0.05346 \le 1 $$

The inequality is respected, the task are schedulable.




## Results

We can see that the different task are printed in the right order and execute according to plan.
In conclusion I can state that the design was successfull and helped me understand vetter the coding part of a scheduler.
