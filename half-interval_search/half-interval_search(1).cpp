#include <cmath>
#include <iostream>
using namespace std;
void bubble(int argc, int argv[]);
bool _search(int argt, int l, int r, int argv[]);
int *argv;

int main() {
  int n;
  int pt;
  bool judge;
  cin >> n;
  argv = new int[n];
  for (int itor = 0; itor < n; itor++) {
    cin >> argv[itor];
  }
  bubble(n, argv);
  cout << "The number you want to search: ";
  cin >> pt;
  cout << endl;
  judge = _search(pt, 0, n - 1, argv);
  if (judge != 0) {
    cout << "Contain." << endl;
  } else {
    cout << "Not contain." << endl;
  }
  delete[] argv;
  return 0;
}

bool _search(int argt, int l, int r, int argv[]) {
  if (l == r) {
    if (argv[l] == argt) {
      return 1;
    }
  } // termination;

  else {
    int mid = (l + r) / 2;
    if (argv[l] == argt || argv[l] == argt || argv[mid] == argt) {
      return 1;
    } else {
      if (argv[mid] > argt) {
        return _search(argt, l, mid - 1, argv);
      }
      if (argv[mid] < argt) {
        return _search(argt, mid + 1, r, argv);
      }
    }
  }
  return 0;
}
void bubble(int argc, int argv[]) {
  // i: the first iterator, from left to right;
  // j: the second iterator, from right ro left;
  // judge: judge when to quit the iteration;

  /*
  * Bubble sort:

  * for function bubble:
  *    parameters:
  *       argc: the amount of the sequence;
  *       argv[]: the array;
  */
  bool judge;
  for (int i = 0; i < argc; i++) {
    judge = 0;
    if (judge == 0) {
      for (int j = argc - 1; j > i; j--) {
        if (argv[j] < argv[j - 1]) {
          int temp = argv[j - 1];
          argv[j - 1] = argv[j];
          argv[j] = temp;
          judge = 1;
        }
      }
    } else
      break;
  }
}
