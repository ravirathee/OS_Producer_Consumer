//Ravi Rathee
//16csu292
//Producer-Consumer Problem

#include <stdio.h>
#include <stdlib.h>  //for exit(0)

int n = 3;

int S = 1;    //Semaphore S
int E = 3;    //Semaphore Empty
int F = 0;    //Semaphore Full

void wait1(int *a){
    *a-=1;

}

void signal1(int *a){
    *a+=1;

}

void producer(){
        wait1(&E);
        wait1(&S);
            //append the item in queue
        signal1(&S);
        signal1(&F);
}

void consumer(){

       wait1(&F);
       wait1(&S);
            //take one item from queue
       signal1(&S);
       signal1(&E);
}

int main() {
    int choice = 0 ;
    while(1){
        printf("\nEnter your choice :");
        printf("   1. Producer");
        printf("   2. Consumer");
        printf("   Exit()    : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : {
                if(S==1 && E!=0){
                    producer();
                }else{
                    printf("Cant produce more. Queue is full");
                }
                break;
            }
            case 2 : {
                if(S==1 && F!=0){
                    consumer();
                }else{
                    printf("Cant consume more. Queue is empty");
                }

                break;
            }
            default : {
                printf("Exited the program.");
                exit(0);
            }
        }
    }
}


/*

 OUTPUT

Enter your choice :   1. Producer   2. Consumer   Exit()    : 1

Enter your choice :   1. Producer   2. Consumer   Exit()    : 1

Enter your choice :   1. Producer   2. Consumer   Exit()    : 1

Enter your choice :   1. Producer   2. Consumer   Exit()    : 1
Cant produce more. Queue is full
Enter your choice :   1. Producer   2. Consumer   Exit()    : 2

Enter your choice :   1. Producer   2. Consumer   Exit()    : 2

Enter your choice :   1. Producer   2. Consumer   Exit()    : 2

Enter your choice :   1. Producer   2. Consumer   Exit()    : 2
Cant consume more. Queue is empty
Enter your choice :   1. Producer   2. Consumer   Exit()    :


 */