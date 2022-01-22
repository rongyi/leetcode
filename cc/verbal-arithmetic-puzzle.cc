// http://leetcode.com/problems/verbal-arithmetic-puzzle/description/
#include "xxx.hpp"

class Solution {
public:
  bool isSolvable(vector<string> &words, string result) {
    // only one carry
    int maxlen = 0;
    for (auto &w : words) {
      maxlen = max(int(w.size()), maxlen);
    }
    if (result.size() > maxlen + 1) {
      return false;
    }

    // sum can not be shorter
    for (auto &w : words) {
      if (w.size() > result.size()) {
        return false;
      }
    }

    // initial
    i2c_.resize(10);
    fill(i2c_.begin(), i2c_.end(), '\0');
    c2i_.resize(26);
    fill(c2i_.begin(), c2i_.end(), -1);

    // reverse
    for (auto &w : words) {
      reverse(w.begin(), w.end());
    }
    reverse(result.begin(), result.end());

    return help(words, result, 0, 0, 0);
  }

private:
  // idx: index of word in words
  // pos: position in a word, e.g M[O]NEY -> pos == 2
  bool help(vector<string> &words, string &result, int idx, int pos, int sum) {
    if (pos == result.size()) {
      return sum == 0;
    }
    if (idx == words.size()) {
      // already mapped
      if (c2i_[result[pos] - 'A'] != -1) {
        // 这个位置上的映射和算出来的和到底一不一样, 当然考虑进位的情况
        if (c2i_[result[pos] - 'A'] == (sum % 10)) {
          return help(words, result, 0, pos + 1, sum / 10);
        }
      } else if (i2c_[sum % 10] == '\0') {
        // 当前位字符还没有被映射过，但是同时要保证sum对应的数字也没有被映射过
        // 建立映射
        c2i_[result[pos] - 'A'] = sum % 10;
        i2c_[sum % 10] = result[pos];

        if (help(words, result, 0, pos + 1, sum / 10)) {
          return true;
        }

        // dfs restore
        c2i_[result[pos] - 'A'] = -1;
        i2c_[sum % 10] = '\0';
      }

      return false;
    }

    // 跳过短的
    // e.g. MON + N
    if (pos >= words[idx].size()) {
      return help(words, result, idx + 1, pos, sum);
    }

    if (c2i_[words[idx][pos] - 'A'] != -1) {
      if (pos + 1 == words[idx].length() && words[idx].length() > 1 &&
          c2i_[words[idx][pos] - 'A'] == 0) {
        return false;
      }
      return help(words, result, idx + 1, pos,
                  sum + c2i_[words[idx][pos] - 'A']);
    }

    for (int i = 0; i < 10; i++) {
      if (i2c_[i] != '\0') {
        continue;
      }
      // no leading zero
      if (i == 0 && pos == words[idx].size() - 1 && words[idx].size() > 1) {
        continue;
      }
      i2c_[i] = words[idx][pos];
      c2i_[words[idx][pos] - 'A'] = i;
      if (help(words, result, idx + 1, pos, sum + i)) {
        return true;
      }
      i2c_[i] = '\0';
      c2i_[words[idx][pos] - 'A'] = -1;
    }

    return false;
  }

private:
  vector<char> i2c_;
  vector<int> c2i_;
};
