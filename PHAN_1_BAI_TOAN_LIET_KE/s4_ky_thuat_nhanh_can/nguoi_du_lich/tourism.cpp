/*
- Hiểu về input ---> n m
ở đây n = 4 trong tourism.inp là số đỉnh - số thành phố
ở đây m = 6 trong tourism.inp là số đường đi qua các đỉnh và chi phí đi qua.
Ví dụ: 1 2 3 ---> nghĩa là có đường đi trực tiếp giữa thành phố 1 và thành phố 2, có chi phí = 3

Solution:

- Cần 1 mảng đánh dấu thành phố nào đã đi qua (mỗi thành phố đi qua 1 lần, ngoại trừ thành phố 1 là đi 2 lần - vì
                để hoàn thành 1 chu trình.)
- Cần 1 mảng 2 chiều để chứa chi phí của các thành phố, nếu giữa 2 thành phố không có đường đi ==> chi phí bằng dương vô cùng
(dương vô cùng là nói ở đây thôi :)) khi vào bài thì max chi phí giữa 2 thành phố là <= 100 nên dương vô cùng sẽ
    khởi tạo bằng 20*100+1  )
- cần 1 biến chứa chi phí khi đi theo đường đi đó.
- Cần 1 mảng để lưu trữ lại các thành phố đã đi qua.
- Cần 1 mảng một chiều T để lưu chi phí đi từ X1 đến Xi

- Bản chất ra thì bài này là tìm hoán vị phù hợp với yêu cầu đề bài của dãy (1, 2, 3, 4, ... , n)
- Mỗi lần thử để tìm config mới:
    + Thành phố nào đã đi rồi ===> không đi lại
    + Nếu thành phố đó có chi phí lớn hơn minCost thì bỏ, biết là dù xét tiếp với cấu hình đó thì đó cx kp là cấu hình 
    cuối thoả mãn chi phí thấp nhất.

*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void Try(int i, int n, vector<bool>& danhDau, vector<int>& T, vector<vector<int> >& cost, int& minCost, vector<int>& bestConfig) {
    for (int j = 1; j <= n; j++) {
        if (danhDau[j]) {
            bestConfig[i] = j;
            // chi phi hien tai = chi phi truoc do + duong di truc tiep tu i - 1 den i
            T[i] = T[i-1] + cost[bestConfig[i-1]][j];
            if (T[i] < minCost) {
                // chua den dinh n
                if (i < n) {
                    danhDau[j] = false;
                    Try(i+1, n, danhDau, T, cost, minCost, bestConfig);
                    danhDau[j] = true;
                }
                else {
                    if (T[n] + cost[bestConfig[n]][1] < minCost) {
                        // cap nhat bestConfig ===> chuan duong di roi => da cap nhat trong bestConfig
                        // cap nhat lai gia tien
                        minCost = T[n] + cost[bestConfig[n]][1];
                    }
                    // minCost = min(minCost, T[n] + cost[bestConfig[n]][1]);
                }
            }
        }
    }
}

void printConfig(vector<int>& bestConfig, int n, int& minCost, fstream& out) {
    for (int i = 0; i < n; i++) {
        out << bestConfig[i] << " ---> ";
    }
    out << bestConfig[n] << endl;
    out << "Cost: " << minCost;
}

int main()
{
    fstream inFile("tourism.inp"), outFile("tourism.out");
    // khoi tao
    int n, m, maxC = 20 * 100 + 1;
    int minCost = maxC;
    inFile >> n >> m;

    vector<vector<int> > cost(n + 1, vector<int>(n + 1, maxC));
    vector<bool> danhDau(n + 1, true);
    // bắt đầu đi từ thành phố 1 ===> T[0] = 0;
    vector<int> T(n + 1, 0);
    vector<int> bestConfig(n+1);
    bestConfig[0] = 1;

    for (int i = 0; i <= n; i++) {
        cost[0][i] = 0;
        cost[i][0] = 0;
    }

    for (int i = 1; i <= n; i++)
        cost[i][i] = 0;

    for (int i = 1; i <= m; i++)
    {
        int x, y, value;
        inFile >> x >> y >> value;
        cost[x][y] = cost[y][x] = value;
    }

    Try(1, n, danhDau, T, cost, minCost, bestConfig);

    printConfig(bestConfig, n, minCost, outFile);

    inFile.close();
    outFile.close();
    return 0;
}