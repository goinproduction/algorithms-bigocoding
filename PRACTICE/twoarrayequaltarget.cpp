#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> a, res;
    int mNum, target;
    cin >> mNum >> target;

    for (int i = 0; i < mNum; ++i)
    {
        int data;
        cin >> data;
        a.push_back(data);
    }
    sort(a.begin(), a.end());
    int left = 0, right = mNum - 1;
    while (left < right)
    {
        if (left + right > target)
        {
            --right;
        }
        else if (left + right < target)
        {
            ++left;
        }
        else if (left + right == target)
        {
            res.push_back(left);
            res.push_back(right);
            break;
        }
    }
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }
    return 0;
}