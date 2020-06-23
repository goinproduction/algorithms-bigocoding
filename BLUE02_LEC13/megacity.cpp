#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
using namespace std;
 
int main() {
    int numLocation, totalPeople, people;
    double x, y;
    cin >> numLocation >> totalPeople;
    map<double, int> location;
    for (int i = 0; i < numLocation; ++ i) {
        cin >> x >> y;
        cin >> people;
        /*
        Tính bán kính của đường tròn, do tâm thành phố là (0, 0) 
        nên để tính bán kính thì chỉ cần công thức bên dưới là đủ 
        thay cho công thức sqrt((x1-x0)*(x1-x0) + (y1-y0)*(y1-y0))
        */
        double r = x * x + y * y;
        if (location.find(r) != location.end()) 
            location[r] += people;
        else
            location[r] = people;
    }
    for (map<double, int>::iterator it = location.begin(); it != location.end(); ++it) {
        totalPeople += it->second;
        if (totalPeople >= 1000000) {
            cout << fixed << setprecision(6) << sqrt(it->first) << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}