// http://leetcode.com/problems/letter-tile-possibilities/description/
#include "xxx.hpp"
class Solution {
public:
  Solution() {
    for (int i = 0; i < 8; ++i) {
      fact_[i] = fact(i);
    }
  }
  int numTilePossibilities(string tiles) {
    sort(tiles.begin(), tiles.end());
    return dfs(tiles) - 1;
  }

private:
  int uniqPerm(string &s) {
    int cnt[26]{};
    for (auto ch : s) {
      ++cnt[ch - 'A'];
    }
    auto ret = fact_[s.size()];
    for (auto n : cnt) {
      ret /= fact_[n];
    }
    return ret;
  }

  int dfs(string &s, string seq = "", int pos = 0) {
    if (pos >= s.size()) {
      return cache_.insert(seq).second ? uniqPerm(seq) : 0;
    }

    return dfs(s, seq, pos + 1) + dfs(s, seq + s[pos], pos + 1);
  }
  int fact(int i) {
    if (i == 0) {
      return 1;
    }
    return i * fact(i - 1);
  }

private:
  int fact_[8];
  unordered_set<string> cache_;
};

int main() {
  for (int i = 0; i < 8; ++i) {
    cout << fact(i) << endl;
  }
}
