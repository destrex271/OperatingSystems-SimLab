#include <pthread.h>
#include <iostream>
#include <unistd.h>

int main(){
	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex, NULL);
	std::cout << "Before Locking" << std::endl;
	pthread_mutex_lock(&mutex);
	fork();
	std::cout << "Locked" << std::endl << "Executing critical section" << std::endl;
	pthread_mutex_unlock(&mutex);
	return 0;
}
