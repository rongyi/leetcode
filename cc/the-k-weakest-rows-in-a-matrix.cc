// http://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> kWeakestRows2(vector<vector<int>> &mat, int k) {
    vector<int> ret;
    unordered_map<int, vector<int>> cnt;
    for (int i = 0; i < mat.size(); i++) {
      cnt[count(mat[i].begin(), mat[i].end(), 1)].push_back(i);
    }
    vector<int> keys;
    for (auto kv : cnt) {
      keys.push_back(kv.first);
    }
    sort(keys.begin(), keys.end());
    for (auto curk : keys) {
      for (auto l : cnt[curk]) {
        if (ret.size() == k) {
          return ret;
        }
        ret.push_back(l);
      }
    }

    return ret;
  }
  vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
    set<pair<int, int>> s;
    for (auto i = 0; i < mat.size(); i++) {
      auto p = count(mat[i].begin(), mat[i].end(), 1);

      s.insert({p, i});
    }
    vector<int> ret;
    for (auto it = begin(s); k > 0; ++it, --k) {
      ret.push_back(it->second);
    }

    return ret;
  }
};
