#include <iostream>
#include "merge_sort.hpp"

using namespace std;
namespace itis {


  int MergeSort::min(int firstNum, int secondNum) {
    return firstNum > secondNum ? secondNum : firstNum;
  }

  void MergeSort::mergeSort(int *arr) {
    int length = sizeof(arr) / sizeof(arr[0]);
    for (int size = 1; size < length; size = size * 2) {
      for (int left = 0; left < length; left += size*2) {
        int middle = min(left + size - 1, length - 1);
        int right = min(middle + size, length - 1);
        merge(arr, left, middle, right);
      }
    }
  }

  void MergeSort::merge(int *arr, int left, int middle, int right) {
    int maxElem = 0;
    for (int i = left; i <= right; ++i) {
      if(arr[i] > maxElem) maxElem = arr[i];
    }

    maxElem++;
    int i = left, j = middle+1, k = left;
    while (i<=middle && j<=right && k <= (middle + right)){
      int e1 = arr[i] % maxElem;
      int e2 = arr[j] % maxElem;

      if(e1 <= e2){
        if(k <= middle){
          arr[k] += (e1*maxElem);
        } else arr[k] += e1*maxElem;
        i++;
        k++;
      }else{
        if(k <= middle){
          arr[k] += (e2*maxElem);
        }else{
          arr[k] += e2*maxElem;
        }
        j++;
        k++;
      }
    }

    while (i <= middle) {
      int el = arr[i] % maxElem;
      if (k <= middle)
        arr[k] += (el * maxElem);
      else
        arr[k] += (el * maxElem);
      i++;
      k++;
    }

    while (j <= right) {
      int el = arr[j] % maxElem;
      if (k <= middle)
        arr[k] += (el * maxElem);
      else
        arr[k] += (el * maxElem);
      j++;
      k++;
    }

    for (int l = left; l <= right; ++l) {
      arr[l] = arr[l] / maxElem;
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