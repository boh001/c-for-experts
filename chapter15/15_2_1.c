#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void* thread_body(void* arg) {
	char* str = (char*)arg;
	printf("%s\n", str);
	return NULL;
}

int main(int argc, char** argv) {
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;

	char str1[8], str2[8], str3[8];
	strcpy(str1, "Apple");
	strcpy(str2, "Orange");
	strcpy(str3, "Lemon");

	int result1 = pthread_create(&thread1, NULL, thread_body, str1);
	int result2 = pthread_create(&thread2, NULL, thread_body, str2);
	int result3 = pthread_create(&thread3, NULL, thread_body, str3);

	if (result1 || result2 || result3)  {
		printf("Thread could not be created.");
		exit(1);
	}

	result1 = pthread_detach(thread1);
	result2 = pthread_detach(thread2);
	result3 = pthread_detach(thread3);

	if (result1 || result2 || result3)  {
		printf("The thread could not be detached.");
		exit(2);
	}

	pthread_exit(NULL);
	return 0;
}

