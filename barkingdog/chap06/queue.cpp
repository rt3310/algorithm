#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;


void push(int x){
    dat[tail] = x;
    tail = (tail + 1) % 1000005;
}

void pop(){
    if (head == tail) {
        return;
    }
    head = (head + 1) % 1000005;
}

int front(){
    if (head == tail) {
        throw -1;
    }
    return dat[head];
}

int back(){
    if (head == tail) {
        throw -1;
    }
    if (tail == 0) {
        return dat[MX - 1];
    }
    return dat[tail - 1];
}

void test(){
    push(10); push(20); push(30);
    cout << front() << '\n'; // 10
    cout << back() << '\n'; // 30
    pop(); pop();
    push(15); push(25);
    cout << front() << '\n'; // 30
    cout << back() << '\n'; // 25
}

int main() {
    test();
    return 0;
}