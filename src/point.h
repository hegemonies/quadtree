#ifndef POINT_H
#define POINT_H

typedef struct
{
	double x;
	double y;
} point;

point *point_init(double /*x*/, double /*y*/);
void point_free(point */*point*/);

#endif