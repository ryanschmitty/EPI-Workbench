#pragma once
#include <stack>

// 8.1, 8.2, 8.4, (8.5, 8.8)

template <typename T>
struct ListNode {
    T data;
    std::shared_ptr<ListNode<T>> next;
};

// 8.1
std::shared_ptr<ListNode<int>> MergeSortedLists(std::shared_ptr<ListNode<int>> listA, std::shared_ptr<ListNode<int>> listB)
{
    std::shared_ptr<ListNode<int>> head(new ListNode<int>);
    auto tail = head;

    auto AppendNode = [&tail](std::shared_ptr<ListNode<int>>& node)
    {
        tail->next = std::shared_ptr<ListNode<int>>(new ListNode<int>{node->data});
        tail = tail->next;
        node = node->next;
    };

    while (listA && listB)
    {
        AppendNode(listA->data < listB->data ? listA : listB);
    }
    tail->next = listA ? listA : listB;
    return head->next;
}

// 8.2
std::shared_ptr<ListNode<int>> ReverseList(std::shared_ptr<ListNode<int>> node)
{
    std::shared_ptr<ListNode<int>> prev{};
    while (node)
    {
        auto next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }
    return prev;
}

// 8.4
std::shared_ptr<ListNode<int>> hasCycle(const std::shared_ptr<ListNode<int>>& head)
{
    auto fastNode = head, slowNode = head;
    while (fastNode && fastNode->next && fastNode->next->next)
    {
        slowNode = slowNode->next;
        fastNode = fastNode->next->next;
        if (slowNode == fastNode)
        {
            // get cycle length
            int cycleLength = 0;
            do
            {
                ++cycleLength;
                fastNode = fastNode->next;
            } while (slowNode != fastNode);
            // advance a fwd iterator by cycle-length
            auto fwdIter = head;
            while (cycleLength--)
            {
                fwdIter = fwdIter->next;
            }
            // start advacing two iterators until equal
            auto iter = head;
            while (fwdIter != iter)
            {
                fwdIter = fwdIter->next;
                iter = iter->next;
            }
            return iter;
        }
    }
    return nullptr;
}
