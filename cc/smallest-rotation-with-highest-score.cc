// https://leetcode.com/problems/smallest-rotation-with-highest-score/description/
#include "xxx.hpp"
class Solution {
public:
  // https://leetcode.com/problems/smallest-rotation-with-highest-score/discuss/118725/Easy-and-Concise-5-lines-Solution-C++JavaPython?page=1
  // https://github.com/cherryljr/LeetCode/blob/master/Smallest%20Rotation%20with%20Highest%20Score.java
  // 1. 要求 A[i] <= i，对于数组的取值范围：
  // 总体策略，把初始状态即 K == 0情况下作为基准点，然后算出每次rotation
  // 之后的值变化情况，在算变化情况之前，我们需要把变化的点找到，
  // 所以要分析一下情况
  // 先看数组取值范围： A[i] will be in the range [0, A.length]
  // 1. 0的情况，0放在那里都满足条件 0 <= index，所以这种不变的情况不考虑
  // 2. N的情况，N放在那里都不满足条件 N <= index，因为index最大值也就 N - 1，
  //    不变的情况统一不考虑
  // 考虑[1, N-1]区间的这些值情况，
  // 减小的边沿触发：把某个位置的值移动到其相等的index下需要rotation
  // 的次数是： (i - A[i] + N) % N，再来一次这个值就会变小，所以触发沿在这个位置
  // 增加: 每次rotation，因为最后一个位置放谁都有效，所以肯定会加1
  // 而且，因为是左移，所以如果A[i] > i的话，因为index减一了，所以肯定还是大，
  // 原先失分的地方下一次还是会失分。
  int bestRotation(vector<int> &A) {
    const int n = A.size();
    vector<int> change(n, 0);
    for (int i = 0; i < n; ++i) {
      change[(i - A[i] + n + 1) % n] -= 1; // 累加算出来的是在i位置有多少个数字不得分
    }
    for (int i = 1; i < n; ++i) {
      change[i] += change[i - 1] + 1; // 由于是左移，坐标在不断减小，所以原先失分的地方，在K+1的时候还是失分
    }

    return max_element(change.begin(), change.end()) - change.begin();
  }
};

int main() {
  Solution so;
  vector<int> input{2, 3, 1, 4, 0};
  auto test = so.bestRotation(input);
  cout << test << endl;
}
