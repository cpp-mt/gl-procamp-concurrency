#include <algorithm>
#include <numeric>
#include <vector>
#include "time_logger.h"

long long accumulate_list_st(const std::vector<int>& randValues)
{
  TimeLogger log("single-thread accumulate list");
  return  std::accumulate(randValues.begin(),randValues.end(), 0LL);
}
