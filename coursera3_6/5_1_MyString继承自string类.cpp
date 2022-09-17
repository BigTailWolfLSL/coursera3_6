//#include <iostream>
//#include <iomanip>
//#include <cstring>
//#include <stdlib.h>
//#include <stdio.h>
//#include <math.h>
//#include <cstdlib>
//using namespace std;
#define qsort(a,b,c,d) myqsort(a,b,c,d)
class MyString:public string {
public:
    MyString(){}
    MyString(const char* ch):string(ch){}
    MyString(const MyString & s):string(s){}
    MyString(const string & s):string(s){}
    MyString operator+(const MyString& mys){
        string s1=mys;
        string s2=*this;
        MyString t(s2+s1);
        return t;
    }
    string operator()(int a,int n){
        string s=*this;
        return (s.substr(a,n));
    }
};
MyString operator+(char * ch,MyString mys){
    string s1(ch);
    string s2(mys);
    string s=s1+s2;
    MyString t(s);
    return t;
}
MyString operator+(MyString mys,char * ch){
    string s1(ch);
    string s2(mys);
    string s=s2+s1;
    MyString t(s);
    return t;
}
void myqsort(MyString SArray[],int,int,int(*)(const void*,const void*)){
    for (int i=0;i<3;i++){
        for (int j=i+1;j<4;j++){
            if (SArray[i]>=SArray[j]){
                MyString t=SArray[i];
                SArray[i]=SArray[j];
                SArray[j]=t;
            }
        }
    }
}
//int CompareString( const void * e1, const void * e2) {
//    MyString * s1 = (MyString * ) e1;
//    MyString * s2 = (MyString * ) e2;
//    if( *s1 < *s2 )     return -1;
//    else if( *s1 == *s2 ) return 0;
//    else if( *s1 > *s2 ) return 1;
//}
//int main() {
//    MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
//    MyString SArray[4]= {"big","me","about","take"};
//    cout << "1. " << s1 << s2 << s3<< s4<< endl;
//    s4 = s3;    s3 = s1 + s3;
//    cout << "2. " << s1 << endl;
//    cout << "3. " << s2 << endl;
//    cout << "4. " << s3 << endl;
//    cout << "5. " << s4 << endl;
//    cout << "6. " << s1[2] << endl;
//    s2 = s1;    s1 = "ijkl-";
//    s1[2] = 'A' ;
//    cout << "7. " << s2 << endl;
//    cout << "8. " << s1 << endl;
//    s1 += "mnop";
//    cout << "9. " << s1 << endl;
//    s4 = "qrst-" + s2;
//    cout << "10. " << s4 << endl;
//    s1 = s2 + s4 + " uvw " + "xyz";
//    cout << "11. " << s1 << endl;
//    qsort(SArray,4,sizeof(MyString), CompareString);
//    for( int i = 0;i < 4;++i )
//        cout << SArray[i] << endl;
//   //输出s1从下标0开始长度为4的子串
//    cout << s1(0,4) << endl;
//    //输出s1从下标为5开始长度为10的子串
//    cout << s1(5,10) << endl;
//    return 0;
//}
//
