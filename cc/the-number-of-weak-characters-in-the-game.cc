// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
#include "xxx.hpp"

class Solution {
public:
  int numberOfWeakCharacters(vector<vector<int>> &properties) {
    sort(properties.begin(), properties.end(), [](auto &l, auto &r) -> bool {
      if (l[0] == r[0]) {
        // we need strictly increat, so we put larger one first
        // if the first value(attach) is same
        // e.g. if we sort thisway: [4, 3] [4, 4]
        // we will get a count 1
        // so we must put bigger one first: [4, 4] [4, 3] 
        // to make count zero
        return l[1] > r[1];
      }
      return l[0] < r[0];
    });
    int sz = properties.size();
    int cur_max = numeric_limits<int>::min();
    int count = 0;
    for (int i = sz - 1; i >= 0; --i) {
      if (properties[i][1] < cur_max) {
        ++count;
      }
      cur_max = max(cur_max, properties[i][1]);
    }
    return count;
  }
  // exist any, not all! this way is so lame!
  int numberOfWeakCharactersTTL(vector<vector<int>> &properties) {
    // find the min index, check their index match or not
    // pair<num, index>
    vector<pair<int, int>> attacks;
    vector<pair<int, int>> defenses;
    int sz = properties.size();
    for (int i = 0; i < properties.size(); ++i) {
      attacks.push_back({properties[i][0], i});
      defenses.push_back({properties[i][1], i});
    }
    // now sort!
    sort(attacks.begin(), attacks.end());
    sort(defenses.begin(), defenses.end());

    // cache the defenses index
    vector<int> defenses_index(sz, 0);
    for (int i = 0; i < sz; ++i) {
      defenses_index[defenses[i].second] = i;
    }
    int count = 0;
    for (int i = 0; i < sz; ++i) {
      set<int> attack_index_set;
      set<int> defens_index_set;
      int j = i;
      while (j < sz && attacks[j].first == attacks[i].first) {
        j++;
      }
      for (; j < sz; ++j) {
        attack_index_set.insert(attacks[j].second);
      }

      int k = defenses_index[attacks[i].second];
      j = k;
      while (j < sz && defenses[j].first == defenses[k].first) {
        ++j;
      }
      // now j stops at the first bigger one
      for (; j < sz; ++j) {
        defens_index_set.insert(defenses[j].second);
      }
      if (intersection(attack_index_set, defens_index_set)) {
        ++count;
      }
    }

    return count;
  }

private:
  bool intersection(set<int> &l, set<int> &r) {
    for (auto k : l) {
      if (r.count(k)) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{7, 7}, {1, 2},  {9, 7}, {7, 3}, {3, 10},
                            {9, 8}, {8, 10}, {4, 3}, {1, 5}, {1, 5}};
  auto ret = so.numberOfWeakCharacters(input);
  cout << ret << endl;
}
