#pragma once
#include "merge_sort.hpp"

namespace itis {

  int run;

  struct TimSort {

    static void sort(int arr[], int length);
    static void insertionSort(int arr[], int left, int right);
  };
}
