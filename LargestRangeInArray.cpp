#include <bits/stdc++.h>
using namespace std;
vector<int> largestRange(vector<int> &v)
{
    sort(v.begin(), v.end());
    int pos = 0, len = 1, mx_pos = 0, mx = 0;
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i - 1] + 1 == v[i])
            len++;
        else
            pos = i, len = 1;

        if (mx < len)
            mx_pos = pos, mx = len;
    }

    vector<int> ans;
    ans.push_back(v[mx_pos]);
    ans.push_back(v[mx_pos + mx - 1]);
    return ans;
}
int main()
{
    vector<int> v = {9, 6, 1, 3, 8, 10, 12, 11, 14, 15, 16, 17, 18, 19, 20, 21};
    vector<int> range = largestRange(v);
    cout << "(" << range[0] << "," << range[1] << ")" << endl;
}