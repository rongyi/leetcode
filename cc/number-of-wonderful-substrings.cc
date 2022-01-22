// http://leetcode.com/problems/number-of-wonderful-substrings/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/number-of-wonderful-substrings/discuss/1299773/Intuitive-explanation-easy-to-understand
  // should be mark as hard
  long long wonderfulSubstrings(string word) {
    vector<long long> count(1024, 0);
    // all char occur even
    count[0] = 1;

    long long cur_mask = 0;
    long long ret = 0;
    for (auto &c : word) {
      int idx = c - 'a';
      cur_mask ^= (1 << idx);
      ret += count[cur_mask];
      // why a loop?
      // e.g aaaba
      // in this case for loop make b desappear and make a valid substring
      // There is a string with all even count of characters if the current
      // running mask (say 1011) has already come before. There are two
      // possibilities for the counts of each char i.e. odd or even, but
      // odd-odd(5-3) and even-even(4-2) will be even, so in that case when the
      // same mask has been encountered in a previous index less than current i,
      // then there is a substring of >1 length (logically 1 won't happen
      // because if the same mask occurred before then atleast one bit must've
      // been switched twice) so atleast of length 2. If it has occurred more
      // number of times then for each such mask we can find out another even
      // string until the current i (so res+=cnt[mask])

      // If there is a mask that has previously come up that is just one bit
      // switch off from the current one, no matter which character, then there
      // is a substring from that previous mask until current running mask which
      // has odd number occurrence of the said character. For example, if the
      // current running mask is 1011, and there was already a mask with count 2
      // in 1010, then the char representing the last bit must've been switched
      // an odd number of times from back then till now and all the other bits
      // are of even switches in length, so for each such occurrence of the mask
      // 1010 there is a substring from the end of each until current i which
      // has just one character in odd count. Doing the same for all characters
      // by checking if there is a previous mask which has opposite parity wrt
      // the char under consideration, if yes then the same char is of odd count
      // from the end of the prev mask occurrence and now.
      for (int i = 0; i < 10; ++i) {
        int prev = cur_mask ^ (1 << i);
        ret += count[prev];
      }

      count[cur_mask]++;
    }

    return ret;
  }
};
