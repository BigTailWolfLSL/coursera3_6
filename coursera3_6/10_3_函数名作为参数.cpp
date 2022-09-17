//#include <iostream>
//using namespace std;
//
////int tryal(int n,int get()){//尝试着去用无参函数名作为参数 无返回值参数为void
////    return n*get();
////}
////int get1(){
////    return 1;
////}

int sum(int a[],int n, int fun(int)){
    int t=0;
    for (int i=0;i<n;i++){
        t=t+fun(a[i]);
    }
    return t;
}

//int sqr(int n) {
//    return n * n;
//}
//int main() {
////    cout<<tryal(2,get1)<<endl;
//    int t, n, a[0x100];
//    cin >> t;
//    for (int c = 0; c < t; ++c) {
//        cin >> n;
//        for (int i = 0; i < n; ++i) cin >> a[i];
//        cout << sum(a, n, sqr) << endl;
//    }
//    return 0;
//}