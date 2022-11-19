// https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/
#include "xxx.hpp"

class Solution {
public:
  int countDistinctIntegers(vector<int> &nums) {
    set<int> uniq;
    // slow version
    // auto revnum = [](int n) -> int {
    // string s = to_string(n);
    // reverse(s.begin(), s.end());
    // int i = 0;
    // while (i < s.size() && s[i] == '0') {
    //++i;
    //}
    // if (i > 0) {
    // s = s.substr(i);
    //}

    // return stoi(s);
    //};
    //
    auto revnum = [](int n) {
      int sum = 0;
      while (n) {
        int d = n % 10;
        n /= 10;
        sum *= 10;
        sum += d;
      }

      return sum;
    };

    for (auto &num : nums) {
      uniq.insert(num);
      uniq.insert(revnum(num));
    }

    return uniq.size();
  }
};
