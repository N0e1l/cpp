#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 110;
int map[MAX_N][MAX_N];
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};//上、下、左、右
int path[MAX_N][MAX_N];//记录路径方向。0、1、2、3分别表示上下左右
int cnt[MAX_N][MAX_N];//相当于map的备份
struct node {
    int x;
    int y;
    int time;
    node(int x, int y, int time) {//构造方法
        this->x = x;
        this->y = y;
        this->time = time;
    }
};
struct nodecmp {
    bool operator()(const node &a, const node &b) {
        return a.time > b.time;
    }
};
int bfs(int n, int m) {
    memset(path, -1, sizeof(path));
    priority_queue<node, vector<node>, nodecmp> pq;
    pq.push(node(0, 0, 0) );
    map[0][0] = -1;
    while (pq.size()) {
        node tmp = pq.top();
        pq.pop();
        if (tmp.x == n - 1 && tmp.y == m - 1) return tmp.time;
        for (int i = 0; i < 4; ++i) {
            int nx = tmp.x + dir[i][0];
            int ny = tmp.y + dir[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != -1) {
                int t = tmp.time + map[nx][ny] + 1;
                pq.push(node(nx, ny, t) );
                path[nx][ny] = i;//记录方向
                map[nx][ny] = -1;//标记为已经访问过
            }
        }
    }
    return 0;
}

int tt;
void print(int a, int b) {
    int nx = a - dir[path[a][b]][0];
    int ny = b - dir[path[a][b]][1];
    if (a == 0 && b == 0) return ;
    print(nx, ny);
    printf("%ds:(%d,%d)->(%d,%d)\n", ++tt, nx, ny, a, b);
    while (cnt[a][b]-- > 0) printf("%ds:FIGHT AT (%d,%d)\n", ++tt, a, b);
}

int main () {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                char c;
                scanf(" %c", &c);
                if (c == 'X') map[i][j] = -1;
                else if (c == '.') map[i][j] = 0;
                else map[i][j] = c - '0';
                cnt[i][j] = map[i][j];
            }
        int ans = bfs(n, m);
        if (ans) {
            tt = 0;
            printf("It takes %d seconds to reach the target position, let me show you the way.\n", ans);
            print(n - 1, m - 1);
        }
        else printf("God please help our poor hero.\n");
        printf("FINISH\n");
    }
    return 0;
}