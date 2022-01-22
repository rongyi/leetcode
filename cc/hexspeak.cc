// http://leetcode.com/problems/hexspeak/description/
#include "xxx.hpp"

class Solution {
public:
  string toHexspeak(string num) {
    stringstream ss;
    ss << hex << stoll(num);
    string hex = ss.str();
    unordered_set<char> valid{'A', 'B', 'C', 'D', 'E', 'F', 'I', 'O'};

    for (auto &c : hex) {
      c = toupper(c);
      if (c == '1') {
        c = 'I';
      }
      if (c == '0') {
        c = 'O';
      }
      if (valid.find(c) == valid.end()) {
        return "ERROR";
      }
    }
    return hex;
  }
};
