// http://leetcode.com/problems/find-the-closest-palindrome/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/find-the-closest-palindrome/discuss/147949/Logical-Thinking-with-Java-Code-Beats-98.80
  // For a palindrome number, e.g., 12321, the next bigger palindrome should be
  // 12421, and the next smaller one should be 12221. That is, if we define 123
  // as palindromeRoot of 12321, the next bigger palindrome number's
  // palindromeRoot ispalindromeRoot + 1, while the next smaller one's
  // palindromeRoot ispalindromeRoot - 1. For palindrome numbers with even
  // digits, e.g., 123321, the change of palindromeRoot follows the same
  // pattern. And the closest palindromic one should be among the palindromic
  // numbers formed by these two palindromeRoots.

  // Inspired by the idea above, for a number which is not palindromic, e.g.,
  // 12345, we still focus on the front half of the number, i.e., palindromeRoot
  // as 123 in the example. Except for the bigger one formed by palindromeRoot +
  // 1(124), the smaller one formed by palindromeRoot - 1(122), there should be
  // one more possibility, i.e., the number formed by palindromeRoot (123). We
  // chose the closest one among these three palindromic numbers formed.

  // There are some cases missing the rules above,
  // case 1. smaller than or equal to 10 OR 100, 1000, 10000, ... We simply
  // decrease n by 1.
  // case 2. 11, 101, 1001, 10001, 100001, ... We simply
  // decrease n by 2.
  // case 3. 99, 999, 9999, 99999, ... We simply increase n
  // by 2.

  string nearestPalindromic(string n) {
    // The input n is a positive integer represented by string, whose length
    // will not exceed 18. so val will not be zero
    long long val = stoll(n);
    // just one digit or 10
    if (val <= 10) {
      return to_string(val - 1);
    }
    // or 100 1000 ....
    if (val % 10 == 0 && n[0] == '1' && stoll(n.substr(1)) == 0) {
      return to_string(val - 1);
    }
    // or 11 101 1001 10001...
    if (val == 11 ||
        ((val % 10 == 1) && n[0] == '1' && stoll(n.substr(1)) == 1)) {
      return to_string(val - 2);
    }

    // or 99 999 9999 ...
    bool all_nine = true;
    for (int i = 0; i < n.size(); i++) {
      if (n[i] != '9') {
        all_nine = false;
        break;
      }
    }

    if (all_nine) {
      return to_string(val + 2);
    }

    // 偶数加1没有卵用
    string root = n.substr(0, (n.size() + 1) / 2);
    long long root_val = stoll(root);
    bool is_even = n.size() % 2 == 0;
    long long equal = stoll(compose(root_val, is_even));
    long long bigger = stoll(compose(root_val + 1, is_even));
    long long smaller = stoll(compose(root_val - 1, is_even));
    long long de = llabs(equal - val);
    long long db = llabs(bigger - val);
    long long ds = llabs(smaller - val);

    long long smallest = 0ll;
    // do not including it self
    if (de == 0) {
      smallest = min(db, ds);
    } else {
      smallest = min(de, min(ds, db));
    }

    if (smallest == ds) {
      return to_string(smaller);
    }
    if (smallest == de) {
      return to_string(equal);
    }
    return to_string(bigger);
  }

private:
  // 123 ==> 12321 if !is_even
  // 123 ==> 123321 if is_even
  string compose(int n, bool is_even) {
    string s = to_string(n);
    string cp = s;
    reverse(cp.begin(), cp.end());
    if (is_even) {
      return s + cp;
    }

    return s + cp.substr(1);
  }
};

int main() {
  Solution so;
  auto ret = so.nearestPalindromic("100");
  cout << ret << endl;
}
