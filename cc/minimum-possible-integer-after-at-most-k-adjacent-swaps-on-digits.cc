// http://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/description/
#include "xxx.h"

class Solution {
public:
  string minIntegerTLE(string num, int k) {
    if (k <= 0) {
      return num;
    }
    const int n = num.size();
    if (k >= n * (n + 2) / 2) {
      sort(num.begin(), num.end());
      return num;
    }
    for (int i = 0; i < 10; ++i) {
      int idx = num.find(to_string(i));
      if (idx >= 0 && idx <= k) {
        return num[idx] +
               minIntegerTLE(num.substr(0, idx) + num.substr(idx + 1), k - idx);
      }
    }
    return num;
  }

  //   We take 10 queues for digits 0 to 9 and store their occurence(index in
  //   the original string) in the queues (clearly all the queues are sorted by
  //   default)
  // Now we want the most significant digit to be the smallest so we try all the
  // 0-9 digits at position i . Suppose we want to place any digit j in range
  // [0,9] at a position i we do a binay search on all the 10 queues to find the
  // number of digits with index smaller than the current chosen digits index
  // then we will check if the swaps are less than or equal to the current k
  // value if yes we put the current digit in new string and go for the (i+1)th
  // place else we will continue to check for digit j+1 . Below is the
  // implementation

  string minInteger(string num, int k) {
    const int n = num.size();
    if (k >= n * (n - 1) / 2) {
      sort(num.begin(), num.end());
      return num;
    }
    // queue
    vector<vector<int>> v(10);
    for (int i = 0; i < n; ++i) {
      v[num[i] - '0'].push_back(i);
    }

    // head
    vector<int> head(10, 0);
    string ret{};
    vector<bool> visit(n, false);

    // 准备找到一个数字放到i这个位置上
    for (int i = 0; i < n && k > 0; ++i) {
      // 从10个队列里找，从最小的开始
      for (int j = 0; j < 10; ++j) {
        // 首先这个队列里还有字符可用
        if (head[j] < v[j].size()) {
          // 算一下当前这个数字：head[j]移动到i这个位置需要的步数
          // 穿过的层层阻碍：
          // 1. 自己当前队列前面的那些值
          // 2. 其他队列里排在自己前面的，用binary search来查找
          int idx = 0;
          // binary search on all the 10 queues
          for (int l = 0; l < 10; ++l) {
            if (l != j) {
              idx += bs(v[l], 0, head[l] - 1, v[j][head[j]]);
            } else {
              idx += head[l];
            }
          }

          if (k >= (v[j][head[j]] - idx)) {
            ret.push_back((char)(j + '0'));
            visit[v[j][head[j]]] = true;
            k -= (v[j][head[j]] - idx);
            ++head[j];
            break;
          }
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      if (!visit[i]) {
        ret.push_back(num[i]);
      }
    }

    return ret;
  }

private:
  int bs(vector<int> &v, int l, int r, int key) {
    if (l > r) {
      return l;
    }
    int mid = l + (r - l) / 2;

    if (key < v[mid]) {
      return bs(v, l, mid - 1, key);
    }

    return bs(v, mid + 1, r, key);
  }
};
