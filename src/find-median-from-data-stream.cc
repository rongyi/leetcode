// http://leetcode.com/problems/find-median-from-data-stream/description/
#include "simpleone.h"

class MedianFinder {
public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    if (max_heap.empty() || num <= max_heap.top()) {
      max_heap.push(num);
    } else {
      min_heap.push(num);
    }

    if (max_heap.size() > min_heap.size() + 1) {
      min_heap.push(max_heap.top());
      max_heap.pop();
    } else if (min_heap.size() > max_heap.size()) {
      max_heap.push(min_heap.top());
      min_heap.pop();
    }
  }

  double findMedian() {
    return max_heap.size() == min_heap.size()
               ? (max_heap.top() + min_heap.top()) / 2.0
               : max_heap.top();
  }

private:
  // 放的都是比较大的数,高的里面挑矮的
  priority_queue<int, vector<int>, greater<int>> min_heap;
  // 放的都是比较小的数，这样综合起来，矮的里面挑高的，
  // 高的里面挑矮的，挑出来的就是中间的那些高度
  priority_queue<int, vector<int>, less<int>> max_heap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
