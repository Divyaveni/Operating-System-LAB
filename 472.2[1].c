#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sched.h>
#include <stdlib.h>
#include <pthread.h>


void *print(void *args) {
    printf(" thread id - %d process id - %d \n", *(int *)args , getpid());
}

void function(void *args)
{
    printf(" clone of function process id - %d \n", getpid());
}

int main(){
    pthread_t thread;
    void *pchild_stack = malloc(1024 * 1024) + (1024 * 1024);

    pthread_create(&thread, NULL, print, &thread);

    sleep(1);

    pid_t id = fork();

    if (id != 0){
        pthread_create(&thread, NULL, print, &thread);
        sleep(1);
    } else {

        wait(NULL);

        function(1);

        clone(function, pchild_stack, 0, 0);

        pthread_create(&thread, NULL, print, &thread);
    }

    pthread_exit(NULL);
}

