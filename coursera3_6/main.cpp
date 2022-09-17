#include <iostream>
#include <cstring>
#include <exception>
using namespace std;
int main(){
    string s("hello");
    try{//一个try后面要马上至少有一个catch，而且在下一个try之前要被catch捕抓到
        //也不能有catch没有try，相当于整个大程序都在一个try里面，运行错误才能被捕抓。
        throw 1;//只会throw一次
        char ch=s.at(100);//自动throw,虽为红但是是正常输出的一种，退出代码0因为我们自己catch而不是程序catch
        throw 1;
    }
    catch(out_of_range& o) {//系统默认的异常类exception类的派派生类之一
        cerr<<o.what()<<endl;//注释掉不处理看起来就没区别
        //异常类具有.what()成员函数，为错误信息
    }
    catch(int n){
        if (n==1)cout<<"type 1 error"<<endl;
    }
    try{
        throw 'a';
    }
    catch(char){
        cout<<"char type error"<<endl;
    }
    return 0;
}