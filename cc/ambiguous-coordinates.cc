// https://leetcode.com/problems/ambiguous-coordinates/description/
#include "xxx.hpp"

class Solution {
public:
  vector<string> ambiguousCoordinates(string S) {
    vector<string> ret;
    string s = S.substr(1, S.length() - 2);

    const int n = s.size();
    for (int i = 1; i < n; ++i) {
      auto first = s.substr(0, i);
      auto second = s.substr(i);
      // no 000 appear
      auto junkzero = [](const string &s) -> bool {
        return stoi(s) == 0 && s.size() > 1;
      };
      if (junkzero(first) || junkzero(second)) {
        continue;
      }
      auto all_first = allPossibles(first);
      auto all_second = allPossibles(second);

      for (auto fst : all_first) {
        for (auto snd : all_second) {
          ret.push_back("(" + fst + ", " + snd + ")");
        }
      }
    }

    return ret;
  }

private:
  // allPossibles return all possible integer and float
  vector<string> allPossibles(const string &s) {
    vector<string> ret;
    // take as integer is valid, not like 00
    if (s.size() == 1 || s[0] != '0') {
      ret.push_back(s);
    }
    const int n = s.size();

    for (int i = 1; i < n; ++i) {
      string int_part = s.substr(0, i);
      string float_part = s.substr(i);
      // like '00'
      if (int_part.size() > 1 && int_part[0] == '0') {
        continue;
      }
      // like '.00'
      if (stoi(float_part) == 0 || float_part.back() == '0') {
        continue;
      }
      ret.push_back(int_part + "." + float_part);
    }

    return ret;
  }
};

int main() {
  Solution so;

  so.ambiguousCoordinates("(100)");
}
