#include <cstdio>


struct MyTree {
	int value;
	MyTree *left, *right;
};

void addList(MyTree** root, int value) {
	if(*root == NULL) {
		*root = new MyTree;
		(*root)->value = value;
		(*root)->left = (*root)->right = NULL;
		return;
	}
	if((*root)->value <= value) {
		addList(&(*root)->right, value);
	} else {
		addList(&(*root)->left, value);
	}
}

void addList2(MyTree** root, int value) {
	MyTree* temp_list = *root;
	for( ; temp_list != NULL; ) {
		if((temp_list)->value <= value) {
			temp_list = temp_list->right;
		} else {
			temp_list = temp_list->left;
	}
	}
	temp_list = new MyTree;
	temp_list->value = value;
	temp_list->left = temp_list->right = NULL;
/*
	if(*root == NULL) {
		*root = new MyTree;
		(*root)->value = value;
		(*root)->left = (*root)->right = NULL;
		return;
	}
	if((*root)->value <= value) {
		addList(&(*root)->right, value);
	} else {
		addList(&(*root)->left, value);
	}
*/
}

void printTree(MyTree* root) {
	if(root == NULL) {
		return;
	}
	printTree(root->left);
	printf("%d ", root->value);
	printTree(root->right);
}

void deleteTree(MyTree** root) {
	if(*root == NULL) {
		return;
	}
	deleteTree(&(*root)->left);
	deleteTree(&(*root)->right);
	delete (*root);
}

int main() {
	int n;
	MyTree* root = NULL;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int value;
		scanf("%d", &value);
		//addList(&root, value);
		addList2(&root, value);
	}
	printTree(root);
	deleteTree(&root);
	return 0;
}
