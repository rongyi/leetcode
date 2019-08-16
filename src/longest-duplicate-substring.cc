// http://leetcode.com/problems/longest-duplicate-substring/description/
#include "xxx.h"

class Solution {
public:
  Solution() : prime_(19260817) {}

  string longestDupSubstring(string S) {
    string ret{};
    power_ = vector<int>(S.size(), 1);
    for (int i = 1; i < S.size(); ++i) {
      power_[i] = (power_[i - 1] * 26) % prime_;
    }

    int low = 0;
    int high = S.size();
    while (low <= high) {
      int mid = low + (high - low) / 2;
      auto cur = validate(mid, S);
      if (cur.size() == 0) {
        high = mid - 1;
      } else {
        if (cur.size() > ret.size()) {
          ret = cur;
        }
        low = mid + 1;
      }
    }

    return ret;
  }

private:
  string validate(int desire, string &s) {
    if (desire == 0) {
      return "";
    }
    unordered_map<int, vector<int>> hash;
    long long current = 0;

    for (int i = 0; i < desire; ++i) {
      current = ((current * 26) % prime_ + (s[i] - 'a')) % prime_;
    }
    hash[current] = vector<int>(1, 0);

    for (int i = desire; i < s.size(); ++i) {
      current =
          ((current - (long long)power_[desire - 1] * (s[i - desire] - 'a')) %
               prime_ +
           prime_) %
          prime_;
      current = (current * 26 + (s[i] - 'a')) % prime_;
      if (hash.find(current) == hash.end()) {
        hash[current] = vector<int>(1, i - desire + 1);
      } else {
        for (auto start : hash[current]) {
          if (s.substr(start, desire) == s.substr(i - desire + 1, desire)) {
            return s.substr(start, desire);
          }
        }
        hash[current].push_back(i - desire + 1);
      }
    }
    return "";
  }

private:
  int prime_;
  vector<int> power_;
};
