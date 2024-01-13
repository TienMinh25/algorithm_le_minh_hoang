#include<iostream>

using namespace std;

int UCLN(int a, int b) {
    if (a == 0) {
        return b;
    }
    else if (b == 0) {
        return a;
    }
    return UCLN(b, a%b);
}

int main() {
    int a, b;
    cout << "Nhập 2 số a và b: " << endl;
    cin >> a >> b;

    int result = UCLN(a, b);
    cout << "Ước chung lớn nhất của 2 số " << a << " và " << b << " là: " << result << endl;
    return 0;
}