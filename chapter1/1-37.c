#include <stdio.h>

typedef struct {
	int x;
	int y;
} poin_t;

typedef struct {
	poin_t center;
	int radius;
} circle_t;

int main() {
	circle_t c;

	circle_t* p1 = &c;
	poin_t* p2 = (poin_t*)&c;
	int* p3 = (int*)&c;

	printf("p1: %p\n", (void*)p1);
	printf("p2: %p\n", (void*)p2);
	printf("p3: %p\n", (void*)p3);

}
