/*
 * Find Median from Data Stream
 * Link: https://leetcode.com/problems/find-median-from-data-stream/
 */

class fenwick_tree {

private:

    long max_value;

    unordered_map<long, int> f;

    inline int sum(long pos) {
        int res = 0;
        while (pos >= 0) {
            res += f[pos];
            pos = (pos & (pos + 1)) - 1;
        }
        return res;
    }

public:

    inline fenwick_tree() : max_value(INT_MAX - 1) {}

    inline void add(long pos, int val) {
        pos += max_value >> 1;
        while (pos <= max_value) {
            f[pos] += val;
            pos |= pos + 1;
        }
    }

    inline long find_by_order(int ord) {
        long low = 0, high = max_value;
        while (low <= high) {
            long mid = (low + high) >> 1;
            if (sum(mid) > ord) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return high + 1;
    }

};

class MedianFinder {

private:

    int size;

    fenwick_tree f;

public:

    /** initialize your data structure here. */
    MedianFinder() : size(0) {}

    void addNum(int num) {
        f.add(num, 1);
        size++;
    }

    double findMedian() {
        if (size == 0) {
            return 0.0;
        }
        double first = (double) f.find_by_order(size >> 1);
        double second = size & 1 ? first : (double) f.find_by_order((size - 1) >> 1);
        return 0.5 * (first + second - INT_MAX + 1);
    }

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder *obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
