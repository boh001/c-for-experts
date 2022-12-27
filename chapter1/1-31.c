#include <stdio.h>

int sum(int a, int b) {
	return a + b;
}

int substract(int a, int b) {
	return a - b;
}

int main() {
	int (*func_ptr)(int, int) ;
	func_ptr = NULL;

	func_ptr = &sum;
	int result = func_ptr(5, 4);
	printf("Sum: %d\n", result);

	func_ptr = &substract;
	result =func_ptr(5, 4);
}
