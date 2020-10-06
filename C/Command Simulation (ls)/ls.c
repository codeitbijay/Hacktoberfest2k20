#include <stdio.h>
#include <dirent.h>

int main() {
	struct dirent **namelist;

	int n, i;
	char pathname[100];

	getcwd(pathname);

	n = scandir(pathname, &namelist, 0, alphasort);

	if (n < 0) {
		perror("scandir");
	}
	else {
		for (i = 0; i < n; i++) {
			if (namelist[i]->d_name[0] != '.') {
				printf("%s \n", namelist[i]->d_name);
			}
		}
	}

	printf("\n");

	return 0;
}