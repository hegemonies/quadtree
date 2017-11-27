#include <stdio.h>
#include "quadtree.h"

int main(void)
{
	Point *p = point_init(3.0, 2.0);

	printf("%f :: %f\n", p->x, p->y);

	point_free(p);

	Point *p1 = point_init(0.0, 10.0);
	Point *p2 = point_init(10.0, 0.0);

	Bounds *b = bounds_init(p1, p2);

	point_free(p1);
	point_free(p2);

	printf("%f :: %f\n%f :: %f\n", b->nw->x, b->nw->y, b->se->x, b->se->y);

	Point *np1 = point_init(5.0,5.0);
	Point *np2 = point_init(8.0, 1.0);

	bounds_change(b, np1, np2);

	point_free(np1);
	point_free(np2);

	printf("%f :: %f\n%f :: %f\n", b->nw->x, b->nw->y, b->se->x, b->se->y);
	
	bounds_free(b);

	Node *node = node_with_bounds(1.0, 5.0, 5.0, 1.0);

	quadtree_walk(node);

	bounds_expand(node->bounds, 0.5, 10.0);

	quadtree_walk(node);

	bounds_expand(node->bounds, 10.0, 0.5);

	quadtree_walk(node);

	printf("\x1b[33m GOOD \x1b[0m \n");

	return 0;
}