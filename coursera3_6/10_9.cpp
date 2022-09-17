//#include <iostream>
//#include <set>
//#include <iterator>
//#include <algorithm>
//using namespace std;

class A{
public:
    char ch;
    int age;
    A(int a,char c='A'):ch(c),age(a){}
};
class B:public A{
public:
    B(int a):A(a,'B'){}
};
#include <stdio.h>
void Print(A* a){
    char ch[2]={(*a).ch,0};
    printf(ch);
    printf(" ");
    printf("%d\n",(*a).age);
}
class Comp{
public:
    bool operator()(A* a,A* b){
        return a->age<b->age;
    }
};

//int main()
//{
//
//    int t;
//    cin >> t;
//    set<A*,Comp> ct;
//    while( t -- ) {
//        int n;
//        cin >> n;
//        ct.clear();
//        for( int i = 0;i < n; ++i)	{
//            char c; int k;
//            cin >> c >> k;
//
//            if( c == 'A')
//                ct.insert(new A(k));
//            else
//                ct.insert(new B(k));
//        }
//        for_each(ct.begin(),ct.end(),Print);
//        cout << "****" << endl;
//    }
//}