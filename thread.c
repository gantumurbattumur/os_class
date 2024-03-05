#include <pthread.h>
#include <stdio.h>
#include <stdlib.h> /* atoi */
#include <unistd.h>     // For sleep
#include <sys/types.h> // For fork

#define MIN pid 300
#define MAX pid 5000
int sum; /* shared by the threads */
void *runner(void *param); /* threads call this function */

int initialize_map(void);
int allocate_pid(void);
int randGen();

int main(int argc, char *argv[]) {
    pthread_t tid; /* the thread identifier */
    pthread_attr_t attr; /* set of thread attributes */
    if (argc != 2) {
    fprintf(stderr,"usage: a.out <integer value>\n");
    return -1;
    }
    if (atoi(argv[1]) < 0) {
    fprintf(stderr, "%d must be >= 0\n",atoi(argv[1]));
    return -1;
    }
    pthread_attr_init(&attr); /* get the default attributes */
    pthread_create(&tid, &attr, runner, argv[1]); /* create the thread */
    pthread_join(tid, NULL); /* wait for the thread to exit */

   
    int pidVal = allocate_pid;
    printf("Pid value: %d\n", pidVal);
    
    printf("sum = %d\n", sum);

    int randNum = randGen();
    int sleepTime = sleep(randNum);
    printf ("sleep time = %d\n", sleepTime);
    
}
int initialize_map(void){
    int pid = allocate_pid;
    if ( pid < 0) return -1;
    else return 1;
}
int randGen(){
    srand(time(NULL));
    int random = rand() % 10;
    printf("Random: %d\n", random);
    return random;
}
int allocate_pid(void){
   pid_t pid;
   return pid;
}
void release_pid(int pid){

}

//printf("Thread <thread number> is allocated pid <pid number>, and will sleep <sleep time> seconds");
// int initialize_map(void) — Creates and initializes a data structure for representing pids; returns
// -1 if unsuccessful, 1 if successful.
// • int allocate_pid(void) — Allocates and returns a pid; returns -1 if unable to allocate a pid (all
// pids are in use).
// • void release_pid(int pid) — Releases a pid.
void *runner(void *param) {
    int i, upper = atoi((char*)param);
    sum = 0;
    for (i = 1; i <= upper; i++)
    sum += i;
    pthread_exit(0);
}