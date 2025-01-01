#include <stdio.h> #include <stdlib.h> #include <stdbool.h>
#define MAX 100 
struct Graph 
{
int vertices;
int adjMatrix[MAX][MAX];
};

void initGraph(struct Graph* g, int vertices) { g->vertices = vertices;
for (int i = 0; i < vertices; i++) { for (int j = 0; j < vertices; j++) {
g->adjMatrix[i][j] = 0;
}
}
}

void addEdge(struct Graph* g, int u, int v)
{
    g->adjMatrix[u][v] = 1;
g->adjMatrix[v][u] = 1;
}

void dfs(struct Graph* g, int vertex, bool visited[]) 
{ 
visited[vertex] = true;
for (int i = 0; i < g->vertices; i++) 
{
if (g->adjMatrix[vertex][i] == 1 && !visited[i]) 
{ 
dfs(g, i, visited);
  	      	}
      	      }
}

bool isConnected(struct Graph* g) { bool visited[MAX] = {false}; dfs(g, 0, visited);
for (int i = 0; i < g->vertices; i++) { if (!visited[i]) {
return false;
}
}
return true;
}

int main() { struct Graph g;
int vertices = 6; initGraph(&g, vertices);

addEdge(&g, 0, 1);
addEdge(&g, 0, 2);
addEdge(&g, 1, 3);
addEdge(&g, 1, 4);
addEdge(&g, 2, 5);

if (isConnected(&g)) {
printf("The graph is connected.\n");
} else {
printf("The graph is not connected.\n");
}

return 0;
}
