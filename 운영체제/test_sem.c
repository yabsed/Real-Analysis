#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_SLOTS 2
#define NUM_CARS 7

sem_t parking_lot; 

void* car(void* arg){
    int id = *(int*)arg; 
    
    printf("[Car %d] 주차장 도착. 빈 자리 찾는 중...\n", id); 

    sem_wait(&parking_lot); 

    printf("    >> [Car %d] 주차 성공! 🚗 (업무 보는 중...)\n", id);
    sleep(1); 
    printf("    << [Car %d] 출차합니다. 👋\n", id);

    sem_post(&parking_lot); 

    return NULL; 
}

int main(){

    pthread_t threads[NUM_CARS]; 
    int car_ids[NUM_CARS]; 

    sem_init(&parking_lot, 0, NUM_SLOTS); 

    for(int i=0;i<NUM_CARS;i++){
        car_ids[i] = i + 1; 
        pthread_create(&threads[i], NULL, car, &car_ids[i]); 
        usleep(100000);
    }

    for(int i=0;i<NUM_CARS;i++){
        pthread_join(threads[i], NULL); 
    }

    sem_destroy(&parking_lot); 
}