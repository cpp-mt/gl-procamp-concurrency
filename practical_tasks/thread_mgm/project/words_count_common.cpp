#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "words_count_common.h"

// for each word in file, return  # of occurrences
void words_in_file(const std::string& fileName, 
                   WordCountMapType& wordCounts)
{
    std::ifstream file(fileName);
    for (std::string word; file >> word; )
    {
        ++wordCounts[word];
    }
}

WordCountMapType words_in_file(const std::string& fileName)
{
    WordCountMapType wordCounts;
    std::ifstream file(fileName);
    for (std::string word; file >> word; )
    {
        ++wordCounts[word];
    }
    return wordCounts;
}

