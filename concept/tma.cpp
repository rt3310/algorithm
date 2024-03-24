#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


struct info {
    int idx;
    int value;
};

struct Boy {
    int value;
    vector<info> list;
};

struct Girl {
    int value;
    vector<info> list;
    bool engaged = false;
    int engagedboy = -1;
};

int boyvalues[] = {0, 4, 4, 9, 1, 1, 5, 7, 6, 2};
int girlvalues[] = {3, 6, 2, 9, 4, 7, 3, 3, 4, 9};

bool compare(info a, info b) {
    return a.value < b.value;
}

int main() {

    vector<Boy> boys;
    vector<Girl> girls;
    int population = 10;

    for (int i = 0; i < population; i++) {
        Boy b;
        b.value = boyvalues[i];
        info inf {-1, -1};
        b.list.assign(population, inf);
        boys.push_back(b);
        Girl g;
        g.value = girlvalues[i];
        g.list.assign(population, inf);
        girls.push_back(g);
    }

    for (int i = 0; i < population; i++) {
        for (int j = 0; j < population; j++) {
            boys[i].list[j].idx = j;
            boys[i].list[j].value = girls[j].value;

            girls[i].list[j].idx = j;
            girls[i].list[j].value = boys[j].value;
        }
        sort(boys[i].list.begin(), boys[i].list.end(), compare);
        sort(girls[i].list.begin(), girls[i].list.end(), compare);
    }


    for (int i = 0; i < (int) pow(population, 2.0); i++) {
        for (int j = 0; j < population; j++) {
            Girl& proposegirl = girls[boys[j].list[boys[j].list.size() - 1].idx];
            cout << proposegirl.engaged << " " << proposegirl.engagedboy << "\n";

            if (!proposegirl.engaged || boys[proposegirl.engagedboy].value < boys[j].value) {
                cout << "enter\n";
                proposegirl.engaged = true;
                proposegirl.engagedboy = j;
            }
        }

        for (int j = 0; j < population; j++) {
            Girl& proposegirl = girls[boys[j].list[boys[j].list.size() - 1].idx];
            if (proposegirl.engagedboy != j) {
                boys[j].list.pop_back();
            }
        }
    }

    for (Girl g : girls) {
        cout << g.engagedboy << " ";
    }

    return 0;
}