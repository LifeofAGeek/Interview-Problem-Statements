/*
 * Find Median from Data Stream
 * Link: https://leetcode.com/problems/find-median-from-data-stream/
 */

class MedianFinder {

private:

    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;

public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        if (min_heap.empty()) {
            min_heap.push(num);
            return;
        }
        if (num > min_heap.top()) {
            min_heap.push(num);
        } else {
            max_heap.push(num);
        }
        int s1 = (int) min_heap.size();
        int s2 = (int) max_heap.size();
        if (s1 == s2) {
            return;
        }
        if (s1 < s2) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    double findMedian() {
        if (min_heap.empty()) {
            return 0.0;
        }
        int s1 = (int) min_heap.size();
        int s2 = (int) max_heap.size();
        if (s1 == s2) {
            return 0.5 * (0.0 + min_heap.top() + max_heap.top());
        } else if (s1 < s2) {
            return (double) max_heap.top();
        }
        return (double) min_heap.top();
    }

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
