#ifndef POINT_H
#define POINT_H

typedef struct
{
	double x;
	double y;
} Point;

Point *point_init(double /*x*/, double /*y*/);
void point_free(Point */*point*/);

#endif