// https://leetcode.com/problems/split-message-based-on-limit/
#include "xxx.hpp"

class Solution {
public:
  vector<string> splitMessage(string message, int limit) {
    int sz = message.size();
    vector<int> digs(sz + 1, 0);
    vector<int> prefix(sz + 1, 0);
    auto dig_num = [](int n) {
      int ret = 0;
      while (n) {
        ret += 1;
        n /= 10;
      }
      return ret;
    };
    for (int i = 1; i <= sz; ++i) {
      digs[i] = dig_num(i);
      prefix[i] = prefix[i - 1] + digs[i];
    }

    vector<string> ret;
    // parts from 1 ==> sz
    for (int p = 1; p <= sz; ++p) {
      int total_len = sz + 3 * p + digs[p] * p + prefix[p];
      if ((total_len + limit - 1) / limit == p) {
        string cur{};
        int index = 1;
        // "" + </> + digs[p] + digs[index]
        int suffix_len = 3 + digs[p];
        for (auto &c : message) {
          cur.push_back(c);
          if ((cur.size() + suffix_len + digs[index]) == limit) {
            string item =
                cur + "<" + to_string(index) + "/" + to_string(p) + ">";
            ret.push_back(item);

            index += 1;
            cur.clear();
          }
        }
        // last part
        if (cur.size()) {
          cur += "<" + to_string(index) + "/" + to_string(p) + ">";
          ret.push_back(cur);
          cur.clear();
        }
        return ret;
      }
    }

    return ret;
  }
};
