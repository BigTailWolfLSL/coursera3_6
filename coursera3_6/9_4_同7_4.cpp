#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <fstream>
using namespace std;
int n=0;
string s[50];
int getn();
bool judge(string s){
    for(int i=0;i<s.length();i++){
        if (!((s[i]>='0') && (s[i]<='9'))){
            return false;
        }
    }
    int t;
    t=atoi(s.c_str());
    if ((t/1)!=t){return false;}
    if (t<0){return false;}
    if (t>99999){return false;}
    return true;
}
string turn(int n){
    int t;
    string ts="";
    if (n>=0){t=n;}else{t=-n;}
    while (t!=0){
        ts=char(t%10+int('0'))+ts;
        t=t/10;
    }
    if (n<0){
        ts='-'+ts;
    }
    return ts;
}
string gets(){
    char order[600];
    cin>>order;
    if (string(order)=="copy"){
        int n,x,l;
        n=getn();
        x=getn();
        l=getn();
        string ts(s[n].substr(x,l));
        return ts;
    }
    if (string(order)=="add"){
        string s1,s2;
        s1=gets();
        s2=gets();
        if (judge(s1) && judge(s2)){
            char ch[50];
//            itoa((atoi(s1.c_str())+atoi(s2.c_str())),ch,10);
//            string ts(ch);
            return turn((atoi(s1.c_str())+atoi(s2.c_str())));
        } else {
            string ts;
            ts=s1+s2;
            return ts;
        }
    }
    return string(order);
}
int getn(){
    char order[600];
    cin>>order;
    if (string(order)=="rfind"){
        int i=0;
        string ts;
        ts=gets();
        i=getn();
        int n;
        n=s[i].rfind(ts);
        if (n==string::npos){
            n=s[i].length();
        }
        return n;
    }
    if (string(order)=="find"){
        int i=0;
        string ts;
        ts=gets();
        i=getn();
        int n;
        n=s[i].find(ts);
        if (n==string::npos){
            n=s[i].length();
        }
        return n;
    }
    return atoi(order);
}
int main()
{
    cin>>n;
    string ts;
    char order[600];
    for(int i=1;i<=n;i++){
        cin>>order;
        s[i]=string(order);
    }
    cin.getline(order,50);
    while (true){
        cin>>order;
        if (string(order)=="over"){
            return 0;
        }
        if (string(order)=="insert"){
            string ts;
            ts=gets();
            int i,b;
            i=getn();
            b=getn();
            s[i].insert(b,ts);
            continue;
        }
        if (string(order)=="reset"){
            string ts;
            ts=gets();
            int i;
            i=getn();
            s[i]=ts;
            continue;
        }
        if (string(order)=="print"){
            int i;
            i=getn();
            cout << s[i] << endl;
            continue;
        }
        if (string(order)=="printall"){
            for (int i=1;i<=n;i++){
                cout<<s[i]<<endl;
            }
            continue;
        }
    }
    return 0;
}