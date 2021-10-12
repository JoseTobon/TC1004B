#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 20

void * printHola(void *arg){
    char *p = (char *)arg;
    printf("Hola desde hilo %s\n",p);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    char *s = "Soy un hilo";
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, printHola, (void *)s);
    }
    
    pthread_exit(NULL);

    return 0;
}