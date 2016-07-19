// EPI_Workbench.cpp : Defines the entry point for the console application.
// Scenario 2: Finals Cram!!!
// - write code for problems in C0-C1
// - write pseudo-code for problems in C2
//

#include "Zippering.h"
#include "Bitwise.h"
#include <cassert>

//
// MAIN!
//

int main()
{
    DoZipper();
    assert(isPower2(32));
    assert(!isPower2(33));

    return 0;
}