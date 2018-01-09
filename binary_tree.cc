#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
//struct for new tree node
struct Node {
	int data;
	Node* left;
	Node* right;
};
//make a new node
Node* newNode(int n) { // to make new node
	Node* temp = (struct Node*)malloc(sizeof(struct Node));	
	temp->data = n;
	temp->left = temp->right = nullptr;
	return temp;
}
//traverse tree with inorder method
void inorder(Node* root) {
	if (root) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void preorder(Node *root) {
	if (root) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(Node *root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}
//insert a node into a tree
Node* insert(Node* node,int n) {
	if (node == nullptr) {
		return newNode(n);
	}
	Node* tmp;
	if (n <= node->data) {
		node->left = insert(node->left,n);
	} else if (n > node->data) {
		node->right	= insert(node->right,n);
	}
	return node;
}
//search a value from a tree
Node* search(Node* node, int n) {
	if (node == nullptr || node->data == n) {
		return node;
	}
	if (n < node->data) {
		return search(node->left, n);
	} else if (n > node->data) {
		return search(node->right, n);
	}
}
//don't know what the fuck this is
Node* search_succ(Node* node, int n) {
	if (node->data == n || node->left == nullptr && node->right == nullptr) {
		return node;
	}

	if (n < node->data) {
		return search_succ(node->left,n);
	} else if (n > node->data) {
		return search_succ(node->right,n);
	}
}
//get the minimum value from a tree
Node* searchMin(Node* node) {
	if (node->left) {
		return searchMin(node->left);
	} else {
		return node;
	}
}
//get the maximum value from a tree
Node* searchMax(Node* node) {
	if (node->right) {
		return searchMax(node->right);
	} else {
		return node;
	}
}

//successor without parent pointer
struct Node * inOrderSuccessor(struct Node *root, struct Node *n) {
    if( n->right != NULL )
        return searchMin(n->right);
    struct Node *succ = NULL;
    while (root != NULL) {
        if (n->data < root->data) {
            succ = root;
            root = root->left;
        }
        else if (n->data > root->data)
            root = root->right;
        else
           break;
    } 
    return succ;
}
/*
//successor with parent
Node* successor(Node* node, int n) {
	Node* tmp = search_succ(node,n);
	Node* cur;
	if (tmp->right) {
		return cur = searchMin(tmp->right);
	}
	if (tmp->data > n) {
		return tmp;
	} else {
		cur = searchMax(node->right);
		if (cur->data == tmp->data) {
			return node;
		}
		Node* p = tmp->parent;
		while (p && tmp==p->right) {
			tmp = p;
			p = p->parent;
		}
		return p;	
	}
}*/

//find the height of a tree
int findHeight(Node* node) {
	if (node==nullptr) {
		return 0;
	} else {
		int leftHeight = findHeight(node->left);
		int rightHeight = findHeight(node->right);
		if (leftHeight>rightHeight) {
			return leftHeight+1;
		} else {
			return rightHeight+1;
		}
	}
}

//delete a node from a tree
Node* deleteNode(Node* root, int n) {
	if (!root) {
		return root;
	}
	if (n < root->data) {
		root->left = deleteNode(root->left,n);
	} else if (n > root->data) {
		root->right = deleteNode(root->right,n);
	} else {
		if (!root->left) {
			Node* temp = root->right;
			free(root);
			return temp;
		} else if (!root->right) {
			Node* temp = root->left;
			free(root);
			return temp;
		}
		Node* temp = searchMin(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}

int main() {
	Node* root = nullptr;
	root = insert(root, 20);
	root = insert(root, 8);
	root = insert(root, 22);
	root = insert(root, 4);
	root = insert(root, 12);
	root = insert(root, 10);
	root = insert(root, 14);
	Node* temp = root->left->right->left;
	printf("In Order Traversal : ");
	inorder(root);
	printf("\n");
	printf("Pre Order Traversal : ");
	preorder(root);
	printf("\n");
	printf("Post Order Traversal : ");
	postorder(root);
	printf("\n");
    Node* succ = inOrderSuccessor(root, temp);
    printf("The in Order Sccessor of %d is %d\n", temp->data, succ->data);
    printf("The height of the tree is : %d\n", findHeight(root));
    printf("The minimum value of the tree is : %d\n", searchMin(root)->data);
    printf("The maximum value of the tree is : %d\n", searchMax(root)->data);
    Node* search_result = search(root, 10);
    if (!search_result) printf("Not Found!\n");
    else printf("%d is found!\n", search_result->data);
    root = insert(root, 25);
    inorder(root);
    printf("\n");
    printf("Delete value 25 from the tree.\n");
    root = deleteNode(root, 25);
    inorder(root);
    printf("\n\n");
    
	return 0;
}