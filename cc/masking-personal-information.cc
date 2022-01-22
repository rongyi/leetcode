// http://leetcode.com/problems/masking-personal-information/description/
#include "xxx.hpp"
#include <regex>

class Solution {
public:
  string maskPII(string S) {
    if (S.find('@') != string::npos) {
      return maskEmail(S);
    }

    return maskPhone(S);
  }
private:
  string maskEmail(string &s) {
    for (auto &c : s) {
      if (isupper(c)) {
        c = tolower(c);
      }
    }
    string name = s.substr(0, s.find('@'));
    string left = s.substr(s.find('@'));
    ostringstream ss;
    ss << name[0] << "*****" << name.back();

    return ss.str() + left;
  }

  string maskPhone(string &s) {
    vector<string> country = {"", "+*-", "+**-", "+***-"};
    s = std::regex_replace(s, std::regex("[^0-9]"), "");
    return country[s.size() - 10] + "***-***-" + s.substr(s.size() - 4);
  }
};
