#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void selectionSort(vector<int>& v) {
	int n = v.size(), min, index;
	for (int i = 0; i < n; i++) {
		min = INT_MAX; // ���� ū ���� ����
		for (int j = i; j < n; j++) {
			if (min > v[j]) {
				min = v[j]; // i��° ���� ���ĺ��� ��� �ּҰ��� ����ȴ�.
				index = j; // ���� ���� ������ index
			}
		}
		swap(v[index], v[i]);
	}
}


int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	selectionSort(v);
	
	for (int elem : v)
		cout << elem << ' ';

 }