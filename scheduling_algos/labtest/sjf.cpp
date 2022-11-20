#include <iostream>
using namespace std;

struct Process{
	unsigned int pid;
	int arrivalTime;
	int burstTime;
	int waitTime;
	int turnAroundTime;
};

typedef struct Process Process;

void sort(Process* p, int n){
	int i = 1;
	while(i < n){
		int cur = i;
		for(int j = cur-1; j >= 0; j--){
			if(p[cur].burstTime < p[j].burstTime){
				Process tp = p[cur];
				p[cur] = p[j];
				p[j] = tp;
			}else{
				break;
			}
		}
		i++;
	}
}

int main(){
	int n;
	cout << "Enter the number of processes you want > ";
	cin >> n;
	Process* p = new Process[n];
	for(int i = 0; i < n; i++){
		p[i].pid = i;
		cout << "Arrival Time for " << p[i].pid << ": ";
		cin >> p[i].arrivalTime;
		cout << "Burst Time for " << p[i].pid << ": ";
		cin >> p[i].burstTime;
	}
    sort(p, n);
    int prev = 0;
    for(int i = 0; i < n; i++){
      cout << "Executing " << p[i].pid << endl;
      int x;
      if(prev == 0 || prev - p[i].arrivalTime < 0){x=0;}else{
        x = prev - p[i].arrivalTime;
      }
      cout << "Waiting Time: " << x << endl;
      cout << "Turn around time: " << p[i].burstTime + x << endl;
			prev = p[i].burstTime;
    }
	return 0;
}
