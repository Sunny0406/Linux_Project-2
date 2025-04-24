#include <linux/syscalls.h>
#include <linux/wait.h>
#include <linux/sched.h>
#include <linux/kernel.h>
#include <linux/delay.h> 

DECLARE_WAIT_QUEUE_HEAD(my_wait_queue);
int no_wait = 0;

static int enter_wait_queue(void) {
    int ret;
    no_wait = 0;
    ret = wait_event_interruptible(my_wait_queue, no_wait);
    //ret = wait_event_interruptible_exclusive(my_wait_queue, no_wait); //FIFO

    if(ret) return 0;
    return 1; 
}

static int clean_wait_queue(void) {
    no_wait = 1;
    while(my_wait_queue.head.next != &my_wait_queue.head)
    {
        wake_up_interruptible(&my_wait_queue);
        msleep(100);
    }
    return 1; 
}

SYSCALL_DEFINE1(call_my_wait_queue, int, id) {
    switch (id) {
        case 1:
            return enter_wait_queue();
        case 2:
            return clean_wait_queue();
        default:
            return 0; 
    }
}
