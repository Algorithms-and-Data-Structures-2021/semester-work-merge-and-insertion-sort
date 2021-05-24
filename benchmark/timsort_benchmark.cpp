#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <vector>
#include <algorithm>

#include "tim_sort.hpp"

using namespace std;
using namespace itis;


static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kOutputPath = string_view{PROJECT_OUTPUT_DIR};


int main() {

  const auto path = string(kDatasetPath);
  const auto outPath = string(kOutputPath);
  cout << "Path to the 'dataset/' folder: " << path << endl;
  auto output_file = ofstream (outPath + "/tim/result.csv");


  for (int i = 1; i < 6; ++i) {
    for (int j = 0; j < 10; ++j) {
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

      TimSort::sort(arr, vectorSize);

      const auto time_point_after = chrono::steady_clock::now();

      // переводим время в наносекунды
      const auto time_diff = time_point_after - time_point_before;
      const auto time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

      output_file <<time_elapsed_ns/1000
                  <<","<<endl;
      vect.clear();
    }
    output_file<<""<<endl;
  }

  return 0;
}


