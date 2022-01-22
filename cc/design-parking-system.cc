// http://leetcode.com/problems/design-parking-system/description/
#include "xxx.hpp"

class ParkingSystem {
public:
  ParkingSystem(int big, int medium, int small)
      : big_(big), medium_(medium), small_(small), cur_small_(0),
        cur_medium_(0), cur_big_(0) {}

  bool addCar(int carType) {
    switch (carType) {
    case 3:
      if (cur_small_ >= small_) {
        return false;
      }
      ++cur_small_;
      return true;
    case 2:
      if (cur_medium_ >= medium_) {
        return false;
      }
      ++cur_medium_;
      return true;
    case 1:
      if (cur_big_ >= big_) {
        return false;
      }
      ++cur_big_;
      return true;
    }
    return false;
  }

private:
  uint64_t small_;
  uint64_t medium_;
  uint64_t big_;

  uint64_t cur_small_;
  uint64_t cur_medium_;
  uint64_t cur_big_;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
