// http://leetcode.com/problems/find-unique-binary-string/description/
#include "xxx.hpp"

class Solution {
public:
  string findDifferentBinaryString(vector<string> &nums) {
    // find the one not in nums in binary form
    auto bit_width = nums[0].size();
    set<string> uniq;
    for (auto &n : nums) {
      uniq.insert(n);
    }
    for (int i = 0; i < (1 << bit_width); ++i) {
      auto cur = bitset<16>(i).to_string().substr(16 - bit_width);
      if (uniq.count(cur)) {
        continue;
      }
      return cur;
    }
    return "";
  }
};

int main() {
  Solution so;
  vector<string> input{"01", "10"};
  so.findDifferentBinaryString(input);
}
