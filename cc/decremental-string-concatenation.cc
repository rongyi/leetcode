// https://leetcode.com/problems/decremental-string-concatenation/
#include "xxx.hpp"

class Solution {
public:
  int minimizeConcatenatedLength(vector<string> &words) {
    return words[0].size() + dfs(words[0].front(), words[0].back(), 1, words);
  }

  int dfs(char head, char tail, int i, vector<string> &words) {
    if (i >= words.size()) {
      return 0;
    }
    if (dp_[head - 'a'][tail - 'a'][i] != 0) {
      return dp_[head - 'a'][tail - 'a'][i];
    }
    int option1 = words[i].size() + dfs(head, words[i].back(), i + 1, words);
    // concatenation with normal order
    if (tail == words[i].front()) {
      option1 -= 1;
    }
    // concatenation with rever order, i.e. words[i] in front of prev word
    int option2 = words[i].size() + dfs(words[i].front(), tail, i + 1, words);
    if (words[i].back() == head) {
      option2 -= 1;
    }

    return dp_[head - 'a'][tail - 'a'][i] = min(option1, option2);
  }

private:
  int dp_[26][26][1001] = {};
};
