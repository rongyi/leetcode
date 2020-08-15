// http://leetcode.com/problems/valid-mountain-array/description/
#include "xxx.h"

class Solution {
public:
  bool validMountainArray(vector<int> &A) {
    if (A.size() < 3) {
      return false;
    }
    // 至少左边有一个坡
    if (A[0] >= A[1]) {
      return false;
    }

    int i = 1;
    bool has_right = false;
    while (i < A.size()) {
      // 不能有重复的
      if (A[i] == A[i - 1]) {
        return false;
      } else if (A[i] > A[i - 1]) {
        // 一直在左坡
        if (has_right) {
          return false;
        }
        i++;
      } else {
        // 好从今往后只能递减了
        has_right = true;
        i++;
      }
    }

    return has_right;
  }
};

int main() {
  Solution so;
  vector<int> input{2, 1};
  auto ret = so.validMountainArray(input);
  cout << ret << endl;
}
