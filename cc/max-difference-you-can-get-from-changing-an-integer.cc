#include "xxx.hpp"

class Solution {
public:
  // 喷的很惨
  int maxDiff(int num) {
    string str = to_string(num);
    // find the first none 9 to 9
    bool has_change = false;
    char ch = '\0';
    for (int i = 0; i < str.size(); ++i) {
      if (!has_change && str[i] != '9') {
        has_change = true;
        ch = str[i];

        str[i] = '9';
        continue;
      }
      if (has_change && str[i] == ch) {
        str[i] = '9';
      }
    }
    auto big = stoi(str);

    // change to small
    str = to_string(num);
    has_change = false;
    ch = '\0';

    if (str[0] == '1') {
      for (int i = 1; i < str.size(); ++i) {
        // 最高位上是1,就不能把1给改了
        if (!has_change && str[i] != '0' && str[i] != '1') {
          has_change = true;
          ch = str[i];

          str[i] = '0';
          continue;
        }
        if (has_change && str[i] == ch) {
          str[i] = '0';
        }
      }
    } else {
      ch = str[0];
      str[0] = '1';
      for (int i = 1; i < str.size(); ++i) {
        if (str[i] == ch) {
          str[i] = '1';
        }
      }
    }
    auto small = stoi(str);

    return big - small;
  }
};
