#include <iostream>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    multiset<int> v;
    set<int> count;
    while (n--){
        char order[5]={0};
        int t=0;
        cin>>order>>t;
        if (string(order)=="add"){
            v.insert(t);
            count.insert(t);
            vector<int> tv(v.equal_range(t).first,v.equal_range(t).second);
            cout<<(tv.end()-tv.begin())<<endl;
        }
        if (string(order)=="del"){
            pair<multiset<int>::iterator,multiset<int>::iterator> p;
            p=v.equal_range(t);
            vector<int> tv(p.first,p.second);
            cout<<(tv.end()-tv.begin())<<endl;
            v.erase(v.equal_range(t).first,v.equal_range(t).second);
        }
        if (string(order)=="ask"){
            if (count.find(t)!=count.end()){
                cout<<"1 ";
            } else {
                cout<<"0 ";
            }
            vector<int> tv(v.equal_range(t).first,v.equal_range(t).second);
            cout<<(tv.end()-tv.begin())<<endl;
        }
    }
    return 0;

}