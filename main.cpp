/*
 * Created by 张家馨 on 2024/8/18.
 * 这是主程序。
 */
#include "Picture_Scale/Picture_Scale.cpp"
#include "StringExtract/StringExtract.cpp"
#include "水准仪i角计算/Calculate_i.cpp"

int main(int argc, char* argv[]) {
    // 提示
    std::cout << "输入数字：\n"
              << "\t1. 图片缩放\n"
              << "\t2. 文字提取\n"
              << "\t3. 计算水准仪i角\n";
    // 选择功能
    int flag = 1;
    std::cin >> flag;
    switch (flag) {
        case 1:
            picture_scale(argc, argv); // 1.图片缩放
            break;
        case 2:
            string_extract(argc, argv); // 2.提取文字
            break;
        case 3:
            calculate_i(); // 3.计算水准仪i角
            break;
        default:
            std::cout << "输入错误！" << std::endl;
            break;
    }

    return 0;
}