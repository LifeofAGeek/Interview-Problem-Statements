#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_set<string> s;

public:
    Solution()
    {
        s.clear();
    }
    void findsubsequence(string st, string ans)
    {
        if (st.length() == 0)
        {
            s.insert(ans);
            return;
        }
        //pick
        findsubsequence(st.substr(1, st.size() - 1), ans + st[0]);

        //drop
        findsubsequence(st.substr(1, st.size() - 1), ans);
    }
    vector<string> subsequence(string str)
    {
        findsubsequence(str, "");
        vector<string> ans;
        for (auto &x : s)
            ans.push_back(x);
        return ans;
    }
};
int main()
{
    Solution obj;
    vector<string> a = obj.subsequence("ABC");
    for (auto &x : a)
        cout << x << " ";
}