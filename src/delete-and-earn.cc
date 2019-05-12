// http://leetcode.com/problems/delete-and-earn/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/delete-and-earn/discuss/109891/Sharing-my-Simple-Straight-Forward-Java-O(n)-Solution-Explanation-Included
  // The idea is a simple trick. First, you notice that at every single element in our original nums array, you have 2 choices: To earn or not to earn. Based on problem, whichever element you earn, you must delete any values of nums[i]-1 and nums[i]+1. It helps to assume a sorted array so that you can place elements in ascending order to visualize the problem. You notice there that if you earn an element, you cannot earn its immediate unequal neighbors on both sides.
  // You also notice that if you have duplicate values in nums array, if you earn one of them, you end up earning all of them. This is because you have deleted its neighbors and therefore make its remaining duplicates "undeletable". This is important because you notice the problem simplifies to which values can earn you the largest total.
  // So I aggregated the sums into a sums array to map each value (array's index) with the total sum you can earn by deleting all elements of that value (array's value). Then write a for loop to compute the maximum sum ending at i At each step, your sum can either depend on your previous sum or the prior plus the current. You use a greedy algorithm to always pick the maximum value for each i.
  int deleteAndEarn(vector<int> &nums) {
    vector<int> dp(10002, 0);
    for (int i = 0; i < nums.size(); i++) {
      dp[nums[i]] += nums[i];
    }
    for (int i = 2; i < dp.size(); i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + dp[i]);
    }
    return dp[10001];
  }
};
