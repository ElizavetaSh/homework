
#include <stdio.h>
#include <malloc.h>

int*** historgam_point(int** pp, int N) {

	int count_len = 0;
	int count_len1 = 1;
	int res_count = 0;
	int** buffer_value = NULL;
	int** buffer_count = NULL;
	int*** finish_point = NULL;
	//сортирока
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (*pp[i] > *pp[j])
			{
				int* min = pp[j];
				pp[j] = pp[i];
				pp[i] = min;
			}
		}
	}


	for (int i = 0; i < N - 1; i++)
	{
		if (*pp[i] == *pp[i + 1]) {
			count_len1++;
		}
		else {
			count_len++;
			res_count = 2 * count_len;

			int** buffer_value_new = (int**)realloc(buffer_value, res_count * sizeof(int));
			int** buffer_count_new = (int**)realloc(buffer_count, res_count * sizeof(int));

			if ((buffer_value_new != NULL) && (buffer_count_new != NULL))
			{

				buffer_value = buffer_value_new;
				buffer_value[count_len - 1] = pp[i];
				buffer_count = buffer_count_new;
				buffer_count[count_len - 1] = &count_len1;


				//printf("%d ,%d\n ", *buffer_value[count_len - 1], *buffer_count[count_len - 1]);
				count_len1 = 1;
			}

			else return NULL;
		}
	}
	int*** finish_point_new = (int***)realloc(finish_point, 4 * sizeof(int));
	if (finish_point_new != NULL)
	{
		finish_point = finish_point_new;
		finish_point[0] = buffer_value;
		finish_point[1] = buffer_count;
	}
	else return NULL;

	return finish_point;
}