// http://leetcode.com/problems/sliding-window-median/description/
#include "xxx.h"

class Solution {
public:
  vector<double> medianSlidingWindow(vector<int> &nums, int k) {
    vector<double> ret;

    // array layout
    // --------------max_heap-----------|----------------min_heap--------------
    Heap<less<int>> min_heap;
    Heap<greater<int>> max_heap;

    for (int i = 0; i < nums.size(); ++i) {
      min_heap.Add(nums[i]);
      max_heap.Add(min_heap.Pop());

      if (i >= k) {
        if (min_heap.size_ > 0 && nums[i - k] >= min_heap.Top()) {
          min_heap.Remove(nums[i - k]);
        } else {
          max_heap.Remove(nums[i - k]);
        }
      }
      for (; max_heap.size_ > min_heap.size_; min_heap.Add(max_heap.Pop()));
      for (; min_heap.size_ > max_heap.size_; max_heap.Add(min_heap.Pop()));

      if (i >= k - 1) {
        if (max_heap.size_ == min_heap.size_) {
          ret.push_back(max_heap.Top() / 2.0 + min_heap.Top() / 2.0);
        } else {
          ret.push_back(max_heap.Top());
        }
      }
    }
    return ret;
  }

private:
  template <class Cmp> struct Heap {
    int size_;
    map<int, int, Cmp> h;
    Heap() : size_(0) {}

    void Add(int x) {
      h[x]++;

      size_++;
    }
    bool Remove(int x) {
      auto it = h.find(x);
      if (it == h.end()) {
        return false;
      }

      if (--it->second == 0) {
        h.erase(it);
      }
      size_--;
      return true;
    }
    int Pop() {
      int ret = h.begin()->first;
      Remove(ret);

      return ret;
    }
    int Top() { return h.begin()->first; }
  };
};
