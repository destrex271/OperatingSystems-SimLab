#include <iostream>
#include <cstring>
using namespace std;

struct Process{
	string name;
	int pid;
	int arrivalTime;
	int burstTime;
};

typedef struct Process Process;

int main(){
	cout << "Enter the number of processes you want: \n";
	int n;
	cin >> n;
	cout << "Enter process name,Arrival Time and burst time" << endl;
	Process* p = new Process[n];
	for(int i = 0; i < n; i++){
		p[i].pid = i;
		cout << "Name: ";
		cin >> p[i].name;
		cout << "Arrival Time: ";
		cin >> p[i].arrivalTime;
		cout << "Burst Time: ";
		cin >> p[i].burstTime;
	}
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(p[i].arrivalTime > p[j].arrivalTime){
				Process temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
	int sum = 0;
	for(int i = 0; i < n; i++){
		cout << "Executing Process: " <<  p[i].name << " : " << p[i].pid << endl;
		cout << "Arrival Time was: " << p[i].arrivalTime << "\nBurst Time: " << p[i].burstTime << "\nTotal Wait Time: " << sum << "Total Turn around time: " << p[i].burstTime + sum << endl;
		sum += p[i].burstTime;
	}
	return 0;
}
