#include <iostream>
#include <unistd.h>
#include <cmath>
using namespace std;

template <class T>
class Node{
	T data;
	Node *next;
};

template <class T>
class LinkedList{
	private:
		Node* head = NULL, temp;
	public:
		LinkedList(T val){
			head = new node;
			head->data = val;
			head->next = NULL;
			temp = head;
		}
		LinkedList(){
			head = new head;
			head->next = NULL;
			temp = head;
		}
		bool isEmpty(){
			if(head == NULL) return true;
			return false;
		}
		void enqueue(T data){
			Node* n = new node;
			n->data = data;
			temp->next = n;
			n->next = NULL;
			temp = n;
		}
		T dequeue(){
			if(isEmpty()) return NULL;
			T data = temp->data;
			while(tp->next != temp) tp = tp->next;
			tp->next = NULL;
			delete temp;
			temp = tp;
			return data;
		}
};

struct Process{
	int pid;
	int burst;
	int arrival;
	int wait;
	int turnaround;
};

int main(){
	LinkedList<int> ll(10);
	bool queueing = true;
	while(true){
		cout << "Enter 1 to insert; Any to exit" << endl;
		int ch;
		cin >> ch;
		switch(ch){
			case 1:
				Process p;
				p.arrivalTime = 
				break;
			default:
				exit(0);
		}
	}
	return 0;
}
