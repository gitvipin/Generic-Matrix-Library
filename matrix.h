#ifndef __MATRIX_H
#define __MATRIX_H

#include "./common.h"

template <class T>
class Matrix{
    unsigned int nRow ; 
    unsigned int nCol;

    T *data;

    Matrix(); // Default Constructor : Private , because you can not create a Matrix[0][0] 
    
    public:

    Matrix(int, int); // constructor 
    ~Matrix(); // destructor 

    Matrix(const Matrix<T> &); // Copy constructor 
    Matrix<T> & operator=(Matrix<T> );

    public:
    void Print() const;    //print the Matrix
    void GiveInput();
    void Read(T [],unsigned int);

    template<class M> friend const Matrix<M> operator+(Matrix<M> & lhs , Matrix<M> & rhs);
    template<class M> friend const Matrix<M> operator-(Matrix<M> & lhs, Matrix<M> &rhs);
};


template<class T>
Matrix<T>::Matrix():nRow(0),nCol(0),data(NULL){
    PRNTDBG_L3("Matrix::Matrix()");
}


/* Constructor */
template<class T>
Matrix<T>::Matrix(int r, int c):nRow(r),nCol(c),data(NULL){
    PRNTDBG_L3("Matrix::Matrix(int,int)");
    data = new T[nRow * nCol];
}


/* Destructor */
template<class T> 
Matrix<T>::~Matrix(){
    PRNTDBG_L3("Matrix::~Matrix");
    delete data;
    data = NULL;
}

/* Copy Constructor */
template<class T> 
Matrix<T>::Matrix(const Matrix<T> & rhs){
    PRNTDBG_L3("Matrix::Matrix(Matrix& )");

    nRow = rhs.nRow;
    nCol = rhs.nCol;

    T *Data = data = new T[nRow*nCol];

    for(int i =0; i < nRow; i++){
        for (int j=0; j < nCol; j++){
            Data[nCol*i+j] = rhs.data[nCol*i+j];
        }
    }
}

template<class T> 
Matrix<T> & Matrix<T>::operator=(Matrix<T> rhs){
    PRNTDBG_L3("Matrix::operator=");
    assert(data);    
    if (nRow == rhs.nRow && nCol == rhs.nCol){
        T *Data = (T*)data;
        for(int i =0; i < nRow; i++){
            for (int j=0; j < nCol; j++){
                Data[nCol*i+j] = rhs.data[nCol*i+j];
            }
        }
    }else
        throw MATRIX_UNEQUAL;
   return (*this);
}

template<class T>
void Matrix<T>::Print() const {
    cout << "Displaying Matrix ................................" <<endl;
    T *Data = (T*)data; 
    for(int i=0; i < nRow;  i++){
        cout << endl;
        for(int j=0; j < nCol;  j++)
            cout << Data[nCol*i+j] << "\t";
    }
    cout << endl;
}


template<class T>
void Matrix<T>::GiveInput(){
    cout <<endl<< "Give input data for the matrix ["<< nRow<<"]["<<nCol<<"] :"<<endl;
    T *Data = (T*)data; 
    for(int i=0; i < nRow;  i++){
        cout << "Give data for Row # " << i << endl;
        for(int j=0; j < nCol;  j++)
            cin >> Data[nCol*i+j];
    }
    cout << endl;
}

template<class T>
void Matrix<T>::Read(T arrData[],unsigned int asize){
    cout <<endl<< "Reading IN data for matrix ["<< nRow<<"]["<<nCol<<"] :"<<endl;
    T *Data = (T*)data; 
    //unsigned int asize = sizeof arrData / sizeof arrData[0];
    //cout << "Array Size is : "<< asize;
    for(int i=0,k=0; i < nRow;  i++)
        for(int j=0; j < nCol;  j++)
            Data[nCol*i+j] = (k<asize)?arrData[k++]:-1;
}

template <class T>
const Matrix<T> operator+(Matrix<T> & lhs , Matrix<T> & rhs){
    unsigned int nRow = lhs.nRow;
    unsigned int nCol = lhs.nCol;
    Matrix<T> temp(nRow,nCol);
    
    if(lhs.nRow == rhs.nRow && lhs.nCol == rhs.nCol){
        unsigned int nRow = lhs.nRow;
        unsigned int nCol = lhs.nCol;

        T   *ldata = (T*)lhs.data;
        T   *rdata = (T*)rhs.data;
        T   *tdata = (T*)temp.data;

        for(int i=0; i < nRow;  i++)
            for(int j=0; j < nCol;  j++)
                tdata[nCol*i+j] = ldata[nCol*i+j] + rdata[nCol*i+j];
    }else
        throw MATRIX_UNEQUAL_ADDITION ; 

    return temp;
}

template <class T>
const Matrix<T> operator-(Matrix<T> & lhs , Matrix<T> & rhs){
    unsigned int nRow = lhs.nRow;
    unsigned int nCol = lhs.nCol;

    Matrix<T> temp(nRow,nCol);
    
    if(lhs.nRow == rhs.nRow && lhs.nCol == rhs.nCol){
        T   *ldata = (T*)lhs.data;
        T   *rdata = (T*)rhs.data;
        T   *tdata = (T*)temp.data;

        for(int i =0; i < nRow; i++)
            for(int j=0; j <nCol; j++)
                tdata[nCol*i+j] = ldata[nCol*i+j] - rdata[nCol*i+j];
    }else
        throw MATRIX_UNEQUAL_SUBTRACTION;
    return temp;
}


#endif // __MATRIX_H

