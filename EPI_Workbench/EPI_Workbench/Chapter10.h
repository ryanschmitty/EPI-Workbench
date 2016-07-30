#pragma once
// 10.1, 10.4, (10.2, 10.10)

#include <memory>
#include "Chapter9.h"

std::unique_ptr<BinaryTreeNode<int>> GetChapter10Tree()
{
    // depth 0
    std::unique_ptr<BinaryTreeNode<int>> tree(new BinaryTreeNode<int>{ 314 });
    // depth 1
    tree->left = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 6 });
    tree->left->parent = tree.get();
    tree->right = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 6 });
    tree->right->parent = tree.get();
    // depth 2
    tree->left->left = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 271 });
    tree->left->left->parent =
    tree->left.get();
    tree->left->right = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 561 });
    tree->left->right->parent =
    tree->left.get();
    tree->right->left = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 2 });
    tree->right->left->parent =
    tree->right.get();
    tree->right->right = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 271 });
    tree->right->right->parent =
    tree->right.get();
    // depth 3
    tree->left->left->left = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 28 });
    tree->left->left->left->parent =
    tree->left->left.get();
    tree->left->left->right = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 0 });
    tree->left->left->right->parent =
    tree->left->left.get();
    tree->left->right->right = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 3 });
    tree->left->right->right->parent =
    tree->left->right.get();
    tree->right->left->right = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 1 });
    tree->right->left->right->parent =
    tree->right->left.get();
    tree->right->right->right = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 28 });
    tree->right->right->right->parent =
    tree->right->right.get();
    // depth 4
    tree->left->right->right->left = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 17 });
    tree->left->right->right->left->parent =
    tree->left->right->right.get();
    tree->right->left->right->left = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 401 });
    tree->right->left->right->left->parent =
    tree->right->left->right.get();
    tree->right->left->right->right = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 257 });
    tree->right->left->right->right->parent =
    tree->right->left->right.get();
    // depth 5
    tree->right->left->right->left->right = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 641 });
    tree->right->left->right->left->right->parent =
    tree->right->left->right->left.get();

    return tree;
}

std::unique_ptr<BinaryTreeNode<int>> GetBalancedTree()
{
    // depth 0
    std::unique_ptr<BinaryTreeNode<int>> tree(new BinaryTreeNode<int>{ 'a' - 'a' });
    // depth 1
    tree->left  = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 'b' - 'a' });
    tree->right = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 'k' - 'a' });
    // depth 2
    tree->left->left  = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 'c' - 'a' });
    tree->left->right = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 'h' - 'a' });
    tree->right->left  = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 'l' - 'a' });
    tree->right->right = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 'o' - 'a' });
    // depth 3
    tree->left->left->left  = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 'd' - 'a' });
    tree->left->left->right = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 'g' - 'a' });
    tree->left->right->left  = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 'i' - 'a' });
    tree->left->right->right = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 'j' - 'a' });
    tree->right->left->left  = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 'm' - 'a' });
    tree->right->left->right = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 'n' - 'a' });
    // depth 4
    tree->left->left->left->left  = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 'e' - 'a' });
    tree->left->left->left->right = std::unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>{ 'f' - 'a' });

    return tree;
}

bool IsLeafNode(const std::unique_ptr<BinaryTreeNode<int>>& node)
{
    return node && node->left == nullptr && node->right == nullptr;
}

size_t GetBinaryTreeHeight(const std::unique_ptr<BinaryTreeNode<int>>& tree)
{
    if (tree == nullptr || IsLeafNode(tree)) return 0;
    else return 1 + std::max(GetBinaryTreeHeight(tree->left), GetBinaryTreeHeight(tree->right));
}

// 10.1

struct BalanceStatusWithHeight { bool balanced; int height; };

BalanceStatusWithHeight CheckBalance(const std::unique_ptr<BinaryTreeNode<int>>& tree)
{
    if (tree == nullptr)
        return{ true, -1 };

    BalanceStatusWithHeight leftBalance  = CheckBalance(tree->left);
    if (!leftBalance.balanced)
        return{ false, 0 };

    BalanceStatusWithHeight rightBalance = CheckBalance(tree->right);
    if (!rightBalance.balanced)
        return{ false, 0 }; // returning 0 here so imbalanced trees don't have some random height value

    bool balanced = std::abs(leftBalance.height - rightBalance.height) <= 1;
    int height = std::max(leftBalance.height, rightBalance.height) + 1;
    return{ balanced, height };
}

bool IsBinaryTreeBalanced(const std::unique_ptr<BinaryTreeNode<int>>& tree)
{
    return CheckBalance(tree).balanced;
}

// 10.4
size_t GetDepth(const std::unique_ptr<BinaryTreeNode<int>>& node)
{
    size_t depth = 0;
    BinaryTreeNode<int>* aNode = node.get();
    while (aNode->parent != nullptr)
    {
        aNode = aNode->parent;
        ++depth;
    }
    return depth;
}

BinaryTreeNode<int>* FindLCA(const std::unique_ptr<BinaryTreeNode<int>>& nodeA, const std::unique_ptr<BinaryTreeNode<int>>& nodeB)
{
    size_t aDepth = GetDepth(nodeA);
    size_t bDepth = GetDepth(nodeB);
    BinaryTreeNode<int>* aNode = nodeA.get();
    BinaryTreeNode<int>* bNode = nodeB.get();
    while (aDepth > bDepth)
    {
        aNode = aNode->parent;
        --aDepth;
    }
    while (bDepth > aDepth)
    {
        bNode = bNode->parent;
        --bDepth;
    }
    while (aNode != bNode)
    {
        aNode = aNode->parent;
        bNode = bNode->parent;
    }
    return aNode;
}
