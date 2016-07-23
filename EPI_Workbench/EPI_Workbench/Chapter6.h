#pragma once
// 6.1, 6.7, 6.12, 6.18 (6.2, 6.17)

#include <vector>
#include <algorithm>
#include <random>

// 6.1, dutch national flag
template <typename T>
void dutchRearrange(std::vector<T>& arr, uint32_t pivotIndex)
{
    // validate input
    if (arr.size() < 2) return;
    if (pivotIndex > (arr.size() - 1)) return;

    // move pivot to front
    std::swap(arr[pivotIndex], arr[0]);
    pivotIndex = 0;

    // for all values
    uint32_t backIndex = arr.size() - 1;
    for (uint32_t i = 1; i < (backIndex + 1);)
    {
        if (arr[i] <= arr[pivotIndex])
        {
            std::swap(arr[pivotIndex], arr[i]);
            pivotIndex = i++;
        }
        else if (arr[i] > arr[pivotIndex])
        {
            std::swap(arr[i], arr[backIndex--]);
        }
    }
}

// 6.7 optimal buy and sell of stock prices
std::pair<int, int> findBestBuySellPair(const std::vector<int>& stockPrices)
{
    // validate input
    if (stockPrices.size() < 2) return{ 0,0 };

    // initialize stocks
    std::pair<int, int> stocks{ stockPrices[0], stockPrices[1] };
    int minPriceSeen = stockPrices[0];

    for (const auto& curPrice : stockPrices)
    {
        if (curPrice - minPriceSeen > stocks.second - stocks.first)
            stocks = std::make_pair(minPriceSeen, curPrice);

            minPriceSeen = std::min(curPrice, minPriceSeen);
    }

    return stocks;
}

int longestSubarrayLength(const std::vector<int>& vec)
{
    if (vec.empty()) return 0;

    int curLength = 0, longestLength = 0, previousVal = vec[0];

    for (const auto& val : vec)
    {
        if (val == previousVal)
            ++curLength;
        else
            curLength = 1;
        longestLength = std::max(longestLength, curLength);
        previousVal = val;
    }

    return longestLength;
}

// 6.12, sample offline data
// rand() isn't very good, and % N only really even comes close to working if RAND_MAX is evenly divisible by N (think of shrinking down the input into unevenly sized buckets)
template <typename T>
std::vector<T> sample(std::vector<T>& vec, const size_t length)
{
    if (vec.empty()) return;

    std::random_device rd;
    std::mt19937 gen(rd());

    size_t remainder = vec.size();
    for (size_t i = 0; i < length-1; ++i)
    {
        size_t chosenIndex = std::uniform_int_distribution<T>(i, remainder - 1)(gen);
        std::swap(vec[i], vec[i + chosenIndex]);
    }
}

// 6.18, Compute Spiral Ordering
std::vector<int> spiralOrdering(const std::vector<std::vector<int>>& cube)
{
    std::vector<int> spiralOrder{};
    size_t start = 0;
    size_t total = (cube.size()-(2*start)-1) * 4;
    while (2*start < cube.size()-1)
    {
        size_t x = start, y = start;
        // top
        for (; x < (total/4)+start; ++x)
            spiralOrder.push_back(cube[x][y]);
        // right
        for (; y < (total/4)+start; ++y)
            spiralOrder.push_back(cube[x][y]);
        // bottom
        for (; x > start; --x)
            spiralOrder.push_back(cube[x][y]);
        // left
        for (; y > start; --y)
            spiralOrder.push_back(cube[x][y]);
        start += 1;
        total = (cube.size()-(2*start)-1) * 4;
        if (total == 0) spiralOrder.push_back(cube[start][start]);
    }
    return spiralOrder;
}
