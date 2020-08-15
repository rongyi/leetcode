// http://leetcode.com/problems/long-pressed-name/description/
#include "xxx.h"

class Solution {
public:
  bool isLongPressedName(string name, string typed) {

    // aabbccdd ==> abcd, [2, 2, 2, 2]
    // ret put in uniq and count
    auto order_and_count = [](string &input, string &uniq, vector<int> &count) {
      int prev = input[0];
      int prev_index = 0;
      uniq.push_back(prev);
      int i = 0;
      const int n = input.size();
      for (; i < n; i++) {
        if (input[i] != prev) {
          uniq.push_back(input[i]);
          count.push_back(i - prev_index);

          prev = input[i];
          prev_index = i;
        }
      }
      count.push_back(i - prev_index);
    };

    string uniq_name;
    vector<int> count_name;

    string uniq_typed;
    vector<int> count_typed;

    order_and_count(name, uniq_name, count_name);
    order_and_count(typed, uniq_typed, count_typed);

    // 首先顺序必须是一样的
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
  so.isLongPressedName("alex", "aaleeeexxxx");
}
