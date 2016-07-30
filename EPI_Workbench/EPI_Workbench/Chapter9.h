#pragma once
// 9.1, 9.9, (9.2, 9.10)

#include <stack>
#include <vector>
#include <memory>
#include <queue>

// 9.1

template <typename T>
struct MyStack
{
    std::stack<T> vals;
    std::stack<T> maxVals;
    void Push(T val) {
        if (maxVals.empty() || val >= maxVals.top()) {
            maxVals.push(val);
        }
        vals.push(val);
    }
    T Pop() {
        auto r = vals.top();
        if (!maxVals.emtpy() && maxVals.top() == r) {
            maxVals.pop();
        }
        vals.pop();
        return r;
    }
    T Max() {
        return maxVals.top();
    }

};

// 9.9

template <typename T>
struct BinaryTreeNode
{
    T data;
    std::unique_ptr<BinaryTreeNode<T>> left, right;
    BinaryTreeNode<T>* parent;
};

std::vector<std::vector<int>> BinaryTreeDepthOrder(const std::unique_ptr<BinaryTreeNode<int>>& tree)
{
    std::queue<BinaryTreeNode<int>*> children;
    std::vector<std::vector<int>> ret;

    if (tree == nullptr) return ret;

    children.push(tree.get());

    while (!children.empty())
    {
        std::vector<int> curDepthVals;
        size_t childrenSize = children.size();
        for (size_t i = 0; i < childrenSize; ++i)
        {
            auto node = children.front();
            children.pop();
            if (node != nullptr)
            {
                curDepthVals.push_back(node->data);
                children.push(node->left.get());
                children.push(node->right.get());
            }
        }
        if (!curDepthVals.empty())
            ret.push_back(curDepthVals);
    }

    return ret;
}