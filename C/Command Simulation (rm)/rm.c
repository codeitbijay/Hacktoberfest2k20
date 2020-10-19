#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int fd;

	if (argc != 2) {
		printf("Number of Arguements provided != 2 \n");
		printf("Arguements Required: \n");
		printf("Filename \n");
		exit(-1);
	}

	fd = open(argv[1], O_RDONLY);

	if (fd != -1) {
		close(fd);
		unlink(argv[1]);
		printf("%s deleted! \n", argv[1]);
	}
	else {
		perror(argv[1]);
	}

	return 0;
}