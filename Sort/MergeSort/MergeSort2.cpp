// @Author: oxc
// @LastEditors: oxc
// @Date: 2021-10-26 10:24:23
// @LastEditTime: 2021-10-26 12:28:40
// @Description: 实现归并排序(迭代)
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

// 归并排序
// 最坏、最好、平均复杂度O(nlogn)
// 稳定的排序算法
void MergeSort(vector<int>& v, std::size_t len) {
    // vector<int> v = v;
    vector<int> tmp;
    tmp.resize(len);

    for (std::size_t i = 1; i < len; i *= 2) {
        for (std::size_t j = 0; j < len; j += i * 2) {
            std::size_t low = j;
            std::size_t mid = std::min(j + i, len);
            std::size_t high = std::min(j + 2 * i, len);

            std::size_t start1 = low;
            std::size_t end1 = mid;
            std::size_t start2 = mid;
            std::size_t end2 = high;

            while (start1 < end1 && start2 < end2) {
                if (v[start1] <= v[start2]) {
                    tmp[low++] = v[start1++];
                } else {
                    tmp[low++] = v[start2++];
                }
            }

            while (start1 < end1) {
                tmp[low++] = v[start1++];
            }

            while (start2 < end2) {
                tmp[low++] = v[start2++];
            }
        }

        std::copy(tmp.begin(), tmp.end(), v.begin());
    }
}

int main(int argc, char* argv[])
{
    vector<int> v{1, 3, 2, 6, 8, 9, 1, 2, 32, 23, 53, 73, 834, 3, 212, 34};
    
    // 排序前
    cout << "Before ordering...\n";
    for (const auto& i: v)
        cout << i << "\n";
    
    MergeSort(v, v.size());
    cout << "\n";

    // 排序后
    cout << "After ordering...\n";
    for (const auto& i: v)
        cout << i << "\n";


    return 0;
}