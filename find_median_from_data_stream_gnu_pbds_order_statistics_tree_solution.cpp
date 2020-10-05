/*
 * Find Median from Data Stream
 * Link: https://leetcode.com/problems/find-median-from-data-stream/
 */

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

class MedianFinder {

private:

    tree<int, null_type, less_equal<int>, rb_tree_tag,
    tree_order_statistics_node_update> t;

public:

    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        t.insert(num);
    }

    double findMedian() {
        if (t.empty()) {
            return 0.0;
        }
        int size = (int) t.size();
        double first = *t.find_by_order(size >> 1);
        double second = size & 1 ? first : *t.find_by_order((size - 1) >> 1);
        return 0.5 * (first + second);
    }

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
