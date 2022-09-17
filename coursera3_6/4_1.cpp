//#include <iostream>
//#include <iomanip>
//#include <cstring>
//#include <stdlib.h>
//#include <stdio.h>
//#include <math.h>
//#include <cstdlib>
//using namespace std;
//class Complex {
//private:
//    double r,i;
//public:
//    void Print() {
//        cout << r << "+" << i << "i" << endl;
//    }
    Complex operator=(const string s){
        int pos=0;
        if(s.find("+")!=string::npos)pos=s.find("+",0);
        string ts;
        ts=s.substr(0,pos);
        r=atof(ts.c_str());
        ts=s.substr(pos+1,s.length()-pos-2);
        i=atof(ts.c_str());
        return *this;
    }
// 在此处补充你的代码
//};
//int main() {
//    Complex a;
//    a = "3+4i"; a.Print();
//    a = "5+6i"; a.Print();
//    return 0;
//}