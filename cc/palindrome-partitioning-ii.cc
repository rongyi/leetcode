// http://leetcode.com/problems/leetcode/palindrome-partitioning-ii/description/
#include "xxx.hpp"

class Solution {
public:
  /**
   * @param s a string
   * @return an integer
   按照分割回文串去实现，找出最小的分割次数超时。
   改为用动态规划去实现。设置一个数组2boolean维数组isPd[  ][  ]
   isPd[ i ][ j ] = true 表示字符串s[ i , j ]是回文串，isPd[ i ][ j ]  = false
   表示字符串s[ i ][ j ]不是回文串。也用动态规划去生成

   再用dp[i] 表示0..i之间的最小分割数
  */
  // 这个思路很好理解，用这个
  // https://www.programcreek.com/2014/04/leetcode-palindrome-partitioning-ii-java/
  int minCut(string s) {
    if (s.empty())
      return 0;

    const int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    // 用cuts[i]表示当前位置最少需要切几次使每个部分都是回文。
    vector<int> cut(n, 0);
    // j描述的是刀的位置，是缝隙，从左到右标注 0 ... n - 1
    // 下面是j标记的位置
    //        0   1   2   3
    //        |   |   |   |
    // 元素: 1   2   3   4   5
    //
    for (int j = 0; j < n; j++) {
      // 举例来说3的刀位置前面最坏情况需要切三刀，即在0 1
      // 2位置都切下去换来都是回文
      cut[j] = j; // set maximum # of cut
      for (int i = 0; i <= j; i++) {
        if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
          dp[i][j] = true;
          // if need to cut, add 1 to the previous cut[i-1]
          // 如果s(i,j)这部分是回文，就有cuts[j] = cuts[i-1] + 1。
          // |---------i- 1   i  i+1 -------- j
          //               | 从这里下一刀
          if (i > 0) {
            cut[j] = min(cut[j], cut[i - 1] + 1);
          } else {
            // if [0...j] is palindrome, no need to cut
            cut[j] = 0;
          }
        }
      }
    }

    return cut[n - 1];
  }
};
