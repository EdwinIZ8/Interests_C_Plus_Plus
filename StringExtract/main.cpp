/*
    功能：从文件里提取文字。比如：提取html文件里，所有<name>与</name>之间的文字。
    作者：张家馨
    时间：2024-03-15
*/

#include <iostream>
#include "fstream"
#include "string"
#include <vector>


void usage()
{
    std::cout << "程序：StringExtract" << std::endl
              << "功能：提取前缀和后缀之间的文字，然后保存在文件中。" << std::endl
              << "\t1.输入 “./StringExtract 文件名”" << std::endl
              << "\t2.输入要提取文字的前缀；" << std::endl
              << "\t3.输入要提取文字的后缀；" << std::endl
              << "\t4.告诉我你要把结果保存在哪；" << std::endl
              << "\t5.完成！" << std::endl;
}


// 字符串提取函数。从filename文件中，逐行提取前缀（prefix）与后缀（suffix）之间的字符串。
std::vector<std::string> stringExtract(char* filename, std::string &prefix, std::string &suffix)
{
    std::vector<std::string> result;
    std::ifstream infile(filename);
    if (!infile.is_open())
    {
        std::cout << "打开" << filename << "失败！" << std::endl;
        return result;
    }

    while (!infile.eof())
    {
        std::string line;
        std::getline(infile, line, '\n');
        auto start = line.find(prefix);
        if (start == std::string::npos)
            continue;
        else
        {
            size_t real_start = start + prefix.length();
            size_t end = line.find(suffix, real_start);
            std::string subString = line.substr(real_start, end - real_start);
            result.push_back(subString);
        }
    }
    return result;
}


int main(int argc, char* argv[]) {
    if (argc == 2)
    {
        std::string prefix, suffix;
        std::cout << "输入前缀：" << std::endl << "\t";
        std::cin >> prefix;
        std::cout << "输入后缀：" << std::endl << "\t";
        std::cin >> suffix;

        std::vector<std::string> result_of_extract = stringExtract(argv[1], prefix, suffix);

        std::string pathToSave;
        std::cout << "结果保存在哪？（绝对路径）" << std::endl << "\t";
        std::cin >> pathToSave;
        std::ofstream outfile(pathToSave);
        if (!outfile.is_open())
            std::cout << "保存失败！" << std::endl;
        for(auto &elem: result_of_extract)
            outfile << elem << std::endl;
        outfile.close();
    }
    else
        usage();

    return 0;
}