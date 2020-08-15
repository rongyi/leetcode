// http://leetcode.com/problems/html-entity-parser/description/
#include "xxx.h"

class Solution {
public:
  string entityParser(string text) {
    unordered_map<string, char> hd; // html dict
    hd["quot;"] = '"';
    hd["apos;"] = '\'';
    hd["amp;"] = '&';
    hd["gt;"] = '>';
    hd["lt;"] = '<';
    hd["frasl;"] = '/';

    ostringstream ss;
    const int n = text.size();
    int i = 0;
    while (i < n) {
      char cur = text[i];
      // normal char
      if (cur != '&') {
        ss << cur;
        i++;
        continue;
      }

      // peak for translation
      // check &frasl;
      if (i + 6 < n) {
        auto check = text.substr(i + 1, 6);
        if (hd.count(check)) {
          ss << hd[check];
          // pass the last
          i += 7;
          continue;
        }
      }
      if (i + 5 < n) {
        auto check = text.substr(i + 1, 5);
        if (hd.count(check)) {
          ss << hd[check];
          i += 6;
          continue;
        }
      }
      if (i + 4 < n) {
        auto check = text.substr(i + 1, 4);
        // cout << "here --> " << check << endl;
        if (hd.count(check)) {
          ss << hd[check];
          i += 5;
          continue;
        }
      }
      if (i + 3 < n) {
        auto check = text.substr(i + 1, 3);
        if (hd.count(check)) {
          ss << hd[check];
          i += 4;
          continue;
        }
      }

      // just a normal &
      ss << cur;
      i++;
    }

    return ss.str();
  }
};

int main() {
  Solution so;
  auto ret =
      so.entityParser("&amp; is an HTML entity but &ambassador; is not.");
  cout << ret << endl;
}
