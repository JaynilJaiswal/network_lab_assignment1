#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
  
// Driver code 
int main() 
{ 
    int pid, pid1, gpid1, gpid2, gpid3, gpid4; 
  
    // variable pid will store the 
    // value returned from fork() system call 
    pid = fork(); 
    sleep(2);    
    // If fork() returns zero then it 
    // means it is child process. 
    if (pid == 0) { 
        sleep(1);
        // First child needs to be printed 
        // later hence this process is made 
        // to sleep for 3 seconds. 
        // sleep(3); 
  
        // This is first child process 
        // getpid() gives the process 
        // id and getppid() gives the 
        // parent id of that process. 
        // printf("child[1] --> pid = %d and ppid = %d\n", 
        //        getpid(), getppid());

        gpid1=fork();
        if (gpid1==0){
            // wait();
            // sleep(1);
            printf("grandchild[1] --> pid = %d and parent id=%d\n",getpid(),getppid());
            // pid=fork();
            // kill();
        }
        else{
            gpid2=fork();
            if (gpid2==0){
                // sleep(1);
                // sleep(3);
                // wait();
                printf("grandchild[2] --> pid = %d and parent id =%d\n",getpid(),getppid());
                // kill();
            }
            else{
            // sleep(2);
            printf("child[1] --> pid = %d and parent id =%d\n",getpid(),getppid());
            // kill();
            }
        }
        
    } 
  
    else { 
        pid1 = fork(); 
        if (pid1 == 0) { 
            sleep(1);
            gpid3=fork();
            if (gpid3==0){
                // sleep(1);
                printf("grandchild[3] --> pid = %d parent id =%d\n",getpid(),getppid());
            // gpid1=fork();
            }
            else {
                gpid4=fork();
                if (gpid4==0){
                    // sleep(1);
                    printf("grandchild[4] --> pid = %d parent id =%d\n",getpid(),getppid());
                }
                
                
                else{
                    sleep(1);
                    printf("child[2] --> pid = %d parent id =%d\n",getpid(),getppid());
                 
                    }
            }
        }
        else { 
            // pid2 = fork(); 
            // if (pid2 == 0) { 
            //     // This is third child which is 
            //     // needed to be printed first. 
            //     printf("child[3] --> pid = %d and ppid = %d\n", 
            //            getpid(), getppid()); 
            // } 
  
            // If value returned from fork() 
            // in not zero and >0 that means 
            // this is parent process. 
            // else { 
                // This is asked to be printed at last 
                // hence made to sleep for 3 seconds. 
                // sleep(1); 
                printf("parent --> pid = %d\n", getpid()); 
            // } 
        } 
    } 
  
    return 0; 
}