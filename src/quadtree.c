#include "quadtree.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

Quadtree *quadtree_new(double NWx, double NWy, double SEx, double SEy)
{
	Quadtree *tree = malloc(sizeof(Quadtree));
	assert(tree);

	tree->root = node_with_bounds(NWx, NWy, SEx, SEy);
	assert(tree->root);

	tree->root->nw = NULL;
	tree->root->ne = NULL;
	tree->root->sw = NULL;
	tree->root->se = NULL;

	tree->capacity = 0;

	return tree;
}

void quadtree_walk(Node *node)
{
	if (node == NULL) {
		return;
	}
	if (node->bounds != NULL) {
		printf("{ nw.x:%.2f, nw.y:%.2f, se.x:%.2f, se.y:%.2f",
		 node->bounds->nw->x, node->bounds->nw->y, node->bounds->se->x, node->bounds->se->y);
	}

	if (node->center) {
		printf(", center:%.2f, %.2f }:", node->center->x, node->center->y);
	} else {
		printf(" }:");
	}
	
	if (node->nw != NULL) {
		quadtree_walk(node->nw);
	}
	if (node->ne != NULL) {
		quadtree_walk(node->ne);
	}
	if (node->sw != NULL) {
		quadtree_walk(node->sw);
	}
	if (node->se != NULL) {
		quadtree_walk(node->se);
	}

	printf("\n");
}

int node_contains(Node *node, Point *point)
{
	return node->bounds != NULL 
		&& node->bounds->nw->x <= point->x 
		&& node->bounds->nw->y >= point->y 
		&& node->bounds->se->x >= point->x 
		&& node->bounds->se->y <= point->y;
}

int node_is_empty(Node *node)
{
	return node->nw == NULL 
		&& node->ne == NULL 
		&& node->sw == NULL 
		&& node->se == NULL 
		&& !node->center;
}

int node_is_pointer(Node *node)
{
	return node->nw != NULL 
		&& node->ne != NULL 
		&& node->sw != NULL 
		&& node->se != NULL 
		&& node->center != NULL;
}

Node *get_quadrant(Node *node, Point *point)
{
	if (node_contains(node->nw, point)) {
		return node->nw;
	}

	if (node_contains(node->ne, point)) {
		return node->ne;
	}

	if (node_contains(node->sw, point)) {
		return node->sw;
	}

	if (node_contains(node->se, point)) {
		return node->se;
	}

	return NULL;
}

int split_node(Quadtree *tree, Node *node)
{
	Node *nw;
	Node *ne;
	Node *sw;
	Node *se;
	Point *point_old;
	int key_old;

	double x = node->bounds->nw->x;
	double y = node->bounds->nw->y;
	double hw = (node->bounds->se->x - node->bounds->nw->x) / 2;
	double hh = (node->bounds->nw->y - node->bounds->se->y) / 2;

	nw = node_with_bounds(x, y, x + hw, y - hh);
	if (!nw) {
		return 0;
	}

	ne = node_with_bounds(x + hw, y, x + hw * 2, y - hh);
	if (!ne) {
		return 0;
	}

	sw = node_with_bounds(x, y - hh, x + hw, y - hh * 2);
	if (!sw) {
		return 0;
	}

	se = node_with_bounds(x + hw, y - hh, x + hw * 2, y - hh * 2);
	if (!se) {
		return 0;
	}

	node->nw = nw;
	node->ne = ne;
	node->sw = sw;
	node->se = se;

	point_old = node->center;
	key_old = node->key;
	node->center = NULL;
	node->key = 0;

	return _insert(tree, node, point_old, key_old);
}

int _insert(Quadtree *tree, Node *node, Point *point, int key)
{
	if (node_is_empty(node)) {
		printf("_insert 1 case go\n");
		node->center = point;
		node->key = key;
		return 1;
	} else if (node->center) {
		if (node->center->x == point->x && node->center->y == point->y) {
			printf("_insert 2 case go\n");
			node->center = point;
			node->key = key;
		} else {
			printf("_insert 3 case go\n");
			if (!split_node(tree, node)) {
				printf("split == 0\n");
				return 0;
			}
			return _insert(tree, node, point, key);
		}
	} else if (node_is_pointer(node)) {
		printf("_insert 4 case go\n");
		Node *quadrant = get_quadrant(node, point);
		return !quadrant ? 0 : _insert(tree, quadrant, point, key);
	}

	return 0;
}

int quadtree_insert(Quadtree *tree, double x, double y, int key)
{
	Point *point = point_init(x, y);
	if (!point) {
		printf("insert 1 case go\n");
		return 0;
	}

	int insert_status = 0;

	if (!node_contains(tree->root, point)) {
		printf("insert 2 case go\n");
		point_free(point);
		return 0;
	}

	if (!(insert_status = _insert(tree, tree->root, point, key))) {
		printf("insert 3 case go\n");
		point_free(point);
		return 0;
	}

	if (insert_status == 1) {
		tree->capacity++;
	}

	return insert_status;
}