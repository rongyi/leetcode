// https://leetcode.com/problems/watering-plants/
#include "xxx.hpp"

class Solution {
public:
  int wateringPlants(vector<int> &plants, int capacity) {
    int steps = 0;
    int water = capacity;
    for (int i = 0; i < plants.size(); ++i) {
      if (water >= plants[i]) {
        // water this plant, and go one step
        steps += 1;
      } else {
        // refill
        water = capacity;
        // go back, we should go back when we peek the next one,
        // so we pretend to peek at (i - 1)
        steps += (i);
        // and water current plant
        steps += (i + 1);
      }
      water -= plants[i];
    }

    return steps;
  }
};
int main() {
  Solution so;
  vector<int> input{2, 2, 3, 3};
  so.wateringPlants(input, 5);
}
