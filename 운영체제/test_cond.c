#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_SLOTS 2
#define NUM_CARS 7

// 세마포어 대신 사용하는 3가지 요소
int empty_slots = NUM_SLOTS;       // 1. 자원 개수 관리 변수 (State)
pthread_mutex_t mutex;             // 2. 변수 보호용 뮤텍스
pthread_cond_t cond;               // 3. 대기열 관리용 컨디션 변수

void* car(void* arg){
    int id = *(int*)arg; 
    
    printf("[Car %d] 주차장 도착. 빈 자리 찾는 중...\n", id); 

    // === [sem_wait 구현부] ===
    pthread_mutex_lock(&mutex); // 자원 상태를 확인하기 위해 락을 건다

    // 중요: if가 아니라 while! (Spurious Wakeup & 경쟁 상태 방지)
    while (empty_slots == 0) {
        // 자리가 없으면 락을 풀고 대기열(cond)에서 잔다
        // 누군가 깨워주면 다시 락을 잡고 while 조건을 재검사한다
        pthread_cond_wait(&cond, &mutex);
    }
    
    // while을 탈출했다는 것은 자리가 있다는 뜻
    empty_slots--; // 자리 하나 차지함
    pthread_mutex_unlock(&mutex); // 볼일 다 봤으니 락 해제
    // ========================

    printf("    >> [Car %d] 주차 성공! 🚗 (현재 남은 자리: %d)\n", id, empty_slots);
    sleep(1); 
    
    // === [sem_post 구현부] ===
    pthread_mutex_lock(&mutex); // 자원 상태를 변경하기 위해 락을 건다
    
    printf("    << [Car %d] 출차합니다. 👋\n", id);
    empty_slots++; // 자리를 비워줌
    
    // 자리가 났으니 기다리는 차 한 대를 깨워줌 (없으면 무시됨)
    pthread_cond_signal(&cond); 
    
    pthread_mutex_unlock(&mutex); 
    // ========================

    return NULL; 
}

int main(){

    pthread_t threads[NUM_CARS]; 
    int car_ids[NUM_CARS]; 

    // 뮤텍스와 컨디션 변수 초기화
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    for(int i=0;i<NUM_CARS;i++){
        car_ids[i] = i + 1; 
        pthread_create(&threads[i], NULL, car, &car_ids[i]); 
        usleep(100000);
    }

    for(int i=0;i<NUM_CARS;i++){
        pthread_join(threads[i], NULL); 
    }

    // 뒷정리
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
}