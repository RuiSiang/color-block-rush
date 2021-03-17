#include"common.h"
//#include<iostream>
#include<queue>
#define M 18
#define N 18
#define L_MAX 324
struct Node {
    int x, y, dist;
};
int row[] = { -1, 0, 0, 1 };
int col[] = { 0, -1, 1, 0 };
bool isValid(int mat[][N], bool visited[][N], int row, int col)
{
    return (row >= 0) && (row < M) && (col >= 0) && (col < N)
           && mat[row][col] && !visited[row][col];
}
int BFS(int mat[][N], int i, int j, int x, int y)
{
    bool visited[M][N];
    memset(visited, false, sizeof visited);
    std::queue<Node> q;
    visited[i][j] = true;
    q.push({i, j, 0});
    int min_dist = L_MAX;
    while (!q.empty()) {
        Node node = q.front();
        q.pop();
        int i = node.x, j = node.y, dist = node.dist;
        if (i == x && j == y) {
            min_dist = dist;
            break;
        }
        for (int k = 0; k < 4; k++) {
            if (isValid(mat, visited, i + row[k], j + col[k])) {
                visited[i + row[k]][j + col[k]] = true;
                q.push({ i + row[k], j + col[k], dist + 1 });
            }
        }
    }

    if (min_dist<=L_MAX) {
        return min_dist;
    } else {
        return L_MAX;
    }
}
int get_distance(int _sx, int _sy, int _ex, int _ey)
{
    int mat[M][N];
    int ch;
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            ch=m.array[i][j];
            if(ch<=2||ch>=6) {
                mat[i][j]=1;
            } else {
                mat[i][j]=0;
            }
        }
    }
    return BFS(mat, _sx, _sy, _ex, _ey);
}
