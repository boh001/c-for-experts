#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_body_1(void* arg) {
	int local_var = 0;
	printf("Thread1 > Stack Address: %p\n", (void*)&local_var);
	return NULL;
}

void* thread_body_2(void* arg) {
	int local_var = 0;
	printf("Thread2 > Stack Address: %p\n", (void*)&local_var);
	return NULL;
}

int main(int argc, char** argv) {
	size_t buffer_len = PTHREAD_STACK_MIN + 100;

	char* buffer = (char*)malloc(buffer_len * sizeof(char));

	pthread_t thread1;
	pthread_t thread2;

	int result1 = pthread_create(&thread1, NULL, thread_body_1, NULL);

	pthread_attr_t attr;
	pthread_attr_init(&attr);
	if (pthread_attr_setstack(&attr, buffer, buffer_len)) {
		printf("Failed while setting the stack attributes\n");
		exit(1);
	}

	int result2 = pthread_create(&thread2, NULL, thread_body_2, NULL);

	if (result1 || result2)  {
		printf("Thread could not be created.");
		exit(2);
	}

	printf("Main Thread > Heap Address: %p\n", (void*)buffer);
	printf("Main Thread > Stack Address: %p\n", (void*)buffer_len);

	result1 = pthread_join(thread1, NULL);
	result2 = pthread_join(thread2, NULL);

	if (result1 || result2)  {
		printf("The thread could not be joined.");
		exit(3);
	}

	free(buffer);

	return 0;
}



