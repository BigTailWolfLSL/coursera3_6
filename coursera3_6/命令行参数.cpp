#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
using namespace std;

int main(int argc,char*argv[]){
    printf("%d\n",argc);
    int i;
    for (i=0;i<argc;i++){
        printf("%s\n",argv[i]);
    }
    printf("%s\n",argv[i]);
    return 0;//使用方法在cmd里打路径到运行后的exe即可，或者下下方终端打.\coursera3_6.exe即可
}