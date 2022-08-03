// 实现广度优先搜索算法

#include <iostream>
#include <string>
#include <queue>
#include <memory>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::queue;
using std::shared_ptr;
using std::make_shared;

struct BiTree;
using BiTreePtr = shared_ptr<BiTree>;

struct BiTree
{
    int data;        // 节点数据
    BiTreePtr left;  // 左子节点
    BiTreePtr right; // 右子节点
};

int index = 0;
BiTreePtr createBiTree(const vector<int>& nodes)
{
    auto data = nodes[index++];
    if (data == 0)
        return nullptr;

    BiTreePtr root = make_shared<BiTree>();
    root->data = data;
    root->left = createBiTree(nodes);
    root->right = createBiTree(nodes);
    return root;
}

void BFSSearch(BiTreePtr root)
{
    queue<BiTreePtr> queue; // 存放待访问的结点
    queue.push(root);   // 放入初始结点

    BiTreePtr node; 
    while (!queue.empty()) {
        node = queue.front();
        queue.pop();
        cout << node->data << " ";
        if (node->left)
            queue.push(node->left);
        if (node->right)
            queue.push(node->right);
    }
}

int main(int argc, char* argv[])
{
    // 二叉树先序遍历序列,其中用0表示结点无左子树或无右子树
    vector<int> v{1, 3, 4, 0, 0, 5, 0, 0, 7, 0, 0};
    auto root = createBiTree(v);
    BFSSearch(root);

    return 0;
}