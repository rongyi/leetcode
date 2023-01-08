// https://leetcode.com/problems/count-anagrams/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/count-anagrams/solutions/2947111/c-solution-math-with-explanation-each-step-in-detail/?orderBy=most_votes
  int countAnagrams(string s) {
    // cache fact
    fact_[0] = 1;
    for (int i = 1; i <= 100001; ++i) {
      fact_[i] = modMul(fact_[i - 1], i);
    }

    istringstream ss(s);
    string curword;
    int ret = 1;
    while (ss >> curword) {
      ret = modMul(ret, ways(curword));
    }
    return ret;
  }

private:
  int modMul(int a, int b) {
    return ((long long)(a % mod_) * (b % mod_)) % mod_;
  }
  // modular inverse
  int modPow(int a, int b) {
    if (b == 0) {
      return 1;
    }
    int ret = modPow(a, b / 2);
    if (b & 1) {
      return modMul(a, modMul(ret, ret));
    }
    return modMul(ret, ret);
  }
  int modDiv(int a) { return modPow(a, mod_ - 2); }

  int ways(string &w) {
    vector<int> freq(26, 0);
    for (auto &c : w) {
      freq[c - 'a']++;
    }
    int ret = fact_[w.size()];
    // divide same freq
    int d = 1;
    for (int i = 0; i < 26; ++i) {
      d = modMul(d, fact_[freq[i]]);
    }
    return modMul(ret, modDiv(d));
  }

private:
  int mod_ = 1e9 + 7;
  long long fact_[100002];
};
