// https://leetcode.com/problems/count-vowel-substrings-of-a-string/
#include "xxx.hpp"

class Solution {
public:
  int countVowelSubstrings(string word) {
    int j = 0;
    int k = 0;
    int vcnt = 0;
    int valid_cnt = 0;
    unordered_map<char, int> m{
        {'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};
    for (int i = 0; i < word.size(); ++i) {
      if (m.count(word[i])) {
        ++m[word[i]];
        if (m[word[i]] == 1) {
          vcnt += 1;
        }
        while (vcnt == 5) {
          --m[word[k]];
          if (m[word[k]] == 0) {
            vcnt -= 1;
          }

          ++k;
        }
        valid_cnt += k - j;
      } else {
        m['a'] = m['e'] = m['i'] = m['o'] = m['u'] = vcnt = 0;
        j = k = i + 1;
      }
    }

    return valid_cnt;
  }
  // an easy question? fuck!
  int countVowelSubstringsUgly(string word) {
    int sz = word.size();
    vector<vector<int>> prefix(26, vector<int>(sz + 1, 0));
    for (int i = 0; i < sz; ++i) {
      char cur = word[i];
      for (int v = 0; v < 26; ++v) {
        prefix[v][i + 1] = prefix[v][i] + ((cur - 'a') == v);
      }
    }
    int cnt = 0;
    for (int i = 0; i < sz; ++i) {
      for (int j = i; j < sz; ++j) {
        if (j - i + 1 < 5) {
          continue;
        }
        bool valid = true;
        for (int v = 0; v < 26; ++v) {
          auto cur_prefix = prefix[v];
          bool is_vowel =
              (v == ('a' - 'a') || v == ('o' - 'a') || v == ('e' - 'a') ||
               v == ('i' - 'a') || v == ('u' - 'a'));
          if (is_vowel) {
            if (cur_prefix[j + 1] - cur_prefix[i /* - 1 + 1*/] <= 0) {
              valid = false;
              break;
            }
          } else {
            if (cur_prefix[j + 1] - cur_prefix[i] > 0) {
              valid = false;
              break;
            }
          }
        }
        if (valid) {
          cnt++;
        }
      }
    }

    return cnt;
  }
};

int main() {
  Solution so;
  cout << so.countVowelSubstrings("aoeiuu") << endl;
}
