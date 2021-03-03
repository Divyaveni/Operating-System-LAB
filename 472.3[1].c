#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 

pthread_t tid[2]; 
int counter; 
pthread_mutex_t lock; 

void *withOutMutex(void* arg) {
	counter += 1; 
	printf("\n Job %d has started\n", counter); 

	sleep(2);

	printf("\n Job %d has finished\n", counter); 
}
  
void *withMutex(void* arg) { 
    pthread_mutex_lock(&lock);
    
    counter += 1; 
    printf("\n Job %d has started\n", counter); 
  
    sleep(2); 
  
    printf("\n Job %d has finished\n", counter); 
  
    pthread_mutex_unlock(&lock); 
} 

int main(void) {
	int i = 0; 

	while (i < 2) { 
		pthread_create(&(tid[i]), NULL, &withOutMutex, NULL); 
		i++; 
	}

    sleep(5);

    printf("\n Mutex Starts \n");
    
    i = 0;

    pthread_mutex_init(&lock, NULL);

    while (i < 2) { 
		pthread_create(&(tid[i]), NULL, &withMutex, NULL); 
		i++; 
	} 

    pthread_join(tid[0], NULL); 
    pthread_join(tid[1], NULL);

    pthread_mutex_destroy(&lock); 

	return 0; 
}
