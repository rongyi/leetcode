// http://leetcode.com/problems/long-pressed-name/description/
#include "xxx.h"

class Solution {
public:
  bool isLongPressedName(string name, string typed) {
    string uniq_name;
    string uniq_typed;
    char prev = '0';
    int prev_index = -1;

    vector<int> count_name;
    vector<int> count_typed;
    for (int i = 0; i < name.size(); i++) {
      if (name[i] != prev) {
        uniq_name.push_back(name[i]);
        count_name.push_back(i - prev_index);

        prev = name[i];
        prev_index = i;
      }
    }

    prev = '0';
    prev_index = -1;
    for (int i = 0; i < typed.size(); i++) {
      if (typed[i] != prev) {
        uniq_typed.push_back(typed[i]);
        count_typed.push_back(i - prev_index);

        prev = typed[i];
        prev_index = i;
      }
    }

    // 首先书序必须是一样的
    if (uniq_name != uniq_typed) {
      return false;
    }

    // 其次出现的次数只能是打多了，不能少，少了就不是了
    for (int i = 0; i < count_name.size(); i++) {
      if (count_name[i] > count_typed[i]) {
        return false;
      }
    }

    return true;
  }
};

int main() {
  Solution so;
  so.isLongPressedName("alex", "aaleex");
}
