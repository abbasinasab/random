#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

vector<int> bfs_sd(pair<int, int> s, pair<int, int> d, vector<vector<int>> m)
{
    vector<int> shortest_path;
    return shortest_path;
}
void print(const vector<vector<int>> &m)
{
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[0].size(); j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
}
int isValid(const pair<int, int> &s, const pair<int, int> offset, const vector<vector<int>> &m)
{
    int row = s.first + offset.first;
    int col = s.second + offset.second;
    //cout << "isV (" << row << "," << col << ") = " << m[row][col] << endl;
    if (-1 < row && row < m.size() && -1 < col && col < m[0].size())
        return m[row][col];
    return -1;
}
int bfs_s(pair<int, int> s, const vector<vector<int>> &m)
{
    int row = s.first;
    int col = s.second;
    pair<int, int> cell;
    vector<vector<bool>> visited(m.size(), vector<bool>(m[0].size(), 0));

    int l = 0;

    vector<int> shortest_path;
    queue<pair<int, int>> qcell;
    queue<int> qlen;
    queue<pair<int, int>> qpath;
    visited[row][col] = true;
    qcell.push(s);
    qlen.push(0);

    while (!qcell.empty())
    {
        cell = qcell.front();
        qcell.pop();
        //l = qlen.front();
        //qlen.pop();
        cout << "w (" << cell.first << "," << cell.second << ")" << endl;
        int l = isValid(cell, {0, -1}, m);
        if (l > 0 && !visited[cell.first][cell.second - 1])
        {
            if (l == 9)
                cout << "yay" << endl;
            cout << "1 (" << cell.first << "," << cell.second - 1 << ")" << endl;
            visited[cell.first][cell.second - 1] = true;
            qcell.push({cell.first, cell.second - 1});
        }
        int u = isValid(cell, {-1, 0}, m);
        if (u > 0 && !visited[cell.first - 1][cell.second])
        {
            if (u == 9)
                cout << "yay" << endl;
            cout << "2 (" << cell.first - 1 << "," << cell.second << ")" << endl;
            visited[cell.first - 1][cell.second] = true;
            qcell.push({cell.first - 1, cell.second});
        }
        int r = isValid(cell, {0, +1}, m);
        if (r > 0 && !visited[cell.first][cell.second + 1])
        {
            if (r == 9)
                cout << "yay" << endl;
            cout << "3 (" << cell.first << "," << cell.second + 1 << ")" << endl;
            visited[cell.first][cell.second + 1] = true;
            qcell.push({cell.first, cell.second + 1});
        }
        int d = isValid(cell, {+1, 0}, m);
        if (d > 0 && !visited[cell.first + 1][cell.second])
        {
            if (d == 9)
                cout << "yay" << endl;
            cout << "4 (" << cell.first + 1 << "," << cell.second << ")" << endl;
            visited[cell.first + 1][cell.second] = true;
            qcell.push({cell.first + 1, cell.second});
        }
    }
    return 0;
}

int main()
{
    vector<vector<int>> m = {{1, 1, 1, 1, 0}, {2, 0, 0, 1, 1}, {1, 1, 1, 1, 1}, {0, 1, 9, 1, 0}};
    print(m);
    bfs_s({1, 0}, m);
    return 0;
}