#ifndef QUADTREE_H
#define QUADTREE_H
#include "node.h"

typedef struct {
	Node *root;
	int capacity;
} Quadtree;

Quadtree *quadtree_new(double /*NWx*/, double /*NWy*/, double /*SEx*/, double /*SEy*/);
void quadtree_walk(Node */*root*/);
int quadtree_insert(Quadtree */*root*/, double /*x*/, double /*y*/, int /*key*/);
Point *quadtree_search(Quadtree */*root*/, double /*x*/, double /*y*/);
int split_node(Quadtree *tree, Node *node);
int _insert(Quadtree *tree, Node *node, Point *point, int key);
Node *get_quadrant(Node *node, Point *point);
int node_is_leaf(Node *node);

#endif