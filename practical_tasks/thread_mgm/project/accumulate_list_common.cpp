#include <algorithm>
#include <numeric>
#include <random>
#include <vector>

std::vector<int> init_random(long long size)
{
  std::vector<int> randValues;
  randValues.reserve(size);

  // random values
  std::random_device seed;
  std::mt19937 engine(seed());
  std::uniform_int_distribution<> uniformDist(1,10);
  for ( long long i=0 ; i< size ; ++i)
  {
     randValues.push_back(uniformDist(engine));
  }
  return randValues;
}

