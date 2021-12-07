#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(){
    int option;
    system("lshw\n");
    pid_t pid = fork();
    if (pid>0){
        printf("Process id: %d -> This process opens cp-algorithms.com every 5 seconds\n", getpid());
        while(1){
            pid_t pid2 = fork();
            if(pid2==0) execl("/usr/bin/firefox", "/usr/bin/firefox", "cp-algorithms.com", (char*)NULL);
            sleep(5);
        }
    }
    else if(pid < 0) printf("Can't\n");
    else{
        printf("Process id: %d -> This process writes on the terminal\n", getpid());
        while(1){
            printf("I love the Suffix Automatons!\n");
            sleep(5);
        }
    }
}