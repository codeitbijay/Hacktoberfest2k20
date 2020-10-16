#include <cstdio>
#include <cstdlib>
int main(void) {
	int v;
	scanf("%d", &v);
	for (int r = 0; r < v; ++r) {
		for (int s = 0; s < v; ++s) {
			if (r == s || r == (v-1)-s) {
				printf("x");
			} 	else{
					printf(" ");
					}
			
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}