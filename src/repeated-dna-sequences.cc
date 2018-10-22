// http://leetcode.com/problems/repeated-dna-sequences/description/
#include "simpleone.h"

class Solution {
public:
  vector<string> findRepeatedDnaSequencesBruteForce(string s) {
    vector<string> ret;
    unordered_set<string> uniq;
    if (s.size() <= 10) {
      return ret;
    }
    for (int i = 0; i <= s.size() - 10; i++) {
      auto cur = s.substr(i, 10);
      // cout << cur << endl;
      auto match = s.substr(i + 1);
      if (match.find(cur) != string::npos) {
        uniq.insert(cur);
      }
    }
    for (auto &k : uniq) {
      ret.push_back(k);
    }
    return ret;
  }

  // A: 0100 0001　　C: 0100 0011　　G: 0100 0111　　T: 0101 0100
  // 用低三位表示即可, trick在这里
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ret;

    if (s.size() <= 10) {
      return ret;
    }
    unordered_map<int, int> count;
    int cur = 0;
    int i = 0;
    // 十个字符总共需要30位，这个用九位，然后那一位逐渐加进来
    const int mask = 0x7ffffff; // 27bit

    while (i < 9) {
      cur = (cur << 3) | (s[i++] & 7);
    }
    while ( i < s.size()) {
      // 之前九位加上当前这一位，十位了
      cur = ((cur & mask) << 3) | (s[i++] & 7);
      if (count.find(cur) != count.end()) {
        if (count[cur] == 1) {
          ret.push_back(s.substr(i - 10, 10));
        }
        ++count[cur];
      } else {
        count[cur] = 1;
      }
    }

    return ret;
  }
};
int main() {
  Solution so;
  so.findRepeatedDnaSequences("AAAAAAAACCD");
}
