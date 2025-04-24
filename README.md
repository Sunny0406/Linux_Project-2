# Linux-Project-2
## Project Overview
This project implements a custom wait queue functionality in the Linux kernel, allowing user-space applications to interact with it via a system call. A wait queue is a synchronization mechanism that allows processes to sleep while waiting for a condition to be met, and wake up once the condition is fulfilled.
In this implementation, threads enter the wait queue and wait until they are processed in FIFO (First In, First Out) order.
## Features
- Add a Thread to the Wait Queue: Threads enter the queue and sleep until the queue is cleaned.
- Remove Threads from the Queue: Threads wake up in FIFO order when the queue is cleaned.
- Custom System Call Implementation: The project defines call_my_wait_queue(int id) to manage queue operations.


