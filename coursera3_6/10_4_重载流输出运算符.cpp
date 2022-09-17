//#include <iostream>
//using namespace std;

class CType{
public:
    int val;
    void setvalue(int n){
        val=n;
    }
    int& operator++(int n){
        return val;
    }
};
ostream & operator<<(ostream& os,const CType obj){
    int t=obj.val*obj.val;
    os<<t;
    return os;
}
//
//int main(int argc, char* argv[]) {
//    CType obj;
//    int n;
//    cin>>n;
//    while ( n ) {
//        obj.setvalue(n);
//        cout<<obj++<<" "<<obj<<endl;
//        cin>>n;
//    }
//    return 0;
//}