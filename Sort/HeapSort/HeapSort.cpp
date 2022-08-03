// @Author: oxc
// @LastEditors: oxc
// @Date: 2021-10-11 20:03:40
// @LastEditTime: 2021-10-12 08:32:00
// @Description: 实现堆排序算法
// @FilePath: \BubbleSort\BubbleSort.cpp

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// 调整大顶堆，使得堆顶元素为最大值
// 从下往上，从右往左调整
void adjustHeap(vector<int>& v, std::size_t i, std::size_t len) 
{
    // 从i结点的左结点开始，向下调整堆
    for (std::size_t j = i * 2 + 1; j < len; j = j * 2 + 1) {
        if (j + 1 < len && v[j] < v[j + 1])
            j++;

        // 此时i结点的值为左右子结点中较大的值，
        // 不用继续向下调整了
        if (v[i] > v[j])
            break;

        // 交换结点的值
        std::swap(v[i], v[j]);

        // 更改i结点的位置，继续向下调整
        i = j;
    }
}

// 堆排序算法
// 堆排序是不稳定的排序算法
// 时间复杂度O(nlog(n))，空间复杂度O(1)
void HeapSort(vector<int>& v)
{
    // 构建大顶堆
    for (int i = v.size() / 2 - 1; i >= 0; --i) {
        //从第一个非叶子结点从下至上，从右至左调整结构
        adjustHeap(v, i, v.size());
    }

    // 将堆顶元素与最后一个元素交换，然后调整堆
    for (int i = v.size() - 1; i > 0; --i) {
        std::swap(v[0], v[i]);
        adjustHeap(v, 0, i);
    }
}

int main(int argc, char* argv[])
{
    vector<int> v{59, 41, 39, 11, 13, 34, 48, 75, 6, 19, 9, 7};
    
    // 排序前
    cout << "Before ordering...\n";
    for (const auto& i: v)
        cout << i << "\n";
    
    HeapSort(v);
    cout << "\n";

    // 排序后
    cout << "After ordering...\n";
    for (const auto& i: v)
        cout << i << "\n";

    return 0;
}