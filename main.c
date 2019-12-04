//you must install gcc 
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
//sorting structs and method
typedef struct Stacknode{//this struct uses to create node for stack, complexity = O(1).(6 or 12 bytes).
    int number;
    struct stacknode *next;
}StackNode;
typedef struct stack{//this struct uses to create the stack, complexity = O(1)(6 or 12 bytes).
    StackNode *top;
    int sizeStack;
}Stack;
void initStack(Stack *pm){//this method uses to initialize the stack, complexity = O(1).
    pm->top = NULL;
    pm->sizeStack = 0;
}// complexity =0(1).
void push (int n, Stack *pm ){//this method uses to add new node to stack, complexity = O(1). (4 or 8 bytes).
    StackNode *pn=(StackNode*)malloc(sizeof(StackNode));
    pn->number = n;
    pn->next = pm->top;
    pm->top = pn;
    pm->sizeStack++;
}
int pop( Stack *pm){//this method uses to remove new node to stack, complexity = O(1).(8 or 16 bytes).
    StackNode *pt;
    int pn = pm->top->number;
    pt = pm->top;
    pm->top = pm->top->next;
    free(pt);
    pm->sizeStack--;
    return pn;
}
int stackEmpty(Stack *pm){//this method uses to check if stack is empty, complexity O =(1).
     return pm->top==NULL;
}
int stackFull(Stack *pm){//this method uses to check if stack is full, complexity O =(1). (the stack never be full)
    return 0;
}
void clearStack(Stack *pm){//this method uses to clear stack of all node, complexity O =(n).(4 or 8 bytes).
     StackNode *pt1= pm->top;
     while(pt1){
        pt1 = pt1->next;
        free(pm->top);
        pm->top=pt1;
     }
     pm->sizeStack = 0;
}
void display(Stack *pm ){//this method uses to display stack , complexity O =(n).(4 or 8 bytes).
    StackNode *pt=pm->top;
    printf("\n");
    while(pt){
           printf("-  %d  ",pt->number);
        pt= pt->next;
    }// for(StackNode *pt = pm->top;pt;pt=pt->next) printf("-  %d  ",pt->number);
}
int stackSize(Stack *pm){//this method uses to check the size of stack, complexity O =(1).
    return pm->sizeStack;
}
void reve(Stack *pm ,Stack *pt){//this method uses to reverse the stack , complexity O =(n).
    while(pm->sizeStack!=0){
        push(pop(pm),pt);
    }display(pt);
}
void sorting(){//this is the method which calling every stack methods to add, remove, sort, show and reverse to do this task complexity =)(n).(19 or 37 bytes).
    Stack A;//(6 or 12 bytes).
    Stack B;//(6 or 12 bytes).
    initStack(&A);
    initStack(&B);
    int i,y,j;//(6 or 12 bytes).
    for (i=0;i<15;i++){
        printf("\n%d. the number:",i+1);
        scanf("%d",&y);
        while(1){
            if(A.top==NULL){
                push(y,&A);
                printf("\n A.");
                display(&A);
                printf("\n B.");
                display(&B);
                break;
            }
            else{
                if(A.top->number >y){
                    push(pop(&A),&B);
                    printf("\n A.");
                    display(&A);
                    printf("\n B.");
                    display(&B);
                }
                else{
                    push(y,&A);
                    printf("\n A.");
                    display(&A);
                    printf("\n B.");
                    display(&B);
                    break;
                    }
            }
        }
        while(B.top!=NULL){
            push(pop(&B),&A);
            printf("\n A.");
            display(&A);
            printf("\n B.");
            display(&B);
        }
    }
    printf("\n A.");
    display(&A);
    printf("\n B. ");
    display(&B);
    char str;//(1 bytes).
    printf("\n Do you want to reverse the stack ? y/n \n");
    scanf(" %c",&str);
    if (str=='y'||str=='Y'){
        reve(&A,&B);
    }
}
//hot potato game structs and methods
typedef struct queuenode{//this struct uses to create node for queue, complexity = O(1).(6 or 12 bytes).
     int name ;
    struct queuenode *next;
}QueueNode;
typedef struct queue{//this struct uses to create the queue, complexity = O(1).(10 or 20 bytes).
    QueueNode *first;
    QueueNode *last;
    int size;
}Queue;
void initQueue(Queue *pq){//this method uses to initialize the queue, complexity = O(1)
    pq->first = NULL;
    pq->last = NULL;
    pq->size = 0;
}
void add(Queue *pq,int s){//this method uses to add new node to queue, complexity = O(1).(4 or 8 bytes).
    QueueNode *pn = (QueueNode*)malloc(sizeof(QueueNode));
    pn->next = NULL;
    pn->name= s;
    if (!pq->last){//if (pq->size ==0)
        pq->first = pn;
    }else{
        pq->last->next = pn;
    }
    pq->last = pn;
    pq->size++;
}
int remov(Queue *pq){//this method uses to remove new node to queue, complexity = O(1).(6 or 12 bytes).
    QueueNode *pn = pq->first;
    int s = pn->name;
    pq->first = pn->next;
    free(pn);
    if(!pq->first)pq->last=NULL;//if (pq->size==1)
    pq->size--;
    return s;
}
int queueEmpty(Queue *pq){//this method uses to check if queue is empty, complexity O =(1).
    return !pq->first;
}
int queueFull(Queue *pq){//this method uses to check if queue is full, complexity O =(1). (the queue never be full)
    return 0;
}
int queueSize(Queue *pq){//this method uses to check the size of queue, complexity O =(1).
    return pq->size;
}
void clearQueue(Queue *pq){//this method uses to clear queue of all node, complexity O =(n).
    while(pq->first){
        pq->last = pq->first->next;
        free(pq->first);
        pq->first = pq->last;
    }
    pq->size = 0;
}
void show(Queue *pq){//this method uses to show queue , complexity O =(n).(4 or 8 bytes).
    QueueNode *pt= pq->first;
    for(;pt;pt=pt->next) {
        switch(pt->name){
            case 1:printf("  Ahmed");
            break;
            case 2:printf("  Mohamed");
            break;
            case 3:printf("  Salah");
            break;
            case 4:printf("  Yousef");
            break;
            case 5:printf("  Malek");
            break;
            case 6:printf("  Ali");
            break;
            case 7:printf("  Hamza");
            break;
            case 8:printf("  Hazam");
            break;
            case 9:printf("  Eyad");
            break;
            case 10:printf("  Nagy");
            break;
        }
    }
    printf("\n");
}
int gametime(){//this method uses to calculate(create) the time of every player, complexity = O(n)(2 or 4 bytes).

srand(time(0));
int r;
for(;;){
    r=rand()%2001+1000;
    printf("%d",r);
    Sleep(r);
    break;
}
return r;
}
void game(){//this is the method which calling every stack methods to add, remove, sort, show and reverse to do this task complexity =)(n).(24 or 48 bytes).
    Queue L;//(10 or 20 bytes).
    initQueue(&L);
    int a,d,k,o,t,u=0,e;//(14 or 28 bytes).
    printf("How many player did you want ?(you can choose between 3 and 10) :   ");
    scanf("%d",&a);
    for (d=1;d<=a;d++) add(&L,d);
    printf("The players are   ");
    show(&L);
    t=rand()%15001+10000;
    for(;queueSize(&L)>1;){
            printf("\n%d      ",t);
            o=remov(&L);

            add(&L,o);
            u+=gametime();
            printf("\n current players are ");
            show(&L);

            if(u>=t||queueSize(&L)==1){
                remov(&L);
                t=rand()%15001+10000;
                u=0;


                }
   }

    switch(o){
        case 1:printf("\n  The winner is Ahmed");
        break;
        case 2:printf("\n  The winner is Mohamed");
        break;
        case 3:printf("\n  The winner is Salah");
        break;
        case 4:printf("\n  The winner is Yousef");
        break;
        case 5:printf("\n  The winner is Malek");
        break;
        case 6:printf("\n  The winner is Ali");
        break;
        case 7:printf("\n  The winner is Hamza");
        break;
        case 8:printf("\n  The winner is Hazam");
        break;
        case 9:printf("\n  The winner is Eyad");
        break;
        case 10:printf("\n  The winner is Nagy");
        break;
        }
}
int main(){//the main method .


    int way;//(2 or 4 bytes).
        while(1){
            printf("\nSelect the process you want to do from the list .\n");
            printf(" 1- Sorting.\n 2- Hot potato game. \n 3- Exit. \n Your Choice:");
            scanf("%d",&way);
            switch(way){
                case 1:sorting() ;
                break;
                case 2: game();
                break;
                case 3:break;
                default:printf("\nCheck your choice\n");
                break;
            }
        if (way==3) {
                printf("Getting out of the program ...");
                break;
            }
        }
    return 0;
}
