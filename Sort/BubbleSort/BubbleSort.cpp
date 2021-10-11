// @Author: oxc
// @LastEditors: oxc
// @Date: 2021-10-11 20:03:40
// @LastEditTime: 2021-10-11 20:52:58
// @Description: 实现冒泡排序算法
// @FilePath: \BubbleSort\BubbleSort.cpp

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// 冒泡排序算法
// 冒气泡排序是稳定的排序算法

void BubbleSort(vector<int>& v) {
    if (v.size() <= 1)
        return;

    for (int i = 0; i < v.size(); i++) {
        // 判断是否发生数据交换
        bool isSwapData = false;
    
        for (int j = 0; j < v.size() - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                // 交换数据
                int tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;

                // 发生数据交换
                isSwapData = true;
            }
        }

        // 没有发生数据交换时，提前退出循环
        if (isSwapData == false) 
            break;
    }
}

int main(int argc, char* argv[])
{
    vector<int> v{3, 1, 4, 8, 9, 6, 10, 33, 2};
    
    // 排序前
    cout << "Before ordering...\n";
    for (const auto& i: v)
        cout << i << "\n";
    
    BubbleSort(v);
    cout << "\n";

    // 排序后
    cout << "After ordering...\n";
    for (const auto& i: v)
        cout << i << "\n";

    return 0;
}