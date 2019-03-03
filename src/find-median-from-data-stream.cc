// http://leetcode.com/problems/find-median-from-data-stream/description/
#include "xxx.h"

class MedianFinder {
public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    // max_heap 放小值，这样top出来的是一堆矮的里面挑高的
    if (max_heap.empty() || num <= max_heap.top()) {
      max_heap.push(num);
    } else {
      min_heap.push(num);
    }
    // max_heap 可以多一个，但不能太多
    if (max_heap.size() > min_heap.size() + 1) {
      min_heap.push(max_heap.top());
      max_heap.pop();
    } else if (min_heap.size() > max_heap.size()) {
      max_heap.push(min_heap.top());
      min_heap.pop();
    }
  }

  double findMedian() {
    if (min_heap.size() == max_heap.size()) {
      return (min_heap.top() + max_heap.top()) / 2.0;
    }

    return max_heap.top();
  }

private:
  // 放的都是比较大的数,高的里面挑矮的
  priority_queue<int, vector<int>, greater<int>> min_heap;
  // 放的都是比较小的数，这样综合起来，矮的里面挑高的，
  // 高的里面挑矮的，挑出来的就是中间的那些高度
  // 否则如果大顶堆放大的数，小顶堆
  priority_queue<int, vector<int>, less<int>> max_heap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
