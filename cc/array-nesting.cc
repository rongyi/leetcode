// http://leetcode.com/problems/array-nesting/description/
#include "xxx.h"

class Solution {
public:
  int arrayNesting(vector<int> &nums) {
    const int n = nums.size();
    max_loop_ = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
      // 如果这个元素已经被访问过了，那么这个就没必要访问
      // 为什么呢，因为这个点都作为前面某个节点访问的后续
      // 节点，所以前面获取的最大值肯定比当前作为始发节点
      // 获取的最大值要大。所以没必要再继续下去了，就是
      // 这个判断解决TLE
      if (visited[i]) {
        continue;
      }
      loop_ = 0;
      dfs(nums, i, visited);
    }
    return max_loop_;
  }

private:
  void dfs(vector<int> &nums, int start, vector<bool> &visited) {
    if (visited[start]) {
      max_loop_ = max(max_loop_, loop_);
      return;
    }
    visited[start] = true;
    loop_++;

    dfs(nums, nums[start], visited);
  }

private:
  int loop_;
  int max_loop_;
};

int main() {
  Solution so;
  vector<int> input{1, 0, 2};
  auto ret = so.arrayNesting(input);
  cout << ret << endl;
}
