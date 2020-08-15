// http://leetcode.com/problems/compare-version-numbers/description/
#include "xxx.h"

class Solution {
public:
  int compareVersion(string version1, string version2) {
    if (version1 == version2) {
      return 0;
    }
    vector<string> v1;
    vector<string> v2;

    split('.', version1, v1);
    split('.', version2, v2);

    const int n = max(v1.size(), v2.size());
    int i = 0;
    for (; i < n; i++) {
      auto cur1 = i < v1.size() ? stoi(v1[i]) : 0;
      auto cur2 = i < v2.size() ? stoi(v2[i]) : 0;
      if (cur1 < cur2) {
        return -1;
      } else if (cur1 > cur2) {
        return 1;
      }
    }
    return 0;
  }

private:
  inline void split(const char delim, const std::string &input,
                    std::vector<std::string> &output) {
    if (input.empty())
      return;

    output.clear();
    size_t token_start_pos = 0;
    size_t token_size = 0;

    for (size_t i = 0; i <= input.size() - 1; ++i) {
      if (input[i] == delim) {
        if (token_size > 0) {
          output.push_back(std::string(input, token_start_pos, token_size));
        }
        token_start_pos = i + 1;
        token_size = 0;
      } else {
        ++token_size;
      }
    }

    // the last one
    token_size = input.size() - token_start_pos;
    if (token_size > 0) {
      output.push_back(std::string(input, token_start_pos, token_size));
    }
  }
};
