// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/
#include "xxx.hpp"

class Solution {
public:
  long long dividePlayers(vector<int> &skill) {
    int sz = skill.size();
    int group = sz / 2;
    long long sum = accumulate(skill.begin(), skill.end(), 0ll);
    long long group_sum = sum / group;
    long long ret = 0;

    sort(skill.begin(), skill.end());
    map<int, int> cnt;
    for (auto s : skill) {
      cnt[s]++;
    }
    for (auto &kv : cnt) {
      // not exist pair
      if (!cnt.count(group_sum - kv.first)) {
        return -1;
      }
      // not same count
      if (cnt[group_sum - kv.first] != kv.second) {
        return -1;
      }

      ret += kv.second * kv.first * (group_sum - kv.first);
    }

    // total count 2 way
    return ret / 2;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> input{3, 2, 5, 1, 3, 4};
  so.dividePlayers(input);
  return 0;
}
