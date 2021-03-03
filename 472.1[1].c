#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *even(void *param)
{
    for (int i = 1; i <= (int)param; i++)
    {
        if (i%2 == 0)
        {
            printf("EVEN : %d\n",i);
            sleep(1);
        }

    }

}

void *odd(void *param)
{
    for (int i = 1; i <= (int)param; i++)
    {
        if (i%2 != 0)
        {
            printf("ODD : %d\n",i);
            sleep(1);
        }

    }

}

int main()
{
    pthread_t threadeve,threadodd;
    int n;
    printf("GIVE VALUE FOR N : ");
    scanf("%d",&n);
    pthread_create(&threadeve,NULL,even,(void*)n);
    pthread_create(&threadodd,NULL,odd,(void*)n);
    pthread_exit(NULL);
}
