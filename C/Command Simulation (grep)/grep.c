#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	FILE *fd;

	char str[100];
	char c;

	int i, j, k, m, flag;

	char temp[30];

	if (argc != 3) {
		printf("Number of Arguements provided != 3 \n");
		printf("Arguements Required: \n");
		printf("Search Text \n");
		printf("Filename \n");
		exit(-1);
	}

	fd = fopen(argv[2], "r");

	if (!fd) {
		printf("%s does not exist. \n", argv[2]);
		exit(-1);
	}

	while (!feof(fd)) {
		i = 0;
		while (1) {
			c = fgetc(fd);
			if (feof(fd)) {
				str[i++] = '\0';
				break;
			}
			if (c == '\n') {
				str[i++] = '\0';
				break;
			}
			str[i++] = c;
		}

		if (strlen(str) >= strlen(argv[1])) {
			for (k = 0; k <= strlen(str) - strlen(argv[1]); k++) {
				for (m = 0; m < strlen(argv[1]); m++) {
					temp[m] = str[k + m];
				}
				temp[m] = '\0';
				if (strcmp(temp, argv[1]) == 0)	{
					printf("%s\n", str);
					break;
				}
			}
		}
	}

	printf("\n");

	return 0;
}