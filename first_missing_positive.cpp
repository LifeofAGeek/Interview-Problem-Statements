/*
 * First Missing Positive
 * Problem: https://leetcode.com/problems/first-missing-positive/
 */

class Solution {
public:
    int firstMissingPositive(vector<int> &A) {
        int n = (int) A.size();
        for (int i = 0; i < n; i++) {
            if (A[i] >= 1 && A[i] <= n) {
                if (A[i] != i + 1 && A[A[i] - 1] != A[i]) {
                    int in = A[i] - 1;
                    swap(A[i], A[in]);
                    i--;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (A[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
