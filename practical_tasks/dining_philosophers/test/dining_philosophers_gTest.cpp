// Copyright 2018, GlobalLogic Inc.
// All rights reserved.
//


#include "gtest/gtest.h"
#include "dining_philosophers.h"
#include <future>
#include <thread>
#include <chrono>

#define ASSERT_DURATION_LE(secs, stmt) { \
	  std::promise<bool> completed; \
	  auto stmt_future = completed.get_future(); \
	  std::thread([&](std::promise<bool>& completed) { \
			      stmt; \
			          completed.set_value(true); \
				    }, std::ref(completed)).detach(); \
	  if(stmt_future.wait_for(std::chrono::seconds(secs)) == std::future_status::timeout) \
	    GTEST_FATAL_FAILURE_("       timed out (> " #secs \
			        " seconds). Check code for infinite loops"); \
}



void test_start_dining() {
   //std::cout.sync_with_stdio(true);
   std::vector<std::thread> pool;
   done = false;
   for (int i = 0; i < Philosophers_No; i++) {
       pool.emplace_back(philosopher, i);
   }
   // gives loop for 30 secs
   std::this_thread::sleep_for (std::chrono::seconds(15)); 
   done = true;
   for (auto& t : pool) {
       t.join();
   }
}

TEST(DiningPh, deadlock_free) {
   ASSERT_DURATION_LE(20, test_start_dining());
   ASSERT_EQ(true, true);
   for (int i = 0; i < Philosophers_No; ++i) {
       ASSERT_EQ (true, summary[i].eat_no > 0);
       ASSERT_EQ (true, summary[i].think_no > 0);
   }
}

/*
TEST(DiningPh, all_eat) {
   ASSERT_EQ (true, false);
}
*/


int main(int argc, char **argv) {
    printf("Running main() from dining_philosophers_gTest.cpp\n");

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
