/*
 * Merge k Sorted Lists
 * Problem: https://leetcode.com/problems/merge-k-sorted-lists/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < (int) lists.size(); i++) {
            if (lists[i] != nullptr) {
                pq.emplace(-lists[i]->val, i);
                lists[i] = lists[i]->next;
            }
        }
        ListNode *head = nullptr, *cur = nullptr;
        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            if (lists[p.second] != nullptr) {
                pq.emplace(-lists[p.second]->val, p.second);
                lists[p.second] = lists[p.second]->next;
            }
            if (head == nullptr) {
                head = new ListNode(-p.first);
                cur = head;
            } else {
                cur->next = new ListNode(-p.first);
                cur = cur->next;
            }
        }
        return head;
    }
};
