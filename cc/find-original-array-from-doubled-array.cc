// https://leetcode.com/problems/find-original-array-from-doubled-array/
#include "xxx.hpp"

class Solution {
public:
  vector<int> findOriginalArray(vector<int> &changed) {
    // changed[i] >= 0 so this is easy
    map<int, int> count;
    int sz = changed.size();
    // quick path
    // odd len never be an array doubled
    if (sz & 1) {
      return {};
    }

    for (auto num : changed) {
      ++count[num];
    }
    int i = 0;
    bool ok = true;
    vector<int> ret;
    for (auto &kv : count) {
      // even num of 0
      if (kv.first == 0) {
        if ((kv.second & 1) == 0) {
          for (int i = 0; i < kv.second / 2; ++i) {
            ret.push_back(kv.first);
          }
        }
      } else if (kv.second > 0 && count[kv.first * 2] >= kv.second) {
        for (int i = 0; i < kv.second; ++i) {
          ret.push_back(kv.first);
        }
        count[kv.first * 2] -= kv.second;
      }
    }
    if (ret.size() == sz / 2) {
      return ret;
    }
    return {};
  }
};

int main() {
  Solution so;
  vector<int> input{2, 1, 2, 4, 2, 4};
  auto ret = so.findOriginalArray(input);
  for (auto e : ret) {
    cout << e << " ";
  }
  cout << endl;
}
