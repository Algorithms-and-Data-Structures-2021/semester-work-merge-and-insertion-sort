#include <iostream>

#include "merge_sort.hpp"

using namespace std;
using namespace itis;
int main(int argc, char *argv[]) {

  MyStructure *ms = new MyStructure();

  int arr[] = {7,3,5,14,1,6,4};
  cout<<"On entry: ";
  ms->printArr(arr, 7);
  ms->mergeSort(arr, 7);
  cout<<"On end: ";
  ms->printArr(arr, 7);

  return 0;
}