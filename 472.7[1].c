#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data
{
    char status[100];
    int value;
};

int main()
{
    struct data data;
    int page_size = 4096;
    int *pages[10];

    for (int i = 0; i < 10; i++)
    {
        pages[i] = malloc(page_size);
        int randInt = rand() % 2;
        if (randInt == 1)
        {
            strcpy(data.status, "assained");
            *pages[i] = rand() % 100;
            data.value = *pages[i];
        }
        else
        {
            strcpy(data.status, "not assained");
            data.value = 0;
        }

        randInt = rand() % 2;
        if (randInt == 1)
        {
            free(pages[i]);
            strcpy(data.status, "pointer freed");
            data.value = NULL;
        }

        if (data.value == NULL)
        {
            printf("Status : %s\n", data.status);
        }
        else
        {
            printf("Status : %s, Value : %d\n", data.status, data.value);
        }
    }
}