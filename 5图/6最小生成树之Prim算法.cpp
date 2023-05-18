#include <iostream>
#include <vector>
#define MAXVEX 20
#define GRAPH_INFINITY 65536
using namespace std;

typedef struct {
    int weight[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
}Graph;

void createGraph(Graph* G) {
    G->numEdges = 15;
    G->numVertexes = 9;
    for (int i = 0; i < G->numVertexes; ++i) {
        for (int j = 0; j < G->numVertexes; ++j) {
            if (i == j) G->weight[i][j] = 0;
            else G->weight[i][j] = GRAPH_INFINITY;
        }
    }
    G->weight[0][1]=10;
	G->weight[0][5]=11; 
	G->weight[1][2]=18; 
	G->weight[1][8]=12; 
	G->weight[1][6]=16; 
	G->weight[2][8]=8; 
	G->weight[2][3]=22; 
	G->weight[3][8]=21; 
	G->weight[3][6]=24; 
	G->weight[3][7]=16;
	G->weight[3][4]=20;
	G->weight[4][7]=7; 
	G->weight[4][5]=26; 
	G->weight[5][6]=17; 
	G->weight[6][7]=19;
    for (int i = 0; i < G->numVertexes; ++i) {
        for (int j = i; j < G->numVertexes; ++j) {
            G->weight[j][i] = G->weight[i][j];
        }
    }
}

// 算法步骤：
// 1.初始化 将v0加入生成树节点数组，设置最小代价数组
// 2.循环遍历所有节点 更新最小代价数组 得到最小代价及其对应节点
// 3.将最小代价节点加入生成树节点数组 收集最小代价结果
// 4.重复步骤 2、3 直到遍历完所有节点
void MiniSpanTree_Prim(Graph* G, vector<vector<int>>& path, int& totalCost) {
    vector<int> isJoin(G->numVertexes); //存储已经加入树的节点下标 0表示未加入 1表示已加入
    vector<int> lowCost(G->numVertexes, GRAPH_INFINITY); //存储各节点加入树的最小代价
    // 初始化 v0节点加入生成树
    isJoin[0] = 1;
    lowCost[0] = 0;
    int minCost = GRAPH_INFINITY;
    int minVertex = 0;
    int count = G->numVertexes - 1;
    while (count--) {
        int joinIndex = minVertex;
        int minCost = GRAPH_INFINITY;
        // 遍历所有节点 更新lowcost数组 找到新的加入生成树的最小代价 以及对应节点
        for (int i = 0; i < G->numVertexes; ++i) {
            if (isJoin[i] == 0 && G->weight[joinIndex][i] < lowCost[i]) {
                lowCost[i] = G->weight[joinIndex][i];
            }
            if (isJoin[i] == 0 && lowCost[i] < minCost) {
                minCost = lowCost[i];
                minVertex = i;
            }
        }
        isJoin[minVertex] = 1;
        totalCost += minCost;
        //path不对 不知道如何记录加入的每一条边
        path.push_back({joinIndex, minVertex});
        lowCost[minVertex] = 0;      
    }
}

void printOutput(vector<vector<int>>& path, int& totalCost) {
    cout << "Min Cost Path is: ";
    for (vector<vector<int>>::iterator iter = path.begin(); iter != path.end(); ++iter) {
        for (vector<int>::iterator it = (*iter).begin(); it != (*iter).end(); ++it) {
            cout << *it << ",";
        }
        cout << " ";
    }
    cout << endl;
    cout << "Total Cost is: " << totalCost << endl;
}

int main() {
    Graph G;
    vector<vector<int>> path;
    int totalCost = 0;
    createGraph(&G);
    MiniSpanTree_Prim(&G, path, totalCost);
    printOutput(path, totalCost);
    return 0;
}