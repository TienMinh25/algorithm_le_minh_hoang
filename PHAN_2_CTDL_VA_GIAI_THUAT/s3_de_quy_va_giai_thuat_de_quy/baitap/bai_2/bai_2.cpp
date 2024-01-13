/*
Viết một hàm đệ quy tính tổ hợp chập k của n theo công thức truy hồi sau:
    C(0, n) = C(n, n) = 1 ==> điểm neo
    Với 0 < k < n: C(k, n) = C(k-1, n-1) + C(k, n-1) ===> công thức truy hồi
Chứng minh rằng hàm đó cho ra đúng giá trị C(k, n) = n! / (k! * (n-k)!)
output sau khi chạy xong thuật toán với n = 4, k = 2 ==> 6
output khi tính theo công thức: C(2, 4) = 4! / (2! * 2!) = 6 
===> điều phải chứng minh
*/

#include<iostream>

using namespace std;

int toHop(int n, int k){
    if (k == n || k == 0) {
        return 1;
    }
    return toHop(n-1, k-1) + toHop(n-1, k);
}

int main() {
    int n, k;
    cout << "Nhập n và k để tính tổ hợp chập k của n: " << endl;
    cin >> n >> k;

    cout << "Tổ hợp chập k của n là : " << toHop(n, k) << endl;
    return 0;
}