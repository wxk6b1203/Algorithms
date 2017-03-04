#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int main() {
  int i, n, h, itor, tmp;
  char octx[5];
  string ar, oct, hex;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    ar.clear();
    cin >> ar;
    oct.clear();
    while (ar.size() >= 3) {
      memset(octx, 0, sizeof(char) * 5);
      hex = ar.substr(ar.size() - 3);
      ar.erase(ar.size() - 3);
      sscanf(hex.c_str(), "%x", &h);
      sprintf(octx, "%o", h);
      if (strlen(octx) < 4) {
        tmp = strlen(octx);
        for (itor = 3; itor > 3 - tmp; itor--) {
          octx[itor] = octx[itor - (4 - tmp)];
        }
        for (itor = 0; itor < 4 - tmp; itor++) {
          octx[itor] = '0';
        }
      }

      oct.insert(0, octx);
    }
    if (!ar.empty()) {
      sscanf(ar.c_str(), "%x", &h);
      sprintf(octx, "%o", h);
      oct.insert(0, octx);
    }
    cout << oct << endl;
  }
  return 0;
}
