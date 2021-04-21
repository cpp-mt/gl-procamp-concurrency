#include <algorithm>
#include <ctime>
#include <iostream>

// 1mln takes more than 100secs
#define LOOP 100000

void sorted_data_with_branch() {
  std::cout << "Sorted Data with branch: ";
  // Generate data
  const unsigned arraySize = 32768;
  int data[arraySize];
  for (unsigned c = 0; c < arraySize; ++c)
    data[c] = std::rand() % 256;
  std::sort(data, data + arraySize);
  clock_t start = clock();
  long long sum = 0;
  for (unsigned i = 0; i < LOOP; ++i)
  {
    for (unsigned c = 0; c < arraySize; ++c)
    {
      if (data[c] >= 128)
        sum += data[c];
    }
  }
  double elapsedTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
  std::cout << elapsedTime << " seconds " << std::endl;
}
void unsorted_data_with_branch() {
  std::cout << "Unsorted data with branch: ";
  const unsigned arraySize = 32768;
  int data[arraySize];
  for (unsigned c = 0; c < arraySize; ++c)
    data[c] = std::rand() % 256;
  clock_t start = clock();
  long long sum = 0;
  for (unsigned i = 0; i < LOOP; ++i)
  {
    for (unsigned c = 0; c < arraySize; ++c)
    {
      if (data[c] >= 128)
        sum += data[c];
    }
  }
  double elapsedTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
  std::cout << elapsedTime << " seconds" << std::endl;
}

int main() {
  sorted_data_with_branch();
  unsorted_data_with_branch();
  return 0;
}
