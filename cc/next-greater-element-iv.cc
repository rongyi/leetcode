// https://leetcode.com/problems/next-greater-element-iv/
#include "xxx.hpp"

class Solution {
public:
  vector<int> secondGreaterElement(vector<int> &nums) {
    int sz = nums.size();
    vector<int> ret(sz, -1);

    // mono increase
    vector<int> stk;
    stk.push_back(0);
    // value, index
    multiset<pair<int, int>> m;
    for (int i = 1; i < sz; ++i) {

      // so when some number is greaer than the number in this cache,
      // we know this is the second greater number
      while (!m.empty() && nums[i] > m.begin()->first) {
        ret[m.begin()->second] = nums[i];
        m.erase(m.begin());
      }

      // meet the first greater number for index of stk.back()
      // i.e. current number nums[i] is the first greater number for
      // nums[stk.back()] but we don't save this number, we push to cache to
      // indicate all number in m have there first greater number
      while (!stk.empty() && nums[i] > nums[stk.back()]) {
        m.insert({nums[stk.back()], stk.back()});
        stk.pop_back();
      }

      stk.push_back(i);
    }

    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> input{2, 4, 0, 9, 6};
  so.secondGreaterElement(input);
  return 0;
}
