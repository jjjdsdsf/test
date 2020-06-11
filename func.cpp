#include <iostream>
#include <string>
#include <functional>

using namespace std;
using namespace std::placeholders;
//函数对象

struct Person{
    int add(int a,int b){
        return a+b;
    }
};
void test1(){
    Person pe;
    auto p1 = bind(&Person::add,pe,10,10);
    cout << "no1 : " << p1() << endl;
    auto p2 = bind(&Person::add,Person(),_1,_2);
    cout << "no2 : " << p2(10,10) << endl;
}

void test2(){
    Person pe;
    auto p1 = mem_fn(&Person::add);
    cout << "no1 : " << p1(pe,10,10) << endl;
    cout << "no2 : " << p1(Person(),10,10) << endl;
}

void test3(){
    Person pe;
    function<int(Person,int,int)> p1(&Person::add);
    cout << "no1 : " << p1(pe,10,10) << endl;
    cout << "no2 : " << p1(Person(),10,10) << endl;
    function<int(int,int)> p2([](int a,int b){return a+b;});
    cout << "no3 : " << p2(10,10) << endl;
}
int main(int argc,char* argv[])
{
    cout << "===============bind==================" << endl;
    test1();
    cout << "===============function==================" << endl;
    test3();
    cout << "===============mem_fn==================" << endl;
    test2();
    cout << "=========================================" << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

