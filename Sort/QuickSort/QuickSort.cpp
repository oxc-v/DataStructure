// @Author: oxc
// @LastEditors: oxc
// @Date: 2021-10-26 10:24:23
// @LastEditTime: 2021-10-26 12:28:40
// @Description: 快速排序

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// 快速排序算法
// 快速排序是不稳定的排序算法
// 快速排序的最优时间复杂度和平均时间复杂度为O(nlogn)，最坏时间复杂度为O(n^2) 
void QuickSort(vector<int>& v, int left, int right) 
{
    if (left > right) { return; }

    auto l = left;
    auto r = right;
    auto tmp = v[left];

    while (l < r) {
        //从右往左扫描，找到第一个比基准元素小的元素
        while (l < r && tmp <= v[r]) { --r; }
        v[l] = v[r];

        //从左往右扫描，找到第一个比基准元素大的元素
        while (l < r && tmp >= v[l]) { ++l; }
        v[r] = v[l];
    }

    // 基准元素归位
    v[r] = tmp;

    // 对基准元素左边的元素进行递归排序
    QuickSort(v, left, l - 1);

    // 对基准元素右边的元素进行递归排序
    QuickSort(v, r + 1, right);
}

int main(int argc, char* argv[])
{
    vector<int> v{1, 3, 2, 6, 8, 9, 1, 2, 32, 53, 73, 834, 3, 212, 34};
    
    // 排序前
    cout << "Before ordering...\n";
    for (const auto& i: v)
        cout << i << "\n";
    
    QuickSort(v, 0, v.size() - 1);
    cout << "\n";

    // 排序后
    cout << "After ordering...\n";
    for (const auto& i: v)
        cout << i << "\n";


    return 0;
}