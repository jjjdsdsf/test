#include <iostream>
#include <string>
#include <regex>

using namespace std;

void test(){
    std::string str = "zzxayyzz";
    std::regex re1(".*(a|xayy)"); // ECMA
    std::regex re2(".*(a|xayy)", std::regex::extended); // POSIX

    std::smatch m;
    std::regex_search(str, m, re1);
    std::cout << " ECMA (depth first search) match: " << m[0] << '\n';
    std::regex_search(str, m, re2);
    std::cout << " POSIX (leftmost longest)  match: " << m[0] << '\n';

}


int main(int argc,char* argv[])
{
    cout << "============匹配========================" << endl;
    string num = "123456789";
    regex re("\\d*");
    if(regex_match(num,re)){
        cout << "ok"  << "匹配成功" << endl;
    }
    cout << "===============获取子串===================" << endl;
    regex re2("123");
    string num1("123");
    smatch m;
    if(regex_search(num,m,re2)){
        cout << "获取到 : " << m.str() << endl;
    }

    cout << "================获取子串===================" << endl;

    string num3("ad32434fsf6456dsf46546fsf");
    regex re3("\\d+");
    sregex_iterator be(num3.cbegin(),num3.cend(),re3);
    sregex_iterator ed;
    for(auto i = be;i != ed;++i){
        smatch m = *i;
        cout << "获取的子串 : " << m.str() << endl;
    }

    cout << "=================获取子串===================" << endl;
    string num4("abc123abc456abc789abc");
    regex re4("abc(\\d+)abc");
    regex_search(num4,m,re4);
    if(!m.empty()){
        cout << "获取的个数 : " << m.size() << endl;
        cout << "第一个  : " << m.str() << endl;
        cout << "第二个 :  " << m.str(1) << endl;
    }

    cout << "===================替换=====================" << endl;
    string num5("abc123abc456abc789");
    regex re5("abc",regex::icase);
    string str = regex_replace(num5,re5,"");
    cout << "替换后的子串 : " << str << endl;

    cout << "=============手册案例测试====================" << endl;
    test();

    std::cout << "Hello world" << std::endl;
    return 0;
}

