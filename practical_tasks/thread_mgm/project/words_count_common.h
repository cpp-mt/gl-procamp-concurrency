#pragma once

#include <string>
#include <unordered_map>
#include <algorithm>

using WordCountMapType = std::unordered_map<std::string, std::size_t>; 

void words_in_file(const std::string& fileName, WordCountMapType& wordCounts);
WordCountMapType words_in_file(const std::string& fileName);

template<typename MapIt> // print n most common words in [begin, end)
std::vector<WordCountMapType::value_type> get_common_words(MapIt begin, MapIt end, const std::size_t limit) 
{
    std::vector<MapIt> wordIters;
    wordIters.reserve(std::distance(begin, end));
    for (auto i = begin; i != end; ++i)
    {
        wordIters.push_back(i);
    }
    auto sortedRangeEnd = wordIters.begin() + limit;
    std::partial_sort(wordIters.begin(), sortedRangeEnd, wordIters.end(),
                [](MapIt it1, MapIt it2){ return it1->second > it2->second; });

    std::vector<WordCountMapType::value_type> pairs;
    for (auto it = wordIters.cbegin(); it != sortedRangeEnd; ++it)  // Cx11: cbegin
    {
        pairs.push_back(*(*it));
    }
    return pairs;
}

