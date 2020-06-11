#include <iostream>
#include <string>
#include <memory>


using namespace std;

//智能指针


struct Person : enable_shared_from_this<Person>{
public:
    //正确的获取
    shared_ptr<Person> getptr(){
        return shared_from_this();
    }
    Person(){
        cout << "person begin:...." << endl;
    }
    ~Person(){
        cout << "person end:...." << endl;
    }
    string name;
};

//链表节点
template<typename T>
struct Mode{
    T data;
    unique_ptr<Mode<T>> next;
    ~Mode(){
        cout << "delete souess : " << data << endl; 
    }
};


//链表
template<typename T>
class List{
public:
    //头插法
    void Push_font(const T& da){
        auto ptr = make_unique<Mode<T>>();
        ptr->data = da;
        ptr->next = move(head.next);
        head.next = move(ptr);
    }
    //打印
    void Print(){
        Mode<T>* mode = head.next.get();
        while(mode){
            cout << mode->data << "   ";
            mode = mode->next.get();
        }
        cout << endl;
    }
private:
    Mode<T> head;
};

//shared_ptr实例
void shared_test(){
    shared_ptr<Person> ptr1;
    cout << "no1 : " << ptr1.use_count() << endl;
    ptr1 = make_shared<Person>();
    cout << "no2 : " << ptr1.use_count() << endl;
    ptr1->name = "word";
    cout << "shared_ptr name : " << ptr1->name << endl;
    shared_ptr<Person> ptr2;
    ptr2 = ptr1->getptr();
    cout << "no3 : " << ptr1.use_count() << endl;

}

//unique_ptr实例
void unique_test(){
    unique_ptr<string> ptr1(new string("hello unique"));
    cout << *ptr1 << endl;

    unique_ptr<Person> ptr2(new Person);
    ptr2->name = "person";
    cout << ptr2->name << endl;

    auto ptr3 = make_unique<Person>();//临时对象
    List<int> li;
    for(int val:{1,2,3,4,5}){
        li.Push_font(val);
    }
    li.Print();
}

int main(int argc,char* argv[])
{
    
    shared_test();
    unique_test();
    std::cout << "Hello world" << std::endl;
    return 0;
}

