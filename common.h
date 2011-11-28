#ifndef _COMMON_H
#define _COMMON_H

#include <iostream>
using namespace std;

#include "error.h"

#define _DEBUG_LEVEL3   0


inline void PRNTDBG_L3(const char *msg){
#if _DEBUG_LEVEL3
    cout << msg << endl;
#endif
}

#ifndef _DEBUG
/* if not in debug mode, supress all the debugging calls*/
#define PRNTDBG_L3(x)	 
#endif



#endif // _COMMON_H
