#ifndef BOUNDS_H
#define BOUNDS_H

#include "point.h"

typedef struct
{
	Point *nw;
	Point *se;
} Bounds;

Bounds *bounds_init(Point */*nw*/, Point */*se*/);
void bounds_change(Bounds */*bounds*/, Point */*nw*/, Point */*se*/);
void bounds_free(Bounds */*bounds*/);

#endif