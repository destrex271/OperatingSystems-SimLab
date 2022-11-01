#include <iostream>
using namespace std;

class Ram{
	public:
		int rear = -1;
		int* arr;
		int pageFaults = 0;
		int frameCount;
		Ram(int frameCount){
			this -> frameCount = frameCount;
			arr = new int[frameCount];
		}
		bool contains(int val){
			for(int i = 0; i < frameCount; i++){
				if(arr[i] == val) return true;
			}
			return false;
		}
		void push(int pageId){
			if(!contains(pageId)){
				rear = (rear+1) % frameCount;
				arr[rear] = pageId;
				pageFaults++;
			}
		}
		void display(){
			for(int i = 0; i < frameCount; i++){
				cout << arr[i] << endl;
			}
		}
};

int main(){
	int fcount = 0;
	cout << "Enter the number of frames in the ram" << endl;
	cin >> fcount;
	Ram r(fcount);
	cout << "Enter number of pages" << endl;
	int x = 0;
	cin >> x;
	cout << "Enter the page numbers in the sequence" << endl;
	int arr[x];
	for(int i = 0; i < x; i++){
		cin >> arr[i];
		r.push(arr[i]);
	}
	cout << "Page Faults = " << r.pageFaults << endl;
	cout << "Final state of ram " << endl;
	r.display();
	return 0;
}
