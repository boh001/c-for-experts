#include <stdio.h>

int main(int argc, char** argv) {
#if __STDC_VERSION__ >= 201710L
	printf("Hello World from C18!\n");
#elif __STDC_VERSION__ >= 201112L
	printf("Hello World from c11!\n");
#elif __STDC_VERSION__ >= 199901L
	printf("Hello World from c99!\n");
#else
	printf("Hello World from c89/90!\n");
#endif
	return 0;
}
