// http://leetcode.com/problems/rle-iterator/description/
#include "xxx.hpp"

class RLEIterator {
public:
  RLEIterator(vector<int> &A) {
    for (int i = 0; i < A.size(); i += 2) {
      q_.push({A[i], A[i + 1]});
    }
  }

  int next(int n) {
    while (!q_.empty()) {
      auto &cur = q_.front();
      if (cur.first >= n) {
        cur.first -= n;
        return cur.second;
      } else {
        n -= cur.first;
        q_.pop();
      }
    }
    return -1;
  }

private:
  // pair<3， 2> 3个数字2
  queue<pair<int, int>> q_;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
