#include <iostream>
#include <vector>
#define MAXVEX 20
#define GRAPH_INFINITY 65536
using namespace std;

typedef struct {
    int vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
}Graph;

void createGraph(Graph* G) {
    G->numEdges = 16;
    G->numVertexes = 9;

    // 将各个顶点的下标存储在vexs数组内
    for (int i = 0; i < G->numVertexes; ++i) G->vexs[i] = i;

    // 初始化各边权值
    for (int i = 0; i < G->numVertexes; ++i) {
        for (int j = 0; j < G->numVertexes; ++j) {
            if (i == j) G->arc[i][j] = 0;
            else G->arc[i][j] = G->arc[j][i] = GRAPH_INFINITY;
        }
    }

    // 构建此无向图的各边权值
	G->arc[0][1]=1;
	G->arc[0][2]=5; 
	G->arc[1][2]=3; 
	G->arc[1][3]=7; 
	G->arc[1][4]=5; 
	G->arc[2][4]=1; 
	G->arc[2][5]=7; 
	G->arc[3][4]=2; 
	G->arc[3][6]=3; 
	G->arc[4][5]=3;
	G->arc[4][6]=6;
	G->arc[4][7]=9; 
	G->arc[5][7]=5; 
	G->arc[6][7]=2; 
	G->arc[6][8]=7;
	G->arc[7][8]=4;

    for (int i = 0; i < G->numVertexes; ++i) {
        for (int j = i; j < G->numVertexes; ++j) G->arc[j][i] = G->arc[i][j];
    }
}

/**
 * 算法步骤：
 * 1.初始化：设置三个数组
 *  final[Vertex]:标记各顶点是否已找到最短路径
 *  dist[Vertex]:最短路径长度
 *  path[Vertex]:路径上的前驱
 * 2.算法开始：若从V0开始 令final[0]=true; dist[0]=0; path[0]=-1;
 *           其余顶点final[k]=false; dist[k]=arcs[0][k]; path[k]=(arcs[0][k]==无穷) ? -1 : 0;
 * 3.n-1轮处理：循环遍历所有顶点，找到还没确定最短路径，且dist最小的顶点Vi,令final[i]=true;
 *             检查所有邻接自Vi的顶点，对于邻接自Vi的顶点Vj，若final[j]=false且dist[i]+arcs[i][j]<dist[j],
 *             则令dist[j]=dist[i]+arcs[i][j]; path[j]=i;
*/
void ShortestPath_Dijkstra(Graph* G, int& start, vector<int>& dist, vector<int>& path) {
    // start变量记录的是出发节点的下标
    vector<bool> final(G->numVertexes, false); //标记各节点是否已找到最短路径
    for (int i = 0; i < G->numVertexes; ++i) {
        dist[i] = G->arc[start][i]; //初始化各个顶点与起始节点之间的路径长度
        path[i] = -1; //初始化路径数组为-1 即路径上当前节点的前一个节点的下标值为-1
    }
    final[start] = true; //start节点开始 标记为已经找到到start的最短路径
    dist[start] = 0; //start到start的最短路径为0

    // 开始主循环 每次求得start到某个顶点的最短路径
    for (int i = 1; i < G->numVertexes; ++i) {
        // 求出从start节点出发 权值最小的一个节点minVertex 以及最小的权值minDist
        int minDist = GRAPH_INFINITY;
        int minVertex;
        int j;
        for (j = 0; j < G->numVertexes; ++j) {
            if (!final[j] && dist[j] < minDist) {
                minVertex = j;
                minDist = dist[j];
            }
        }
        final[minVertex] = true; //表示j是目前找到的最近节点 将其final数组对应下标置为true

        // 以下为修正到start最短距离dist数组的代码
        for (j = 0; j < G->numVertexes; ++j) {
            if (!final[j] && (minDist + G->arc[minVertex][j]) < dist[j]) {
                // 找到了更短的路径 即通过minVertex周转的路径 此时需要修改dist数组
                dist[j] = minDist + G->arc[minVertex][j];
                path[j] = minVertex;
            }
        }
    }
}

void printOutput(Graph* G, int& start, vector<int>& dist, vector<int>& path) {
    cout << "The shortest path from start index are: " << endl;
    for (int i = 1; i < G->numVertexes; ++i) {
        cout << "V" << start << "->" << "V" << i << ": ";
        int j = i;
        cout << "V" << j << "<-";
        while (path[j] != -1) {
            cout << "V" << path[j] << "<-";
            j = path[j];
        }
        cout << "V" << start << endl;
    }
    cout << "the shortest path from start index to vertexs are: " << endl;
    for (int i = 1; i < G->numVertexes; ++i) {
        cout << "V" << start << "--" << "V" << i << ": " << dist[i] << endl;
    }
}

int main() {
    Graph G;
    createGraph(&G);
    vector<int> dist(G.numVertexes); //记录最短路径长度
    vector<int> path(G.numVertexes); //记录路径上的前驱节点
    int start = 0; //起始节点的下标
    ShortestPath_Dijkstra(&G, start, dist, path);
    printOutput(&G, start, dist, path);
    
    return 0;
}