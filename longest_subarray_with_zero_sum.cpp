// Longest Zero Sum Subarray

vector<int> Solution::lszero(vector<int> &A) {
    unordered_map<long, int> mp;
    long sum = 0;
    int l = -1, r = -10;
    mp[0] = -1;
    for (int i = 0; i < (int) A.size(); i++) {
        sum += A[i];
        auto it = mp.find(sum);
        if (it == mp.end()) {
            mp[sum] = i;
            continue;
        }
        if (r - l + 1 < i - it->second) {
            l = it->second + 1;
            r = i;
        }
    }
    if (l == -1) {
        return vector<int>();
    }
    return vector<int>(A.begin() + l, A.begin() + r + 1);
}
