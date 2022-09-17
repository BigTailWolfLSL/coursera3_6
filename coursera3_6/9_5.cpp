#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<int,int> v;
    v.insert(pair<int,int>(1000000000,1));
    while (n--){
        int id=0,power=0;
        cin>>id>>power;
        map<int,int>::iterator p=v.insert(pair<int,int>(power,id)).first,tp=p;
        if (p==v.begin()){
            cout<<id<<' '<<(++p)->second<<endl;
            continue;
        }
        if ((++tp)==v.end()){
            cout<<id<<' '<<(--p)->second<<endl;
        }
        tp=p;
        tp--;
        p++;
        if ((p->first-power)>=(power-tp->first)){
            cout<<id<<' '<<tp->second<<endl;
            continue;
        } else {
            cout<<id<<' '<<p->second<<endl;
            continue;
        }
    }
    return 0;
}