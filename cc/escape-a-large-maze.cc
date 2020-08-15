// http://leetcode.com/problems/escape-a-large-maze/description/
#include "xxx.h"

class Solution {
public:
  // Note that some solutions in the discussion used the shortcoming of the
  // input and passed all the test which seems quite unreasonable.
  // In general if src->target is impossible only 2 cases should be considered:
  // 1. src is trapped and target is not in the same trap
  // 2. target is trapped and src in not in the same trap

  // The idea is to use 2 depth limited search one start from the source
  // to destination, other start from destination to source. Note that if we
  // can moves to a spot which the Mahhatan distance is over 200 to the
  // starting point we could consider that we escape the blockade.
  // A very special case is that we can reach src to dest within the 200 moves
  // in this way we could just do one BFS and return true.
  // Since the points are given as coordinates a direct mapping is inconvinience
  // in C++, hence, we use unordered_set<long long> which 1000000 * x + y
  // refers to the value of (x, y).
  bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source,
                        vector<int> &target) {
    dirs_ = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (auto b : blocked) {
      blocks_.insert(od(b[0], b[1]));
    }

    int ret = bfs(source, target);
    if (ret == 2) {
      return true;
    }

    if (ret == 0) {
      return false;
    }
    // 为什么等于1不能直接返回？
    // 因为现在只是证明了src可以突出重围，可万一重围
    // 围的就不是src呢？围的是dst，这个时候仍然是不可行的，
    // 所以还需要反向再试一下

    blocks_.clear();
    for (auto b : blocked) {
      blocks_.insert(od(b[0], b[1]));
    }
    return bfs(target, source) > 0;
  }

private:
  // one demension
  long long od(int x, int y) { return (long long)x * 1000000 + y; }
  // 2 ==> src --> target within 200 steps
  // 1 ==> src can break the "block"
  // 0 ==> src is blocked
  int bfs(vector<int> &src, vector<int> &dst) {
    queue<pair<int, int>> q;
    q.push({src[0], src[1]});
    blocks_.insert(od(src[0], src[1]));

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      if (cur.first == dst[0] && cur.second == dst[1]) {
        return 2;
      }
      if (abs(cur.first - src[0]) + abs(cur.second - src[1]) > 200) {
        return 1;
      }
      for (int d = 0; d < 4; ++d) {
        int nx = cur.first + dirs_[d][0];
        int ny = cur.second + dirs_[d][1];
        if (nx < 0 || nx >= 1000000 || ny < 0 || ny >= 1000000  || blocks_.find(od(nx, ny)) != blocks_.end()) {
          continue;
        }
        blocks_.insert(od(nx, ny));
        q.push({nx, ny});
      }
    }

    // can not escape
    return 0;
  }

private:
  unordered_set<long long> blocks_;
  vector<vector<int>> dirs_;
};
