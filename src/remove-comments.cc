// http://leetcode.com/problems/remove-comments/description/
#include "xxx.h"

class Solution {
public:
  // 被喷的很厉害
  vector<string> removeComments(vector<string> &source) {
    vector<string> ret;
    bool in_block = false;

    string cur;
    for (auto &line : source) {
      for (int i = 0; i < line.size();) {
        if (!in_block) {
          if (i + 1 == line.size()) {
            cur += line[i++];
          } else {
            string m = line.substr(i, 2);
            if (m == "/*") {
              in_block = true;
              i += 2;
            } else if (m == "//") {
              break;
            } else {
              cur += line[i++];
            }
          }
        } else {
          if (i + 1 == line.size()) {
            i++;
          } else {
            string m = line.substr(i, 2);
            if (m == "*/") {
              in_block = false;
              i += 2;
            } else {
              i++;
            }
          }
        }
      }
      if (cur.size() && !in_block) {
        ret.push_back(cur);
        cur = {};
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  // vector<string> input{"/*Test program */",
  //                      "int main()",
  //                      "{ ",
  //                      "  // variable declaration ",
  //                      "int a, b, c;",
  //                      "/* This is a test",
  //                      "   multiline  ",
  //                      "   comment for ",
  //                      "   testing */",
  //                      "a = b + c;",
  //                      "}"};
  // vector<string> input{"a/*comment", "line", "more_comment*/b"};
  // vector<string> input{"struct Node{", "    /*/ declare members;/**/",
  //                      "    int size;", "    /**/int val;", "};"};
  // vector<string> input{"main() {",
  //                      "   func(1);",
  //                      "   /** / more comments here",
  //                      "   float f = 2.0",
  //                      "   f += f;",
  //                      "   cout << f; */",
  //                      "}"};

  vector<string> input{"a/*/b//*c", "blank", "d/*/e*//f"};
  auto ret = so.removeComments(input);
  for (auto &s : ret) {
    cout << s << endl;
  }
}
