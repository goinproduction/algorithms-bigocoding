#include <iostream>
#include <string>
using namespace std;
#define MAX 26

struct Node {
    Node* child[MAX];
    bool countWord;
};

Node *newNode() {
    Node *node = new Node;
    node->countWord = 0;
    for (int i = 0; i < MAX; i++)
        node->child[i] = NULL;
    return node;
}

bool addWord(Node* root, string s) {
    Node* temp = root;
    for (int i = 0; i < s.length(); i++) {
        int ch = s[i] - 'a';
        if (temp->child[ch] == NULL) {
            temp->child[ch] = newNode();
        }
        temp = temp->child[ch];
        if (temp->countWord > 0) // có 1 từ là tiền tố của từ đang thêm vào trie
            return false; 
    }
    temp->countWord++;
    for (int i = 0; i < MAX; i++) {
        if (temp->child[i] != NULL) // từ vừa thêm vào trie là tiền tố của 1 từ khác
            return false;
    }
    return true;
}

int main() {
    int n;
    string s;
    cin >> n;
    Node* root = newNode();
    bool nonVulnerable = true;
    while (n--){
        cin >> s;
        if (!addWord(root, s)){
            cout << "BAD SET\n";
            cout << s << "\n";
            return 0;
        }
    }
    cout << "GOOD SET";
    return 0;
}