#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION "2.3.4"

#define LOG_ERROR(format, ...) \
	fprintf(stderr, format, __VA_ARGS__)

int main(int argc, char** argv) {
	if (argc < 3) {
		LOG_ERROR("Invalid number of arguments for version %s\n", VERSION);
		exit(1);
	}
}
