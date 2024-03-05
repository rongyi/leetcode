// http://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/91103/C%2B%2B-O(n)-solution-explanation-added
  // TODO: use trie
  int findMaximumXOR(vector<int> &nums) {
    const int n = nums.size();
    if (n == 0 || n == 1) {
      return 0;
    }
    if (n == 2) {
      return nums[0] ^ nums[1];
    }
    vector<int> set0;
    vector<int> set1;
    int i = 0;
    int ret = 0;

    for (i = 30; i >= 0; --i) {
      for (auto num : nums) {
        if ((num & (1 << i)) == 0) {
          set0.push_back(num);
        } else {
          set1.push_back(num);
        }
      }
      if (set0.size() != 0 && set1.size() != 0) {
        ret = pow(2, i);
        break;
      } else {
        set0.clear();
        set1.clear();
      }
    }
    if (i == -1) {
      return 0;
    }
    ret += getMaxXor(set0, set1, i - 1);

    return ret;
  }

private:
  int getMaxXor(vector<int> &set0, vector<int> &set1, int pos) {
    int ret = 0;

    vector<int> set0one;
    vector<int> set0zero;
    vector<int> set1one;
    vector<int> set1zero;

    if (set0.size() == 0 || set1.size() == 0 || pos < 0) {
      return 0;
    }

    for (auto num : set0) {
      if ((num & (1 << pos)) == 0) {
        set0zero.push_back(num);
      } else {
        set0one.push_back(num);
      }
    }

    for (auto num : set1) {
      if ((num & (1 << pos)) == 0) {
        set1zero.push_back(num);
      } else {
        set1one.push_back(num);
      }
    }

    // 前面两个情况是这个位置 xor为0
    if (set0one.size() == 0 && set1one.size() == 0) {
      ret = getMaxXor(set0, set1, pos - 1);
    } else if (set0zero.size() == 0 && set1zero.size() == 0) {
      ret = getMaxXor(set0, set1, pos - 1);
    } else {
      // 必须始终是set0和set1来进行交集，因为函数传参就已经注定了
      // set0, set1是因为前面有更高的位来分开他们的
      int max1 = getMaxXor(set0zero, set1one, pos - 1);
      int max2 = getMaxXor(set0one, set1zero, pos - 1);
      ret = pow(2, pos) + max(max1, max2);
    }
    return ret;
  }
};
