#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream
#include <vector>
#include <algorithm>

#include "merge_sort.hpp"
#include "tim_sort.hpp"

using namespace std;
using namespace itis;


static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kOutputPath = string_view{PROJECT_OUTPUT_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

int main() {

  const auto path = string(kDatasetPath);
  const auto outPath = string(kOutputPath);
  cout << "Path to the 'dataset/' folder: " << path << endl;

  for (int i = 1; i < 6; ++i) {
    auto output_file = ofstream (outPath + "/tim/TestCase" + to_string(i) + ".csv");
    for (int j = 0; j < 10; ++j) {
      auto input_file = ifstream(path + "/TestCase" + to_string(i) +"/TestData"+ to_string(j) + ".csv");
      vector<int> vect;
      string line;
      if (input_file) {
        while(getline(input_file, line, ',')){
          vect.push_back(stoi(line));
        }
      }
      int vectSize = vect.size();
      int *arr = new int[vectSize];
      for (int k = 0; k <vectSize; ++k) {
        arr[k] = vect[k];
      }
      const auto time_point_before = chrono::steady_clock::now();

      TimSort::sort(arr, vectSize);

      const auto time_point_after = chrono::steady_clock::now();

      // переводим время в наносекунды
      const auto time_diff = time_point_after - time_point_before;
      const auto time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

      output_file << time_elapsed_ns<<","<<endl;
      vect.clear();
    }
  }

  return 0;
}



