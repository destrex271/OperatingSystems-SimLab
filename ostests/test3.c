#include <stdio.h>

int main(){
		int x = fork() || fork() && fork && fork();
		printf("OK %d\n", x);
		return 0;
}
