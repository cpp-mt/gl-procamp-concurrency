#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "words_count_common.h"
#include "time_logger.h"

// take list of file names on command line,
// returns <limit> most common words within;
std::vector<WordCountMapType::value_type> word_count_st(const std::vector<std::string>& filenames, 
		                                        size_t limit)
{
   std::vector<WordCountMapType> results(filenames.size());
   WordCountMapType wordCounts;
   { 
      TimeLogger log("single-threaded word_count");
      for (size_t i = 0; i < filenames.size(); ++i)
      {
         words_in_file(filenames[i], results[i]);
      }
      for (auto& r : results) 
      {
         for (auto& wordCount : r)
         {
            wordCounts[wordCount.first] += wordCount.second;
         }
      }
   }
   std::cout << wordCounts.size() << " words found\n" ;


   return get_common_words(wordCounts.begin(), wordCounts.end(), 
                           std::min(wordCounts.size(), limit));
}
