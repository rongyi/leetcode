// http://leetcode.com/problems/decode-string/description/
#include "xxx.h"

class Solution {
public:
  // 这个方法不算最优，可以看下其他人是怎么做的
  // 思路： 用两个栈， 一个记录前缀的count，一个记录要重复的单词，
  // 3[a2[cbd]] 为例，栈的样子如下：
  // |   |  | cbd |
  // | 2 |  | [   |
  // | 3 |  | a   |
  //  ---   | [   |
  //         ---
  // 辅助这个栈看下面代码就要方便一点
  string decodeString(string s) {
    string ret{};

    const int n = s.size();
    stack<int> prefix;
    stack<string> target;

    int i = 0;
    while (i < n) {
      if (isdigit(s[i])) {
        int j = i;
        while (s[j] != '[') {
          j++;
        }

        string tmp = s.substr(i, j - i);
        int count = stoi(tmp);
        prefix.push(count);

        i = j;
      } else if (s[i] == '[') {
        target.push({s[i]});

        i++;
      } else if (isalpha(s[i])) {
        int j = i;
        while (isalpha(s[j])) {
          j++;
        }

        string tmp = s.substr(i, j - i);
        if (prefix.empty()) {
          ret += tmp;
        } else {
          target.push(tmp);
        }

        i = j;
      } else if (s[i] == ']') {
        auto count = prefix.top();
        prefix.pop();

        string tmp{};
        while (target.top() != "[") {
          tmp = target.top() + tmp;
          target.pop();
        }
        // cout << tmp << endl;
        // the [ delimeter
        target.pop();

        auto rpt = repeat(tmp, count);
        if (prefix.empty()) {
          ret += rpt;
        } else {
          target.push(rpt);
        }

        i++;
      }
    }
    // if target has any string the means it has no prefix, we still need to add
    // it to the result
    if (!target.empty()) {
      ret += target.top();
      target.pop();
    }

    return ret;
  }

private:
  string repeat(string s, int n) {
    stringstream ss;
    for (int i = 0; i < n; i++) {
      ss << s;
    }

    return ss.str();
  }
};

int main() {
  Solution so;
  // auto ret = so.decodeString("3[a2[cbd]]");
  // auto ret = so.decodeString("2[abc]3[cd]ef");
  auto ret = so.decodeString("sd2[f2[e]g]i");
  cout << ret << endl;
}
