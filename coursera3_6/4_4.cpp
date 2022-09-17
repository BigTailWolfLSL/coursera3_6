#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
using namespace std;
class arr{
public:
    int arra[51]={0};
};
ostream & operator<<(ostream & os,arr & c){
    for (int i=c.arra[0];i>=1;i--){
        if (i!=c.arra[0]) os<<setfill('0')<<setw(4)<<c.arra[i];
        else os<<c.arra[i];
    }
    if (c.arra[0]==0)os<<0;
    return os;
}
bool jud(arr& a,arr& b){
    if (a.arra[0]>b.arra[0])return true;
    if (a.arra[0]<b.arra[0])return false;
    for (int i=a.arra[0];i>0;i--){
        if (a.arra[i]>b.arra[i])return true;
        if (a.arra[i]<b.arra[i])return false;
    }
    return true;
}
arr add(arr& a,arr& b){
    int l=0,m=max(a.arra[0],b.arra[0]);
    arr c;
    for (int i=1;i<=m;i++){
        c.arra[i]=(a.arra[i]+b.arra[i]+l)%10000;
        l=(a.arra[i]+b.arra[i]+l)/10000;
    }
    c.arra[0]=m;
    if (l!=0){
        c.arra[0]++;
        c.arra[c.arra[0]]=l;
    }
    return c;
}
arr minu(arr a,arr b){
    arr c;
    int l=0,m=max(a.arra[0],b.arra[0]);
    for (int i=1;i<=m;i++){
        c.arra[i]=a.arra[i]-b.arra[i]-l;
        if (c.arra[i]<0){
            c.arra[i]=c.arra[i]+10000;
            l=1;
        }else l=0;
    }
    c.arra[0]=m;
    for (;c.arra[c.arra[0]]==0&&c.arra[0]>0;c.arra[0]--){}
    return c;
}
arr mul(arr& a,arr& b){
    int l=0;
    arr c;
    if (!(a.arra[0]&&b.arra[0]))return c;
    c.arra[0]=a.arra[0]+b.arra[0];
    for (int i=1;i<=a.arra[0];i++){
        if (a.arra[i]==0)continue;
        for (int j=1;j<=b.arra[0];j++){
            if (b.arra[j]==0&&l==0)continue;
            c.arra[i+j-1]=c.arra[i+j-1]+a.arra[i]*b.arra[j]+l;
            l=c.arra[i+j-1]/10000;
            c.arra[i+j-1]=c.arra[i+j-1]%10000;
        }
        c.arra[i+b.arra[0]]=c.arra[i+b.arra[0]]+l;
        l=0;
    }
    for (;c.arra[c.arra[0]]==0&&c.arra[0]>0;c.arra[0]--){}
    return c;
}
arr div(arr& a,arr& b){
    arr c;
    for (int i=4*a.arra[0]-4*b.arra[0]+4;i>0;i--){
        arr t;
        t.arra[0]=i/4;
        if(i%4!=0)t.arra[0]++;
        t.arra[t.arra[0]]=pow(10,i%4);
        arr t2=mul(t,b);
        while(jud(a,t2)){
            a=minu(a,t2);
            c=add(c,t);
        }
    }
    return c;
}
int main() {
    arr n1,n2;
    char ch[105]={0},oper;
    cin.getline(ch,105);
    int t=0;
    for (int i=0;i<strlen(ch);i++){
        t=t+(ch[strlen(ch)-i-1]-'0')*pow(10,i%4);
        if ((i+1)%4==0){
            n1.arra[0]++;
            n1.arra[n1.arra[0]]=t;
            t=0;
        }
    }
    if (t!=0){
        n1.arra[0]++;
        n1.arra[n1.arra[0]]=t;
        t=0;
    }
    cin>>oper;
    cin.getline(ch,105);
    cin.getline(ch,105);
    for (int i=0;i<strlen(ch);i++){
        t=t+(ch[strlen(ch)-i-1]-'0')*pow(10,i%4);
        if ((i+1)%4==0){
            n2.arra[0]++;
            n2.arra[n2.arra[0]]=t;
            t=0;
        }
    }
    if (t!=0){
        n2.arra[0]++;
        n2.arra[n2.arra[0]]=t;
        t=0;
    }
    switch (oper) {
        case '+':{
            arr c;
            c=add(n1,n2);
            cout<<c<<endl;
            return 0;
        }
        case '-':{
            if (jud(n1,n2)){
                arr c;
                c=minu(n1,n2);
                cout<<c<<endl;
            }else{
                arr c;
                cout<<'-';
                c=minu(n2,n1);
                cout<<c<<endl;
            }
            return 0;
        }
        case '*':{
            arr c;
            c=mul(n1,n2);
            cout<<c<<endl;
            return 0;
        }
        case '/':{
            arr c;
            c=div(n1,n2);
            cout<<c<<endl;
            return 0;
        }
    }
    return 0;
}
