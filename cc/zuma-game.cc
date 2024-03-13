// http://leetcode.com/problems/zuma-game/description/
#include "xxx.hpp"
#include <climits>
#include <string>
#include <unordered_map>

class Solution {
public:
  int findMinStep(string board, string hand) {
    vector<int> freq(26, 0);
    for (auto c : hand) {
      freq[c - 'A'] += 1;
    }
    unordered_map<string, int> cache;
    return dfs(board, freq, cache);
  }

  int dfs(string board, vector<int> &freq, unordered_map<string, int> &cache) {
    string key = board + "#" + freq_to_string(freq);
    if (cache.count(key)) {
      return cache[key];
    }
    int ret = INT_MAX;
    if (board.length() == 0) {
      ret = 0;
    } else {
      for (int i = 0; i < board.length(); i++) {
        for (int j = 0; j < freq.size(); j++) {
          bool word_try = false;
          if (board[i] - 'A' == j) {
            word_try = true;
          } else if (i > 0 && board[i] == board[i - 1] && board[i] - 'A' != j) {
            word_try = true;
          }

          if (freq[j] > 0 && word_try) {
            board.insert(board.begin() + i, j + 'A');
            freq[j] -= 1;

            string new_board = eliminate_action(board);
            int after_step = dfs(new_board, freq, cache);
            if (after_step != -1) {
              ret = min(ret, after_step + 1);
            }

            freq[j] += 1;
            board.erase(board.begin() + i);
          }
        }
      }
    }
    if (ret == INT_MAX) {
      ret = -1;
    }
    cache[key] = ret;
    return ret;
  }

  string eliminate_action(string board) {
    int start = 0;
    int end = 0;
    int sz = board.length();
    while (start < sz) {
      while (end < sz && board[start] == board[end]) {
        end += 1;
      }

      if (end - start >= 3) {
        string new_board = board.substr(0, start) + board.substr(end);

        return eliminate_action(new_board);
      } else {
        start = end;
      }
    }
    return board;
  }

  string freq_to_string(vector<int> &freq) {
    string ret{};

    for (int i = 0; i < freq.size(); i++) {
      if (freq[i] > 0) {
        ret += to_string((char)i + 'A') + to_string(freq[i]);
      }
    }

    return ret;
  }
};

class SolutionWA {
public:
  // https://leetcode.com/problems/zuma-game/discuss/97010/%22short%22-java-solution-beats-98
  // can not pass 20240313
  int findMinStep(string board, string hand) {
    unordered_map<char, int> dict;
    for (auto h : hand) {
      dict[h]++;
    }
    // The number of balls in your hand won't exceed 5,
    max_count_ = 6;

    // why plus #? ==>
    // 是为了处理最后的case，比如最后两个AA，这时候需要特殊处理，而加上
    // #呢，处理前面case和处理这个case一个代码，这里可以学习一下
    int ret = recur(board + '#', dict);

    return ret == max_count_ ? -1 : ret;
  }

private:
  int recur(string s, unordered_map<char, int> &dict) {
    s = shrink(s);

    if (s == "#") {
      return 0;
    }

    int ret = max_count_;
    int need = 0;
    for (int i = 0, j = 0; j < s.size(); ++j) {
      if (s[i] == s[j]) {
        continue;
      }
      need = 3 - (j - i);
      if (dict[s[i]] >= need) {
        dict[s[i]] -= need;

        ret = min(ret, need + recur(s.substr(0, i) + s.substr(j), dict));

        dict[s[i]] += need;
      }

      i = j;
    }

    return ret;
  }

  string shrink(string s) {
    for (int i = 0, j = 0; j < s.size(); ++j) {
      if (s[i] == s[j]) {
        continue;
      }
      if (j - i >= 3) {
        return shrink(s.substr(0, i) + s.substr(j));
      } else {
        i = j;
      }
    }
    return s;
  }

private:
  int max_count_;
};
