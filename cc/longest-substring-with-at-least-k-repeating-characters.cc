// http://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
#include "xxx.hpp"

class Solution {
public:
  int longestSubstring(string s, int k) {
    const int n = s.size();
    ret_ = 0;
    help(s, 0, n, k);

    return ret_;
  }

private:
  // 思路：
  // 如果某个字符全局出现的次数都不够K的那么满足条件的字符串必不包含这些字符，
  // 所以把这些字符当做分割的地方，采用divide and conquer的思路来做
  // 这位的思路和我差不多
  // https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/discuss/207941/C%2B%2B-Simple-Brutal-Recursive-Trimming-Approach-100
  void help(string &s, int start, int end, const int &k) {
    unordered_map<char, int> count;
    for (int i = start; i < end; i++) {
      count[s[i]]++;
    }

    for (int i = start; i < end;) {
      // 这些点压根就不入流，不能作为子字符串的开始，直接忽略
      if (count[s[i]] < k) {
        i++;
        continue;
      }
      // 从这里开始一直往下找，一直找到第一个全局总量都  < k的那个字符
      int j = i;

      // 那么统计已有的所有字符，如果都满足 >=
      // k的要求，显然整个字符串可以作为ret的候选
      // 否则，找到那个从当前的J处切开，把前面的字符串再这样递归处理一把
      unordered_map<char, int> check;
      while (j < end && count[s[j]] >= k) {
        check[s[j]]++;
        j++;
      }
      int len = j - i;
      int nexti = j;
      bool good = true;
      for (auto kv : check) {
        if (kv.second < k) {
          good = false;
          break;
        }
      }

      if (good) {
        ret_ = max(ret_, len);
      } else {
        help(s, i, nexti, k);
      }

      i = nexti;
    }
  }

private:
  int ret_;
};

int main() {
  Solution so;
  auto ret = so.longestSubstring("baaabcb", 3);
  cout << ret << endl;
}
