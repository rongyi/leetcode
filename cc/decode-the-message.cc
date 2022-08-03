// https://leetcode.com/problems/decode-the-message/
#include "xxx.hpp"

class Solution {
public:
  string decodeMessage(string key, string message) {
    vector<int> visited(26, 0);
    // the first char map to 'a'
    // second char map to 'b'
    // and so on
    // if the char is meet again, ignore this
    // because relation is already created
    // we want cipher key to text
    map<char, char> table;
    int cur = 0;
    for (auto c : key) {
      if (c == ' ') {
        continue;
      }
      if (!visited[c - 'a']) {
        table[c] = cur + 'a';
        cur++;
      }
      visited[c - 'a'] = 1;
    }
    ostringstream ss;
    // they are give us key, we need to map to text
    for (auto c : message) {
      if (c == ' ') {
        ss << ' ';
      } else {
        ss << table[c];
      }
    }

    return ss.str();
  }
};
