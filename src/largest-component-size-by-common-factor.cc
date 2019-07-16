// http://leetcode.com/problems/largest-component-size-by-common-factor/description/
#include "xxx.h"

class UnionFindSet {
public:
  UnionFindSet(int n) : _parent(n) {
    for (int i = 0; i < n; i++) {
      _parent[i] = i;
    }
  }

  void Union(int x, int y) { _parent[Find(x)] = _parent[Find(y)]; }

  int Find(int x) {
    if (_parent[x] != x) {
      auto par = Find(_parent[x]);
      _parent[x] = par;
      return par;
    }
    return _parent[x];
  }

private:
  vector<int> _parent;
};

class Solution {
public:
  int largestComponentSize(vector<int> &A) {
    int max_num = *max_element(A.begin(), A.end());
    UnionFindSet ufs(max_num + 1);

    for (auto num : A) {
      for (int k = 2; k <= sqrt(num); k++) {
        if (num % k == 0) {
          ufs.Union(num, k);
          ufs.Union(num, num / k);
        }
      }
    }

    int ret = 1;
    unordered_map<int, int> count;
    for (auto num : A) {
      ret = max(ret, ++count[ufs.Find(num)]);
    }
    return ret;
  }
};

int main() {
  UnionFindSet ufs(22);
  ufs.Union(18, 3);
  ufs.Union(18, 6);
  ufs.Union(18, 2);
  ufs.Union(18, 9);
  cout << "hahah" << endl;
  cout << ufs.Find(18) << endl;
  cout << ufs.Find(3) << endl;
  cout << ufs.Find(6) << endl;
  cout << ufs.Find(2) << endl;
  return 0;
}
