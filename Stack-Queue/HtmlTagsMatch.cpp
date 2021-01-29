#include <string>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<string> getHtmlTags() {
	vector<string> tags;

	while (cin) {
		string line;
		getline(cin, line);
		int pos = 0; // ������ ��ĵ ��ġ
		int ts = line.find("<", pos); // �±��� ����
		while(ts != string::npos) { // ���ڿ��� ������ �ݺ��Ѵ�
			int te = line.find(">", ts + 1); // �±� ���� ã�´�.
			tags.push_back(line.substr(ts, te - ts + 1)); // �±׸� ���Ϳ� �߰�
			pos = te + 1; // ���� ��ġ�� ����
			ts = line.find("<", pos); // �� �ٽ� ��ũ ã��
		}
	}
	return tags;
}

bool isHtmlMatched(const vector<string>& tags) {
	stack<string> S; // ���� �±׸� �����ϴ� ����
	typedef vector<string>::const_iterator Iter; 

	for (Iter p = tags.begin(); p != tags.end(); p++) {
		if (p->at(1) != '/') // ���� �±��϶�
			S.push(*p);
		else { // �ݴ� �±��϶�
			if (S.empty()) return false;
			string open = S.top().substr(1); // '<'�� ������ ���� �±�
			string close = p->substr(2); // '</'�� ������ �ݴ� �±�
			if (open.compare(close) != 0) return false; // ���� ����
			else S.pop();
		}
	}
	if (S.empty())
		return true;
	else
		return false;
}

int main() {
	if (isHtmlMatched(getHtmlTags()))
		cout << "The input file is a matched HTML document" << endl;
	else
		cout << "The input file is not a matched HTML document" << endl;
}