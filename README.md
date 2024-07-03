# Unknown Language Alphabet Order

## Overview
This project is designed to determine the order of characters in an unknown language based on a given index of words. The solution utilizes graph theory and topological sorting to decipher the character sequence.

## Files
- `index.in.txt`: Input file containing the list of words in the unknown language.
- `index.out.txt`: Output file that will contain the correct sequence of characters in the unknown language.
- `main.cpp`: The main C++ source code file for the project.
- `Graphe.h`: Header file for the custom graph class used in the project.
- `Graphe.cpp`: Implementation file for the custom graph class (assumed to be present based on the header file inclusion).

## Input Format
- The input file index.in.txt contains a list of words followed by a line with a single "." character.
- Each word consists of lowercase English letters.
- There are at least 1 and at most 50 words, each having at most 10 characters.

## Output Format
- The output file index.out.txt will contain a sequence of characters representing the correct alphabetical order in the unknown language.

## How to Run
1. Ensure you have a C++ compiler installed (e.g., g++).
2. Place the `main.cpp`, `Graphe.h`, and `index.in.txt` files in the same directory.
3. Compile the program using the following command
```
g++ main.cpp Graphe.cpp -o determine_order
```
4. Run the compiled program:
```
./determine_order
```
5. The output will be written to `index.out.txt`.

## Explanation of the Code
The code performs the following steps:

1. Read Input:
    - Reads words from index.in.txt until a "." is encountered.
2. Build Graph:
    - Compares each pair of consecutive words to determine the order of characters.
    - Adds directed edges between characters to a graph.
3. Topological Sort:
    - Performs a topological sort on the graph to find the correct sequence of characters.
4. Output Result:
    - Writes the sorted sequence to index.out.txt.
5. Key Functions
    - dfs(int x): A recursive function for performing depth-first search on the graph.
    - topologicSort(int x): A recursive function for performing topological sort on the graph.
    - comparareLitere(int n, string v[]): Compares characters of consecutive words and builds the graph.
    - main(): The main function that orchestrates reading input, building the graph, performing topological sort, and writing the output.