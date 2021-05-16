#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream
#include <vector>
#include <algorithm>

#include "merge_sort.hpp"

using namespace std;
using namespace itis;


static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kOutputPath = string_view{PROJECT_OUTPUT_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

int main() {

  const auto path = string(kDatasetPath);
  const auto outPath = string(kOutputPath);
  cout << "Path to the 'dataset/' folder: " << path << endl;

  //TODO Изменить 2 на 6, 5 на 10
  for (int i = 1; i < 2; ++i) {
    auto output_file = ofstream (outPath + "/TestCase" + to_string(i) + ".csv");
    for (int j = 0; j < 5; ++j) {
      auto input_file = ifstream(path + "/TestCase" + to_string(i) +"/TestData"+ to_string(j) + ".csv");
      vector<int> vect;
      string line;
      if (input_file) {
        while(getline(input_file, line, ',')){
          vect.push_back(stoi(line));
        }
      }

      int vectorSize = vect.size();

      int *arr = new int[vectorSize];
      for (int k = 0; k < vectorSize; ++k) {
        arr[k] = vect[k];
      }
      const auto time_point_before = chrono::steady_clock::now();

      MergeSort::mergeSort(arr, vectorSize);

      const auto time_point_after = chrono::steady_clock::now();
      sort(vect.begin(), vect.end());
      // переводим время в наносекунды
      const auto time_diff = time_point_after - time_point_before;
      const auto time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

      for (int k = 0; k < vectorSize; ++k) {
        cout<<arr[k]<<" "<<vect[k]<<endl;
      }

      string equals = equal(arr, arr + vectorSize, vect.begin(), vect.end()) ? "equals" : "not equals";
      output_file << "TestCase" + to_string(i) +"/TestData"+ to_string(j) +"," << time_elapsed_ns
                  <<"," + equals<<endl;
      vect.clear();
    }
  }

  return 0;
}

