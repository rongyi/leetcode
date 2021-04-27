// http://leetcode.com/problems/defuse-the-bomb/description/
#include "xxx.h"

class Solution {
public:
  vector<int> decrypt(vector<int> &code, int k) {
    const int n = code.size();
    if (k == 0) {
      return vector<int>(n, 0);
    }
    // 到prefixsum中的index要加一
    vector<int> psum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      psum[i + 1] = psum[i] + code[i];
    }
    vector<int> ret;
    for (int i = 0; i < n; ++i) {
      if (k > 0) {
        int end = (i + k) % n;
        int cur = 0;
        if (end < i) {
          // 后面部分加前面部分
          cur = psum[end + 1] + (psum[n] - psum[i + 1]);
        } else {
          // 直接就是后面部分，足够长
          cur = psum[end + 1] - psum[i + 1];
        }
        ret.push_back(cur);
      } else {
        int end = (i + k + n) % n;
        int cur = 0;
        // 取两块
        if (end > i) {
          cur = psum[i] + (psum[n] - psum[end]);
        } else {
          // k是负数，往数组前面是加
          cur = psum[i] - psum[i + k];
        }
        ret.push_back(cur);
      }
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{5, 2, 2, 3, 1};
  auto ret = so.decrypt(input, 3);
  for (auto i : ret) {
    cout << i << " ";
  }
  cout << endl;
}
