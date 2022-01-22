// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/
#include "xxx.hpp"

class Solution {
public:
  // just do as they say
  int getLucky(string s, int k) {
    string d = todigit(s);
    // keep sum as string
    // only transform to int at last round
    string sum;
    for (int i = 0; i < k; ++i) {
      sum = adddigit(d);
      d = sum;
    }

    return stoi(sum);
  }

private:
  string todigit(string &s) {
    ostringstream ss;
    for (auto &c : s) {
      ss << (c - 'a' + 1);
    }
    return ss.str();
  }

  string adddigit(string &s) {
    int sum = 0;
    for (auto &c : s) {
      sum += (c - '0');
    }

    return to_string(sum);
  }
};
