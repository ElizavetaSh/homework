#include <stdio.h>
#include <malloc.h>
#include "stdlib.h"
#include <stdio.h>


int compare(const void* x1, const void* x2)
{
	return (*(int*)x1 - *(int*)x2);
}


int*** historgam_point(int** pp, int N) {

	int count_len = 0;
	int count_len1 = 1;
	int res_count = 0;
	int** buffer_value = NULL;
	int* buffer_count = NULL;
	int** buffer_count_point = NULL;
	int*** finish_point = NULL;
	int** Copy_array = NULL;

	if (N == 0) return NULL;
	if (pp == NULL) return NULL;

	Copy_array = (int**)malloc(N * sizeof(int**));

	if (Copy_array != NULL) {
		for (int i = 0; i < N; i++) {
			Copy_array[i] = pp[i];
		}
	}else {
		free(Copy_array);
		return NULL;
	}

	qsort(Copy_array, N, sizeof(int), compare);

	for (int i = 0; i < N - 1; i++)
	{
		if (*Copy_array[i] == *Copy_array[i + 1]) {
			count_len1++;
		}
		else {
			count_len++;
			res_count =2*count_len;

			int** buffer_value_new = (int**)realloc(buffer_value, res_count * sizeof(int**));
			int* buffer_count_new = (int*)realloc(buffer_count, res_count * sizeof(int*));
			int** buffer_count_point_new = (int**)realloc(buffer_count_point, res_count * sizeof(int**));

			if ((buffer_value_new != NULL) && (buffer_count_new != NULL) && (buffer_count_point_new != NULL))
			{

				buffer_value = buffer_value_new;
				buffer_value[count_len - 1] = pp[i];
				buffer_count = buffer_count_new;
				buffer_count[count_len - 1] = count_len1;
				buffer_count_point = buffer_count_point_new;
				buffer_count_point[count_len - 1] = &buffer_count[count_len - 1];

				count_len1 = 1;
			}
			else {
				free(buffer_value);
				free(buffer_count);
				free(buffer_count_point);
				return NULL;
			}

		}
	}

	int** buffer_value_new = (int**)realloc(buffer_value, res_count * sizeof(int**));
	int** buffer_count_point_new = (int**)realloc(buffer_count_point, res_count * sizeof(int**));

	if ((buffer_value_new != NULL) && (buffer_count_point_new != NULL))
	{

		buffer_value = buffer_value_new;
		buffer_value[count_len - 1] = NULL;
		buffer_count_point = buffer_count_point_new;
		buffer_count_point[count_len - 1] = NULL;
	}
	else {
		free(buffer_value);
		free(buffer_count_point);
		return NULL;
	}


	int*** finish_point_new = (int***)realloc(finish_point, 4 * sizeof(int***));
	if (finish_point_new != NULL)
	{
		finish_point = finish_point_new;
		finish_point[0] = buffer_value;
		finish_point[1] = buffer_count_point;
	}
	else {
		free(finish_point);
		return NULL;
	}

	return finish_point;
}