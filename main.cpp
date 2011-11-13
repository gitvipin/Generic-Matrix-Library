#include "common.h"
#include "matrix.h"

int Data[] = {2,3,4,1,34,56,78,98,45,34,23,1,1,1,0,0,0,3,4,9,1,2,3,2,3,4,5,0};


int main (int argc , char *argv[]){

    cout << "=========================================================" <<endl ;
    cout << "============     Welcome to Matrix Library ==============" <<endl ;
    cout << "=========================================================" <<endl ;

    unsigned int size = sizeof Data/sizeof Data[0];

    Matrix<int>  m(4,5);
    Matrix<int>  n(4,5);
    Matrix<int>  o(4,5);

    //m.GiveInput();// read from user , painful 
    m.Read(&Data[5],size-5);
    n.Read(&Data[7],size-7);

    m.Print();
    n.Print();

    o = m;
    o = m+n;

    //(m+n).Print();
    o.Print();

    return 0;
}

