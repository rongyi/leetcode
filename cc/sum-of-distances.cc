// https://leetcode.com/problems/sum-of-distances/
#include "xxx.hpp"

class Solution {
public:
  vector<long long> distance(vector<int> &nums) {
    int sz = nums.size();
    map<int, vector<int>> group;
    // group by same number, collect their index
    for (int i = 0; i < sz; i++) {
      group[nums[i]].push_back(i);
    }
    vector<long long> ret(sz, 0);
    for (auto &kv : group) {
      auto &ref = kv.second;
      if (ref.size() >= 2) {
        vector<long long> dis = calculateDistance(ref);
        for (int i = 0; i < ref.size(); i++) {
          ret[ref[i]] = dis[i];
        }
      }
    }

    return ret;
  }

  vector<long long> calculateDistance(vector<int> &same_index) {
    int sz = same_index.size();
    vector<long long> ret(sz, 0);
    vector<long long> prefix(sz + 1, 0);
    vector<long long> suffix(sz + 1, 0);

    // [0, 2 ,3, 8, 13]
    //        ^
    //        (3 - 2) + (3 - 0) --> i * 3 - prefix[i - 1]
    //        (8 - 3) + (13 - 3) --> suffix[i + 1] - (n - i - 1) * i
    // so first, we calculate the prefix
    // and suffix
    for (long long i = 0; i < sz; i++) {
      prefix[i + 1] = prefix[i] + same_index[i];
    }
    for (long long i = sz - 1; i >= 0; i--) {
      suffix[i] = suffix[i + 1] + same_index[i];
    }
    for (long long i = 0; i < sz; i++) {
      ret[i] += i * same_index[i] - prefix[i /*- 1 + 1*/];
      ret[i] += suffix[i + 1] - (sz - i - 1) * same_index[i];
    }
    // for (long long i = sz - 1; i >= 0; i--) {
    // ret[i] += suffix[i + 1] - (sz - i - 1) * same_index[i];
    //}

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{6, 1, 3, 3, 4, 3, 4};
  so.distance(input);
}
