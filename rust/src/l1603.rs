// https://leetcode.com/problems/design-parking-system/
struct ParkingSystem {
    big: i32,
    medium: i32,
    small: i32,

    cur_big: i32,
    cur_medium: i32,
    cur_small: i32,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl ParkingSystem {
    fn new(big: i32, medium: i32, small: i32) -> Self {
        Self {
            big,
            medium,
            small,
            cur_big: 0,
            cur_medium: 0,
            cur_small: 0,
        }
    }

    fn add_car(&mut self, car_type: i32) -> bool {
        match car_type {
            1 => {
                if self.cur_big >= self.big {
                    return false;
                }
                self.cur_big += 1;
                return true;
            }
            2 => {
                if self.cur_medium >= self.medium {
                    return false;
                }
                self.cur_medium += 1;
                return true;
            }
            3 => {
                if self.cur_small >= self.small {
                    return false;
                }
                self.cur_small += 1;
                return true;
            }
            _ => false,
        }
    }
}
