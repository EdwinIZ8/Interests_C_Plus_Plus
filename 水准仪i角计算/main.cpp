/*
 * 原理：
        1.采用AI1BI2法（第一次测站I1在前后尺之间；第二次测站I2在水准尺一侧，A是远尺，B是近尺。）
        2.每测站重复观测前后尺各4次

    解：
        设在测站I1上，A尺读数是a1，B尺读数是b1；在测站I2上，A尺读数是a2，B尺读数是b2；近标尺距离是D1，远标尺距离是D2。
        𝛥 = (a2-b2)-(a1-b1)
        ρ = 206265（″）
        i = 𝛥 * ρ / (D2 - D1) - 1.61 * 10^-5 * (D1 + D2)

    备注：
        计算过程中，长度单位统一换算成毫米。
 */
#include <iostream>
#include "vector"
#include "cmath"
using namespace std;

vector<double> a1(4), b1(4), a2(4), b2(4);
double delta, i, D1, D2, a1_average, b1_average, a2_average, b2_average;
const double rho = 206265;

// 输入观测数据
void input() {
    // 输入a1的4次观测值，单位：米
    cout << endl << "输入a1的4次观测值（m，回车分隔）:" << endl;
    cin >> a1[0];
    cin >> a1[1];
    cin >> a1[2];
    cin >> a1[3];
    // 输入b1的4次观测值，单位：米
    cout << endl << "输入b1的4次观测值（m，回车分隔）:" << endl;
    cin >> b1[0];
    cin >> b1[1];
    cin >> b1[2];
    cin >> b1[3];
    // 输入a2的4次观测值，单位：米
    cout << endl << "输入a2的4次观测值（m，回车分隔）:" << endl;
    cin >> a2[0];
    cin >> a2[1];
    cin >> a2[2];
    cin >> a2[3];
    // 输入a1的4次观测值，单位：米
    cout << endl << "输入b2的4次观测值（m，回车分隔）:" << endl;
    cin >> b2[0];
    cin >> b2[1];
    cin >> b2[2];
    cin >> b2[3];
    // 输入近尺距离D1，单位：米
    cout << endl << "输入近尺距离D1（单位：米；范围：5～7米）:" << endl;
    cin >> D1;
    if (D1 < 5 || D1 > 7) {
        cout << "近尺距离不在5～7米范围内。" << endl;
        exit(EXIT_FAILURE);
    }
    // 输入远尺距离D2，单位：米
    cout << endl << "输入远尺距离D2（单位：米；范围40～50米）:" << endl;
    cin >> D2;
    if (D2 < 40 || D2 > 50) {
        cout << "远尺距离不在40～50米范围内。" << endl;
        exit(EXIT_FAILURE);
    }
}

// 计算i角大小（单位：秒）
double calculate() {
    a1_average = (a1[0] + a1[1] + a1[2] + a1[3]) / 4; // 单位：米
    b1_average = (b1[0] + b1[1] + b1[2] + b1[3]) / 4; // 单位：米
    a2_average = (a2[0] + a2[1] + a2[2] + a2[3]) / 4; // 单位：米
    b2_average = (b2[0] + b2[1] + b2[2] + b2[3]) / 4; // 单位：米
    delta = ((a2_average - b2_average) - (a1_average - b1_average)) * 1000; // 单位：毫米
    i = delta / 1000 * rho / (D2 - D1) - 1.61 * pow(10.0, -5.0) * (D1 + D2) * 1000; // 单位：秒
    return i;
}

// 显示计算过程和结果，四舍五入保留两位小数
void show() {
    cout << endl << "计算结果：" << endl;
    cout << "  a1平均值是（m）：\t" << a1_average << endl;
    cout << "  b1平均值是（m）：\t" << b1_average << endl;
    cout << "  a2平均值是（m）：\t" << a2_average << endl;
    cout << "  b2平均值是（m）：\t" << b2_average << endl;
    cout << "  以下是四舍五入的结果，保留两位小数。" << endl;
    double delta_a1_b1 = (a1_average - b1_average) * 1000;
    cout << "  高差(a1 - b1)是（mm）：\t" << round(delta_a1_b1 * 100) / 100 << endl;
    double delta_a2_b2 = (a2_average - b2_average) * 1000;
    cout << "  高差(a2 - b2)是（mm）：\t" << round(delta_a2_b2 * 100) / 100 << endl;
    cout << "  delta等于（mm）：\t" << round(delta * 100) / 100 << endl;
    cout << "  i角等于（″）：\t" << round(i * 100) / 100 << endl;
}

int main() {
    cout << "功能：用AI1BI2法，计算水准仪i角；\n"
         << "作者：张家馨。\n"
         << "说明：\n"
         << "\tA是远尺，B是近尺。\n\t先把水准仪架设在两尺中间，对A尺读4次数，再对B尺读4次数；再把水准仪架设在B尺一侧，对A尺读4次数，对B尺读4次数。"
         << endl;
    // 输入观测数据
    input();
    // 计算水准仪i角
    calculate();
    // 显示计算过程和结果
    show();
    return 0;
}
