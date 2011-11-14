#ifndef _COMMON_H
#define _COMMON_H

#include <iostream>
using namespace std;

enum EXCEPTION_CODES{
    MATRIX_UNEQUAL=101,
    MATRIX_UNEQUAL_ADDITION=101,
    MATRIX_UNEQUAL_SUBTRACTION=102
};

#define _DEBUG_LEVEL3   0


inline void PRNTDBG_L3(const char *msg){
#if _DEBUG_LEVEL3
    cout << msg << endl;
#endif
}


#endif // _COMMON_H




