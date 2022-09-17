#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int c;
    cin>>c;
    while (c--){
        int n,i,j;
        cin>>n;
        int count=0;
        int bi[35]={0};
        while (n){
            bi[count]=n%2;
            n=n/2;
            count++;
        }
        count--;
        cin>>i>>j;
        for (int k=0;k<j;k++){
            if (k<i){
                bi[k]=0;
            }
            if (k>i){
                bi[k]=1;
            }
        }
        bi[j]=!bi[j];
        n=0;
        for (int k=j;k>=0;k--){
            n=n*2+bi[k];
        }
        printf("%x",n);
        cout<<endl;
    }
}