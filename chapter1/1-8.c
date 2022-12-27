#include <stdio.h>
#include <string.h>

#define CMD(NAME) \
	char NAME ## _cmd[256] = ""; \
	strcpy(NAME ## _cmd, NAME);

int main(int argc, char** argv) {
}
