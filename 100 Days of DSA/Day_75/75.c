#include <stdio.h>
#include <stdbool.h>

#define MAX 1001

int adj[MAX][MAX];
bool visited[MAX];
int n, m;

void dfs(int u) {
    visited[u] = true;
    for (int v = 1; v <= n; v++) {
        if (adj[u][v] == 1 && !visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i <= n; i++) {
        visited[i] = false;
        for (int j = 0; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            count++;
            dfs(i);
        }
    }

    printf("%d\n", count);

    return 0;
}