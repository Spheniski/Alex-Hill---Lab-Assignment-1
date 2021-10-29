// God damn assignment that I have no idea how to even begin please help aaaaaaaaahhhhhhhh
//producer and comsumer
//producer provides, consumer takes, uses table of size 2
//if table is full: producer waits, if table is empty: consumer waits

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <pthread.h>

int main(){
    const char * name = "shared memory";
    const char * sema1 = "fill";
    const char * sema2 = "empty";
    const char * sema3 = "mutex";
    int shm_fd;
    int * shelf;
    int loop = 2;
    sem_t * fill, * empty, * mutex;

    shm_fd = shm_open(name, O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(int));
    shelf = mmap(0, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    fill = sem_open(sema1, O_CREAT, 0666, 0);
    empty = sem_open(sema2, O_CREAT, 0666, 3);
    mutex = sem_open(sema3, O_CREAT, 0666, 1);

    printf("\nConsmer is ready.")

    while(loop--){
        sem_wait(fill);
        sleep(rand()%2+1);
        sem_wait(mutex);
        (* shelf)--;
        sem_post(mutex);
        printf("Consumed an item, there are %d item(s) on the table.\n");
        sem_post(empty);
    }

    printf("Consumer is finished");

    sem_close(fill);
    sem_close(empty);
    sem_close(mutex);
    sem_unlink(sema1);
    sem_unlink(sema2);
    sem_unlink(sema3);

    munmap(shelf, sizeof(int));
    close(shm_fd);
    shm_unlink(name);
    return 0;
}
