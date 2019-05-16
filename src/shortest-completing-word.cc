// http://leetcode.com/problems/shortest-completing-word/description/
#include "xxx.h"

class Solution {
public:
  string shortestCompletingWord(string licensePlate, vector<string> &words) {
    vector<unordered_map<char, int>> dicts;
    for (auto &w : words) {
      unordered_map<char, int> cnt;
      for (auto c : w) {
        cnt[c]++;
      }
      dicts.push_back(cnt);
    }
    unordered_map<char, int> candi;
    for (auto c : licensePlate) {
      if (isalpha(c)) {
        candi[tolower(c)]++;
      }
    }
    // vector<int> index;
    int index = -1;
    int min_len = numeric_limits<int>::max();
    for (int i = 0; i < dicts.size(); i++) {
      if (cmp(dicts[i], candi)) {
        if (words[i].size() < min_len) {
          index = i;
          min_len = words[i].size();
        }
      }
    }
    // It is guaranteed an answer exists.
    // so index will not be -1;
    return words[index];
  }

private:
  // hay contain all the char in needle and which count >= needle count
  bool cmp(unordered_map<char, int> &hay, unordered_map<char, int> &needle) {
    for (auto kv : needle) {
      if (hay.find(kv.first) == hay.end() || hay[kv.first] < kv.second) {
        return false;
      }
    }
    return true;
  }
};
