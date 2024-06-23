#include <stdio.h>
#include <stdlib.h>

typedef struct ttree{
	int dato;
	struct ttree *leftchild;
	struct ttree *rightchild;
}Binarytree;

void destroytree(Binarytree* root);
void remove(Binarytree* root, int value);
void PreOrden(Binarytree* root);
void InOrden(Binarytree* root);
void PostOrden(Binarytree* root);
void update(Binarytree* root, int value, int newValue);
Binarytree* search(Binarytree* root, int value);
Binarytree* insert(Binarytree* root, int value);
Binarytree* getNode(int value);

Binarytree* getNode(int value){
	Binarytree node=(Binarytree)malloc(sizeof(Binarytree));
	node->dato=value;
	node->leftchild=node->rightchild=NULL;
	return node;
}

Binarytree* insert(Binarytree* root, int value){
	if(root==NULL){
		return getnode(value);
	}else if(root->dato==value){
		printf("\n\nError: el valor %d ya existe", value);
	}else if(value<root->dato){
		root->leftchild=insert(root->leftchild, value);
	}else{
		root->rightchild=insert(root->rightchild, value);
	}
	return root;
}

Binarytree* search(Binarytree* root, int value){
	if(root==NULL){  /*if(root=NULL){*/
		printf("\n\n\t Error: el valor %d no existe\n", value);
		return NULL;
	}else if(root->dato==value){
		return root;
	}else if(value<root->dato){
		search(root->leftchild, value);
	}else{
		search(root->rightchild, value);
	}
}

void update(Binarytree* root, int value, int newValue){
	if(root=search(root, value)){
		root->dato=value;
	}
}

void PreOrden(Binarytree* root){
	if(root=NULL)
		return;
		printf("%d", root->value);
		PreOrden(root->leftchild);
		PreOrden(root->rightchild);
}

void InOrden(Binarytree* root){
	if(root=NULL)
		return;
		InOrden(root->leftchild);
		printf("%d", root->value);
		InOrden(root->rightchild);
}

void PostOrden(Binarytree* root){
	if(root=NULL)
		return;
		PostOrden(root->leftchild);
		PostOrden(root->rightchild);
		printf("%d", root->value);		
}

void remove(Binarytree* root, int value){
	Binarytree* nodotodelete=search(root, value);
	if(nodotodelete!=NULL){
		if(root->leftchild==NULL&&root->rightchild==NULL){
			free(nodotodelete);
		}else{
			Binarytree* Explore;
			if(Explore==nodotodelete->leftchild){
				while(Explore->rightchild)
				Explore=Explore->rightchild;
			}else if(Explorer==nodotodelete->rightchild){
				while(Explore->leftchild)
				Explore=Explore->leftchild;
			}
			nodotodelete->dato=Explore->dato;
			free(Explore);
		}
	}
}

void destroytree(Binarytree* root){
	if(root=NULL)
		return;
	destroytree(root->leftchild);
	destroytree(root->rightchild);
		free(nodo);
	root->dato=0;
	root=root->leftchild=root->rightchild=NULL;
}

int main() {
	Binarytree* TREE=NULL;
	TREE=insert(TREE,S);
	insert(TREE, 8);
	PreOrden(TREE);
	insert(TREE, 1);
	update(TREE, 8,9);
	search(TREE, 32);
	remove(TREE, 1);
	return 0;
}
