// http://leetcode.com/problems/reformat-phone-number/description/
#include "xxx.h"

class Solution {
public:
  string reformatNumber(string number) {
    string alldigit;
    for (auto &c : number) {
      if (isdigit(c)) {
        alldigit.push_back(c);
      }
    }
    if (alldigit.size() <= 3) {
      return alldigit;
    }
    if (alldigit.size() == 4) {
      return alldigit.substr(0, 2) + '-' + alldigit.substr(2, 2);
    }
    ostringstream ss;
    int i = 0;
    for (; i < alldigit.size(); i += 3) {
      ss << alldigit.substr(i, 3) << '-';
    }
    auto ret = ss.str();
    ret.pop_back(); // last dash
    auto left = alldigit.substr(i - 3);
    // 就是不能等于1，题目也是够绕的
    if (left.size() == 1) {
      // 123-4 ==> 12-34
      ret.pop_back(); // the last single one
      ret.pop_back(); // the dash
      ret.push_back(left[0]);
      ret.insert(ret.end() - 2, '-');
    }

    return ret;
  }
};

int main() {
  Solution so;
  cout << so.reformatNumber("12345678") << endl;
}
