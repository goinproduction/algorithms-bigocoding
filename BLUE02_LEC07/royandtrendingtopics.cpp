#include <iostream>
#include <queue>
using namespace std;

struct Topic {
    int id;
    long long old_score, new_score, change;

    Topic(int _id, long long _old_score, long long _new_score) {
        id = _id;
        old_score = _old_score;
        new_score = _new_score;
        change = new_score - old_score;
    }

    bool operator<(const Topic &other) const {
        return change < other.change || (change == other.change && id < other.id);
    }
};

int main() {
    int n;
    cin >> n;
    int id;
    long long old_score, new_score, post, like, comment, share;
    priority_queue<Topic> pq;

    while (n--) {
        cin >> id >> old_score >> post >> like >> comment >> share;
        new_score = post * 50 + like * 5 + comment * 10 + share * 20;
        pq.push(Topic(id, old_score, new_score));
    }

    for (int i = 0; i < 5; i++) {
        Topic t = pq.top();
        pq.pop();
        cout << t.id << " " << t.new_score << endl;
    }
    return 0;
}