// https://leetcode.com/problems/append-k-integers-with-minimal-sum/
#include "xxx.hpp"



// suck problem
class Solution {
public:
  long long minimalKSum(vector<int> &nums, int k) {
    set<int> uniq(nums.begin(), nums.end());
    long long sum = (long long)k * (k + 1) / 2;
    for (auto num: uniq) {
      if (num <= k) {
        sum += (++k);
        sum -= num;
      }
    }

    return sum;
  }
};


// suck problem
class SolutionTLE {
public:
  long long minimalKSum(vector<int> &nums, int k) {
    set<int> uniq(nums.begin(), nums.end());
    int i = 1;
    long long sum = 0;
    while (k) {
      if (uniq.count(i)) {
        i++;
        continue;
      }
      sum += i++;
      k--;
    }
    return sum;
  }
};
