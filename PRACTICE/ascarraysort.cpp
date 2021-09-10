#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> a, b, c;
    int mNum, nNum;
    cin >> mNum >> nNum;

    for (int i = 0; i < mNum; ++i)
    {
        int data;
        cin >> data;
        a.push_back(data);
    }
    for (int i = 0; i < nNum; ++i)
    {
        int data;
        cin >> data;
        b.push_back(data);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int m = a.size();
    int n = b.size();
    // O(m+n)
    int i = 0, j = 0;

    while (i <= m - 1 || j <= n - 1)
    {
        if (a[i] <= b[j] && i <= m - 1)
        {
            c.push_back(a[i]);
            ++i;
        }
        else
        {
            c.push_back(b[j]);
            ++j;
        }
    }
    for (int i = 0; i < c.size(); ++i)
    {
        cout << c[i] << " ";
    }
    return 0;
}