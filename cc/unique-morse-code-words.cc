// http://leetcode.com/problems/unique-morse-code-words/description/
#include "xxx.hpp"

class Solution {
public:
  int uniqueMorseRepresentations(vector<string>& words) {
    vector<string> dict{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    unordered_set<string> ret;
    for (auto w : words) {
      string morse_str("");
      for (auto c : w) {
        morse_str += dict[c - 'a'];
      }
      ret.insert(morse_str);
    }

    return ret.size();
  }
};
