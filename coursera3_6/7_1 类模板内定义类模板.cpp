//#include <iostream>
//#include <iomanip>
//#include <cstring>
//#include <stdlib.h>
//#include <stdio.h>
//#include <math.h>
//#include <cstdlib>
//#include <fstream>
//using namespace std;

template<class T3>
class CArray3D{
    template<class T2>
    class CArray2D{
        template<class T1>
        class CArray1D{
            T1* p1=NULL;
        public:
            void set(int d1){
                p1=new T1[d1];
            }
            T1 &operator[](int i){
                return p1[i];
            }
            ~CArray1D(){
                if (p1) delete[] p1;
            }
        };
        CArray1D<T2>* p2=NULL;
    public:
        void set(int d2,int d1){
            p2=new CArray1D<T2>[d2];
            for (int i=0;i<d2;i++){
                p2[i].set(d1);
            }
        }
        CArray1D<T2> &operator[](int i){
            return p2[i];
        }
        ~CArray2D(){
            if (p2) delete[] p2;
        }
    };
    CArray2D<T3>* p3=NULL;
public:
    CArray3D(int d3,int d2,int d1){
        p3=new CArray2D<T3>[d3];
        for (int i=0;i<d3;i++){
            p3[i].set(d2,d1);
        }
    }
    CArray2D<T3> &operator[](int i){
        return p3[i];
    }
    ~CArray3D(){
        delete[] p3;
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