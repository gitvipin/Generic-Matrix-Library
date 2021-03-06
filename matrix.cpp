#include "common.h"
#include "matrix.h"


int Data[] = {2,3,4,1,34,56,78,98,45,34,23,1,1,1,0,0,0,3,4,9,1,2,3,2,3,4,5,0};

void TEST_MATRIX(){	

    cout << "=========================================================" <<endl ;
    cout << "============     Welcome to Matrix Library ==============" <<endl ;
    cout << "=========================================================" <<endl ;

	unsigned int size = sizeof Data/sizeof Data[0];
	try {
		Matrix<int>  m(4,5);
		Matrix<int>  n(4,5);
		Matrix<int>  o(4,5);
		
		//m.GiveInput();// read from user , painful 
		m.Read(&Data[5],size-5);
		n.Read(&Data[7],size-7);
		
		m.Print();
		n.Print();
		
		(m+n).Print();
		(m-n).Print();
	}
	catch(EXCEPTION_CODE e){
		HandleError(e);
	}
	catch( Error & e){
		HandleError(e);
	}
}


