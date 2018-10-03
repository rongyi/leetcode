// http://leetcode.com/problems/permutation-sequence/description/
#include "one.h"

class Solution {
public:
  // http://bangbingsyb.blogspot.com/2014/11/leetcode-permutation-sequence.html
  // 最高位可以取{1, 2, 3, 4}，而每个数重复3! =
  // 6次。所以第k=9个permutation的s[0] 为{1, 2, 3, 4}中的第9/6+1 = 2个数字
  // s[0] = 2。

  // 而对于以2开头的6个数字而言，k = 9是其中的第k' = 9%(3!) =
  // 3个。而剩下的数字{1, 3, 4}的重复周期为 2! = 2次。所以s[1]为{1, 3,
  // 4}中的第k'/(2!)+1 = 2个，即s[1] = 3。

  // 对于以23开头的2个数字而言，k = 9是其中的第k'' = k'%(2!) =
  // 1个。剩下的数字{1, 4}的重复周期为 1! = 1次。所以s[2] = 1.

  // 对于以231开头的一个数字而言，k = 9
  // 是其中的第k''' = k''/(1!)+1 = 1个。s[3] =  4
  string getPermutation(int n, int k) {
    vector<int> digit_vec;
    int bucket_size = 1;
    for (int i = 1; i <= n; i++) {
      digit_vec.push_back(i);
      bucket_size *= i;
    }

    k--;
    string ret;
    while (!digit_vec.empty()) {
      k %= bucket_size;
      bucket_size /= digit_vec.size();
      ret.push_back(digit_vec[k / bucket_size] + '0');
      digit_vec.erase(digit_vec.begin() + (k / bucket_size));
      digit_vec.shrink_to_fit();
    }

    return ret;
  }
};
