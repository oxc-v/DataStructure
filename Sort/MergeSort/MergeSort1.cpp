// @Author: oxc
// @LastEditors: oxc
// @Date: 2021-10-26 10:24:23
// @LastEditTime: 2021-10-26 12:28:40
// @Description: 实现归并排序(递归)
// @FilePath: \MergeSort\MergeSort.cpp

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

// 合并两个有序区
void Merge(vector<int>& v, const int low, const int mid, const int high) {
    int i = low;
    int j = mid + 1;

    // 暂存数组 
    int k = 0;
    vector<int> temp;

    temp.resize(high - low + 1);

    while (i <= mid && j <= high) {
        if (v[i] <= v[j])
            temp[k++] = v[i++];
        else 
            temp[k++] = v[j++];
    }

    // 检查有序区是否有剩余没合并的
    while (i <= mid)
        temp[k++] = v[i++];

    while (j <= high)
        temp[k++] = v[j++];

    // 转移数组
    for (i = low, k = 0; i <= high; i++, k++)
        v[i] = temp[k];
}

// 归并排序
// 最坏、最好、平均复杂度O(nlogn)
// 稳定的排序算法
void MergeSort(vector<int>& v, const int low, const int high) {

    // 常规用法
    // if (low >= high) {
    //     return;
    // }

    // 优化算法，当数组长度比较小时，使用插入排序算法，减少小规模问题的方法调用
    if (high - low <= 10) {
        InsertionSort(v);
        return;
    }

    const int mid = low + (high - low) / 2;

    // 分
    MergeSort(v, low, mid);
    MergeSort(v, mid + 1, high);
    
    // 避免不必要的合并
    if (v[mid] <= v[mid + 1])
        return;
    
    // 治
    Merge(v, low, mid, high);
}

int main(int argc, char* argv[])
{
    vector<int> v{1, 3, 2, 6, 8, 9, 1, 2, 32, 53, 73, 834, 3, 212, 34};
    
    // 排序前
    cout << "Before ordering...\n";
    for (const auto& i: v)
        cout << i << "\n";
    
    MergeSort(v, 0, v.size() - 1);
    cout << "\n";

    // 排序后
    cout << "After ordering...\n";
    for (const auto& i: v)
        cout << i << "\n";


    return 0;
}