#include <iostream>
#include <deque> // deque는 vector와 달리 모든 원소들이 메모리 상에 연속하게 배치되어 있지 않다.
using namespace std;

const int MX = 1000005;
int dat[2 * MX + 1];
int head = MX, tail = MX;


void push_front(int x){
    dat[tail++] = x;
}

void push_back(int x){
    dat[--head] = x;
    
}

void pop_front(){
    tail--;
}

void pop_back(){
    head++;
}

int front(){
    return dat[tail - 1];
}

int back(){
    return dat[head];
}


void test(){
    push_back(30); // 30
    cout << front() << '\n'; // 30
    cout << back() << '\n'; // 30
    push_front(25); // 25 30
    push_back(12); // 25 30 12
    cout << back() << '\n'; // 12
    push_back(62); // 25 30 12 62
    pop_front(); // 30 12 62
    cout << front() << '\n'; // 30
    pop_front(); // 12 62
    cout << back() << '\n'; // 62
}

int main(){
    test();
    return 0;
}