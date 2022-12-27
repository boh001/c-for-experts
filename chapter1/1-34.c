#include <stdio.h>

struct sample_t {
	char first;
	char seconde;
	char third;
	short fourth;
};

void print_size(struct sample_t* var) {
	printf("Size: %lu bytes\n", sizeof(*var));
}

void printf_bytes(struct sample_t* var) {
	unsigned char* ptr = (unsigned char*)var;
	for (int i = 0; i < sizeof(*var); i++, ptr++) {
		printf("%d", (unsigned int)*ptr);
	}

	printf("\n");
}

int main() {
	struct sample_t var;
	var.first = 'A';
	var.seconde = 'B';
	var.third = 'C';
	var.fourth = 765;
	print_size(&var);
	printf_bytes(&var);

	return 0;
}
