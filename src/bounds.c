#include "bounds.h"
#include <stdlib.h>
#include <assert.h>

Bounds *bounds_init(Point *NW, Point *SE)
{
	assert(NW);
	assert(SE);

	Bounds *bounds = malloc(sizeof(bounds));
	assert(bounds);

	bounds->nw = malloc(sizeof(Point));
	bounds->nw->x = NW->x;
	bounds->nw->y = NW->y;

	bounds->se = malloc(sizeof(Point));
	bounds->se->x = SE->x;
	bounds->se->y = SE->y;

	return bounds;
}

void bounds_change(Bounds *bounds, Point *NW, Point *SE)
{
	assert(bounds);
	assert(NW);
	assert(SE);

	bounds->nw->x = NW->x;
	bounds->nw->y = NW->y;

	bounds->se->x = SE->x;
	bounds->se->y = SE->y;
}

void bounds_free(Bounds *bounds)
{
	assert(bounds);

	free(bounds->nw);
	free(bounds->se);
	free(bounds);
}