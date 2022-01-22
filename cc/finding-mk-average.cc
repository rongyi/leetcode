// http://leetcode.com/problems/finding-mk-average/description/
#include "xxx.hpp"

class MKAverage {
public:
  MKAverage(int m, int k) : m(m), k(k), pos(0), sum(0) {
    // 数据流一旦有m个数字进来，那么保证中间的集合的个数是这么多，
    // 插入的时候先left，left满放最大值到mid， mid满，放mid最大值到right
    // 删除也是这个调整顺序
    // 设想一下三个杯子，容量 k (m - 2*k) k
    // 接水从左到右，在add中体现
    mid_sz = m - 2 * k;
    window = vector<int>(m, 0);
  }

  void addElement(int num) {
    if (pos >= m) {
      int old = window[pos % m];
      remove(old);
    }
    window[pos % m] = num;
    pos++;

    add(num);
  }

  int calculateMKAverage() {
    if (pos < m) {
      return -1;
    }

    return sum / mid_sz;
  }

private:
  void add(int num) {
    left.insert(num);
    if (left.size() > k) {
      auto it = prev(end(left));

      // shift to mid
      sum += *it;
      mid.insert(*it);

      left.erase(it);
    }
    if (mid.size() > mid_sz) {
      auto it = prev(end(mid));

      sum -= *it;
      right.insert(*it);
      mid.erase(it);
    }
  }

  void remove(int num) {
    if (num <= *rbegin(left)) {
      left.erase(left.find(num));
    } else if (num <= *rbegin(mid)) {
      mid.erase(mid.find(num));
      sum -= num;
    } else {
      right.erase(right.find(num));
    }

    if (left.size() < k) {
      // shift mid to left
      auto it = begin(mid);
      left.insert(*it);
      sum -= *it;
      mid.erase(it);
    }
    if (mid.size() < mid_sz) {
      auto it = begin(right);
      mid.insert(*it);
      sum += *it;

      right.erase(it);
    }
  }

private:
  int m;
  int k;
  int mid_sz;
  int pos;
  long sum;

  // insert order from left --> mid --> right
  multiset<int> left;
  multiset<int> mid;
  multiset<int> right;
  vector<int> window;
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
