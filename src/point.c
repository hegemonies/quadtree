#include <stdlib.h>
#include <assert.h>
#include "point.h"

Point *point_init(double x, double y)
{
	Point *p = malloc(sizeof(Point));
	assert(p);
	p->x = x;
	p->y = y;

	return p;
}

void point_free(Point *p)
{
	free(p);
}