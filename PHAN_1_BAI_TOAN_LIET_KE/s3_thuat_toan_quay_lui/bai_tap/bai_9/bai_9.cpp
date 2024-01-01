/*
Bài toán mã đi tuần: Cho bàn cờ tổng quát kích thước nxn và một quân Mã, hãy chỉ ra một hành trình của quân
Mã xuất phát từ ô đang đứng đi qua tất cả các ô còn lại của bàn cờ, mỗi ô đúng một lần.
nghĩa là bài này cần n để xác định kích thước bàn cờ vua nxn
thứ 2 là location đang đứng của quân mã để xđ có thể đi vào nơi nào

Solution:
    bài này cần 1 mảng 2 chiều để đánh dấu nơi mã đã đi qua, và xác định các ô mà mã có thể nhảy qua
    ====> nếu soi xét tại 1 vị trí khi mã đang đứng, thì ta có mấy cách để di chuyển ---> vẽ để xem
    có
    x x o x o x x x
    x o x x x o x x
    x x x o x x x x
    x o x x x o x x
    x x o x o x x x
    x x x x x x x x
    x x x x x x x x
    x x x x x x x x
    vị trí mã: (i, j)
    (i-1, j-2), (i-2,j-1), (i-2,j+1), (i-1,j+2), (i+1, j+ 2), (i+2,j+1), (i+2, j-1), (i+1, j-2)
    2 array:
    x[8] = {-1, -2, -2, -1, 1, 2, 2, 1}
    y[8] = {-2, -1, 1, 2, 2, 1, -1, -2}
*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

void printConfig(vector<pair<int, int> > &rs, fstream &out)
{
    for (int i = 0; i < rs.size(); i++)
    {
        out << "(" << rs[i].first << ", " << rs[i].second << ")" << endl;
    }
    out << "-----------------------------------------------------" << endl;
}

void Try(int i, int j, int n, int t, vector<vector<bool> > &danhDau, vector<int> &spaceX, vector<int> &spaceY, vector<pair<int, int> > &result, fstream &out)
{
    for (int k = 1; k <= 8; k++)
    {
        if ((i + spaceX[k] >= 1) && (j + spaceY[k] >= 1) && (i + spaceX[k] <= n) && (j + spaceY[k] <= n))
        {
            if (danhDau[i + spaceX[k]][j + spaceY[k]])
            {
                cout << t << endl;
                if (t == n * n)
                {
                    printConfig(result, out);
                    exit(0);
                }
                else
                {
                    danhDau[i + spaceX[k]][j + spaceY[k]] = false;
                    result.push_back(make_pair(i + spaceX[k], j + spaceY[k]));
                    Try(i + spaceX[k], j + spaceY[k], n, t + 1, danhDau, spaceX, spaceY, result, out);
                    danhDau[i + spaceX[k]][j + spaceY[k]] = true;
                    result.pop_back();
                }
            }
        }
    }
}

int main()
{
    fstream inFile("./bai_9.inp"), outFile("./bai_9.out");
    int n, x, y;
    inFile >> n >> x >> y;

    vector<int> spaceX;
    spaceX.push_back(0);
    spaceX.push_back(-1);
    spaceX.push_back(-2);
    spaceX.push_back(-2);
    spaceX.push_back(-1);
    spaceX.push_back(1);
    spaceX.push_back(2);
    spaceX.push_back(2);
    spaceX.push_back(1);
    vector<int> spaceY;
    spaceY.push_back(0);
    spaceY.push_back(-2);
    spaceY.push_back(-1);
    spaceY.push_back(1);
    spaceY.push_back(2);
    spaceY.push_back(2);
    spaceY.push_back(1);
    spaceY.push_back(-1);
    spaceY.push_back(-2);

    vector<vector<bool> > danhDau(n + 1, vector<bool>(n + 1, true));
    vector<pair<int, int> > result;
    result.push_back(make_pair(x, y));
    danhDau[x][y] = false;

    inFile.close();
    Try(x, y, n, 1, danhDau, spaceX, spaceY, result, outFile);
    outFile.close();
    return 0;
}
