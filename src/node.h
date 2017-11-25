#ifndef NODE_H
#define NODE_H
#include "bounds.h"

typedef struct Node {
	struct node *nw;
	struct node *ne;
	struct node *sw;
	struct node *se;

	Bounds *bounds;
	Point *center;
} Node;

#endif