// http://leetcode.com/problems/defanging-an-ip-address/description/
#include "xxx.hpp"

class Solution {
public:
  string defangIPaddr(string address) {
    ostringstream ss;
    for (auto c : address) {
      if (c == '.') {
        ss << "[.]";
      } else {
        ss << c;
      }
    }
    return ss.str();
  }
};
