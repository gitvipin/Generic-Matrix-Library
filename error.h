#ifndef __ERROR_H
#define __ERROR_H

enum ERROR_TYPE{
	SYSTEM_ERROR,
	MATRIX_ERROR
};


/* ALL THE SYSTEM ERROR CODES TO BE WITHIN 10 - 100*/
/* ALL THE MATRIX ERROR CODES TO BE WITHIN 100 - 200*/
enum EXCEPTION_CODE{	
    MATRIX_UNEQUAL_ASSIGNMENT=101,
    MATRIX_UNEQUAL_ADDITION	,
    MATRIX_UNEQUAL_SUBTRACTION
};

typedef void (*fpErrHandler)();

class Error{
	ERROR_TYPE	errType;
	EXCEPTION_CODE errCode;
	fpErrHandler errHandler;
public:
	Error(ERROR_TYPE eType, EXCEPTION_CODE eCode,fpErrHandler f):errType(eType),errCode(eCode),errHandler(f){
	}
};

#endif // __ERROR_H

