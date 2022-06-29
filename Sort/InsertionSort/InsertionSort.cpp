// @Author: oxc
// @LastEditors: oxc
// @Date: 2021-10-12 09:38:38
// @LastEditTime: 2021-10-13 09:55:38
// @Description: 实现插入排序算法
// @FilePath: \InsertionSort\InsertionSort.cpp

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// 插入排序算法
// 插入排序是稳定的排序算法
// 最好时间复杂度 O(n)，最坏时间复杂度 O(n^2)
void InsertionSort(vector<int>& v) {
    if (v.size() <= 1)
        return;

    for (int i = 1; i < v.size(); i++) {
        int j = i - 1;
        int value = v[i];

        // 查找插入的位置
        for (; j >= 0; j--) {
            if (value < v[j]) {
                v[j + 1] = v[j];
            } else {
                break;
            }
        }

        // 插入数据
        v[j + 1] = value;
    }
}

int main(int argc, char* argv[])
{
    vector<int> v{1, 5, 16, 2, 78, 3, 4, 55};
    
    // 排序前
    cout << "Before ordering...\n";
    for (const auto& i: v)
        cout << i << "\n";
    
    InsertionSort(v);
    cout << "\n";

    // 排序后
    cout << "After ordering...\n";
    for (const auto& i: v)
        cout << i << "\n";

    return 0;
}