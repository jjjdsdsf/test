#include <iostream>
#include <string>
#include <type_traits>


using namespace std;

struct Person{
    int operator()(int);
    bool operator()(int&,char);
    string getname();
};

int main(int argc,char* argv[])
{
    result_of_t<decltype(&Person::getname)(Person)> ret = "hello";
    result_of_t<Person(int)> num1 = 10;
    result_of_t<Person(int&,char)> num2 = true;
    cout << ret << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

