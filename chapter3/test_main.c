#include "test_head.h"
#include <stdio.h>

int main() {
	int a = add(1, 3);
	int b = minus(1, 3);

	printf("%d", a);
	printf("%d", b);
	
	return 0;
}
