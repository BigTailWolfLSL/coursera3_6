#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <fstream>
using namespace std;
int main()
{
    int D;
    cin>>D;
    printf("%x",D);//x与X表示用小写还是大写表示16进制，“#”加在x前表示显示0x标识。
    printf("\n");
//    cout<<endl;
    printf("%010d",D);//010前面的0表示用0补齐，10表示10位。在010前面加“-”则左对齐。
    return 0;
}