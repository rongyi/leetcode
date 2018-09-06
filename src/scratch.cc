#include "one.h"

int main() {
  int i = 1e6;
  cout << i << endl;
  for (int j = 1; j < 31; ++j) {
    if ((1 << j) > i) {
      cout << "here" << j << endl;
      break;
    }
  }

}
