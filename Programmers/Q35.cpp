#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

bool isPrime(long long number) {
    if (number < 2) {
        return false;
    }
    
    if (number == 2) {
        return true;
    }
    
    if (number % 2 == 0) {
        return false;
    }
    
    for (long long i = 3; i <= sqrt(number); i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

vector<long long> split(string num) {
    stringstream ss(num);
    
    string buf;
    vector<long long> result;
    
    while (getline(ss, buf, '0')) {
        if (buf.size() == 0) {
            continue;
        }
        result.push_back(stoll(buf));
    }
    
    return result;
}

int solution(int n, int k) {
    int answer = 0;
    
    int number = n;
    string knumber = "";
    while (number > 0) {
        knumber = to_string(number % k) + knumber;
        number /= k;
    }
    
    vector<long long> sNumber = split(knumber);
    
    for (long long num : sNumber) {
        if (isPrime(num)) {
            answer++;
        }
    }
    return answer;
}