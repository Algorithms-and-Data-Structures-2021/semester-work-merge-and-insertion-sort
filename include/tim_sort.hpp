#pragma once
#include "merge_sort.hpp"

namespace itis {

  const int RUN = 32;

  struct TimSort {

    static void sort(int arr[], int length);
    static void insertionSort(int arr[], int left, int right);
  };
}
