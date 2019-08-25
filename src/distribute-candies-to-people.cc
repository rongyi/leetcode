// http://leetcode.com/problems/distribute-candies-to-people/description/
#include "xxx.h"

class Solution {
public:
  vector<int> distributeCandies(int candies, int num_people) {
    const int one_round_consume = (num_people + 1) * num_people / 2;

    int perfect_round = 0;
    int consume = 0;
    int prev = consume;
    while (true) {
      prev = consume;
      consume += (num_people * num_people * perfect_round++) + one_round_consume;

      if (consume > candies) {
        --perfect_round;
        consume = prev;
        break;
      }
    }

    vector<int> ret(num_people, 0);
    if (perfect_round > 0) {
      for (int i = 0; i < num_people; ++i) {
        // 等差数列的和
        int end = (i + 1) + (perfect_round - 1) * num_people;
        ret[i] = (end + (i + 1)) * perfect_round / 2;
      }
    }
    // 剩下的残局
    candies -= consume;
    int num_expect_candy = perfect_round * num_people + 1;
    for (int i = 0; i < num_people; ++i) {
      if (candies >= num_expect_candy) {
        candies -= num_expect_candy;
        ret[i] += num_expect_candy++;
      } else {
        ret[i] += candies;
        break;
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  int candies = 60;
  int num_people = 4;
  int one_round_consume = num_people * (num_people + 1) / 2;
  int perfect_round = 0;
  int consume = 0;
  int prev = consume;
  while (true) {
    prev = consume;
    consume += (num_people * num_people * perfect_round++) + one_round_consume;

    if (consume > candies) {
      --perfect_round;
      consume = prev;
      break;
    }
  }
  cout << perfect_round << endl;
  cout << prev << endl;

  so.distributeCandies(candies, num_people);
}
