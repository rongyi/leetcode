// http://leetcode.com/problems/adding-two-negabinary-numbers/description/
#include "xxx.h"

class Solution {
public:
  vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2) {
    const int m = arr1.size();
    const int n = arr2.size();
    int len = max(m, n);
    reverse(begin(arr1), end(arr1));
    reverse(begin(arr2), end(arr2));

    vector<int> ret;

    int carry = 0;
    for (int i = 0; i < len || carry != 0; ++i) {
      int cur_sum = (i < m ? arr1[i] : 0) + (i < n ? arr2[i] : 0) + carry;
      ret.push_back(abs(cur_sum) % 2);
      if (cur_sum > 1) {
        carry = -1;
      } else if (cur_sum < 0) {
        carry = 1;
      } else {
        carry = 0;
      }
    }


    // prefix是0的赶紧弹出来
    while (ret.size() > 0 && ret.back() == 0) {
      ret.pop_back();
    }
    if (ret.empty()) {
      return {0};
    }

    reverse(begin(ret), end(ret));
    return ret;
  }
  vector<int> addNegabinary2(vector<int> &arr1, vector<int> &arr2) {
    const int m = arr1.size();
    const int n = arr2.size();
    int len = max(m, n);
    reverse(begin(arr1), end(arr1));
    reverse(begin(arr2), end(arr2));

    vector<int> ret;
    int carry = 0;
    bool plus = true;
    for (int i = 0; i < len; ++i, plus = !plus) {
      int cur_sum = (i < m ? arr1[i] : 0) + (i < n ? arr2[i] : 0);
      // 没有进位
      if (carry == 0) {
        if (cur_sum == 2) {
          ret.push_back(0);
          // 生成新的进位
          carry = 1;
        } else {
          // 当前是0或是1直接追加到结果
          ret.push_back(cur_sum);
        }
      } else {
        // 有进位
        if (cur_sum == 0) {
          // 就是进位的那个值写在这里
          ret.push_back(1);
          // 更新进位信息
          carry = 1;
        } else if (cur_sum == 1) {
          // 该位拉下水
          if (!plus) {
            ret.push_back(0);
            carry = 0;
          } else {
            ret.push_back(0);
            carry = 1;
          }
        } else {
          ret.push_back(1);
          carry = 0;
        }
      }
    }

    if (carry) {
      ret.push_back(1);
      ret.push_back(1);
    }
    // prefix是0的赶紧弹出来
    while (ret.size() > 0 && ret.back() == 0) {
      ret.pop_back();
    }
    if (ret.empty()) {
      return {0};
    }

    reverse(begin(ret), end(ret));
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> arr1{1, 1, 1, 1, 1};
  vector<int> arr2{1, 0, 1};
  auto ret = so.addNegabinary(arr1, arr2);
  for (auto num : ret) {
    cout << num << "  ";
  }
  cout << endl;
}
