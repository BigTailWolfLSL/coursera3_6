//#include <iostream>
//#include <iomanip>
//#include <cstring>
//#include <stdlib.h>
//#include <stdio.h>
//#include <math.h>
//#include <cstdlib>
//using namespace std;
//class MyInt {
//    int nVal;
//public:
//    MyInt(int n) { nVal = n; }
//    int ReturnVal() { return nVal; }
    MyInt & operator-(int n){
        nVal=nVal-n;
        return *this;
    }
// 在此处补充你的代码
//};
//int main () {
//    MyInt objInt(10);
//    objInt-2-1-3;
//    cout << objInt.ReturnVal();
//    cout <<",";
//    objInt-2-1;
//    cout << objInt.ReturnVal();
//    return 0;
//}