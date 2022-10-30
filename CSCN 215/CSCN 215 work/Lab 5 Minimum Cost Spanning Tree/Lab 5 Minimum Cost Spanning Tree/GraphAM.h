// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Include this file to access Graph representation implemented using an
// Adjacency Matrix.

#include "GraphADT.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

// Used by the mark array
#define UNVISITED 0
#define VISITED 1

enum INCLUDED { INCLUDED, EXCLUDED };

// Implementation for the adjacency matrix representation
class GraphAM : public Graph {
private:
    int numVertex, numEdge; // Store number of vertices, edges
    int** matrix;           // Pointer to adjacency matrix
    int* mark;              // Pointer to mark array
    ifstream readFile;
    ofstream writeFile;

    // Function to make sure filename is valid
    bool isValidFile(string file) {
        bool valid = file.find(".txt") != string::npos;
        if (!valid) {
            cout << "Unable to read file '" << file << "': invalid format." << endl;
        }
        return valid;
    }

    // Read graph from file
    void read(string file) {
        if (!isValidFile(file)) return;

        string buffer;
        int index = 0;
        int row = 0;
        bool valid = true;
        readFile.open(file);

        while (getline(readFile, buffer)) {

            // Update graph based on the state of the file input
            if (index == 0) {
                valid = (buffer == "Graph");
            }
            else if (index == 1) {
                int numIndex = (int)buffer.find("Num_Vertices=");
                int numVertices;
                valid = (numIndex != string::npos);
                if (valid) {
                    numVertices = stoi(buffer.substr(numIndex + 13, (buffer.size() - numIndex + 13)));
                    Init(numVertices); // this is another notation I learned while creating this file that 
                                      //  subtracts the buffer size from the index number
                }
            }
            else { // else statement that sets the edges correctly
                stringstream line;
                line.str(buffer);
                int weight = 0;
                for (int col = 0; col < numVertex; col++) {
                    line >> weight;
                    if (weight != 0) {
                        setEdge(row, col, weight);
                    }
                    weight = 0;
                }
                row++;
            }
            // Check for validity of file input
            if (!valid) {
                cout << "Unable to read file '" << file << "': invalid format." << endl;
                return;
            }

            // Update/clear variables
            buffer.clear();
            index++;
        }
        readFile.close();
    }

    // Find minimum cost vertex
    int minVertex(GraphAM* G, int* D) { // implementing smart pointers into the graph implementation
        int i, v = -1;
        // Get first unvisited node
        for (i = 0; i < G->n(); i++) {
            if (G->getMark(i) == UNVISITED) {
                v = i;
                break;
            }
        }
        // Check all subsequent nodes to see if one exists such that 
        // A) it is also unvisited
        // B) it has a cheaper cost
        for (i++; i < G->n(); i++) {
            if (G->getMark(i) == UNVISITED && D[i] < D[v]) {
                v = i;
            }
        }
        return v;
    }

public:
    GraphAM(int numVert)     // Constructor
    {
        Init(numVert);
    }
    GraphAM(string file) {
        read(file);
    }
    ~GraphAM() {       // Destructor
        delete[] mark; // Return dynamically allocated memory
        for (int i = 0; i < numVertex; i++)
            delete[] matrix[i];
        delete[] matrix;
    }

    void Init(int n) { // Initialize the graph
        int i;
        numVertex = n;
        numEdge = 0;
        mark = new int[n];     // Initialize mark array
        for (i = 0; i < numVertex; i++)
            mark[i] = UNVISITED;
        matrix = (int**) new int* [numVertex]; // Make matrix
        for (i = 0; i < numVertex; i++)
            matrix[i] = new int[numVertex];
        for (i = 0; i < numVertex; i++) // Initialize to 0 weights
            for (int j = 0; j < numVertex; j++)
                matrix[i][j] = 0;
    }

    int n() { return numVertex; } // Number of vertices
    int e() { return numEdge; }   // Number of edges

    // Return first neighbor of "v"
    int first(int v) {
        for (int i = 0; i < numVertex; i++)
            if (matrix[v][i] != 0) return i;
        return numVertex;           // Return n if none
    }

    // Return v's next neighbor after w
    int next(int v, int w) {
        for (int i = w + 1; i < numVertex; i++)
            if (matrix[v][i] != 0)
                return i;
        return numVertex;           // Return n if none
    }

    // Set edge (v1, v2) to "wt"
    void setEdge(int v1, int v2, int wt) {
        if (wt >= 0) {
            if (matrix[v1][v2] == 0) {
                numEdge++;
            }
            matrix[v1][v2] = wt;
            matrix[v2][v1] = wt; // after debugging I made this change in order for the output to be 8
        }
    }


    void delEdge(int v1, int v2) { // Delete edge (v1, v2)
        if (matrix[v1][v2] != 0) numEdge--;
        matrix[v1][v2] = 0;
    }

    bool isEdge(int i, int j) // Determine if an edge is in the graph
    {
        return matrix[i][j] != 0;
    }

    int weight(int v1, int v2) {
        return matrix[v1][v2];
    }
    int getMark(int v) {
        return mark[v];
    }
    void setMark(int v, int val) {
        mark[v] = val;
    }

    // Print Graph to console and formatting 
    void print(bool mst) const {
        if (!mst) {
            cout << "Number of vertices is " << numVertex << endl;
            cout << "Number of edges is " << numEdge << endl;
            cout << "Matrix:" << endl;
        }
        for (int row = 0; row < numVertex; row++) {
            for (int col = 0; col < numVertex; col++) {
                cout << matrix[row][col] << " ";
            }
            cout << endl;
        }
        cout << "End of MST" << endl;
    }

    // Write graph to file
    void write(string file) {
        if (!isValidFile(file)) return;

        writeFile.open(file);

        writeFile << "Graph" << endl;
        writeFile << "Num_Vertices=" << numVertex << endl;

        for (int row = 0; row < numVertex; row++) {
            for (int col = 0; col < numVertex; col++) {
                writeFile << matrix[row][col];
                if (col + 1 < numVertex) {
                    writeFile << " ";
                }
            }
            writeFile << endl;
        }

        writeFile.close();
    }

    // Generate a minimum cost spanning tree starting from vertex v
    GraphAM* MCST(int s) {
        GraphAM* mst = new GraphAM(numVertex);
        cout << endl << "Begin MST starting at vertex " << s << endl;

        // Used Prim's Algorithm to perform the MST
        int* D = new int[this->n()]; // Array of weights
        int* V = new int[this->n()]; // Array of node markers, manages state of node included/excluded
        int i, w;

        // Set all weights to infinite
        for (int i = 0; i < this->n(); i++) {
            D[i] = INT_MAX;
            V[i] = INT_MAX;
            this->setMark(i, UNVISITED);
        }
        D[s] = 0;
        for (i = 0; i < this->n(); i++) {
            int v = minVertex(this, D);
            this->setMark(v, VISITED);
            if (v != s) {
                int a = (V[v] == INT_MAX ? s : V[v]); //altervative from an if statement
                cout << "Add Edge " << a << " to " << v << endl; // formatting in order to display the edges
                mst->setEdge(a, v, D[v]);
                mst->setEdge(v, a, D[v]);
            }
            if (D[v] == INFINITY) return mst;

            for (w = this->first(v); w < this->n(); w = this->next(v, w)) {
                if (D[w] > this->weight(v, w)) {
                    D[w] = this->weight(v, w);
                    V[w] = v;
                }
            }
        }

        mst->print(true);
        return mst;
    }
};