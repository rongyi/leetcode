// http://leetcode.com/problems/simplify-path/description/
#include "xxx.hpp"

class Solution {
public:
  string simplifyPath(string path) {
    vector<string> ret;
    const int n = path.size();
    if (path[n - 1] == '/') {
      path = path.substr(0, n - 1);
    }
    auto i = string::npos;
    auto j = string::npos;
    // 一直截取两个斜线之间的内容，然后判断
    while (true) {
      i = path.find('/');
      if (i == string::npos) {
        break;
      }
      j = path.find('/', i + 1);
      string sub;
      if (j == string::npos) {
        // cout << path.substr(i + 1) << endl;
        sub = path.substr(i + 1);
      } else {
        // cout << path.substr(i + 1, j - i - 1) << endl;
        sub = path.substr(i + 1, j - i - 1);
      }

      if (sub == "..") {
        if (ret.size() > 0) {
          ret.pop_back();
        }
      } else if (sub != "." && sub != "") {
        ret.push_back(sub);
      }
      path = path.substr(i + 1);
    }
    stringstream ss;
    ss << "/";
    for (int i = 0; i < ret.size(); ++i) {
      ss << ret[i];
      if (i != ret.size() - 1) {
        ss << '/';
      }
    }

    return ss.str();
  }
};
int main() {
  Solution so;
  // string input{"/a/./b/../../c/"};
  string input{"/abc/..."};
  auto ret = so.simplifyPath(input);
  cout << ret << endl;
}
