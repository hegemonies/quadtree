#include <stdio.h>
#include "quadtree.h"
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <inttypes.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int main(void)
{
	srand(time(0));
	double NWx = 0.0;
	double NWy = 1000.0;
	double SEx = 1000.0;
	double SEy = 0.0;

	unsigned int sum_point = (NWy / 0.5) * (SEx / 0.5);

	Quadtree *tree = quadtree_new(NWx, NWy, SEx, SEy);

	double find_500[8] = { 0 };

	//double t[sum_point] = { 0 };
	double *t = malloc(sizeof(double) * sum_point);
	double time_500[8] = { 0 };
	int count_find = 0;
	int count = 0;

	for (double i = 0; i < SEx; i += 0.5) {
		for (double j = 0; j < NWy; j += 0.5) {
			t[count] = wtime();
			quadtree_insert(tree, j, i, i + j);
			t[count] = wtime() - t[count];
			count++;

			// if (count % 500000 == 0) {
			// 	for (int mx = 0; mx < 1000; mx++) {
			// 		for (int m = 0; m < 1000; m++) {
			// 			find_500[count_find] = wtime();
			// 			quadtree_search(tree, m, mx);
			// 			find_500[count_find] = wtime() - find_500[count_find];
			// 		}
			// 	}
			// 	printf("%.20f\n", find_500[count_find]);
			// 	find_500[count_find] = find_500[count_find] / 500000;
			// }


			if (count % 500000 == 0) {
				for (int i = 0; i < 10000; i++) {
					find_500[count_find] = wtime();
					quadtree_search(tree, getrand(0, 1000), getrand(0, 1000));
					find_500[count_find] = wtime() - find_500[count_find];
				}
				printf("%.40f\n", find_500[count_find] / 500000);
				find_500[count_find] /= 500000;
			}
		}
	}

	unsigned int k = 0;
	for (unsigned int i = 0; i < 8; i++) {
		for (unsigned int j = k; j < k + 500000; j++) {
			time_500[i] += t[j];
		}
		k += 500000;
	}

	double f[500] = { 0 };
	double j = 0.5;

	for (int i = 0; i < 500; i++) {
		f[i] = wtime();
		quadtree_search(tree, j, i);
		f[i] = wtime() - f[i];
		j += 0.5;
	}

	FILE *out = fopen("benchmark.txt", "w");

	double max = 0.0;
	double min = 99999.0;

	fprintf(out, "\nИзмерение времени добавления точек с шагом в 1:\n\n");
	for (int i = 0; i < sum_point; i++) {
		if (t[i] > max) {
			max = t[i];
		}
		if (t[i] < min) {
			min = t[i];
		}
		fprintf(out, "%d.\t\t%0.10f\n", i, t[i]);
	}

	fprintf(out, "max = %.10f\n", max);
	fprintf(out, "min = %.20f\n\n\n", min);

	fprintf(out, "\nИзмерение времени поиска точек:\n\n");
	for (int i = 0; i < 500; i++) {
		fprintf(out, "%d.\t %.10f\n", i, f[i]);
	}

	fprintf(out, "\nСумма времени для добавления точек с шагом в 500 000:\n\n");
	int tmp = 500000;
	for (int i = 0; i < 8; i++) {
		fprintf(out, "%u-%u = %.10f\n", tmp - 500000, tmp, time_500[i]);
		tmp += 500000;
	}

	fprintf(out, "\nСреднее время добавления точки с шагом в 500 000:\n\n");
	tmp = 500000;
	for (int i = 0; i < 8; i++) {
		if (i == 0) {
			fprintf(out, "%u-%u =\t\t %.10f\n", tmp - 500000, tmp, time_500[i] / tmp);
		} else {
			fprintf(out, "%u-%u =\t %.10f\n", tmp - 500000, tmp, time_500[i] / tmp);
		}
		tmp += 500000;
	}

	fprintf(out, "\nСреднее время поиска 1000 точек с шагом в 500 000:\n");
	for (int i = 0; i < 8; i++) {
		fprintf(out, "%d = %0.20f\n", i, find_500[i]);
	}

	fclose(out);

	// quadtree_walk(tree->root);

	printf("capacity = %d\n", tree->capacity);

	//printf("search (1.0, 1.0) = %d\n", quadtree_search(tree, 1.0, 1.0));

	quadtree_free(tree);

	printf("\x1b[33m GOOD \x1b[0m \n");

	free(t);

	return 0;
}