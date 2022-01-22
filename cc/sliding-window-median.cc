// http://leetcode.com/problems/sliding-window-median/description/
#include "xxx.hpp"

class Solution {
public:
  vector<double> medianSlidingWindow(vector<int> &nums, int k) {
    vector<double> ret;

    // array layout
    // --------------max_heap-----------|----------------min_heap--------------
    // 高的里面去挑矮的，所以这里面要放大值
    Heap<less<int>> min_heap;
    // 矮的里面去挑高的，所以这里面要放小值
    Heap<greater<int>> max_heap;

    for (int i = 0; i < nums.size(); ++i) {
      min_heap.Add(nums[i]);
      // 通过 min_heap 弹出来的都是小值
      // max_heap 里尽放小矮个
      max_heap.Add(min_heap.Pop());

      // 走出window了，要移除一个数，那么这个数在哪呢？
      if (i >= k) {
        // min_heap.Top()是min里最小的，如果滑动窗口要移除的那个数字比
        // 这个最小的还大，那么这个删除的target就在 min_heap里无疑
        if (min_heap.size_ > 0 && nums[i - k] >= min_heap.Top()) {
          min_heap.Remove(nums[i - k]);
        } else {
          // 否则，删除目标在 max_heap 里
          max_heap.Remove(nums[i - k]);
        }
      }
      for (; max_heap.size_ > min_heap.size_; min_heap.Add(max_heap.Pop()))
        ;
      // 其实这保证了 max_heap 和  min_heap 要么相等，要么 max_heap 大 1
      for (; min_heap.size_ > max_heap.size_; max_heap.Add(min_heap.Pop()))
        ;

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

  void test() {
    Heap<less<int>> heap;
    heap.Add(1);
    heap.Add(2);
    cout << heap.Top() << endl;

    Heap<greater<int>> heap2;
    heap2.Add(1);
    heap2.Add(2);
    cout << heap2.Top() << endl;
  }

public:
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
int main() {
  Solution so;
  // so.test();
  vector<int> input{1, 3, -1, -3, 5, 3, 6, 7};
  auto ret = so.medianSlidingWindow(input, 3);
  for (auto d : ret) {
    cout << d << endl;
  }
}
