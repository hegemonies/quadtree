#include "node.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

Node *node_new(void)
{
	Node *node = malloc(sizeof(Node));

	assert(node);

	node->nw = NULL;
	node->ne = NULL;
	node->sw = NULL;
	node->se = NULL;
	node->bounds = NULL;
	node->center = NULL;

	return node;
}

Node *node_with_bounds(double NWx, double NWy, double SEx, double SEy)
{
	Node *node = node_new();

	Point *nw = point_init(NWx, NWy);
	Point *se = point_init(SEx, SEy);

	node->bounds = bounds_init(nw, se);

	point_free(nw);
	point_free(se);

	node->center = point_init((SEx - NWx) / 2, (NWy - SEy) / 2);

	return node;
}


void node_free(Node *node)
{
	point_free(node->center);
	bounds_free(node->bounds);
	if (node->nw) {
		node_free(node->nw);
	}
	if (node->ne) {
		node_free(node->ne);
	}
	if (node->se) {
		node_free(node->se);
	}
	if (node->sw) {
		node_free(node->sw);
	}
	free(node);
}

