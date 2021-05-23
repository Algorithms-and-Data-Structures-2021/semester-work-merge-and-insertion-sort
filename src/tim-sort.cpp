#include "tim_sort.hpp"
#include "merge_sort.hpp"

using namespace std;

namespace itis {

  int getRun(int length)
  {
    int r = 0;
    while (length >= 64) {
      r |= length & 1;
      length >>= 1;
    }
    return length + r;
  }

  void TimSort::sort(int *arr, int length) {
    run = getRun(length);
    for (int i = 0; i < length; i+= run) {
      insertionSort(arr, i, MergeSort::min(i+ run -1, length - 1));
    }
    for (int size = run; size < length;
         size = 2*size)
    {
      for (int left = 0; left < length;
           left += 2*size)
      {
        int mid = left + size - 1;
        int right = MergeSort::min((left + 2*size - 1),
                        (length-1));
        if(mid < right)
          MergeSort::merge(arr, left, mid, right, length);
      }
    }
  }

  void TimSort::insertionSort(int *arr, int left, int right) {
    for (int i = left + 1; i <= right ; ++i) {
      int temp = arr[i];
      int j = i - 1;
      while (j >= left && arr[j] > temp){
        arr[j+1] = arr[j];
        j--;
      }
      arr[j+1] = temp;
    }
  }
}
