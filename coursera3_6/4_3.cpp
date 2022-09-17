//#include <iostream>
//#include <iomanip>
//#include <cstring>
//#include <stdlib.h>
//#include <stdio.h>
//#include <math.h>
//#include <cstdlib>
//using namespace std;
class Array2{
    int**arr=NULL;
public:
    Array2(int r=0,int c=0){
        if (r==0||c==0)return;
        arr=new int*[r];
        for (int i = 0; i < r; ++i) {
            arr[i]=new int[c];
        }
    }
    int*& operator[](int r){
        return arr[r];
    }
    int operator()(int i,int j){
        return arr[i][j];
    }
};
// 在此处补充你的代码
//int main() {
//    Array2 a(3,4);
//    int i,j;
//    for( i = 0;i < 3; ++i )
//        for( j = 0; j < 4; j ++ )
//            a[i][j] = i * 4 + j;
//    for( i = 0;i < 3; ++i ) {
//        for( j = 0; j < 4; j ++ ) {
//            cout << a(i,j) << ",";
//        }
//        cout << endl;
//    }
//    cout << "next" << endl;
//    Array2 b; b = a;
//    for( i = 0;i < 3; ++i ) {
//        for( j = 0; j < 4; j ++ ) {
//            cout << b[i][j] << ",";
//        }
//        cout << endl;
//    }
//    return 0;
//}