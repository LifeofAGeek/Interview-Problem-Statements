inline int get_unique(const vector<int> &a) {
    return (int) unordered_set<int>(a.begin(), a.end()).size();
}
 
inline int solve(const vector<int> &a) {
    int n = (int) a.size();
    int l = 0, r = -1;
    int start = 0, end = n + 1;
    const int count = get_unique(a);
    unordered_map<int, int> mp;
    while (l < n && r < n) {
        while (r + 1 < n && (int) mp.size() < count) {
            mp[a[++r]]++;
        }
        if ((int) mp.size() == count && end - start > r - l) {
            /*
             *  Check map size (when 'r' becomes fixed (n - 1), then r - l will
             *  start to shrink, and then mp.size() will also not be 'count'.
             */
            start = l;
            end = r;
        }
        unordered_map<int, int>::iterator it = mp.find(a[l]);
        if (--(it->second) == 0) {
            mp.erase(it);
        }
        l++;
    }
    return end - start + 1;
}
