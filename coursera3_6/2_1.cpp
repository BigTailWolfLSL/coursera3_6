#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class student{
private:
    char name[20]={0};
    int age=0,id=0,mark1,mark2,mark3,mark4,aver;
public:
    void init(char nam[],int ag,int id2,int ma1,int ma2,int ma3,int ma4){
        for (int i=0;i<strlen(nam);i++)name[i]=nam[i];
        age=ag;
        id=id2;
        mark1=ma1;
        mark2=ma2;
        mark3=ma3;
        mark4=ma4;
    }
    int average(){
        int sum=(mark1+mark2+mark3+mark4)/4;
        aver=sum;
        return sum;
    }
    void myprint(){
        cout<<name;
        cout<<','<<age<<','<<id<<','<<aver<<endl;
    }
};
int main(){
    student a;
    char nam[20]={0},str[20]={0},ch;
    int age,id,mark1,mark2,mark3,mark4;
    cin.get(nam,20,',');
    cin>>ch;
    cin.get(str,20,',');
    age=atoi(str);
    cin>>ch;
    cin.get(str,20,',');
    id=atoi(str);
    cin>>ch;
    cin.get(str,20,',');
    mark1=atoi(str);
    cin>>ch;
    cin.get(str,20,',');
    mark2=atoi(str);
    cin>>ch;
    cin.get(str,20,',');
    mark3=atoi(str);
    cin>>ch;
    cin.getline(str,20);
    mark4=atoi(str);
    a.init(nam,age,id,mark1,mark2,mark3,mark4);
    a.average();
    a.myprint();
}