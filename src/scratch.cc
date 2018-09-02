#include "one.h"

int main() {
  string a("ab");
  for (int i = 0; i < 4; i++) {
    string cur{""};
    if ((i >> 2) & 1) {
      cur.push_back(toupper('a'));
    } else {
      cur.push_back(tolower('a'));
    }

    if ((i >> 1) & 1) {
      cur.push_back(toupper('b'));
    } else {
      cur.push_back(tolower('b'));
    }
    cout << cur << endl;
  }
  cout << endl;
}
