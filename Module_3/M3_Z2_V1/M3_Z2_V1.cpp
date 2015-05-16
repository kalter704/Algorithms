#include <cstdio>
#include <stack>


struct MyTree {
	int value;
	MyTree *left, *right;
};

struct temp_i {
    MyTree* list;
    int act;
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
    MyTree* new_list = new MyTree;
    new_list->value = value;
    new_list->left = new_list->right = NULL;
    if(*root == NULL) {
        *root = new_list;
        return;
    }
    for(MyTree* temp = *root; ; ) {
        if(temp->value <= value) {
            if(temp->right == NULL) {
                temp->right = new_list;
                return;
            }
            temp = temp->right;
        } else {
            if(temp->left == NULL) {
                temp->left = new_list;
                return;
            }
            temp = temp->left;
        }
    }
}

void printTree(MyTree* root) {
	if(root == NULL) {
		return;
	}
	printTree(root->left);
	printf("%d ", root->value);
	printTree(root->right);
}

void printTree2(MyTree* root) {
    std::stack<temp_i> temp_stack;
    temp_i temp = {root, 0};
    temp_stack.push(temp);
    while(temp_stack.empty() == false) {
        temp = temp_stack.top();
        if(temp.act == 0) {
            temp.act += 1;
            temp_stack.pop();
            temp_stack.push(temp);
            if(temp.list->left != NULL) {
                temp.list = temp.list->left;
                temp.act = 0;
                temp_stack.push(temp);
            }
        } else {
            temp_stack.pop();
            printf("%d ", temp.list->value);
            if(temp.list->right != NULL) {
                temp.list = temp.list->right;
                temp.act = 0;
                temp_stack.push(temp);
            }
        }
    }
}

void deleteTree(MyTree** root) {
	if(*root == NULL) {
		return;
	}
	deleteTree(&(*root)->left);
	deleteTree(&(*root)->right);
	delete (*root);
}

void deleteTree2(MyTree** root) {
    std::stack<MyTree*> temp_stack;
    temp_stack.push(*root);
    while(temp_stack.empty() == false) {
        MyTree* temp = temp_stack.top();
        if(temp->right == NULL && temp->left == NULL) {
            temp_stack.pop();
            delete temp;
            continue;
        }
        if(temp->right != NULL) {
            temp_stack.push(temp->right);
            temp->right = NULL;
        }
        if(temp->left != NULL) {
            temp_stack.push(temp->left);
            temp->left = NULL;
        }
    }
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
	
	//printTree(root);
	printTree2(root);
	
	//deleteTree(&root);
	deleteTree2(&root);    

	return 0;
}
