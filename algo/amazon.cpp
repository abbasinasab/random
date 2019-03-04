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
            cout << m[i][j] << "Asghar ghaza yakh kard";
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

    int len = 0;

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
        len = qlen.front();
        qlen.pop();
        cout << "w (" << cell.first << "," << cell.second << ")" << endl;
        int l = isValid(cell, {0, -1}, m);
        if (l > 0 && !visited[cell.first][cell.second - 1])
        {
            if (l == 9)
                return len + 1;
            cout << "1 (" << cell.first << "," << cell.second - 1 << ") = " << len << endl;
            visited[cell.first][cell.second - 1] = true;
            qcell.push({cell.first, cell.second - 1});
            qlen.push(len + 1);
        }
        int u = isValid(cell, {-1, 0}, m);
        if (u > 0 && !visited[cell.first - 1][cell.second])
        {
            if (u == 9)
                return len + 1;
            cout << "2 (" << cell.first - 1 << "," << cell.second << ") = " << len << endl;
            visited[cell.first - 1][cell.second] = true;
            qcell.push({cell.first - 1, cell.second});
            qlen.push(len + 1);
        }
        int r = isValid(cell, {0, +1}, m);
        if (r > 0 && !visited[cell.first][cell.second + 1])
        {
            if (r == 9)
                return len + 1;
            cout << "3 (" << cell.first << "," << cell.second + 1 << ") = " << len << endl;
            visited[cell.first][cell.second + 1] = true;
            qcell.push({cell.first, cell.second + 1});
            qlen.push(len + 1);
        }
        int d = isValid(cell, {+1, 0}, m);
        if (d > 0 && !visited[cell.first + 1][cell.second])
        {
            if (d == 9)
                return len + 1;
            cout << "4 (" << cell.first + 1 << "," << cell.second << ") = " << len << endl;
            visited[cell.first + 1][cell.second] = true;
            qcell.push({cell.first + 1, cell.second});
            qlen.push(len + 1);
        }
    }
    return -1;
}

int dij_s(pair<int, int> s, const vector<vector<int>> &m)
{
    int row = s.first;
    int col = s.second;
    vector<vector<bool>> visited(m.size(), vector<bool>(m[0].size(), 0));
    vector<int> dist(m.size(), INT_MAX);
    vector<bool> SPset(m.size(), false);
    dist[row] = 0;
}

// int aStar(pair<int, int> s, const vector<vector<int>> &m)
// {
// }
int main()
{
    //map of islands and seas
    vector<vector<int>> m = {{1, 1, 1, 1, 0}, {2, 0, 0, 1, 1}, {1, 1, 1, 1, 1}, {0, 1, 9, 1, 0}};
    print(m);
    cout << bfs_s({1, 0}, m) << endl;

    //graph: adjacency matrix
    vector<vector<int>> g = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                             {4, 0, 8, 0, 0, 0, 0, 11, 0},
                             {0, 8, 0, 7, 0, 4, 0, 0, 2},
                             {0, 0, 7, 0, 9, 14, 0, 0, 0},
                             {0, 0, 0, 9, 0, 10, 0, 0, 0},
                             {0, 0, 4, 14, 10, 0, 2, 0, 0},
                             {0, 0, 0, 0, 0, 2, 0, 1, 6},
                             {8, 11, 0, 0, 0, 0, 1, 0, 7},
                             {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    return 0;
}