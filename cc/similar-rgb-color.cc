// https://leetcode.com/problems/similar-rgb-color/description/
#include "xxx.h"
class Solution {
public:
  string similarRGB(string color) {
    auto fn = [](string str) -> string {
      const static string dict = "0123456789abcdef";
      int num = stoi(str, nullptr, 16);
      int idx = num / 17 + ((num % 17) > 8 ? 1 : 0);
      return string(2, dict[idx]);
    };
    return "#" + fn(color.substr(1, 2)) + fn(color.substr(3, 2)) +
           fn(color.substr(5, 2));
  }
};



int main() {
  Solution so;
  auto near = so.similarRGB("#09f166");
  cout << near << endl;
}
