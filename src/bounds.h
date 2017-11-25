#ifndef BOUNDS_H
#define BOUNDS_H

#include "point.h"

typedef struct
{
	point *nw;
	point *se;
} bounds;

bounds *bounds_init(point */*nw*/, point */*se*/);
void bounds_change(bounds */*bounds*/, point */*nw*/, point */*se*/);
void bounds_free(bounds */*bounds*/);

#endif