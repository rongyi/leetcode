// http://leetcode.com/problems/reconstruct-original-digits-from-english/description/
#include "xxx.hpp"

class Solution {
public:
  string originalDigits(string s) {
    // 在0 ~10的英文中， 0 2 4 6
    // 8这几个单词有些字符有唯一属性，比如z只出现在zero中
    vector<char> uniqall{'g', 'x', 'u', 'w', 'z'};
    unordered_map<char, string> uniqmap{{'g', "eight"},
                                        {'x', "six"},
                                        {'u', "four"},
                                        {'w', "two"},
                                        {'z', "zero"}};
    unordered_map<char, int> tointmap{
        {'g', 8}, {'x', 6}, {'u', 4}, {'w', 2}, {'z', 0}};
    unordered_map<char, int> count;
    for (auto c : s) {
      count[c]++;
    }
    stringstream ss;
    for (auto c : uniqall) {
      // 通过标记性字符找到对应的数字英文
      if (count.find(c) != count.end() && count[c] > 0) {
        auto word_count = count[c];
        auto cur_word = uniqmap[c];
        auto cur_int = tointmap[c];
        // 都是按规矩出现，对应的把这些单词干掉
        for (int i = 0; i < word_count; i++) {
          ss << cur_int;
          for (auto delchar : cur_word) {
            count[delchar]--;
          }
        }
      }
    }
    // 剩下来的1 3 5 7 9 中也有这样的属性字符

    vector<char> uniqleft{'s', 'f', 'r', 'h', 't', 'o'};
    unordered_map<char, string> leftstr{{'s', "seven"}, {'f', "five"},
                                        {'r', "three"}, {'h', "three"},
                                        {'t', "three"}, {'o', "one"}};
    unordered_map<char, int> leftint{{'s', 7}, {'f', 5}, {'r', 3},
                                     {'h', 3}, {'t', 3}, {'o', 1}};


    for (auto c : uniqleft) {
      // 通过标记性字符找到对应的数字英文
      if (count.find(c) != count.end() && count[c] > 0) {
        auto word_count = count[c];
        auto cur_word = leftstr[c];
        auto cur_int = leftint[c];
        // 都是按规矩出现，对应的把这些单词干掉
        for (int i = 0; i < word_count; i++) {
          ss << cur_int;
          for (auto delchar : cur_word) {
            count[delchar]--;
          }
        }
      }
    }
    // 如果此时还有n出现那么此时必定有9
    if (count.find('n') != count.end() && count['n'] > 0) {
      int nine_count = count['n'] / 2;
      for (int i = 0; i < nine_count; i++) {
        ss << 9;
        // no need to delete
      }
    }


    string ret = ss.str();
    sort(ret.begin(), ret.end());
    return ret;
  }
  string originalDigitsAnalysis(string s) {
    static string zero = "zero";
    static string one = "one";
    static string two = "two";
    static string three = "three";
    static string four = "four";
    static string five = "five";
    static string six = "six";
    static string seven = "seven";
    static string eight = "eight";
    static string nine = "nine";
    vector<string> lst{zero, one, two,   three, four,
                       five, six, seven, eight, nine};

    unordered_map<char, int> count;
    for (auto s : lst) {
      for (auto c : s) {
        count[c]++;
      }
    }
    for (auto kv : count) {
      if (kv.second == 1) {
        cout << kv.first << endl;
      }
    }

    lst = {nine, seven, five, three, one};

    count.clear();
    cout << "---" << endl;
    for (auto s : lst) {
      for (auto c : s) {
        count[c]++;
      }
    }
    for (auto kv : count) {
      if (kv.second == 1) {
        cout << kv.first << endl;
      }
    }

    lst = {nine, five, three};

    count.clear();
    cout << "---" << endl;
    for (auto s : lst) {
      for (auto c : s) {
        count[c]++;
      }
    }
    for (auto kv : count) {
      if (kv.second == 1) {
        cout << kv.first << endl;
      }
    }
    return "";
  }
};

int main() {
  Solution so;
  so.originalDigitsAnalysis("");
}
