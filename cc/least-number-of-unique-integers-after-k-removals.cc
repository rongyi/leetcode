// http://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/
#include "xxx.h"

class Solution {
public:
  int findLeastNumOfUniqueIntsRaw(vector<int> &arr, int k) {
    unordered_map<int, int> count;
    for (auto num : arr) {
      count[num]++;
    }
    vector<int> uniq;
    for (auto &kv : count) {
      uniq.push_back(kv.first);
    }
    sort(uniq.begin(), uniq.end(),
         [&count](int &l, int &r) -> bool { return count[l] < count[r]; });
    int i = 0;
    while (k > 0) {
      if (k >= count[uniq[i]]) {
        k -= count[uniq[i]];
        i++;
      } else {
        break;
      }
    }

    return uniq.size() - i;
  }
  // or using heap
  int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
    unordered_map<int, int> count;
    for (auto &num : arr) {
      count[num]++;
    }
    vector<int> heap;
    for (auto &kv : count) {
      heap.push_back(kv.second);
    }
    make_heap(heap.begin(), heap.end(), greater<int>());
    while (k > 0) {
      k -= heap.front();
      pop_heap(heap.begin(), heap.end(), greater<int>());
      if (k >= 0) {
        heap.pop_back();
      }
    }

    return heap.size();
  }
};
