#include <iostream>
#include <string>
#include <cstdarg>

using namespace std;

#define ARG_BEGIN(ars,type)(ars = (char*)(&type) + sizeof(type))
#define ARG_ARG(ags,type)(*(type*) ((ags += sizeof(type)) - sizeof(type)) )
#define ARG_END(ags)(ags = nullptr)

void test(int count,...){
    char* st = nullptr;
    ARG_BEGIN(st,count);
    for(int i = 0;i < count;++i){
        cout << ARG_ARG(st,int) << endl;
    }
}

void tlog(const char* fmt,...)
{
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);

}

int main(int argc,char* argv[])
{

    tlog("============== %d %d %c",1,2,'a');
    cout << endl;
    cout << "=============================" << endl;
    test(1,2,3,4);
    cout << "=============================" << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

