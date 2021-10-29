#include <stdio.h>
#include "stdlib.h"
#include "hist.h"

int main()
{
	int sd = -44;
	int s1d = 45;
	int s2d = 11;
	int* p[] = { &s2d,&s1d,&s2d,&s1d };

	int N = sizeof(p) / (2 * sizeof(int));
	int*** finish_point = historgam_point(&*p, N);

	printf("%d", **finish_point[0]);
	printf("%d", **finish_point[1]);

	free(finish_point);

	return EXIT_SUCCESS;
}