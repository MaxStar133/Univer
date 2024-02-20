# include <iostream>
# include <fstream>
# include <string>
# include <time.h>


using namespace std;


struct Node {
	int data;
	Node* left, * right;
};



void add(int x, Node*& node) {
	if (node == NULL) {
		node = new Node;
		node->data = x;
		node->left = NULL;
		node->right = NULL;
	}
 else {
	 if (x < node->data) {
		 add(x, node->left);
	 }
	 else {
		 add(x, node->right);
		 }
	}
}
void createTree(Node*& root) {
	srand(time(NULL));
	int capacity = 20;
	for (int i = 0; i < capacity; ++i) {
		int value = rand() % 10;
		add(value, root);
	}
}


// ����� ������ ������ ��������
void prePrint(Node* node) {
	if (node != NULL) {
		cout << node->data << " ";
		prePrint(node->left);
		prePrint(node->right);
	}
}

// ����� ������ ������������ �������� 
void inPrint(Node* node) {
	if (node != NULL) {
		inPrint(node->left);
		cout << node->data << " ";
		inPrint(node->right);
	}
}
// ����� ������ �������� �������� 
void postPrint(Node* node) {
	if (node != NULL) {
		postPrint(node->left);
		postPrint(node->right);
		cout << node->data << " ";
	}
}

void Search(Node* node,int& max, int& count,  int arr[]) {
	if (node != NULL) {
		arr[node->data]++;
		if (arr[node->data] > count) {
			count = arr[node->data];
			max = node->data;
		}
		
		Search(node->left, max, count, arr);
		Search(node->right,max, count, arr);

		}
	}









int main() {
	const int n = 100;
	int arr[n];
	int max=-1, count=0;
	for (int i = 0; i <= n; i++)
		arr[i] = 0;
	Node* root = NULL;
	createTree(root);
	prePrint(root);
	cout << endl;
	inPrint(root);
	cout << endl;
	postPrint(root);
	cout << endl;
	Search(root, max, count, arr);
	cout << max;
	cout << endl;


	system("pause");
	return 0;
}