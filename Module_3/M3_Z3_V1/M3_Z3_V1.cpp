#include <cstdio>

///////////////////	Описание бинарного дерева

struct MyBinTree {
	int value, 
			height;
	MyBinTree *left, *right;
};

class	BinTree {
	public:
		void add(int value) { addList(&root, value); }
		void print() { printTree(root); }
		int getHeight() { return root->height;	}
		BinTree(): root(NULL) {}
		~BinTree() {
			deleteTree(&root);
		}
	private:
		void addList(MyBinTree** r, int value);
		void deleteTree(MyBinTree** r);
		void printTree(MyBinTree* r);
		MyBinTree* root;
};

void BinTree::addList(MyBinTree** r, int value) {
	if(*r == NULL) {
		*r = new MyBinTree;
		(*r)->value = value;
		(*r)->height = 0;
		(*r)->left = (*r)->right = NULL;
		return;
	}
	if((*r)->value <= value) {
		addList(&(*r)->right, value);
	} else {
		addList(&(*r)->left, value);
	}
	int h = 0;
	if((*r)->left != NULL) {
		h = (*r)->left->height;
	}
	if((*r)->right != NULL && (*r)->right->height > h) {
		h = (*r)->right->height;
	}
	(*r)->height = ++h;
}

void BinTree::printTree(MyBinTree* r) {
	if(r == NULL) {
		return;
	}
	printTree(r->left);
	printf("%d ", r->value);
	printTree(r->right);
}

void BinTree::deleteTree(MyBinTree** r) {
	if(*r == NULL) {
		return;
	}
	deleteTree(&(*r)->left);
	deleteTree(&(*r)->right);
	delete (*r);
}

///////////////////	Описание бинарного дерева  ##############

///////////////////	Описание декартового дерева 

struct MyDecTree {
	int value, 
		  prior,
			height;
	MyDecTree *left, *right;
};

class DecTree {
	public:
		DecTree(): root(NULL) {}
		~DecTree() {
			deleteTree(&root);
		}
		void add(int value, int prior) { addList(&root, value, prior);	}
		void print() { printTree(root); }
		void printWithPrior() { printTreeWithPrior(root); } 
		int getHeight() { return root->height;	}
	private:
		void split(MyDecTree* r, int value, MyDecTree** T1, MyDecTree** T2);
		void addList(MyDecTree** r, int value, int prior);
		int countHeight(MyDecTree** r);
		void printTree(MyDecTree* r);
		void printTreeWithPrior(MyDecTree* r);
		void deleteTree(MyDecTree** r);
		MyDecTree *root;
};

void DecTree::printTree(MyDecTree* r) {
	if(r == NULL) {
		return;
	}
	printTree(r->left);
	printf("%d ", r->value);
	printTree(r->right);
}

void DecTree::printTreeWithPrior(MyDecTree* r) {
		if(r == NULL) {
		return;
	}
	printTree(r->left);
	printf("%d %d ", r->value, r->prior);
	printTree(r->right);
}

void DecTree::deleteTree(MyDecTree** r){
	if(*r == NULL) {
		return;
	}
	deleteTree(&(*r)->left);
	deleteTree(&(*r)->right);
	delete (*r);
}

void DecTree::split(MyDecTree* r, int value, MyDecTree** T1, MyDecTree** T2) {
	if(r == NULL) {
		*T1 = NULL;
		*T2 = NULL;
		return;
	}
	if(r->value < value) {
		split(r->right, value, &(r->right), T2);
		*T1 = r;
	} else {
		split(r->left, value, T1, &(r->left));
		*T2 = r;
	}
}

void DecTree::addList(MyDecTree** r, int value, int prior) {
	if(*r == NULL) {
		(*r) = new MyDecTree;
		(*r)->value = value;
		(*r)->prior = prior;
		(*r)->height = 0;
		(*r)->left = NULL;
		(*r)->right = NULL;
		return;
	}
	if((*r)->prior >= prior) {
		if((*r)->value <= value) {
			addList(&((*r)->right), value, prior);
		} else {
			addList(&((*r)->left), value, prior);
		}
	} else {
		MyDecTree *T1, *T2;
		split(*r, value, &T1, &T2);
		MyDecTree *temp_1, 
				  *temp_2;
		temp_1 = temp_2 = NULL;
		if(T1 != NULL) {
			temp_1 = new MyDecTree;
			temp_1->value = T1->value;
			temp_1->prior = T1->prior;
			temp_1->height = T1->height;
			temp_1->left = T1->left;
			temp_1->right = T1->right;
		}
		if(T2 != NULL) {
			temp_2 = new MyDecTree;
			temp_2->value = T2->value;
			temp_2->prior = T2->prior;
			temp_2->height = T2->height;
			temp_2->left = T2->left;
			temp_2->right = T2->right;
		}
		(*r)->value = value;
		(*r)->prior = prior;
		(*r)->left = temp_1;
		(*r)->right = temp_2;
		(*r)->height = countHeight(r);
	}
	int h = 0;
	if((*r)->left != NULL) {
		h = (*r)->left->height;
	}
	if((*r)->right != NULL && (*r)->right->height > h) {
		h = (*r)->right->height;
	}
	(*r)->height = ++h;
}

int DecTree::countHeight(MyDecTree** r) {
	if((*r) == NULL) {
		return -1;
	}
	int h_left = countHeight(&(*r)->left) + 1;
	int h_right = countHeight(&(*r)->right) + 1;
	(*r)->height = (h_left > h_right)? h_left: h_right;
	return (*r)->height; 
}

///////////////////	Описание декартового дерева #############

int main() {
	int n;
	BinTree bin_tree;
	DecTree dec_tree;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int value, prior;
		scanf("%d %d", &value, &prior);
		bin_tree.add(value);
		dec_tree.add(value, prior);
	}
	int delta_height = bin_tree.getHeight() - dec_tree.getHeight();
	delta_height = (delta_height<0)?-delta_height:delta_height;
	printf("%d", delta_height);
	return 0;
}
