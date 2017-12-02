#include "bounds.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

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

	if ((NW->x > SE->x) && (NW->y < SE->y)) {
		Point *tmp = NW;
		NW = SE;
		SE = tmp;
	}

	bounds->nw->x = NW->x;
	bounds->nw->y = NW->y;

	bounds->se->x = SE->x;
	bounds->se->y = SE->y;
}

void bounds_expand(Bounds *bounds, double x, double y)
{
	assert(bounds);

	bounds->nw->x = (x < bounds->nw->x) ? x : bounds->nw->x;
	bounds->nw->y = (y > bounds->nw->y) ? y : bounds->nw->y;
	bounds->se->x = (x > bounds->se->x) ? x : bounds->se->x;
	bounds->se->y = (y < bounds->se->y) ? y : bounds->se->y;
}

void bounds_free(Bounds *bounds)
{
	if (!bounds) {
		return;
	}
	free(bounds->nw);
	free(bounds->se);
	free(bounds);
}