// http://leetcode.com/problems/validate-ip-address/description/
#include "xxx.h"

class Solution {
public:
  static const string kValidIPv6Chars;
  // 用getline来分section
  string validIPAddress(string IP) {
    static const string option[3] = {"IPv4", "IPv6", "Neither"};
    stringstream ss(IP);
    string block;

    if (IP.substr(0, 4).find('.') != string::npos) {
      for (int i = 0; i < 4; ++i) {
        if (!getline(ss, block, '.') || !validIPv4(block)) {
          return option[2];
        }
      }
      return ss.eof() ? option[0] : option[2];
    } else if (IP.substr(0, 5).find(':') != string::npos) {
      for (int i = 0; i < 8; i++) {
        if (!getline(ss, block, ':') || !validIPv6(block)) {
          return option[2];
        }
      }
      return ss.eof() ? option[1] : option[2];
    }
    return option[2];
  }

private:
  bool validIPv4(string &block) {
    if (block.empty() || block.size() > 3) {
      return false;
    }
    int sum = 0;
    for (int i = 0; i < block.size(); i++) {
      auto c = block[i];
      if (!isdigit(c) || (i == 0 && c == '0' && block.size() > 1)) {
        return false;
      }
      sum *= 10;
      sum += c - '0';
    }

    return sum <= 255;
  }
  bool validIPv6(string &block) {
    if (block.empty() || block.size() > 4) {
      return false;
    }
    for (int i = 0; i < block.size(); i++) {
      auto c = block[i];
      if (kValidIPv6Chars.find(c) == string::npos) {
        return false;
      }
    }
    return true;
  }
};

const string Solution::kValidIPv6Chars = "0123456789abcdefABCDEF";

int main() {
  Solution so;
  auto ret = so.validIPAddress("0001:0db8:85a3:0000:0000:8a2e:0370:7334");
  cout << ret << endl;
}
