#include "bounds.h"
#include <stdlib.h>
#include <assert.h>

bounds *bounds_init(point *NW, point *SE)
{
	assert(NW);
	assert(SE);

	bounds *b = malloc(sizeof(bounds));
	assert(b);

	b->nw = malloc(sizeof(point));
	b->nw->x = NW->x;
	b->nw->y = NW->y;

	b->se = malloc(sizeof(point));
	b->se->x = SE->x;
	b->se->y = SE->y;

	return b;
}

void bounds_change(bounds *bounds, point *NW, point *SE)
{
	assert(bounds);
	assert(NW);
	assert(SE);

	bounds->nw->x = NW->x;
	bounds->nw->y = NW->y;

	bounds->se->x = SE->x;
	bounds->se->y = SE->y;
}

void bounds_free(bounds *bounds)
{
	assert(bounds);

	free(bounds->nw);
	free(bounds->se);
	free(bounds);
}