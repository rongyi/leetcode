// http://leetcode.com/problems/largest-number/description/
#include "one.h"

class Solution {
public:
  string largestNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end(), [](const int &a, const int &b) -> bool {
      auto s1 = to_string(a);
      auto s2 = to_string(b);
      return s1 + s2 > s2 + s1;
    });
    stringstream ss;
    for (auto i : nums) {
      ss << i;
    }
    auto ret = ss.str();
    return ret[0] == '0' ? "0" : ret;
  }
};

int main() {
  Solution so;
  vector<int> input{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  // sort(input.begin(), input.end());
  auto ret = so.largestNumber(input);
  cout << ret << endl;
}
