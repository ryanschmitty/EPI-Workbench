#pragma once

#include <cctype>

// 7.1, 7.2, 7.4, (7.5, 7.6)

// 7.1
int parseInteger(const std::string& s)
{
    int result = 0;
    const bool neg = s[0] == '-';
    const int start = neg ? 1 : 0;
    for (size_t i = start; i < s.length(); ++i)
    {
        int v = static_cast<int>(s[i]) - static_cast<int>('0');
        if (v > 9 || v < 0) return 0;
        result += v;
        result *= 10;
    }
    return neg ? -result/10 : result/10;
}

// 7.2
std::string baseConvert(std::string& s, int b1, int b2)
{
    const bool isNeg = s[0] == '-';
    int base10 = 0;
    for (int i = isNeg ? 1 : 0; i < s.length(); ++i)
    {
        base10 *= b1;
        base10 += std::isdigit(s[i]) ? s[i] - '0' : s[i] - 'A' + 10;
    }

    std::string result{};
    do
    {
        int remainder = base10 % b2;
        char v = remainder < 10 ? remainder + '0' : remainder-10 + 'A';
        result.insert(result.begin(), v);
        base10 /= b2;
    } while (base10 > 0);

    if (isNeg) result.insert(result.begin(), '-');
    return result;
}

// 7.4
size_t replaceAndRemove(size_t size, char s[])
{
    /* O(n^2) (insertions and deletions are O(n))
    for (auto& v = vec.begin(); v != vec.end();)
    {
        if (*v == 'a')
        {
            v = vec.erase(v);
            v = vec.insert(v, 'd');
            v = vec.insert(v, 'd');
            v += 2;
        }
        else if (*v == 'b')
            v = vec.erase(v);
        else
            ++v;
    }
    */

    /* O(n) but O(n) space too
    std::vector<char> result{};
    for (const auto& c : vec)
    {
        if (c == 'a')
        {
            result.push_back('d');
            result.push_back('d');
        }
        else if (c != 'b')
            result.push_back(c);
    }
    return result;
    */

    // forward iteration to remove b's and count a's
    size_t numAs = 0;
    size_t writeIdx = 0;
    for (size_t i = 0; i < size; ++i)
    {
        if (s[i] == 'a')
            ++numAs;
        if (s[i] != 'b')
            s[writeIdx++] = s[i];
    }
    size_t curLastIndex = writeIdx - 1;

    // backward iteration to convert a's to dd's
    writeIdx = curLastIndex + numAs;
    for (int i = static_cast<int>(curLastIndex); i >= 0; --i)
    {
        if (s[i] == 'a')
        {
            s[writeIdx--] = 'd';
            s[writeIdx--] = 'd';
        }
        else
            s[writeIdx--] = s[i];
    }
    return curLastIndex + numAs + 1;
}

// (7.5)

// (7.6)
