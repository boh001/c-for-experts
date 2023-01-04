#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define CHECK_RESULT(result) \
	if (result) { \
		printf("A phtread error happened. \n"); \
		exit(1); \
	}

int TRUE = 1;
int FALSE = 0;

char* shared_array;
size_t shared_array_len;

pthread_barrier_t alloc_barrier;
pthread_barrier_t fill_barrier;
pthread_barrier_t done_barrier;

void* alloc_thread_body(void* arg) {
	shared_array_len = 20;
	shared_array = (char*)malloc(shared_array_len * sizeof(char*));
	pthread_barrier_wait(&alloc_barrier);
	return NULL;
}

