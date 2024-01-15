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


To study the schedulablity of the four tasks, we use the following formula :
$$\ \sum_{i=1}^n \frac{C_i}{T_i} \le 1 $$



## Results

We can see that the different task are printed in the right order and execute according to plan.
In conclusion I can state that the design was successfull and helped me understand vetter the coding part of a scheduler.
