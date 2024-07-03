#include <stdio.h>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <fstream>
#include "Graphe.h" //custom graph class header 

using namespace std;

ifstream fin("index.in.txt"); //input file
ofstream fout("index.out.txt"); //output file

Graph<int, int> g(27); 
char* visited;
stack<int> s;//stack for topologic sort FILO

// Depth-First Search (DFS) function
void dfs(int x) {
    int y;
    //printf("%d\n", x);
    cout << char(x + 'a' - 1) << " "; // Print the character corresponding to the node
    visited[x] = 1; // Mark the node as visited

    //traverse all the nodes
    for (y = 0; y < g.N; y++)
        if (g.A[x][y] && !visited[y])
            dfs(y);
}

// Topologic Sort function
void topologicSort(int x) { 

    // Recursively visit all adjacent nodes
    for (int i = 0; i < g.N; i++)
        if (g.A[x][i] && !visited[i])
            topologicSort(i);

    visited[x] = 1; // Mark the node as visited
    s.push(x); // Push the node to the stack
    cout << char(x + 'a' - 1) << " ";

}

// Function to compare letters of two consecutive words and build the graph
void compareLetters(int n, string v[]) {
    for (int i = 0; i < n - 2; i++) {
        int ok = 0;

        cout << v[i] << " " << v[i].length() << endl;
        cout << v[i + 1] << " " << v[i + 1].length() << endl;

        // Compare characters of two words
        if (v[i].length() >= v[i + 1].length()) {
            for (int j = 0; j < v[i + 1].length(); j++) {

                cout << v[i][j] << " - " << v[i + 1][j] << endl;
                if (v[i][j] == v[i + 1][j])
                    ok++;
                if (ok == j && v[i][j] != v[i + 1][j]) {
                    cout << v[i][j] << v[i + 1][j] << endl;
                    g.addEdge(v[i][j] - 'a' + 1, v[i + 1][j] - 'a' + 1);
                    ok = 0;
                }
            }
        }
        else if (v[i].length() < v[i + 1].length()) {
            for (int j = 0; j < v[i].length(); j++) {

                cout << v[i][j] << " - " << v[i + 1][j] << endl;
                if (v[i][j] == v[i + 1][j])
                    ok++;
                if (ok == j && v[i][j] != v[i + 1][j]) {
                    cout << v[i][j] << v[i + 1][j] << endl;
                    g.addEdge(v[i][j] - 'a' + 1, v[i + 1][j] - 'a' + 1);
                    ok = 0;
                }
            }
        }
        cout << endl;
    }
}

int main() {
    string v[50]; // Array to store words from the input file
    int n = 0; // Number of words

    // Read words from the input file until "." is encountered
    while (fin && v[n] != ".")
    {
        fin >> v[n];
        n++;
    }

    // Print all words read from the input file
    for (int i = 0; i < n; i++)
        cout << v[i] << endl;

    char c = v[0][0]; // Obtain the first character of the first word
    cout << "First letter: " << c << endl;

    compareLetters(n, v); // Build the graph based on word comparisons

    /*
    visited = new char[g.N];
    for (int i = 0; i < g.N; i++)
        visited[i] = 0;

    dfs(c - 'a' + 1);
    cout << endl;
    */

   // Initialize the visited array for topological sort
    visited = new char[g.N];
    for (int i = 0; i < g.N; i++)
        visited[i] = 0;

    topologicSort(c - 'a' + 1); // Perform topological sort

    // Output the sorted characters to the output file
    while (!s.empty()) {
        fout << char(s.top() + 'a' - 1);
        s.pop();
    }
    fin.close();
    fout.close();
}



/*
Sample input in index.in.txt:

ion
ana
adonia
doina
doinn
ddan
ddao

b


xwy
zx
zxy
zxw
ywwx
*/