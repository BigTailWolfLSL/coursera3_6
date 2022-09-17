#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <set>
#include <vector>
using namespace std;
int main() {
    int a[] = {8,7,8,9,6,2,1};
    set<int> v(a,a+7);
//    cout<<*v.find(v.begin(),v.end(),10);
    ostream_iterator<int> o(cout," ");
    copy(v.begin(),v.end(),o);
    return 0;
}