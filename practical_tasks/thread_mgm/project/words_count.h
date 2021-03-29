#include <vector>
#include <string>
#include "words_count_common.h"

std::vector<WordCountMapType::value_type>
word_count_st(const std::vector<std::string>& filenames, size_t limit);

std::vector<WordCountMapType::value_type>
word_count_mt(const std::vector<std::string>& filenames, size_t limit);

