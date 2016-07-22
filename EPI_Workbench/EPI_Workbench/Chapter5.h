#pragma once

// 5.1, 5.7, (5.8)

// 5.7

float xPowY(float x, uint32_t y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return xPowY(x, y / 2) * xPowY(x, y / 2);
    else
        return x * xPowY(x, y / 2) * xPowY(x, y / 2);
}

// if LSB is 0 (even), then result =     x^(y/2) * x^(y/2)
// if LSB is 1 (odd), then  result = x * x^(y/2) * x^(y/2)
float xPowY2(float x, uint32_t y)
{
    float result = 1.f;
    uint32_t power = y;
    while (power)
    {
        if (power & 1)
        {
            result *= x;
        }
        x *= x;
        power >>= 1;
    }
    return result;
}

// 421 % 10 = 1
// 421 / 10 = 42
//  42 % 10 = 2
//  42 / 10 = 4
//   4 % 10 = 4
//   4 / 10 = 0
// 
int reverseInt(int i)
{
    bool bNeg = i < 0;
    int result = 0;
    while (i != 0)
    {
        result *= 10;
        result += abs(i % 10);
        i /= 10;
    }
    return bNeg ? -result : result;
}
