// http://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/description/
#include "xxx.h"

class Solution {
public:
  vector<int> constructDistancedSequence(int n) {
    vector<int> ret(2 * n - 1, 0);
    vector<bool> visited(n + 1, false);

    dfs(0, ret, visited, n);

    return ret;
  }

private:
  bool dfs(int pos, vector<int> &ret, vector<bool> &visited, int n) {
    if (pos == ret.size()) {
      return true;
    }
    if (ret[pos] != 0) {
      return dfs(pos + 1, ret, visited, n);
    }
    for (int i = n; i >= 1; i--) {
      if (visited[i]) {
        continue;
      }
      visited[i] = true;
      ret[pos] = i;
      if (i == 1) {
        if (dfs(pos + 1, ret, visited, n)) {
          return true;
        }
      } else {
        if (pos + i < ret.size() && ret[pos + i] == 0) {
          ret[pos + i] = i;
          if (dfs(pos + 1, ret, visited, n)) {
            return true;
          }

          // restore
          ret[pos + i] = 0;
        }
      }

      // restore
      visited[i] = false;
      ret[pos] = 0;
    }

    return false;
  }
};
int main() {
  Solution so;
  auto ret = so.constructDistancedSequence(5);
  for (auto i : ret) {
    cout << i << " ";
  }
  cout << endl;
}
