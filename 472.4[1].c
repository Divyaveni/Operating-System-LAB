#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    int *num = (int *)shmat(shmid, (void *)0, 0);

    for (int i = 0; i < 5; i++)
    {

        int id = fork();

        if (id == 0)
        {
            *num = (*num * *num);
            exit(0);
        }
        else
        {
            *num = (rand() % 500) + 1;
            printf("Number Is : %d\n", *num);
            wait(NULL);
            printf("Square of Number Is : %d\n", *num);
        }
    }

    shmdt(num);
    shmctl(shmid, IPC_RMID, NULL);

    fflush(stdin);

    return 0;
}
