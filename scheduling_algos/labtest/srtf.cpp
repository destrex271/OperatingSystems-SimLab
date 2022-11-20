#include <iostream>
using namespace std;

struct Process{
	unsigned int pid;
	int arrivalTime;
	int burstTime;
};

class Queue{
	
	private:
		Process* p;
		int n;
		int front = -1, rear = -1;
	public:
		Queue(int n){this->n = n; p = new Process[n];}
		void enqueue(Process py){
			if(front == -1) front++;
			p[++rear] = py;
		}
		void dequeue(){
			front++;
		}
		void timedec(){
			if(front == -1){
				p[0].burstTime--;
			}else{
				p[front].burstTime--;
				if(p[front].burstTime == 0){
					dequeue();
				}
			}
			display();
		}
		void display(){
			for(int i = front; i <= rear; i++){
				cout << "PID: " << p[front].pid << "\nBurst Time: " << p[front].burstTime << endl;
			}
		}
		void sort(){
			int k = front+1;
			while(k<n){
				int cur = k;
				for(int i = k-1; i >= front; i--){
					if(p[cur].burstTime < p[i].burstTime){
						Process tp = p[cur];
						p[cur] = p[i];
						p[i] = tp;
						cur = i;
					}else if(p[cur].burstTime == p[i].burstTime){
						if(p[cur].arrivalTime < p[i].burstTime){
							Process ap = p[cur];
							p[cur] = p[i];
							p[i] = ap;
							cur = i;
						}else{
							break;
						}
					}
				}
				k++;
			}
		}
		bool isEmpty(){
			if(front == rear+1) return true;
			return false;
		}
};

int main(){
	cout << "Enter the number of processes> ";
	int n;
	cin >> n;
	Queue q(n);
	for(int i = 0; i < n; i++){
		Process p;
		p.pid = i;
		cout << "Arrival time: ";
		cin >> p.arrivalTime;
		cout << "Burst Time: ";
		cin >> p.burstTime;
		q.enqueue(p);
	}
	q.sort();
	while(!q.isEmpty()){
		q.timedec();
		q.sort();
	}
}
