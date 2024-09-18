#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>
using namespace std;

class Test
{
private:
    mutable int val;
public:
    Test(int val) {
        cout << "기본 생성자 val : " << val << endl;
        this->val = val;
    }

    Test(const Test& src)
    {
        cout << "복사 생성자 val : " << src.val << endl;
        val = src.val;
    }

    void operator=(const Test& src)
    {
        cout << "대입 연산자 val : " << src.val << endl;
        val = src.val;
    }

    int GetVal() { return val; }

    void DoSomething(int x) const {
        val = x;
    }
};

int main() {
    Test t1(5);
    Test t2(3);
    Test t3 = t2;
    t1 = t2;
    string s1("234", 2);
    cout << s1 << endl;

    t1.DoSomething(1);

    cout << t1.GetVal() << endl;
    cout << t2.GetVal() << endl;
}