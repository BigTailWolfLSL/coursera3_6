#include <iostream>
using namespace std;
class A{
public:
    int * p;
    A():p(new int){*p=0;}
    A(int i):p(new int){*p=i;}
    A(const A & a):p(a.p){
        //a.p=new int;//两个是连着的,虽是引用不能修改原参数。
    }
    A(A && a):p(a.p){//通过右值引用：1，不用赋值直接使用原空间；2，可以修改参数。
        a.p=new int;
        *a.p=0;
    }
//    A & operator=(A & a){//普通=等价于移动赋值
//        delete p;
//        p=a.p;
//        cout<<'='<<*p<<endl;
//        a.p=new int;
//        *a.p=0;
//        return *this;
//    }
    A & operator=(A && a){//移动赋值右值引用区分普通等号
        delete p;
        p=a.p;
        cout<<'='<<*p<<endl;
        a.p=new int;
        *a.p=0;
        return *this;
    }
    A & operator+(A && a){
        *p=*p+*a.p;
        cout<<'+'<<*p<<endl;
        *a.p=0;
        return *this;
    }
};
int add(int & a1,int & a2){
    int t=a1+a2;
    a1=0;
    a2=0;
    return t;
}
int main(){
    A a1(1);
    A a2(2);
    A a3(move(a1));
    *a3.p=3;
    cout<<*a1.p<<' '<<*a3.p<<endl;
    a1=move(a3);
    cout<<*a1.p<<' '<<*a3.p<<endl;
    a3=move(a2+move(a1));
    cout<<*a1.p<<' '<<*a2.p<<' '<<*a3.p<<endl;
    int b1=2,b2=4;
    cout<<add(b1,b2)<<' '<<b1<<' '<<b2<<endl;
    return 0;
}