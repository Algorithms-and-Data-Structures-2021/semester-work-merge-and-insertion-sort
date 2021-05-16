#include <iostream>

#include "merge_sort.hpp"
#include "tim_sort.hpp"

using namespace std;
using namespace itis;

int main() {

  int arr[] = {10, 9, 8, 7,6,5,4,3,2,1,14,13,12};
  MergeSort::mergeSort(arr, 13);
  MergeSort::printArr(arr,13);

  return 0;
}


