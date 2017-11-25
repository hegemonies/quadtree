#include <stdlib.h>
#include <assert.h>
#include "point.h"

point *point_init(double x, double y)
{
	point *p = malloc(sizeof(point));
	assert(p);
	p->x = x;
	p->y = y;

	return p;
}

void point_free(point *p)
{
	free(p);
}