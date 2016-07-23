// EPI_Workbench.cpp : Defines the entry point for the console application.
// Scenario 2: Finals Cram!!!
// - write code for problems in C0-C1, and pseudo-code for problems in (C2)
//  Data Structures
//      5.1, 5.7, (5.8)
//      6.1, 6.7, 6.12, 6.18 (6.2, 6.17)
//      7.1, 7.2, 7.4, (7.5, 7.6)
//      8.1, 8.2, 8.4, (8.5, 8.8)
//      9.1, 9.9, (9.2, 9.10)
//      10.1, 10.4, (10.2, 10.10)
//      11.1, 11.4, (11.3)
//  Algorithms
//      12.1, 12.5, 12.9, (12.4, 12.11)
//      13.1, 13.3, 13.4, (13.2, 13.7)
//      14.1, 14.2, (14.3, 14.5)
//      15.1, 15.3, 15.4, (15.5, 15.9)
//      16.1, 16.2, (16.3)
//  Advanced Algorithms
//      17.1, 17.2, (17.3, 17.6)
//      18.5, 18.7, (18.6, 18.8)
//      19.1, 19.7, (19.2)
//      20.3, 20.7, (20.6)
//      21.11, 21.13, (21.14)
//
//  TOTAL:  41 code problems, 28 pseudocode problems, 16 chapters
//  Hours: 28 (7 days @ 4 hours per day)
//  Minutes per Code Question:       33
//  Minutes per Pseudocode Question: 11
//  Chapters per Day: 2.25
//

#include <cassert>
#include "Zippering.h"
#include "Bitwise.h"
#include "Chapter5.h"
#include "Chapter6.h"
#include "Chapter7.h"

//
// MAIN!
//

int main()
{
    std::vector<char> vec{'a','c','d','b','b','c','a'};
    std::vector<char> res = replaceAndRemove(vec);
    return 0;
}
