#include <cmath>
#include <iostream>
using namespace std;
void bubble(int argc, int argv[]);
int *argv;
/*
* Bubble sort:
* input: 2 lines, first one is amount "n", second is n number;
* output: a sorted seuence;
*
* for function bubble:
*    parameters:
*       argc: the amount of the sequence;
*       argv[]: the array;
*/
int main() {
  int n;
  cin >> n;
  argv = new int[n];
  for (int itor = 0; itor < n; itor++) {
    cin >> argv[itor];
  }
  bubble(n, argv);
  for (int i = 0; i < n; i++) {
    cout << argv[i] << " ";
  }
  delete[] argv;
  return 0;
}

void bubble(int argc, int argv[]) {
  // i: the first iterator, from left to right;
  // j: the second iterator, from right ro left;
  // judge: judge when to quit the iteration;
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
