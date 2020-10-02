class Solution
{
public:
    string FrequentCharacter(string str)
    {
        int n = str.length();

        // If the string is empty return empty string
        if (n == 0)
            return "";

        // Store the Frequency of each character in HashMap

        unordered_map<char, int> freq;
        for (auto &x : str)
            freq[x]++;

        // Store the frequency and character value in vector and sort it
        vector<pair<int, char>> res;

        for (auto &[key, val] : freq)
        {
            res.push_back({val, key});
        }
        sort(res.begin(), res.end(), greater<int>());

        //Iterate through the Vector of pair and store the character value in the string ans
        string ans = "";
        for (auto &x : res)
        {
            while (x.first > 0)
            {
                ans += x.second;
                x.first--;
            }
        }
        return ans;
    }
};