//#include <iostream>
//#include <iomanip>
//#include <cstring>
//#include <stdlib.h>
//#include <stdio.h>
//#include <math.h>
//#include <cstdlib>
//#include <fstream>
//using namespace std;

//template<class T>
//class CArray{
//public:
//    T* p=NULL;
//    CArray(){
//        p=new T[10];
//    }
//    T &operator[](int i){
//        return p[i];
//    }
//    ~CArray(){
//        delete[] p;
//    }
//};
//template<class T1>
//class CArray3D:public CArray<CArray<CArray<T1>>>{
//public:
//    CArray3D(int,int,int){}
//};以上是一种方法

template<class T>
class CArray3D{
public:
    T*** p;
    int m=0;
    int n=0;
    CArray3D(int d1,int d2,int d3){
        p=new T**[d1];
        n=d1;
        m=d2;
        for (int i=0;i<d1;i++){
            p[i]=new T*[d2];
            for (int j=0;j<d2;j++){
                p[i][j]=new T[d3];
            }
        }
    }
    T** &operator[](int i){
        return p[i];
    }
    ~CArray3D(){
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                delete[] p[i][j];
            }
            delete[] p[i];
        }
        delete[] p;
    }
};
//int main()
//{
//    CArray3D<int> a(3,4,5);
//    int No = 0;
//    for( int i = 0; i < 3; ++ i )
//        for( int j = 0; j < 4; ++j )
//            for( int k = 0; k < 5; ++k )
//                a[i][j][k] = No ++;
//    for( int i = 0; i < 3; ++ i )
//        for( int j = 0; j < 4; ++j )
//            for( int k = 0; k < 5; ++k )
//                cout << a[i][j][k] << ",";
//    return 0;
//}