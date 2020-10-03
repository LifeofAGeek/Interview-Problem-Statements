#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> historicalurl(vector<string> &user1, vector<string> &user2)
    {
        int n = user1.size(), m = user2.size();
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        int len = 0, pos = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (user1[i - 1] != user2[j - 1])
                {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (dp[i][j] > len)
                {
                    len = dp[i][j];
                    pos = i - len;
                }
            }
        }
        vector<string> ans;
        for (int i = pos; i < pos + len; i++)
            ans.push_back(user1[i]);

        return ans;
    }
};
int main()
{
    vector<string> user1 = {"/home", "/register", "/login", "/user", "/one", "/two"};
    vector<string> user2 = {"/home", "/red", "/login", "/user", "/one", "/pink"};
    Solution obj;
    vector<string> ans = obj.historicalurl(user1, user2);
    for (auto &x : ans)
        cout << x << " ";
}