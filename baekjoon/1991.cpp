#include <iostream>
using namespace std;

int n;
int leftChild[27];
int rightChild[27];

int alphaToNumber(char c) {
    return c - 'A' + 1;
}

char numberToAlpha(int i) {
    return i + 'A' - 1;
}

void preorder(int cur) {
    if (cur == 0) {
        return;
    }

    cout << numberToAlpha(cur);
    preorder(leftChild[cur]);
    preorder(rightChild[cur]);
}

void inorder(int cur) {
    if (cur == 0) {
        return;
    }

    inorder(leftChild[cur]);
    cout << numberToAlpha(cur);
    inorder(rightChild[cur]);
}

void postorder(int cur) {
    if (cur == 0) {
        return;
    }

    postorder(leftChild[cur]);
    postorder(rightChild[cur]);
    cout << numberToAlpha(cur);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        char p, l, r;
        cin >> p >> l >> r;
        if (l != '.') {
            leftChild[alphaToNumber(p)] = alphaToNumber(l);
        }
        if (r != '.') {
            rightChild[alphaToNumber(p)] = alphaToNumber(r);
        }
    }

    preorder(1);
    cout << '\n';
    inorder(1);
    cout << '\n';
    postorder(1);

    return 0;
}