#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1e6 + 5;

struct Point {
    int x, y;
    bool operator<(const Point& another) {
        return (x < another.x || (x == another.x && y < another.y));
    }
};

bool fre_x[MAX], fre_y[MAX];

int main() {
    int x, y;
    vector<int> unique_x, unique_y;
    vector<Point> points;

    for (int i = 0; i < 8; i++) {
        cin >> x >> y;
        points.push_back({x, y});

        if (!fre_x[x]) {
            fre_x[x] = true;
            unique_x.push_back(x);
        }

        if (!fre_y[y]) {
            fre_y[y] = true;
            unique_y.push_back(y);
        }
    }

    if (unique_x.size() != 3 || unique_y.size() != 3) {
        cout << "ugly";
        return 0;
    }

    sort(unique_x.begin(), unique_x.end());
    sort(unique_y.begin(), unique_y.end());
    sort(points.begin(), points.end());
    int index = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j && i == 1) {
                continue;
            }
            if (unique_x[i] == points[index].x && unique_y[j] == points[index].y) {
                index++;
            }
            else {
                cout << "ugly";
                return 0;
            }
        }
    }

    cout << "respectable";
    return 0;
}