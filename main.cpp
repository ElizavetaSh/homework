
#include <iostream>
#include <stdio.h>
#include <malloc.h>

using namespace std;

extern "C" {
#include "hist.h"
}

int main()
{
	int sd = -44;
	int s1d = 45;
	int s2d = 11;
	int* fd = &sd;
	int* p[] = { fd,fd,&s2d,fd,fd,&s1d,&s2d,&s1d };

	int N = sizeof(p) / (2 * sizeof(int));
	int*** finish_point = historgam_point(&*p, N);

	std::cout << finish_point << std::endl;
	std::cout << *finish_point[0] << std::endl;
	std::cout << *finish_point[1] << std::endl;

	free(finish_point);

	return 0;
}