#pragma once
// 6.1, 6.7, 6.12, 6.18 (6.2, 6.17)

#include <vector>
#include <algorithm>

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