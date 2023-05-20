// http://leetcode.com/problems/palindrome-pairs/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> palindromePairs(vector<string> &words) {
    vector<vector<int>> ret;
    unordered_map<string, int> dict;
    for (int i = 0; i < words.size(); i++) {
      auto cp = words[i];
      // 为毛倒过来存？
      // 结合后面来解释: 后面会分割每一个字符串，
      // 假设一刀切下去分 left right两半，形如： left | right
      // 我们可以在左侧加一坨拼接成回文或者在右侧加一坨拼接成回文
      // 1. 左侧： xxxx left | right 如果是回文则要求
      //    left本身是回文，且xxxx是right的 *逆序*
      //    如果字典里存在right,
      //    那么我们就知道原数组中对应的那字符串就是xxxx，因为我们反着存
      // 2. 右侧： left | right xxxx ==> right本身是回文，且xxxx是left的逆序
      // why save it in reverse order?
      // say we split a string in words, e.g. words[i] in two parts:
      // left | right, that is words[i] == (left + right)
      // then we put something it its left, or right
      // xxxx left | right
      // or left | right xxxx
      // if the two case is palindrome, we can deduce
      // xxxx is the reverse order of (right)
      // xxxx is the reverse order of (left) respectively
      // so here, we save the case in reverse order
      reverse(cp.begin(), cp.end());
      dict[cp] = i;
    }
    // 每个字符串都可以和空字符串组合，
    // if input already contain empty string
    if (dict.find("") != dict.end()) {
      for (int i = 0; i < words.size(); i++) {
        if (i == dict[""]) {
          continue;
        }
        if (isPalindrome(words[i])) {
          ret.push_back({i, dict[""]});
          ret.push_back({dict[""], i});
        }
      }
      // act like it does not exist
      dict.erase(dict.find(""));
    }

    for (int i = 0; i < words.size(); i++) {
      auto curw = words[i];
      for (int j = 0; j < curw.size(); j++) {
        auto left = curw.substr(0, j);
        auto right = curw.substr(j);
        // xxxx left | right
        if (dict.find(right) != dict.end() && isPalindrome(left) &&
            dict[right] != i) {
          ret.push_back({dict[right], i});
        }
        // left| right xxxx
        if (dict.find(left) != dict.end() && isPalindrome(right) &&
            dict[left] != i) {
          ret.push_back({i, dict[left]});
        }
      }
    }

    return ret;
  }

  bool isPalindrome(string str) {
    int sz = str.size() - 1;
    for (int i = 0, j = sz - 1; i < j; i++, j--) {
      if (str[i] != str[j]) {
        return false;
      }
    }

    return true;
  }
};

int main() {
  Solution so;
  string input{};

  auto ret = so.isPalindrome(input);
  cout << ret << endl;
  string s{"hello"};
  for (int i = 0; i <= s.size(); i++) {
    cout << s.substr(0, i) << endl;
    cout << s.substr(i) << endl;
    cout << "====" << endl;
  }
}
