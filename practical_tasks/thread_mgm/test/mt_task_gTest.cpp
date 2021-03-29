// Copyright 2018, GlobalLogic Inc.
// All rights reserved.
//

#include "counter.h"
#include "words_count.h"
#include "accumulate_list.h"

#include "gtest/gtest.h"


const char* filenames[] = {
 "../texts/alice.txt", 
 "../texts/dracula.txt", 
  "../texts/sherlock.txt", 
  "../texts/tom.txt"};

struct WCData
{
   const char* word;
   size_t count;
};

WCData test_data[]=
{ 
  {"the", 17784},
  {"and", 12084},
  {"to", 9617},
  {"of", 8453},
  {"I", 7943},
  {"a", 7873},
  {"in", 5364},
  {"that", 4873},
  {"was", 4605},
  {"he", 3866}
};


TEST(MtTask, word_count_performance_st)
{
   std::vector<std::string> params;
   params.assign (std::begin(filenames), std::end(filenames)); 
   
   auto res = word_count_st(params, 10);
   ASSERT_EQ (res.size(), 10);
   for (int i = 0; i < 10; ++i)
   {
      EXPECT_STREQ(res[i].first.c_str(), test_data[i].word);
      EXPECT_EQ(res[i].second, test_data[i].count);
   }
}

TEST(MtTask, word_count_performance_mt)
{
   std::vector<std::string> params;
   params.assign(std::begin(filenames), std::end(filenames)); 
   auto res = word_count_mt(params, 10);
   ASSERT_EQ (res.size(), 10);
   for (int i = 0; i < 10; ++i)
   {
      EXPECT_STREQ(res[i].first.c_str(), test_data[i].word);
      EXPECT_EQ(res[i].second, test_data[i].count);
   }
}

TEST(MtTask, word_count_st_vs_mt)
{
   std::vector<std::string> params;
   params.assign(std::begin(filenames), std::end(filenames)); 
   auto res_st = word_count_st(params, 10);
   auto res_mt = word_count_mt(params, 10);
   EXPECT_EQ(res_st, res_mt);
}

TEST(MtTask, counter_st)
{
   int iterations = 400000;
   int res = count_st(400000);
   EXPECT_EQ(res, iterations);
}

TEST(MtTask, counter_mt)
{
   int iterations = 400000;
    // run counter mt test 5 iterations
   for (int i = 0; i < 5; i++)
   {
      int res = count_mt(400000);
      EXPECT_EQ(res, iterations);
   }
}

TEST(MtTask, accumulate_list_mt_vs_st)
{
   std::vector<int> list = init_random(100000000);
   long long res_st = accumulate_list_st(list);
   long long res_mt = accumulate_list_mt(list);
   EXPECT_EQ(res_st, res_mt);
}

TEST(MtTask, accumulate_list_performance_st)
{
   std::vector<int> list = init_random(100000000);
   long long res_st = accumulate_list_st(list);
   ASSERT_TRUE(res_st != 0);
}   

TEST(MtTask, accumulate_list_performance_mt)
{
   std::vector<int> list = init_random(100000000);
   long long res_mt = accumulate_list_mt(list);
   ASSERT_TRUE(res_mt != 0);
}

int main(int argc, char **argv)
{
    printf("Running main() from mt_task_gTest.cpp\n");

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
