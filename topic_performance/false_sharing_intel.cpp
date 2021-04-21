#include <thread>
#include <chrono>
#include <random>
#include <numeric>
#include "time_logger.h"


/*

double sum=0.0, sum_local[NUM_THREADS];
#pragma omp parallel num_threads(NUM_THREADS)
{
 int me = omp_get_thread_num();
 sum_local[me] = 0.0;

 #pragma omp for
 for (i = 0; i < N; i++)
 sum_local[me] += x[i] * y[i];

 #pragma omp atomic
 sum += sum_local[me];
}

*/

const int threads_no = 4;

   
double sum=0.0;
double sum_local[threads_no];

const int N = 1000000;
double x[N];
double y[N];

int foo(int index) {

   sum_local[index] = 0.0;

   for (int i = 0; i < N; i++) {
      sum_local[index] += x[i] * y[i];
   }
}



void init_rand(int* x, int* y) {
	// random values
	std::random_device seed;
	std::mt19937 engine(seed());
	std::uniform_int_distribution<> uniformDist(1, 10);


   for (int i = 0; i < N; i++) {
      x[i] = uniformDist(engine);
      y[i] = uniformDist(engine);
   }
}

int main() {
   double sum=0.0;
   double sum_local[threads_no];

   {
   TimeLogger log("eliminate false sharing");
   std::vector<std::thread> pool;
   for (int i = 0; i < threads_no; i++) {
      pool.emplace_back(foo, i);
   }
   for (auto& t: pool) {
      t.join();
   }
   } 
}
