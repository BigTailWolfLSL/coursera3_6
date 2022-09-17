#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <fstream>
using namespace std;
template <class T1,class T2>
class A{
public:
    T1 v1; T2 v2;
};
template <class T1,class T2>
class B:public A<T2,T1>{
    T1 v3;T2 v4;
};
template <class T>
class C:public B<T,T>{
    T vs;
};
int main(){
    B<int,double> obj;
    C<int> obj2;
    cout<<sizeof(obj.v2);
    return 0;
}