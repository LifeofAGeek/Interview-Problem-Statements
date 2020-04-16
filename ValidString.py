class Solution {
public:
    bool checkValidString(string s) {
    int l = s.length() - 1;
    int openCount = 0, closedCount = 0;
    for (int i = 0; i <= l; i++)
    {
        if (s[i] == '*' || s[i] == '(') openCount++;
        else openCount--;
        if (s[l - i] == '*' || s[l - i] == ')') closedCount++;
        else closedCount--;
        if (openCount < 0 || closedCount < 0) return false;
    }
    return true;
    }
};
