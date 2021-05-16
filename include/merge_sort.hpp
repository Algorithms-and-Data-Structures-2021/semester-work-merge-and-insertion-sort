#pragma once

// Заголовочный файл с объявлением структуры данных

namespace itis {

  inline constexpr auto kStringConstant = "Hello, stranger!";

  // Пример: объявление структуры с полями и методами
  struct MyStructure {

    MyStructure();

    void merge(int arr[], int left, int middle, int right, int arrSize, int temp[]);
    int min(int firstNum, int secondNum);
    void mergeSort(int arr[], int length);
    void printArr(int arr[], int length);
  };

}  // namespace itis