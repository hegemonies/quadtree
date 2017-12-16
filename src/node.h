#ifndef NODE_H
#define NODE_H
#include "bounds.h"

typedef struct Node {
	struct Node *nw;
	struct Node *ne;
	struct Node *sw;
	struct Node *se;

	Bounds *bounds;
	Point *center;
	int key;
} Node;

Node *node_new(void);
Node *node_with_bounds(double /*NWx*/, double /*NWy*/, double /*SEx*/, double /*SEy*/);
void node_free(Node */*node*/);
int node_contains(Node */*node*/, Point */*point*/);
int node_is_empty(Node */*node*/);

#endif