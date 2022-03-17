// https://leetcode.com/problems/partition-array-according-to-given-pivot/
#include "xxx.hpp"

class Solution {
public:
  vector<int> pivotArray(vector<int> &nums, int pivot) {
    vector<int> lt;
    vector<int> eq;
    vector<int> gt;
    for (auto num : nums) {
      if (num < pivot) {
        lt.push_back(num);
      } else if (num > pivot) {
        gt.push_back(num);
      } else {
        eq.push_back(num);
      }
    }
    lt.insert(lt.end(), eq.begin(), eq.end());
    lt.insert(lt.end(), gt.begin(), gt.end());
    return lt;
  }
};
