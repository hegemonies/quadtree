#include <stdio.h>
#include "quadtree.h"

int main(void)
{
	/*Point *p = point_init(3.0, 2.0);

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


	printf("\n");*/

	Node *node = node_with_bounds(5.0, 11.0, 11.0, 5.0);
	printf("node->bounds->nw->x = %f\n", node->bounds->nw->x);
	printf("node->bounds->nw->y = %f\n", node->bounds->nw->y);
	printf("node->bounds->se->x = %f\n", node->bounds->se->x);
	printf("node->bounds->se->y = %f\n", node->bounds->se->y);
	printf("node->center->x = %f\n", node->center->x);
	printf("node->center->y = %f\n", node->center->y);
	printf("\n");


	Quadtree *tree = quadtree_new(1.0, 11.0, 11.0, 1.0);

	printf("tree->root->nw->x = %f\n", tree->root->bounds->nw->x);
	printf("tree->root->nw->y = %f\n", tree->root->bounds->nw->y);
	printf("tree->root->se->x = %f\n", tree->root->bounds->se->x);
	printf("tree->root->se->y = %f\n", tree->root->bounds->se->y);
	printf("tree->root->center->x = %f\n", tree->root->center->x);
	printf("tree->root->center->y = %f\n", tree->root->center->y);

	quadtree_insert(tree, 3.5, 8.5, 5);
	quadtree_insert(tree, 2, 6, 5);

	printf("root->root->nw == %p\n", tree->root->nw);
	printf("root->root->ne == %p\n", tree->root->ne);
	printf("root->root->sw == %p\n", tree->root->sw);
	printf("root->root->se == %p\n", tree->root->se);

	printf("capacity = %d\n", tree->capacity);

	quadtree_walk(tree->root);

	printf("\x1b[33m GOOD \x1b[0m \n");

	return 0;
}