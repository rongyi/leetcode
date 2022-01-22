// http://leetcode.com/problems/word-break-ii/description/
#include "xxx.hpp"

class Solution {
public:
  vector<string> wordBreakTLEVersion(string s, vector<string> &wordDict) {
    unordered_set<string> ws;
    for (auto &w : wordDict) {
      ws.insert(w);
    }
    vector<string> ret;
    string cur;

    dfs(s, ws, ret, 0, cur);

    return ret;
  }

private:
  void dfs(string &s, unordered_set<string> &ws, vector<string> &ret, int i,
           string cur) {
    const int n = s.size();
    if (i == n) {
      ret.push_back(cur);
      return;
    }
    // cout << n << endl;
    for (int j = i + 1; j <= n; ++j) {
      auto tmp = s.substr(i, j - i);
      if (ws.find(tmp) == ws.end()) {
        continue;
      }
      // now is a valid choice
      // cout << tmp << " j:" << j << endl;
      auto origin_cur = cur;
      if (cur == "") {
        cur = tmp;
      } else {
        cur += " " + tmp;
      }
      dfs(s, ws, ret, j, cur);
      // restore
      cur = origin_cur;
    }
  }
  // ===============
  // 优化过的代码，加dp缓存
public:
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> ws;
    for (auto &w : wordDict) {
      ws.insert(w);
    }

    const int n = s.size();
    // 长度为n的字符串有n+1个隔板
    vector<bool> dp(n + 1, false);
    // 空串的情况
    dp[0] = true;
    // dp2[i][j]为true，表示s[j, i)是一个合法单词，可以从j处切开
    // 第一行未用
    vector<vector<bool>> dp2(n + 1, vector<bool>(n, false));
    for (int i = 1; i <= n; ++i) {
      for (int j = i - 1; j >= 0; --j) {
        string tmp = s.substr(j, i - j);

        // 如果j出可以隔开，而且s[j, i)也在字典里，那么i处也可以隔开
        // 并且缓存索引用于后面直接查找
        if (dp[j] && ws.find(tmp) != ws.end()) {
          dp[i] = true;
          dp2[i][j] = true;
        }
      }
    }

    vector<string> ret;
    vector<string> path;

    // 从最后边开始查找，传s.length()大小表示从末尾开始切割，即第一刀是完整的原始字符
    dfs2(s, dp2, ret, n, path);
    return ret;
  }

private:
  void dfs2(string &s, vector<vector<bool>> &dp, vector<string> &ret, int cur,
            vector<string> &path) {

    // 找到头了，这时候将path添加到ret
    if (cur == 0) {
      string tmp;
      for (auto iter = path.crbegin(); iter != path.crend(); ++iter)
        tmp += *iter + " ";
      tmp.erase(tmp.end() - 1);
      ret.push_back(tmp);
    }
    for (size_t i = 0; i < s.size(); ++i) {
      // 表示i位置可以切下去，即保证下面tmp这个字符串在字典里
      if (dp[cur][i]) {
        string tmp = s.substr(i, cur - i);
        path.push_back(tmp);
        // 再从i这个位置开始往前找下一个位置可以切下去
        dfs2(s, dp, ret, i, path);
        path.pop_back();
      }
    }
  }
};
int main() {
  Solution so;
  vector<string> input{"cat", "cats", "and", "sand", "dog"};
  auto ret = so.wordBreak("catsanddog", input);
  for (auto s : ret) {
    cout << s << endl;
  }
}
