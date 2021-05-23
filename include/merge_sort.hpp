#pragma once


namespace itis {

  struct MergeSort {

    MergeSort();

    static void merge(int arr[], int left, int middle, int right, int arrSize);
    static int min(int firstNum, int secondNum);
    static void mergeSort(int arr[], int length);
    static void printArr(int arr[], int length);
    static void swap(int &val1, int &val2);
  };

}