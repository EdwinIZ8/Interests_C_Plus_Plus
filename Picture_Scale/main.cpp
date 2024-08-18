/*
    功能：图片批量缩放
    作者：张家馨
    备注：用到了OpenCV库
*/


#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

int main(int argc, char* argv[])
{
    /* 方法一
    // 输入图片宽度
    int nWidth;
    std::cout << "请输入图片宽度：" << std::endl;
    std::cin >> nWidth;

    for (int i = 1; i <= argc; i++) {
        cv::Mat input, output;
        // 打开图片
        input = cv::imread(argv[i]);
        int cols, rows;
        cols = input.cols;
        rows = input.rows;
        // 缩放图片
        cv::Size dsize = cv::Size(nWidth, (int)(nWidth * rows / cols));
        cv::resize(input, output, dsize, 0, 0);
        // 保存图片
        cv::imwrite(argv[i], output);
        // 调试信息
        std::cout << argv[i] << "已保存为：" << nWidth << "×" << (int)(nWidth * rows / cols) << "像素。" << std::endl;
    }
    */
    /* 方法二 */
    int nWidth;
    std::cout << "最多支持89张图片"
              << "请输入图片宽度（像素）：" 
              << std::endl;
    std::cin >> nWidth;

    cv::Mat input, output;
    cv::String str = argv[1];
    while (true) {
        input = cv::imread(str);
        if (input.data == nullptr)
            break;

        cv::resize(input, output, cv::Size(nWidth, (int)(nWidth * input.rows / input.cols)), 0, 0);

        cv::imwrite(str, output);

        std::cout << str << "已保存为：" << nWidth << "×" << (int)(nWidth * input.rows / input.cols) << "像素。" << std::endl;

        int len = str.length();
        if (str[len - 5] < '9')
            str[len - 5]++;
        else {
            str[len - 6]++;
            str[len - 5] = '0';
        }
    }

    return 0;
}