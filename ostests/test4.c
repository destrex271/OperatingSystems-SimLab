#include <stdio.h>

// Testing using function

void proc1(){
		printf("%d",fork());
		sleep(30);
		printf("In proc 1\n");
}

void proc2(){
		printf("%d",fork());
		sleep(30);
		printf("In proc 2\n");
}

int main(){		
		proc1();	
		proc2();
		printf("In main!\n");
		return 0;
}
