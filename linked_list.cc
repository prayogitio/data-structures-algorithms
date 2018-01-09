#include <cstdio>
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* createNode(int data) {
	Node* node = new Node();
	node->data=data;
	node->next=nullptr;
	return node;
}

void deleteNode(Node* node) {
	delete node;
}

Node* createList() {
	Node* head = createNode(-1);
	return head;
}

void deleteData(Node* head,int n) {
	Node* cur = head->next;
	Node* temp = head;
	while (cur && cur->data != n) {
		cur = cur->next;
		temp = temp->next;
	}
	if (cur) {
		if (cur->data == n) {
		temp->next = cur->next;
		deleteNode(cur);
		printf("Data %d udah kehapus bung!(case : delete a node from list)\n",n);
		} 
	} else {
		printf("%d gak ada di list bung!(case : delete a node that does not exist in the list)\n",n);
	}
}

void reverse(Node* head) {
	printf("case : reverse display\n");
	Node* parent = head->next;
	Node* me = parent->next;
	Node* child = me->next;
	parent->next = nullptr;
	while (child) {
		me->next = parent;
		parent = me;
		me = child;
		child = child->next;
	}
	me->next = parent;
	head->next = me;
}

void insertFront(Node *head,int n) {
	Node* baru = new Node();
	baru->data = n;
	baru->next = head->next;
	head->next = baru;
}

void insertEnd(Node* head,int n) {
	Node* baru = new Node();
	baru->data = n;
	baru->next = nullptr;
	if (head->next) {
		Node* cur = head->next;
		while (cur->next != nullptr) {
			cur = cur->next;
		}
		cur->next = baru;
	} else {
		insertFront(head,n);
	}

}

int compute(Node* node) {
	Node* list = node->next;
	int count = 0;
	while (list) {
		list = list->next;
		count++;
	}
	printf("%d (case : length of the current list)\n", count);
	return count;
}

void findbydata(Node* node,int n) {
	Node* cur = node->next;
	while (cur && cur->data != n) {
		cur = cur->next;
	}
	if (cur) {
		printf("Ketemu bung!(case : cari data %d)\n",n);
	} else {
		printf("Data %d gak ada di list bung! (case : cari 40 from the list)\n",n);
	}
}

void findbypos(Node* node,int pos) {
	int jumlah = compute(node);
	Node* cur = node->next;
	if (pos > jumlah) {
		printf("Posisi terlalu banyak bung!(case : findbypos %d larger than list length\n",pos);
	} else {
		int i=1;
		while (i < pos) {
			cur = cur->next;
			i++;
		}
		cout << "Ketemu Bung posisi " << pos << "! yaitu " << cur->data << ". case : findbypos berhasil" << endl;
	}
}

void deleteList(Node* head) {
	printf("Case : hapus list\n");
	Node* cur = head->next;
	while (cur) {
		Node* next = cur->next;
		deleteNode(cur);
		cur=next;
	}
	head->next = nullptr;
}



void display(Node* head) {
	printf("case : display\n");
	if (head->next == nullptr) {
		printf("Empty bung!(case : display empty list)\n");
	} else {
		Node* list = head->next;
		while (list) {
			cout << list->data << " ";
			list = list->next;
		}
		cout << endl;
	}
}

int main() {
	Node* node = createList();
	insertFront(node,10);
	insertFront(node,20);
	insertEnd(node,30);
	insertEnd(node,50);
	insertEnd(node,90);
	insertEnd(node,100);
	insertEnd(node,70);
	insertEnd(node,55);
	display(node);
	findbydata(node,10);
	findbydata(node,40);
	display(node);
	compute(node);
	deleteData(node,57);
	display(node);
	deleteData(node,55);
	display(node);
	findbypos(node,10);
	findbypos(node,6);
	deleteList(node);
	display(node);
	compute(node);
	insertEnd(node,10);
	insertEnd(node,20);
	insertEnd(node,30);
	insertEnd(node,40);
	insertEnd(node,50);
	display(node);
	reverse(node);
	display(node);
	return 0;
}