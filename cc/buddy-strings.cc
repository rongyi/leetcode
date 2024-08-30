// https://leetcode.com/problems/buddy-strings/description/
#include "xxx.hpp"

class Solution {
public:
  bool buddyStrings(string s, string goal) {
    if (s.size() != goal.size()) {
      return false;
    }

    if (s == goal) {
      unordered_set<int> seen;
      for (auto c : s) {
        if (!seen.insert(c).second) {
          return true;
        }
      }
      return false;
    }
    vector<pair<char, char>> diff;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] != goal[i]) {
        diff.push_back({s[i], goal[i]});
      }
    }

    return diff.size() == 2 && diff[0].first == diff[1].second &&
           diff[0].second == diff[1].first;
  }
};

int main() {
  Solution so;
  auto ret = so.buddyStrings("ab", "ba");
  cout << ret << endl;
}
