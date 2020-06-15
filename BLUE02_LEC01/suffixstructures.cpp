#include <iostream>
#include <string>
using namespace std;

int main() {
    int sCount[26] = {0}, tCount[26] = {0};
    string s, t;
    bool need_tree = false, array = false, automaton = false;

    cin >> s >> t;

    for (int i = 0; i < s.size(); i++) {
        sCount[s[i] - 'a']++;
    }

    for (int i = 0; i < t.size(); i++) {
        tCount[t[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (tCount[i] > sCount[i]) {
            need_tree = true;
        }
        else if (tCount[i] < sCount[i]) {
            automaton = true;
        }
    }

    int index_found = 0, match = -1;

    for (int i = 0; i < t.size(); i++) {
        index_found = s.find_first_of(t[i], match + 1);
        
        if (index_found > match) {
            match = index_found;
        }
        else {
            array = true;
            break;
        }
    }

    if (need_tree) {
        cout << "need tree";
    }
    else if (automaton && array) {
        cout << "both";
    }
    else if (automaton) {
        cout << "automaton";
    }
    else {
        cout << "array";
    }

    return 0;
}