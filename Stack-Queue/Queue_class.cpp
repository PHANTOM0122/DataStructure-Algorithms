#include <iostream>

using namespace std;

template <typename T>
class Queue {
private:
	T* p_list; // ������ �������� ������ �迭
	int size; // ���� ����� �������� ����
	int MAX_SIZE; // �ִ�� ������ �� �ִ� ����Ʈ�� ũ��
public:
	Queue(int _MAX_SIZE = 1000) {
		MAX_SIZE = _MAX_SIZE;
		size = 0;
		p_list = new T[_MAX_SIZE];
	}
	~Queue(); 
	int find_index(T _item);
	void Enqueue(T _item);
	T Dequeue(); 
	void print() const; 
	int get_size(); 
	T get_item(int _index); 
};

int main()
{
	Queue<int> int_queue;
	Queue<float> float_queue;
	Queue<char> char_queue;
	int_queue.Enqueue(1);
	int_queue.Enqueue(2);
	int_queue.Enqueue(2);
	int_queue.Enqueue(5);
	float_queue.Enqueue(4.3);
	float_queue.Enqueue(2.5);
	float_queue.Enqueue(3.7);
	float_queue.Enqueue(3.7);
	char_queue.Enqueue('b');
	char_queue.Enqueue('b');
	char_queue.Enqueue('c');
	char_queue.Enqueue('a');
	cout << "<Before Dequeue>" << endl;
	int_queue.print();
	float_queue.print();
	char_queue.print();
	int_queue.Dequeue();
	float_queue.Dequeue();
	float_queue.Dequeue();
	char_queue.Dequeue();
	char_queue.Dequeue();
	char_queue.Dequeue();
	char_queue.Dequeue();
	cout << "<After Dequeue>" << endl;
	int_queue.print();
	float_queue.print();
	char_queue.print();
	return 0;
}


// �Ҹ��� : p_list �� ���� �Ҵ��� ����
template<typename T>
Queue<T>::~Queue()
{	
	delete[] p_list;
}
// p_list ���� _item �� ������ ���� �ִ��� �˻� �� �߽߰� index �� ��ȯ�Ѵ� ���� �߰����� ���ϸ� 1 �� ��ȯ�Ѵ�
template<typename T>
int Queue<T>::find_index(T _item)
{
	int index = -1;
	for (int i = 0; i < size; i++) {
		if (p_list[i] == _item)
			index = i;
	}
	return index;
}
/*
* �Է� item �� p_list �� ���� �����Ѵ� . ���� _item �� ������ ���� p_list �� ������ ��� p_list �� �Է� item �� �߰����� �ʴ´�.
* ��Ʈ : find_index �Լ��� ����ؼ� �ߺ��� ���� p_list �� �ִ��� ������ ���� ��쿡 �Է� item �� p_list �� �߰� ). size ��
MAX_SIZE ���� ũ�� item �� �߰����� �ʴ´� .("Error: out of ���
*/
template<typename T>
void Queue<T>::Enqueue(T _item)
{
	if (size > MAX_SIZE) {
		cout << "Error: out of memeory!" << endl;
	}
	
	if (find_index(_item) == -1) {
		p_list[size] = _item;
		size++;
	}
}

/* p_list �� �ִ� ù��° item �� �����Ѵ��� �� �������� return �Ѵ�
��Ʈ :size ���� ���̸� p_list �� �������� ������ �Ͱ� ������ ȿ�� ) size �� 0 �� ���� item ��
�������� �ʴ´� . ( "Error: No item exists in th e list" ���
*/
template<typename T>
T Queue<T>::Dequeue()
{	
	if (size == 0) {
		cout << "No item exist in the list" << endl;
	}

	T item = p_list[0];

	size -= 1;
	for (int i = 0; i < size; i++) {
		p_list[i] = p_list[i + 1];
	}
	
	return item;
}
// Queue ��ü�� item ���� ����Ѵ�
template<typename T>
void Queue<T>::print() const
{
	for (int i = 0; i < size; i++)
		cout << p_list[i] << " ";
	cout << endl;
}
//Queue ��ü�� ũ�⸦ ����Ѵ�
template<typename T>
int Queue<T>::get_size()
{
	return size;
}
// p_list �� �ش� index �� �ִ� item ���� �����Ѵ�
template<typename T>
T Queue<T>::get_item(int _index)
{
	return p_list[_index];
}
