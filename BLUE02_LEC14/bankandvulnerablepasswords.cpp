#include <iostream>
#include <string>
using namespace std;
#define MAX 26

struct Node {
    Node* child[MAX];
    bool isLeaf;
};

Node *newNode() {
    Node *node = new Node;
    node->isLeaf = false;
    for (int i = 0; i < MAX; i++)
        node->child[i] = NULL;
    return node;
}

bool addWord(Node* root, string s) {
    Node* temp = root;
    bool flag = false;
    for (int i = 0; i < s.length(); i++) {
        int ch = s[i] - 'a';
        if (temp->child[ch] == NULL) {
            flag = true;
            temp->child[ch] = newNode();
        }
        temp = temp->child[ch];
        if (temp->isLeaf)
            return false;
    }
    temp->isLeaf = true;
    return flag;
}

int main() {
    int n;
    string s;
    cin >> n;
    Node* root = newNode();
    bool nonVulnerable = true;
    while (n--) {
        cin >> s;
        nonVulnerable &= addWord(root, s);
    }
    if (nonVulnerable)
        cout << "non vulnerable";
    else
        cout << "vulnerable";
    return 0;
}