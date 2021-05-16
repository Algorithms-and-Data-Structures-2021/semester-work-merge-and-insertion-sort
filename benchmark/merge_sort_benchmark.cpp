#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream

#include "merge_sort.hpp"

using namespace std;
using namespace itis;


static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

int main() {

  const auto path = string(kDatasetPath);
  cout << "Path to the 'dataset/' folder: " << path << endl;

  auto input_file = ifstream(path + "/dataset-example.csv");

  if (input_file) {
    // чтение и обработка набора данных ...
  }


  const auto time_point_before = chrono::steady_clock::now();

  // здесь находится участок кода, время которого необходимо замерить

  const auto time_point_after = chrono::steady_clock::now();

  // переводим время в наносекунды
  const auto time_diff = time_point_after - time_point_before;
  const auto time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

  cout << "Time elapsed (ns): " << time_elapsed_ns << '\n';

  return 0;
}

