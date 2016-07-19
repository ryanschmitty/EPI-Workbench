#pragma once

#include <memory>
#include <cassert>
#include <iostream>

struct Node
{
    int data;
    Node* next;
};

Node* AllocateList(int size)
{
    // Validate input
    if (size < 1) return nullptr;

    // Create head of list (track so we can return it)
    Node* pHead = new Node;
    pHead->data = 0;
    pHead->next = nullptr;
    
    // Create remainder of list
    Node* pCur = pHead;
    for (int i = 1; i < size; i++)
    {
        // Allocate new node
        pCur->next = new Node;
        // Update current and initialize
        pCur = pCur->next;
        pCur->data = i;
        pCur->next = nullptr;
    }

    return pHead;
}

void PrintList(Node* pNode)
{
    for (size_t i = 0; pNode != nullptr; i++)
    {
        std::cout << "<i=" << i << ",data=" << pNode->data << ">" << std::endl;
        pNode = pNode->next;
    }
}

void DeallocateList(Node* pNode)
{
    while (pNode != nullptr)
    {
        Node* pNext = pNode->next;
        delete pNode;
        pNode = pNext;
    }
}

Node* RemoveLast(Node* pNode)
{
    // Validate input
    if (pNode == nullptr || pNode->next == nullptr) return pNode;

    // Get pointers to Last and Next-to-last
    Node* pLast = pNode;
    Node* pNextToLast = nullptr;
    while (pLast->next != nullptr)
    {
        pNextToLast = pLast;
        pLast = pLast->next;
    }

    // Remove pLast
    assert(pNextToLast->next == pLast);
    pNextToLast->next = nullptr;

    return pLast;
}

void Insert(Node* pCur, Node* pNew)
{
    if (pCur == nullptr || pNew == nullptr) return;
    pNew->next = pCur->next;
    pCur->next = pNew;
}

void Zipper(Node* pNode)
{
    while (pNode != nullptr)
    {
        // Remove Last
        Node* pLast = RemoveLast(pNode);

        // Insert Last after current
        Insert(pNode, pLast);

        // advance to the next node (the one after the new location of pLast)
        pNode = pLast->next;
    }
}

// Zippering a linked list
void DoZipper()
{
    Node* pHead = AllocateList(10);
    PrintList(pHead);
    Zipper(pHead);
    PrintList(pHead);
    DeallocateList(pHead);
}
