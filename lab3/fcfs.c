#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Process{
		int pid;
		char name[100];
		int arrivalTime;
		int cpuTime;
		int waitTime;
		int taTime;
		int procTime;
};

typedef struct Process Process;

struct Queue{
		Process arr[100];
		int front;
		int rear;
		int cap;
};
typedef struct Queue Queue;

void enqueue(Process x, Queue *q){
		if(q->rear == q->cap){
				printf("No more processes can be queued!\nPlease wait for the resources to be released...\n");
				return;
		}
		q->arr[q->rear++] = x;
		printf("Queued: %d\n",q->arr[q->rear-1].pid);
}

Process dequeue(Queue *q){
		if(q->front == q->rear){
				printf("Process Queue is Complete!\n");
				Process p;
				return p;
		}
		return q->arr[q->front++];
}

int isEmpty(Queue q){
		if(q.rear == q.front){
				return 0;
		}
		return 1;
}

Process current(Queue *q){
		if(q->front == q->rear){
				printf("No processes in queue right now!\n");
				Process p;
				return p;
		}
		return q->arr[q->rear-1];
}

void arrange(Queue* q){
		for(int i = 0; i < q->rear - 1; i++){
				for(int j = i+1; j < q->rear; j++){
						if(q->arr[i].arrivalTime > q->arr[j].arrivalTime){
								int t = q->arr[i].arrivalTime;
								q->arr[i].arrivalTime = q->arr[j].arrivalTime;
								q->arr[j].arrivalTime = t;
						}
				}
		}
}

void assign(int* pid){
		*pid = (int)(rand() % (20000 - 10000)) + 10000;
}

void printQueue(Queue q){
		for(int i = 0; i <  q.rear; i++){
				printf("----- %s process with PID : %\n",q.arr[i].name,q.arr[i].pid);
		}
}

int main(){
		printf("Enter the processes you want to execute by pressing n and press q to exit\n");
		Queue q;
		q.front = 0;
		q.rear = 0;
		q.cap = 100;
		char c;
		scanf("%c", &c);
		while(c != 'q'){
				printf("Enter process arrival time, name(no spaces) and its estimated Cpu Burst time\n");
				Process p;
				scanf("%d",&p.arrivalTime);
				scanf("%s",&p.name);
				scanf("%d",&p.cpuTime);
				assign(&p.pid);
				enqueue(p, &q);
				scanf("%c%c",&c,&c);
		}
		
		// Processes queued
		// Implementing First Come, First Serve Algorithm

		int t = 0;
		int prev = 0;
		printf("%d %d", q.rear, q.front);
		while(q.rear != q.front){
				Process cur = dequeue(&q);
				t += cur.cpuTime;
				cur.waitTime = prev;
				printf("Executing Process: #%d\n\tName: %s\n\tArrival Time: %d\n\tTime Elapsed: %d\n\n",cur.pid,cur.name,cur.arrivalTime,cur.waitTime);
				prev += cur.cpuTime;
		}
		return 0;
}
