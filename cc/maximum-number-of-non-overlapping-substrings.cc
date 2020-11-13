// http://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/description/
#include "xxx.h"

class Solution {
public:
  // 取不重叠的子字符串，而且任意串中包含的字符要全在这个子字符串中
  vector<string> maxNumOfSubstrings(string s) {
    // 每一个字符的最左边的那个位置
    vector<int> l(26, numeric_limits<int>::max());
    // 每一个字符的最右边的那个位置
    vector<int> r(26, numeric_limits<int>::min());
    for (int i = 0; i < s.size(); ++i) {
      // 最左就是最小的
      l[s[i] - 'a'] = min(l[s[i] - 'a'], i);
      // 最右边就是当前值
      r[s[i] - 'a'] = i;
    }
    int right = -1;
    vector<string> ret;
    for (int i = 0; i < s.size(); ++i) {
      if (i != l[s[i] - 'a']) {
        continue;
      }

      // now start the new check
      int new_right = check(s, i, l, r);
      // 有戏
      if (new_right != -1) {
        // 从i开始的位置有一个更小的选择，在里面的要出来
        // 上一个取的字符串的右边界在当前这个字符之后，
        if (i <= right) {
          ret.pop_back();
        }

        ret.push_back(s.substr(i, new_right - i + 1));
        // 更新右边界
        right = new_right;
      }
    }

    return ret;
  }

private:
  int check(string &s, int cur, vector<int> &l, vector<int> &r) {
    // 最右边界
    int right = r[s[cur] - 'a'];
    for (int i = cur; i <= right; ++i) {
      // 直接没戏，囊括的字符中有字符的最左已经跳出开头的cur位置了
      if (l[s[i] - 'a'] < cur) {
        return -1;
      }
      // 如果囊括这个字符，那么就要囊括所有
      right = max(right, r[s[i] - 'a']);
    }
    return right;
  }
};

int main() {
  Solution so;
  auto ret = so.maxNumOfSubstrings("abca");
  for (auto &num : ret) {
    cout << num << endl;
  }
}
