#include <iostream>
#include <string>

using namespace std;

int main(int argc,char* argv[])
{

    int num = 0;
    int& a = num;
    a = 20;
    cout << num << endl;
    cout << "hello git" << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

