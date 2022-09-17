#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main()  {
    int z;
    cin>>z;
    char names[5][10]={"dragon","ninja","iceman","lion","wolf"};
    int redorder[5]={2,3,4,1,0};
    int blueorder[5]={3,0,1,2,4};
    for (int l=0;l<z;l++){
        int mred=0,mblue=0;
        cin>>mred;
        mblue=mred;
        int health[5]={0};
        for (int i=0;i<5;i++){
            cin>>health[i];
        }
        bool flagblue=true,flagred=true;
        int countblue=0,countred=0;
        int countnamered[5]={0},countnameblue[5]={0};
        int pointblue=4,pointred=4;
        int time=0;
        cout<<"Case:"<<(l+1)<<endl;
        while (flagblue||flagred){
            if (flagred){
                for (int j=1;j<6;j++){
                    if (mred>=health[redorder[(pointred+j)%5]]){
                        countred++;
                        mred=mred-health[redorder[(pointred+j)%5]];
                        countnamered[redorder[(pointred+j)%5]]++;
                        cout<<setfill('0')<<setw(3)<<time;
                        cout<<" red "<<names[redorder[(pointred+j)%5]]<<' '<<countred<<" born with strength "<<health[redorder[(pointred+j)%5]]<<","<<countnamered[redorder[(pointred+j)%5]]<<" "<<names[redorder[(pointred+j)%5]]<<" in red headquarter"<<endl;
                        pointred=(pointred+j)%5;
                        break;
                    }
                    if (j==5){
                        cout<<setfill('0')<<setw(3)<<time;
                        cout<<" red headquarter stops making warriors"<<endl;
                        flagred= false;
                    }
                }
            }
            if (flagblue){
                for (int j=1;j<6;j++){
                    if (mblue>=health[blueorder[(pointblue+j)%5]]){
                        countblue++;
                        mblue=mblue-health[blueorder[(pointblue+j)%5]];
                        countnameblue[blueorder[(pointblue+j)%5]]++;
                        cout<<setfill('0')<<setw(3)<<time;
                        cout<<" blue "<<names[blueorder[(pointblue+j)%5]]<<' '<<countblue<<" born with strength "<<health[blueorder[(pointblue+j)%5]]<<","<<countnameblue[blueorder[(pointblue+j)%5]]<<" "<<names[blueorder[(pointblue+j)%5]]<<" in blue headquarter"<<endl;
                        pointblue=(pointblue+j)%5;
                        break;
                    }
                    if (j==5){
                        cout<<setfill('0')<<setw(3)<<time;
                        cout<<" blue headquarter stops making warriors"<<endl;
                        flagblue= false;
                    }
                }
            }
            time++;
        }
    }
    return 0;
}