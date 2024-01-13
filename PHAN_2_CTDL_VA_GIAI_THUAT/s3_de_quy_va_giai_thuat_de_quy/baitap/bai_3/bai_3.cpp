/*
Nêu rõ các bước thực hiện của giải thuật cho bài toán Tháp Hà Nội trong trường hợp n = 3.
Viết chương trình giải bài toán Tháp Hà Nội không đệ quy.

===> Dùng stack để giải quyết bài toán không đệ quy ( khử đệ quy cho bài toán tháp hà nội )
Bài toán có thể được hiểu như này:
    - Với trường hợp n == 1 ==> chuyển trực tiếp 1 đĩa từ A sang C ===> đây là trường hợp suy biến:biế.
    - Với trường hợp n > 1: ==> gọi chung cho tất cả trường hợp
        + Thì ta sẽ xem n - 1 đĩa ở cột A là là 1 đĩa ===> chuyển n - 1 đĩa sang B (coi như 1 đĩa)
        + Sau đó chuyển 1 đĩa từ A sang C
        + Sau đó chuyển n-1 đĩa ở cột B (đang xem là 1 đĩa) sang C.

     ===> đây chính là ý tưởng bài toán để thực hiện đệ quy.
*/

#include <iostream>
#include <stack>

using namespace std;

struct item_tower
{
    int num; // so dia
    char source, middle, destination;
    void assign(int n, char a, char b, char c)
    {
        num = n;
        source = a;
        middle = b;
        destination = c;
    }
};

void thap_HN_khu_de_quy(int n, char a, char b, char c)
{
    stack<item_tower> st;
    item_tower t;
    t.assign(n, a, b, c);
    st.push(t);

    while (!st.empty())
    {
        item_tower topOfTower = st.top();
        st.pop();
        if (topOfTower.num == 1)
        {
            cout << topOfTower.source << " ----> " << topOfTower.destination << endl;
        }
        else
        {
            t.assign(topOfTower.num - 1, topOfTower.middle, topOfTower.source, topOfTower.destination);
            st.push(t);
            t.assign(1, topOfTower.source, topOfTower.middle, topOfTower.destination);
            st.push(t);
            t.assign(topOfTower.num - 1, topOfTower.source, topOfTower.destination, topOfTower.middle);
            st.push(t);
        }
    }
}

int main()
{
    thap_HN_khu_de_quy(3, 'A', 'B', 'C');
    return 0;
}