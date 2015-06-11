#include "stdio.h"

struct AvlTree {
	int key,
			height;
	AvlTree *left, *right;
};

void addList(AvlTree* list, int value) {
	if(list == NULL) {
		list = new AvlTree;
		list->key = value;
		list->height = 0;
		list->left = list->right = NULL;
	}
	if(list->key <= value) {
		addList(list->right, value);
	} else {
		addList(list->left, value);
	}
	int l_h = (list->left == NULL) ? 0 : list->left->height,
			r_h = (list->right == NULL) ? 0 : list->right->height;
	/*
	if(list->left != NULL) {
		l_h = list->left->height;
	}
	if(list->right != NULL) {
		r_h = list->right->key;
	}
	*/
	if((l_h - r_h) == 2) {
		
	} else if((r_h - l_h) == 2) {
		
	}
}

//---------------------------------------------
void deleteList(AvlTree) {
	
}

int main() {
	AvlTree* root = NULL;
	
	return 0;
}
