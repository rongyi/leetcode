// http://leetcode.com/problems/maximum-product-of-three-numbers/description/
#include "xxx.h"

class Solution {
public:
  int maximumProduct(vector<int> &nums) {
    int max1 = numeric_limits<int>::min();
    int max2 = max1;
    int max3 = max2;

    int min1 = numeric_limits<int>::max();
    int min2 = min1;

    for (auto i : nums) {
      if (i > max1) {
        max3 = max2;
        max2 = max1;
        max1 = i;
      } else if (i > max2) {
        max3 = max2;
        max2 = i;
      } else if (i > max3) {
        max3 = i;
      }

      if (i < min1) {
        min2 = min1;
        min1 = i;
      } else if (i < min2) {
        min2 = i;
      }
    }
    return max(max1 * max2 * max3, max1 * min1 * min2);
  }

  int maximumProductPQ(vector<int> &nums) {
    priority_queue<int, vector<int>, less<int>> pq;

    priority_queue<int, vector<int>, greater<int>> pq2;
    for (auto n : nums) {
      pq.push(n);
      pq2.push(n);
    }
    int ret = 1;
    int larget = pq.top();
    // the largest number
    for (int i = 0; i < 3; i++) {
      ret *= pq.top();
      pq.pop();
    }
    auto neg = 1;
    // 没有负数相乘的情况出现
    if (pq2.top() >= 0) {
      return ret;
    }
    neg *= pq2.top();
    pq2.pop();
    // 只有一个负数
    if (pq2.top() >= 0) {
      return ret;
    }
    neg *= pq2.top();
    pq2.pop();
    neg *= larget;

    return max(ret, neg);
  }
};

int main() {
  Solution so;
  vector<int> input{-4, -3, -2, -1, 60};
  cout << so.maximumProduct(input) << endl;
}
