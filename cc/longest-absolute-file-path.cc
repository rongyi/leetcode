// http://leetcode.com/problems/longest-absolute-file-path/description/
#include "xxx.hpp"

class Solution {
public:
  int lengthLongestPath(string input) {
    stringstream ss(input);
    string line;

    vector<int> dir_len;
    int ret = 0;

    while (getline(ss, line, '\n')) {
      bool is_dir = true;
      // only file contain dot
      if (line.find(".") != string::npos) {
        is_dir = false;
      }

      if (is_dir) {
        int i = 0;
        // 缩进就代表文件夹的level层次
        for (; i < line.size() && line[i] == '\t'; i++) {
          ;
        }

        // 新增加的层次，直接push进去
        // 如果文件夹层次已经有了，则直接更新，这种什么情况会出现？
        // 是在同一层级下有多个文件夹的时候，后续的文件夹都会更新这个位置的长度
        if (i < dir_len.size()) {
          dir_len[i] = line.substr(i).size();
        } else {
          dir_len.push_back(line.substr(i).size());
        }
      } else {
        int i = 0;
        int len = 0;
        for (; i < line.size() && line[i] == '\t'; i++) {
          // and the '/', dude
          len += dir_len[i] + 1;
        }
        len += line.substr(i).size();
        ret = max(ret, len);
      }
    }

    return ret;
  }
};
int main() {
  Solution so;
  auto ret = so.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext");
  cout << ret << endl;
}
