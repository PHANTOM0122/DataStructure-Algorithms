#include <iostream>
#define MAX 1001
using namespace std;

struct Node {
	int index;
	Node* next;
};

struct Queue {
	Node* front;
	Node* rear;
	int count; // ������ ����
};

Node** a;
int vertex, edge, visited[MAX];

void addFront(Node* root, int index) {
	Node* temp = new Node;
	temp->index = index;
	temp->next = root->next;
	root->next = temp;
}

void queuePush(Queue* queue, int index) {
	Node* temp = new Node;
	temp->index = index;
	temp->next = NULL;
	if (queue->count == 0) { // queue is empty!
		queue->front = temp; // ��������� front�� ����
	}
	else {
		queue->rear->next = temp; // rear�� ����
	}

	queue->rear = temp; // front�� ������ ��� ����
	queue->count++; // ���� ����
}

int queuePop(Queue* queue) {
	if(queue->count==0) // empty
	{
		cout << "EmptyQueue!";
	}

	Node* temp = queue->front;
	int index = temp->index;
	queue->front = temp->next; // front��ĭ �ڷ� �̵�!
	delete temp;
	queue->count--;
	return index;
}

void BFS(int start) {
	Queue q;
	q.front = q.rear = NULL;
	q.count = 0;
	queuePush(&q, start); // start index Queue ����
	visited[start] = 1; // �湮��ϳ���
	while (q.count != 0) {
		int x = queuePop(&q); // print current index 
		cout << x << " is visited!" << endl;
		
		Node* cur = a[x]->next; // next element
		while (cur != NULL) {
			int next = cur->index;
			if (!visited[next]) { // ������ ���Ҹ� ó�� �湮��
				queuePush(&q, next); // index�� queue�� ����
				visited[next] = 1;
			}
			cur = cur->next;
		}
	}
}
int main() {
	cin >> vertex >> edge;
	a = new Node * [MAX];
	for (int i = 1; i <= vertex; i++) {
		a[i] = new Node;
		a[i]->next = NULL;
	}

	for (int i = 0; i < edge; i++) {
		int x, y; // x is from y is to index!
		cin >> x >> y;
		addFront(a[x], y);
		addFront(a[y], x);

	}
	BFS(1);
}