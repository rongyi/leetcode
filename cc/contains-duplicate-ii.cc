// http://leetcode.com/problems/contains-duplicate-ii/description/
#include "xxx.hpp"

class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    const int n = nums.size();
    unordered_map<int, vector<int>> cache;
    for (int i = 0; i < n; i++) {
      cache[nums[i]].push_back(i);
    }
    for (auto kv : cache) {
      auto cur = kv.second;
      if (cur.size() > 1) {
        for (int i = 0; i < cur.size(); i++) {
          for (int j = i + 1; j < cur.size(); j++) {
            if (cur[j] - cur[i] <= k) {
              return true;
            }
          }
        }
      }
    }
    return false;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 0, 1, 1};
  auto ret = so.containsNearbyDuplicate(input, 1);
  cout << ret << endl;
}
