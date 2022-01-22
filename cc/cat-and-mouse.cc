// http://leetcode.com/problems/cat-and-mouse/description/
#include "xxx.hpp"

class Solution {
public:
  // 设状态 f(t,x,y)f(t,x,y) 表示 tt 时刻，老鼠位于 xx 且猫位于 yy
  // 时的结果（0，1 或 2）。
  // 如果当前为老鼠行动，那么他可以走到
  // f(t+1,i,y),i∈graph[x]f(t+1,i,y),i∈graph[x]，如果他走到的这些点结果都是
  // 2，则老鼠必输无疑；若其中有一个是 1，则老鼠必获胜；否则结果就是平局。
  // 对于猫来说，以上分析相反。
  // 我们已经知道的状态有，f(t,0,y)=1f(t,0,y)=1，f(t,x,x)=2f(t,x,x)=2，分别代表老鼠获胜和猫获胜。
  // 若游戏进行了 2n2n
  // 个单位时间还没有结束，则可以宣布平局（待证明，以下为直觉想法）。因为每一次移动老鼠都有可能到达一个新的位置，所以它最多只需要
  // 2n2n 步就可能找到出口（因为猫对应也走了 nn 步）。若超过了 2n2n
  // 步，则老鼠必定走了回头路，此时不管猫在哪，走回头路都是向猫 “妥协”
  // 的选择；同理对猫来说，走回头路也是向老鼠 “妥协” 的结果；故最大的 tt 只需要
  // 2n2n 即可。
  // 我们从 solve(0,1,2)solve(0,1,2) 开始记忆化搜索即可。


  // 个人觉得最难的一道题目2019-07-03 星期三
  int catMouseGame(vector<vector<int>> &graph) {
    const int n = graph.size();

    f_ = vector<vector<vector<int>>>(
        2 * n, vector<vector<int>>(n, vector<int>(n, -1)));
    return solve(graph, 0, 1, 2);
  }

private:
  // at time t, mouse at x and cat at y
  // cat win: 2
  // mouse win: 1
  // tie(平局 ): 0
  int solve(vector<vector<int>> &graph, int t, int x, int y) {
    // 平局
    if (t == graph.size() * 2) {
      return 0;
    }
    // 相遇了，cat win
    if (x == y) {
      return f_[t][x][y] = 2;
    }
    // mourse进洞
    if (x == 0) {
      return f_[t][x][y] = 1;
    }

    // cache hit
    if (f_[t][x][y] != -1) {
      return f_[t][x][y];
    }

    // mouse move first, so initial time is 0
    int who = t % 2;
    if (who == 0) {
      // mouse move
      // cat stay still
      bool cat_can_win = true;
      for (int i = 0; i < graph[x].size(); i++) {
        int nxt = solve(graph, t + 1, graph[x][i], y);
        if (nxt == 1) {
          return f_[t][x][y] = 1;
        } else if (nxt != 2) {
          cat_can_win = false;
        }
      }

      if (cat_can_win) {
        return f_[t][x][y] = 2;
      } else {
        return f_[t][x][y] = 0;
      }
    } else { // cat goes next
      bool mouse_can_win = true;
      for (int i = 0; i < graph[y].size(); i++) {
        if (graph[y][i] != 0) {
          // mouse stay still, cat move to next
          int nxt = solve(graph, t + 1, x, graph[y][i]);
          if (nxt == 2) {
            return f_[t][x][y] = 2;
          } else if (nxt != 1) {
            mouse_can_win = false;
          }
        }
      }
      if (mouse_can_win) {
        return f_[t][x][y] = 1;
      } else {
        return f_[t][x][y] = 0;
      }
    }
  }

private:
  vector<vector<vector<int>>> f_;
};
