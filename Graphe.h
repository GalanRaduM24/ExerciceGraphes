#include <stdio.h>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

template<typename TnodeInfo, typename TedgeInfo>
class Graph {
public:
    int N;//numar de noduri
    char** A;//matrice
    TnodeInfo* nodeInfo;
    TedgeInfo** edgeInfo;

    Graph(int numNodes) {
        int i, j;

        N = numNodes;

        // allocation de la matrice d'adjacence
        A = new char* [N];
        for (i = 0; i < N; i++)
            A[i] = new char[N];

        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                A[i][j] = 0;

        // allocation de l'info des noeuds
        nodeInfo = new TnodeInfo[N];

        // allocation de la matrice avec l'info des aretes
        edgeInfo = new TedgeInfo * [N];
        for (i = 0; i < N; i++)
            edgeInfo[i] = new TedgeInfo[N];
    }

    void setNodeInfo(int i, TnodeInfo info) {
        nodeInfo[i] = info;
    }

    TnodeInfo getNodeInfo(int i) {
        return nodeInfo[i];
    }

    void addEdge(int i, int j) {
        A[i][j] = 1;
    }

    void removeEdge(int i, int j) {
        A[i][j]  = 0;
    }

    void setEdgeInfo(int i, int j, TedgeInfo info) {
        edgeInfo[i][j] = info;
    }

    TedgeInfo getEdgeInfo(int i, int j) {
        return edgeInfo[i][j];
    }

    ~Graph() {
        int i;
        for (i = 0; i < N; i++) {
            delete A[i];
            delete edgeInfo[i];
        }
        delete A;
        delete edgeInfo;
        delete nodeInfo;
    }


};
