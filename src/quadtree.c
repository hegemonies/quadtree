#include "quadtree.h"
#include <stdio.h>

void quadtree_walk(Node *root)
{
	if(root->bounds != NULL) {
		printf("{ nw.x:%f, nw.y:%f, se.x:%f, se.y:%f }: ",
		 root->bounds->nw->x, root->bounds->nw->y, root->bounds->se->x, root->bounds->se->y);
	}
	
	if(root->nw != NULL) quadtree_walk(root->nw);
	if(root->ne != NULL) quadtree_walk(root->ne);
	if(root->sw != NULL) quadtree_walk(root->sw);
	if(root->se != NULL) quadtree_walk(root->se);
	printf("\n");
}