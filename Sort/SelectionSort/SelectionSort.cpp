// @Author: oxc
// @LastEditors: oxc
// @Date: 2021-10-13 11:29:37
// @LastEditTime: 2021-10-13 12:00:03
// @Description: 实现选择排序算法
// @FilePath: \SelectionSort\SelectionSort.cpp

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// 选择排序
// 选择排序不是稳定的排序算法
// 最好时间复杂度 O(n^2)，最坏时间复杂度 O(n^2)
void SelectionSort(vector<int>& v) {
    if (v.size() <= 1)
        return;
    
    for (int i = 0; i < v.size() - 1; i++) {
        int minIndex = i;

        // 找出未排序区的最小值
        for (int j = i + 1; j < v.size(); j++) {
            if (v[minIndex] > v[j])
                minIndex = j;
        }

        // 交换数据
        std::swap(v[i], v[minIndex]);
    }
}

int main(int argc, char* argv[])
{
    vector<int> v{1, 5, 16, 2, 78, 3, 4, 55};
    
    // 排序前
    cout << "Before ordering...\n";
    for (const auto& i: v)
        cout << i << "\n";
    
    SelectionSort(v);
    cout << "\n";

    // 排序后
    cout << "After ordering...\n";
    for (const auto& i: v)
        cout << i << "\n";


    return 0;
}