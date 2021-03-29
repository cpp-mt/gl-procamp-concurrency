#include <vector>
#include <string>

//#include "words_count_common.h"
#include "words_count.h"


int main(int argc, char** argv)
{
    std::vector<std::string> files;
    for (int argNum = 1; argNum < argc; ++argNum)
    {
        files.push_back(argv[argNum]);
    }
    auto res = word_count_st(files, 20);
    for (auto item : res)
    {
       std::printf(" %-10s%10zu\n", item.first.c_str(), item.second);
    }
}
