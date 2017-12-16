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

	Quadtree *tree = quadtree_new(1.0, 11.0, 11.0, 1.0);

	// printf("tree->root->nw->x = %f\n", tree->root->bounds->nw->x);
	// printf("tree->root->nw->y = %f\n", tree->root->bounds->nw->y);
	// printf("tree->root->se->x = %f\n", tree->root->bounds->se->x);
	// printf("tree->root->se->y = %f\n", tree->root->bounds->se->y);
	// printf("tree->root->center->x = %f\n", tree->root->center->x);
	// printf("tree->root->center->y = %f\n", tree->root->center->y);

	//printf("quadtree_insert (0, 0, 0) = %d\n", quadtree_insert(tree, 0, 0, 0));
	
	// printf("node is empty = %d\n", node_is_empty(tree->root));

	printf("quadtree_insert (8.0, 2.0) = %d\n", quadtree_insert(tree, 8.0, 2.0, 1));
	printf("quadtree_insert (4.2, 3.0) = %d\n", quadtree_insert(tree, 4.2, 3.0, 2));
	printf("quadtree_insert (4.2, 3.0) = %d\n", quadtree_insert(tree, 6.0, 6.0, 3));
	printf("quadtree_insert (5.5, 2.0) = %d\n", quadtree_insert(tree, 5.5, 2.0, 4));
	printf("quadtree_insert (8.0, 2.0) = %d\n", quadtree_insert(tree, 8.0, 2.0, 5));
	quadtree_walk(tree->root);

	// printf("tree->root->nw == %d\n", tree->root->nw == NULL);
	// printf("tree->root->ne == %d\n", tree->root->ne == NULL);
	// printf("tree->root->sw == %d\n", tree->root->sw == NULL);
	// printf("tree->root->se == %d\n", tree->root->se == NULL);
	// printf("tree->root->center == %d\n", tree->root->center == NULL);

	printf("capacity = %d\n", tree->capacity);

	printf("search (5.5, 2.0) = %d\n", quadtree_search(tree, 5.5, 2.0));

	quadtree_free(tree);

	printf("\x1b[33m GOOD \x1b[0m \n");

	return 0;
}