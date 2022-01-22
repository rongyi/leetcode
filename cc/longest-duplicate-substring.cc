// http://leetcode.com/problems/longest-duplicate-substring/description/
#include "xxx.hpp"

class Solution {
public:
  Solution() : prime_(19260817) {}

  // This is a tricky one on two sides:
  // 1. how to find the length of the lonest string
  // 2. how to compare the string of the same length
  // For the first point, we can use binary search for answer since if a string
  // of length n is invalid then for all k > n, there's definetly no solution
  // because length n strings would become a substring of the length k string.
  // Similarly if a string of length n is valid, we have no use of checking
  // strings with length less than n. Due to these properties we can use binary
  // search for final answer. For the second point, we are actually trying to
  // compare a sliding window of string, and Rabin Karp algorithm is perfect for
  // doing so. The algorithm basically computes the hash value of all the string
  // and start a character by character comparison only if the two strings have
  // the same hash value. In order to avoid collision we can use a large prime
  // number such as 1e9 + 7, 19260817, 99999989, etc.
  string longestDupSubstring(string S) {
    string ret{};
    power_ = vector<int>(S.size(), 1);
    // 看做是一个26进制的数，power_代表的每一位上的值
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
    // start位置
    hash[current] = {0};

    // abcd a代表的是最高位，所以它的值对应着 power_[desire - 1]
    for (int i = desire; i < s.size(); ++i) {
      // 减去最高位的值
      current = ((current - (long long)power_[desire - 1] * (s[i - desire] - 'a')) % prime_ + prime_) % prime_;
      current = (current * 26 + (s[i] - 'a')) % prime_;
      if (hash.find(current) == hash.end()) {
        hash[current] = {i - desire + 1};
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
