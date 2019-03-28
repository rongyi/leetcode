// http://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
#include "xxx.h"

class Solution {
public:
  int findUnsortedSubarray(vector<int> &nums) {
    const int n = nums.size();
    // 右边必须是降序
    int end = n - 1;
    while (end > 0 && nums[end - 1] <= nums[end]) {
      end--;
    }
    // 本身就是排好的
    if (end == 0) {
      return 0;
    }
    // 左边必须是升序
    int start = 0;
    while (start < n - 1 && nums[start + 1] >= nums[start]) {
      start++;
    }
    // [start + 1, end - 1] inclusive is the smallest possible if
    // minof nums[start + 1, end - 1] >= nums[start] *and*
    // maxof nums[start + 1, end - 1] <= nums[end]
    priority_queue<int, vector<int>, less<int>> maxp;
    priority_queue<int, vector<int>, greater<int>> minp;
    for (int i = start; i <= end; i++) {
      maxp.push(nums[i]);
      minp.push(nums[i]);
    }
    while (end < n && maxp.top() > nums[end]) {
      maxp.push(nums[end]);
      end++;
    }
    while (start >= 0 && minp.top() < nums[start]) {
      minp.push(nums[start]);
      start--;
    }

    return end - start - 1;
  }
};

int main() {
  Solution so;
  // vector<int> input{2, 6, 4, 8, 10, 9, 15};
  // vector<int> input{2, 1};
  vector<int> input{1, 3, 2, 2, 2};
  auto ret = so.findUnsortedSubarray(input);
  cout << ret << endl;
}
