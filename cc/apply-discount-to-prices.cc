// https://leetcode.com/problems/apply-discount-to-prices/
#include "xxx.hpp"
#include <iomanip>

class Solution {
public:
  string discountPrices(string s, int discount) {
    vector<int> spaces_idx;
    string ret;
    s = " " + s;
    int sz = s.size();

    for (int i = 0; i < sz;) {
      if (s[i] == ' ') {
        int j = i + 1;
        int k = i + 1;
        while (k < sz && s[k] != ' ') {
          k++;
        }
        if (j != k) {
          string cur = s.substr(j, k - j);
          if (cur.size()) {
            if (cur[0] == '$') {
              // apply discount
              // cout << "cur " << cur << endl;
              auto d = cur.substr(1);
              if (d.size()) {
                // only digits and at most one single dot
                int dot_count = 0;
                bool valid = true;
                for (int i = 0; i < d.size(); ++i) {
                  if (d[i] == '.') {
                    dot_count++;
                  } else {
                    if (!isdigit(d[i])) {
                      valid = false;
                      break;
                    }
                  }
                }
                if (!valid || (dot_count > 1)) {
                  cout << "invalid" << d << endl;
                  ret += cur;
                } else {
                  double p = stod(d);
                  stringstream ss;
                  ss << std::fixed << std::setprecision(2)
                     << p * (100 - discount) / 100.0;
                  ret += "$" + ss.str();
                }
              } else {
                ret += cur;
              }
            } else {
              ret += cur;
            }
          }
        }
        ret.push_back(' ');
        i = k;
      }
    }

    ret.pop_back();

    return ret;
  }
};

int main() {
  Solution so;
  so.discountPrices("in the shop", 50);
}
