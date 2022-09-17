#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;
class com{
public:
    int r=0,i=0;
    com(int a=0,int b=0){
        r=a;
        i=b;
    }
    com operator+(com const & a){
        return com(a.r+r,a.i+i);
    }
    friend istream & operator>>(istream & is,com & c);
    friend ostream & operator<<(ostream & os,com & c);
    operator double(){return sqrt(r*r+i*i);}
};
istream & operator>>(istream & is,com & c){
    char ch;
    is>>c.r>>ch>>c.i>>ch;
    return is;
}
ostream & operator<<(ostream & os,com & c){
    os<<c.r<<"+"<<c.i<<"i";
    return os;
}
com operator++(com & a,int){
    com temp=a;
    a.r++;
    return temp;
}

int main()  {
    com a,b,c;
    cin>>a;
    cout<<a<<endl;
    double d;
    d=(double)a;
    cout<<d<<endl;
    return 0;
}
