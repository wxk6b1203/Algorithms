#include <cmath>
#include <iostream>
using namespace std;
bool half(int argt, int argc, int argv[]);
void merge_sort(int argv[], int pre, int r);
void merge(int argv[], int pre, int mid, int r);
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
  merge_sort(argv, 0, n - 1);
  cout << "The number you want to search: ";
  cin >> pt;
  cout << endl;
  judge = half(pt, n - 1, argv);
  if (judge != 0) {
    cout << "Contain." << endl;
  } else {
    cout << "Not contain." << endl;
  }
  delete[] argv;
  return 0;
}
bool half(int argt, int argc, int argv[]) {
  int l, r;
  int mid_d;

  l = 0;
  r = argc;
  int mid = argc / 2;
  while (abs(l - r) > 1) {
    mid_d = argv[mid];
    if (argv[l] == argt || argv[r] == argt || argv[mid] == argt) {
      return 1;

    } else {
      if (mid_d < argt) {
        l = mid;
        mid = (mid + r) / 2;
      }
      if (mid_d > argt) {
        r = mid;
        mid = (mid + l) / 2;
      }
    }
  }
  return 0;
}

void merge_sort(int argv[], int pre, int r) {
  // parameters: argv[]: the main array;
  //             pre   : the first one of the sub-array;
  //             r     : the last one of the sub-array;
  if (pre < r) {
    int mid = (pre + r) / 2;
    merge_sort(argv, pre, mid);
    merge_sort(argv, mid + 1, r);
    merge(argv, pre, mid, r);
  }
}
void merge(int argv[], int pre, int mid, int r) {
  /*  parameters:
   *    argv[]: the main array;
   *    pre:    the first one of the sub-array;
   *    mid:    the middium one of it;
   *    r  :    the last one.
   *
   *  output: partically sorted array.
   */

  int n_1 = mid - pre + 1;
  int n_2 = r - mid;
  int *Lt = new int[n_1];
  // new and store(or define as)the Left sight of the array;
  int *Rt = new int[n_2];
  // new and store(or define as)the Right sight of the array;
  int i, j;
  // Do as iterator and pointer;

  for (i = 0; i < mid - pre + 1; i++) {
    Lt[i] = argv[pre + i];
  }
  for (i = 0; i < r - mid; i++) {
    Rt[i] = argv[mid + i + 1];
  }
  // Temperorily store the two sizes of number;

  i = 0; //
  j = 0; // Initalize the pointer;
  int k = pre;
  while (k <= r && i < n_1 && j < n_2) { /// TEST CODE if (i < n_1 && j < n_2)
    {
      if (Lt[i] < Rt[j]) {
        argv[k] = Lt[i];
        i++;
      } else { /// TEST CODE (Lt[i] > Rt[j])
        argv[k] = Rt[j];
        j++;
      }
    }
    k++;
  }

  while (j < n_2) {
    argv[k++] = Rt[j++];
  }
  while (i < n_1) {
    argv[k++] = Lt[i++];
  }
  delete[] Rt;
  delete[] Lt;
}
