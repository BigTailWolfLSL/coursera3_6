/*
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class Sample{
public:
    int v;
    Sample(int n):v(n) { }
*/
    Sample(Sample const &t){
        v=t.v+5;
    }
// 在此处补充你的代码
/*
};
int main() {
    Sample a(5);
    Sample b = a;
    cout << b.v;
    return 0;
}*/
