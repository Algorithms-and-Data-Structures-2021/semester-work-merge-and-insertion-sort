#include <iostream>
#include "merge_sort.hpp"

using namespace std;
namespace itis {

  int nextGap(int gap)
  {
    if (gap <= 1){ return 0;}
    return (gap / 2) + (gap % 2);
  }

  int MergeSort::min(int firstNum, int secondNum) {
    return firstNum > secondNum ? secondNum : firstNum;
  }

  void MergeSort::mergeSort(int *arr, int length) {
    for (int size = 1; size < length; size = size * 2) {
      for (int left = 0; left < length; left += size*2) {
        int middle = min(left + size - 1, length - 1);
        int right = min(middle + size, length - 1);
        merge(arr, left, middle, right, length);
      }
    }
  }

  void MergeSort::merge(int *arr, int left, int middle, int right, int arrSize) {

    int gap = (right - left)/2 + (right - left)%2;
    for(;gap != 0; gap = nextGap(gap)) {
      for (int l = left; l + gap <= right; l++) {
        if(arr[l] > arr[l + gap]){
          swap(arr[l], arr[l+gap]);
        }
      }
    }
  }
  void MergeSort::printArr(int *arr, int length) {
    for (int i = 0; i < length; ++i) {
      std::cout<<arr[i]<<" ";
    }
    std::cout<<" "<<std::endl;
  }
  MergeSort::MergeSort() {}
  void MergeSort::swap(int &val1, int &val2) {
    int temp = val1;
    val1 = val2;
    val2 = temp;
  }


}  // namespace itis