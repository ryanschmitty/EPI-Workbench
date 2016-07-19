#pragma once
#include <cassert>
typedef unsigned int UINT;

// Right propogate the right-most bit in x:
//  (x-1) - sets right-most bit to 0 and right propogates it
//  e.g. 10100 - 1 = 10_0_11
//  so you can bitwise-OR that back in to just propogate the lowest bit
UINT rightPropogateLowestBit(UINT x)
{
    return x | (x - 1);
}

// Check for power of 2
// x & (x-1): replaces lowest bit with 0
// power of 2 values only have 1 bit set (the lowest one, duh), so replacing the lowest bit results in 0 for power of 2s
// e.g. 100 & 011 = 0 (pow2), but 110 & 101 = 100 (not pow2)
bool isPower2(UINT x)
{
    return (x > 0) && ((x & (x - 1)) == 0);
}

// Compute x modulo y, where y is a power of 2 only
//  e.g.
//  77 = 1001101
//  64 = 1000000
//  13 = 0001101
//  or
//  77 = 1001101
//  16 = 0001000
//  05 = 0000101
//  I'm thinking we want to assert y isPower2, then right propogate the lowest bit and bitwise & it with x
UINT moduloPow2(UINT x, UINT y)
{
    assert(isPower2(y));
    return x & (y - 1);
}
