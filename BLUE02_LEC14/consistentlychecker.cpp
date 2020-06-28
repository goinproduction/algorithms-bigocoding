#include <iostream>
#include <vector>
using namespace std;
const int MAX = 10;

struct Node {
   Node* child[MAX];
   bool end_word;
};

Node *newNode() {
   Node *new_node = new Node;
   new_node->end_word = false;
   for (int i = 0; i < MAX; i++) {
      new_node->child[i] = nullptr;
   }
   return new_node;
}

bool addWord(Node* root, const string& s) {
   Node* temp = root;
   bool s_prefix_other = false;
   bool other_prefix_s = true;

   for (int i = 0; i < s.size(); i++) {
      int ch = s[i] - '0';

      if (temp->child[ch] == nullptr) {
         temp->child[ch] = newNode();
         other_prefix_s = false;
      }

      temp = temp->child[ch];
      if (temp->end_word) {
         s_prefix_other = true;
      }
   }

   temp->end_word = true;
   return (s_prefix_other || other_prefix_s);
}
      
int main() {
   int t, n, tc;
   string s;
   cin >> t;

   for (tc = 1; tc <= t; tc++) {
      cin >> n;
      Node* root = newNode();
      bool is_inconsistent = false;

      for (int i = 0; i < n; i++) {
         cin >> s;
         if (!is_inconsistent) {
            is_inconsistent = addWord(root, s);
         }
      }

      cout << "Case " << tc << ": " << (is_inconsistent ? "NO" : "YES") << endl;
   }
   return 0;
}