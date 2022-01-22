// http://leetcode.com/problems/largest-number/description/
#include "xxx.hpp"

class Solution {
public:
  string largestNumber(vector<int> &nums) {
    vector<string> strs;
    for (auto i : nums) {
      strs.push_back(to_string(i));
    }
    sort(
        strs.begin(), strs.end(),
        [](const string &a, const string &b) -> bool { return a + b > b + a; });

    stringstream ss;
    for (auto s : strs) {
      ss << s;
    }
    auto ret = ss.str();
    return ret[0] == '0' ? "0" : ret;
  }
};
int main() {
  Solution so;
  vector<int> input{10, 2};
  auto ret = so.largestNumber(input);
  cout << ret << endl;
}
