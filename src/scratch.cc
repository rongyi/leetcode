#include "one.h"
// prove somthing in this scratch file
int main() {
  set<int> test;
  test.insert(1);
  test.insert(2);
  test.insert(3);
  for (auto i: test) {
    cout << i << endl;
  }
}
