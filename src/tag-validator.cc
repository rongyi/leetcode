// http://leetcode.com/problems/tag-validator/description/
#include "xxx.h"

class Solution {
public:
  bool isValid(string code) {
    int i = 0;
    return validTag(code, i) && i == code.size();
  }

private:
  bool validTag(string &s, int &i) {
    int j = i;
    string tag = parseTagName(s, j);
    if (tag.empty()) {
      return false;
    }
    if (!validContent(s, j)) {
      return false;
    }
    // j is at '<' of end_tag
    // j + 2 + tag ==> '>'
    int k = j + tag.size() + 2;
    if (k >= s.size() || s.substr(j, k + 1 - j) != "</" + tag + ">") {
      return false;
    }
    i = k + 1;
    return true;
  }
  string parseTagName(string &s, int &i) {
    if (s[i] != '<') {
      return "";
    }
    int j = s.find('>', i);
    if ((j == string::npos) || (j - i - 1 < 1) || (j - i - 1 > 9)) {
      return "";
    }
    string tag = s.substr(i + 1, j - i - 1);
    for (auto c : tag) {
      if (!isupper(c)) {
        return "";
      }
    }
    // pass '>'
    i = j + 1;

    return tag;
  }

  bool validContent(string &s, int &i) {
    int j = i;
    while (j < s.size()) {
      if (!validText(s, j) && !validCData(s, j) && !validTag(s, j)) {
        break;
      }
    }
    i = j;
    return true;
  }
  bool validText(string &s, int &i) {
    int j = i;
    while (i < s.size() && s[i] != '<') {
      i++;
    }
    return i != j;
  }
  bool validCData(string &s, int &i) {
    if (s.find("<![CDATA[", i) != i) {
      return false;
    }
    int j = s.find("]]>", i);
    if (j == string::npos) {
      return false;
    }
    i = j + 3;

    return true;
  }
};
