// https://leetcode.com/problems/remove-letter-to-equalize-frequency/
#include "xxx.hpp"

class Solution {
public:
  bool equalFrequency(string word) {
    map<char, int> cnt;
    for (auto &c : word) {
      cnt[c]++;
    }
    // sick of the edge cases
    for (auto &kv : cnt) {
      kv.second -= 1;
      if (valid(cnt)) {
        return true;
      }
      kv.second += 1;
    }
    return false;
  }

private:
  bool valid(map<char, int> &cnt) {
    int prev = -1;
    for (auto &kv : cnt) {
      if (kv.second == 0) {
        continue;
      }
      if (prev == -1) {
        prev = kv.second;
      } else {
        if (prev != kv.second) {
          return false;
        }
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  so.equalFrequency("abcc");
  return 0;
}
