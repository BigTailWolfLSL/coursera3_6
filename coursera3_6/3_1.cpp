//#include <iostream>
//using namespace std;//clion快速注释，单行与取消：ctrl+/，多行与取消：ctrl+shirt+/
//class A {
//public:
//    int val;
    int &GetObj(){
        return val;
    }
//};
//main()  {
//    A a;
//    cout << a.val << endl;
//    a.GetObj() = 5;
//    cout << a.val << endl;
//}