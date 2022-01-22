// https://leetcode.com/problems/kth-distinct-string-in-an-array/
#include "xxx.hpp"

class Solution {
public:
  string kthDistinct(vector<string> &arr, int k) {
    map<string, int> cnt;
    for (auto &s: arr) {
      cnt[s]++;
    }
    int idx = 0;
    for (int i = 0; i < arr.size(); ++i) {
      if (cnt[arr[i]] == 1) {
        idx++;
        if (idx == k) {
          return arr[i];
        }
      }
    }
    return "";
  }
};
