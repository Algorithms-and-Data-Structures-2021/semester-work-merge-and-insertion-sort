#include <iostream>
#include "merge_sort.hpp"


namespace itis {

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
    int i = left;
    int j = middle + 1;
    int k = left;
    int *temp = new int[arrSize];
    std::copy(arr, arr + arrSize, temp);
    while(i<=middle && j <=right){
      if(arr[i] < arr[j]){
        temp[k++] = arr[i++];
      }else{
        temp[k++] = arr[j++];
      }
    }

    while(i <= middle){
      temp[k++] = arr[i++];
    }

    while(j <= right){
      temp[k++] = arr[j++];
    }
    std::copy(temp, temp + arrSize, arr);
    delete[] temp;
  }
  void MergeSort::printArr(int *arr, int length) {
    for (int i = 0; i < length; ++i) {
      std::cout<<arr[i]<<" ";
    }
    std::cout<<" "<<std::endl;
  }
  MergeSort::MergeSort() {}

}  // namespace itis