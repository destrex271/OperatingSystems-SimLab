#include <stdio.h>

int main(){
		if(fork() && fork()){
				printf("Hello\n");
		}
		return 0;
}
