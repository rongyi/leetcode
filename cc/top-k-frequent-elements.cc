// http://leetcode.com/problems/top-k-frequent-elements/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    // value --> count
    unordered_map<int, int> count;
    // we must count all numbers to get the frequency
    for (auto i : nums) {
      count[i]++;
    }
    // count --> [value,]
    unordered_map<int, vector<int>> occ;
    for (auto kv : count) {
      occ[kv.second].push_back(kv.first);
    }
    priority_queue<int, vector<int>, less<int>> q;
    for (auto kv : occ) {
      q.push(kv.first);
    }
    vector<int> ret;
    int total = k;
    while (!q.empty() && k) {
      auto cur_count = q.top();
      for (auto value : occ[cur_count]) {
        if (ret.size() < total) {
          ret.push_back(value);
        } else {
          // reach total number, break and do nothing
          goto outer;
        }
      }

      q.pop();
      k--;
    }
  outer:
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{4, 1, -1, 2, -1, 2, 3};
  auto e = so.topKFrequent(input, 2);
  for (auto i : e) {
    cout << i << endl;
  }
}
