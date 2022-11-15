#include <iostream>
using namespace std;

class Ram{
	private:
		int* frame;
		int frameCapacity, pageFaults = 0;
	public:
		Ram(int x){
			this->frameCapacity = x;
		}
		bool pageExists(int x){
			for(int i = 0; i < frameCapacity; i++){
				if(frame[i] == x) return true;
			}
			return false;
		}
		int findFirstIndex(int page, int* arr, int len, int beg){
			for(int j = beg; j < len; j++){
				if(arr[j] == page) return j;
			}
			return -1;
		}
		int swapIndex(int* arr, int len, int beg){
			this->pageFaults++;
			int maxv = findFirstIndex(frame[0], arr, len, beg);
			int ind = 0;
			for(int i = 1; i < frameCapacity; i++){
				int v = findFirstIndex(frame[i], arr, len, beg);
				if(maxv < v){
					maxv = v;
					ind = i;
				}
			}
			return 0;
		}
		void displayState(){
			cout << "Ram state is: ";
			for(int i = 0; i < frameCapacity; i++){
				cout << frame[i] << " ";
			}
			cout << endl << "Page faults are: " << this->pageFaults << endl;
		}
		void push(int x, int* arr, int len, int beg){
			if(!pageExists(x)){
				int ind = swapIndex(arr, len, beg);
				frame[ind] = x;
			}else{
				cout << "Already Present!" << endl;
			}
			this->displayState();
		}
		~Ram(){
			cout << "Emptying frames" << endl;
		}
};

int main(){
	cout << "Enter the number of pages you have in swap" << endl;
	int n;
	cin >> n;
	if(n == 0){
		cout << "No processes to execute" << endl;
		return 0;
	}
	int* arr = new int[n];
	for(int i = 0; i < n; i++){
		cout << "[" << i << "]: ";
		cin >> arr[i];
	}
	Ram r1(3);
	for(int i = 0; i < n; i++){
		r1.push(arr[i], arr, n, i);
	}
	return 0;
}
