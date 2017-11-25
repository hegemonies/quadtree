#include <stdio.h>
#include "point.h"
#include "bounds.h"

int main(void)
{
	point *p = point_init(3.0, 2.0);

	printf("%f :: %f\n", p->x, p->y);

	point_free(p);

	point *p1 = point_init(0.0, 10.0);
	point *p2 = point_init(10.0, 0.0);

	bounds *b = bounds_init(p1, p2);

	point_free(p1);
	point_free(p2);

	printf("%f :: %f\n%f :: %f\n", b->nw->x, b->nw->y, b->se->x, b->se->y);

	point *np1 = point_init(5.0,5.0);
	point *np2 = point_init(8.0, 1.0);

	bounds_change(b, np1, np2);

	point_free(np1);
	point_free(np2);

	printf("%f :: %f\n%f :: %f\n", b->nw->x, b->nw->y, b->se->x, b->se->y);

	bounds_free(b);

	return 0;
}