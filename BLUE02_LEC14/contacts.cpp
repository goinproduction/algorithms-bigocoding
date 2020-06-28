#include <iostream>
#include <string>
#define K 26
using namespace std;
typedef struct Node* ref;
struct Node {
	ref child[K];
	int count;
	Node() {
		for (int i = 0; i < K; i++)
			child[i] = NULL;
		count = 0;
	}
}* root;
void addContact(string& s) {
	ref p = root;
	for (int i = 0; i < s.length(); i++) {
		int c = s[i] - 'a';
		if (!p->child[c])
			p->child[c] = new Node;
		p = p->child[c];
		p->count++;
	}
}
int countContacts(string& s) {
	ref p = root;
	for (int i = 0; i < s.length(); i++) {
		int c = s[i] - 'a';
		if (!p->child[c])
			return 0;
		p = p->child[c];
	}
	return p->count;
}
int main() {
	int n;
	cin >> n;
	root = new Node;
	while (n--) {
		string opt, arg;
		cin >> opt >> arg;
		if (opt[0] == 'a')
			addContact(arg);
		else
			cout << countContacts(arg) << endl;
	}
	delete root;
}