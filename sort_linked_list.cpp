// Sort a Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* merge(ListNode *A, ListNode *B) {
    if (A == nullptr || B == nullptr) {
        return A == nullptr ? B : A;
    }
    ListNode *head = nullptr, *temp = nullptr;
    if (A->val <= B->val) {
        head = A;
        temp = A;
        A = A->next;
    } else {
        head = B;
        temp = B;
        B = B->next;
    }
    while (A != nullptr && B != nullptr) {
        if (A->val <= B->val) {
            temp->next = A;
            temp = A;
            A = A->next;
        } else {
            temp->next = B;
            temp = B;
            B = B->next;
        }
    }
    if (A != nullptr) {
        temp->next = A;
    } else if (B != nullptr) {
        temp->next = B;
    }
    return head;
}

ListNode* Solution::sortList(ListNode *A) {
    if (A == nullptr || A->next == nullptr) {
        return A;
    }
    ListNode *l1 = A, *slow = A, *fast = A->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *l2 = slow->next;
    slow->next = nullptr;
    return merge(sortList(l1), sortList(l2));
}
