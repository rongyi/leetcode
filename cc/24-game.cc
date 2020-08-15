// http://leetcode.com/problems/24-game/description/
#include "xxx.h"

class Solution {
public:
  bool judgePoint24(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    do {
      if (valid(nums)) {
        return true;
      }
    } while (next_permutation(nums.begin(), nums.end()));
    return false;
  }

private:
  bool valid(double a, double b) {
    if (fabs(a + b - 24.0) < 0.0001 || fabs(a - b - 24.0) < 0.0001 ||
        fabs(a * b - 24.0) < 0.0001 || (b && fabs(a / b - 24.0) < 0.0001)) {
      return true;
    }
    return false;
  }
  bool valid(double a, double b, double c) {
    // here c maybe zero
    if (valid(a + b, c) || valid(a - b, c) || valid(a * b, c) ||
        (b && valid(a / b, c))) {
      return true;
    }
    if (valid(a, b + c) || valid(a, b - c) || valid(a, b * c) ||
        (c && valid(a, b / c))) {
      return true;
    }
    return false;
  }
  bool valid(const vector<int> &nums) {
    double a = nums[0];
    double b = nums[1];
    double c = nums[2];
    double d = nums[3];
    return valid(a, b, c, d);
  }
  bool valid(double a, double b, double c, double d) {
    // / will not generate 0
    if (valid(a + b, c, d) || valid(a - b, c, d) || valid(a * b, c, d) ||
        valid(a / b, c, d)) {
      return true;
    }
    if (valid(a, b + c, d) || valid(a, b - c, d) || valid(a, b * c, d) ||
        valid(a, b / c, d)) {
      return true;
    }
    if (valid(a, b, c + d) || valid(a, b, c - d) || valid(a, b, c * d) ||
        valid(a, b, c / d)) {
      return true;
    }
    return false;
  }
};
int main() {
  Solution so;
  vector<int> input{1, 2, 1, 2};
  auto ret = so.judgePoint24(input);
  cout << ret << endl;
}
