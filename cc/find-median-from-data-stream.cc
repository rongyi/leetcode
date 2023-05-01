// http://leetcode.com/problems/find-median-from-data-stream/description/
#include "xxx.hpp"

class MedianFinder {
public:
  MedianFinder() {}

  void addNum(int num) {
    if (max_queue_.empty() || num <= max_queue_.top()) {
      max_queue_.push(num);
    } else {
      min_queue_.push(num);
    }

    if (max_queue_.size() > min_queue_.size() + 1) {
      min_queue_.push(max_queue_.top());
      max_queue_.pop();
    } else if (min_queue_.size() > max_queue_.size()) {
      max_queue_.push(min_queue_.top());
      min_queue_.pop();
    }
  }

  double findMedian() {
    if (max_queue_.size() == min_queue_.size()) {
      return (max_queue_.top() + min_queue_.top()) / 2.0;
    }

    return max_queue_.top();
  }

private:
  // put smaller value in this queue, we can take bigger one in long(N)
  priority_queue<int> max_queue_;
  // put bigger value in min queue, and we can take smaller one in log(n)
  // and we resize two queue to same size(at out best, so one queue may bigger with one size) 
  // and we can get middle value from this two queue
  priority_queue<int, vector<int>, greater<int>> min_queue_;
};

