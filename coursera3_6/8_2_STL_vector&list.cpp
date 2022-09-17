#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector< list< int > > a;
    vector<int> id;
    for (int i=0;i<n;i++){
        char order[10]={0};
        cin>>order;
        if (string(order)=="new"){
            int t;
            cin>>t;
            list<int> tl;
            a.push_back(tl);
            id.push_back(t);
        }
        if (string(order)=="add"){
            int tid,t;
            cin>>tid>>t;
            a[(find(id.begin(),id.end(),tid)-id.begin())].push_back(t);
        }
        if (string(order)=="merge"){
            int tid1,tid2;
            cin>>tid1>>tid2;
            tid1=(find(id.begin(),id.end(),tid1)-id.begin());
            tid2=(find(id.begin(),id.end(),tid2)-id.begin());
            a[tid1].merge(a[tid2]);
        }
        if (string(order)=="unique"){
            int tid;
            cin>>tid;
            a[(find(id.begin(),id.end(),tid)-id.begin())].sort();
            a[(find(id.begin(),id.end(),tid)-id.begin())].unique();
        }
        if (string(order)=="out"){
            int tid;
            cin>>tid;
            int ai=(find(id.begin(),id.end(),tid)-id.begin());
            a[ai].sort();
            ostream_iterator< int > o(cout," ");
            copy(a[ai].begin(),a[ai].end(),o);
            cout<<endl;
        }
    }
    return 0;
}