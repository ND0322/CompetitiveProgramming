// A C++ Program to generate test cases for
// an unweighted tree
#include<bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;

// Define the number of runs for the test data
// generated
#define RUN 1

// Define the maximum number of nodes of the tree
#define MAXNODE 10

class Tree
{
	int V; // No. of vertices

	// Pointer to an array containing adjacency vectorss
	vector<int> *adj;

	// used by isCyclic()
	bool isCyclicUtil(int v, bool visited[], bool *rs);
public:
	Tree(int V); // Constructor
	void addEdge(int v, int w); // adds an edge
	void removeEdge(int v, int w); // removes an edge

	// returns true if there is a cycle in this graph
	bool isCyclic();
};

// Constructor
Tree::Tree(int V)
{
	this->V = V;
	adj = new vector<int>[V];
}

void Tree::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s vector.
}

void Tree::removeEdge(int v, int w)
{
	vector<int>::iterator it;
	for (it=adj[v].begin(); it!=adj[v].end(); it++)
	{
		if (*it == w)
		{
			adj[v].erase(it);
			break;
		}
	}
	return;
}

// This function is a variation of DFSUytil() in
// https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
bool Tree::isCyclicUtil(int v, bool visited[], bool *recStack)
{
	if (visited[v] == false)
	{
		// Mark the current node as visited and part of
		// recursion stack
		visited[v] = true;
		recStack[v] = true;

		// Recur for all the vertices adjacent to this vertex
		vector<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
				return true;
			else if (recStack[*i])
				return true;
		}

	}
	recStack[v] = false; // remove the vertex from recursion stack
	return false;
}

// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in
// https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
bool Tree::isCyclic()
{
	// Mark all the vertices as not visited and not part of recursion
	// stack
	bool *visited = new bool[V];
	bool *recStack = new bool[V];
	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
		recStack[i] = false;
	}

	// Call the recursive helper function to detect cycle in different
	// DFS trees
	for (int i = 0; i < V; i++)
		if (isCyclicUtil(i, visited, recStack))
			return true;

	return false;
}

int main()
{
	set<pair<int, int>> container;
	set<pair<int, int>>::iterator it;

	// Uncomment the below line to store
	// the test data in a file
	// freopen ("Test_Cases_Unweighted_Tree.in", "w", stdout);

	//For random values every time
	srand(time(NULL));

	int NUM; // Number of Vertices/Nodes

	for (int i=1; i<=RUN; i++)
	{
		NUM = 1 + rand() % MAXNODE;

		// First print the number of vertices/nodes
		printf("%d\n", NUM);
		Tree t(NUM);
		// Then print the edges of the form (a b)
		// where 'a' is parent of 'b'
		for (int j=1; j<=NUM-1; j++)
		{
			int a = rand() % NUM;
			int b = rand() % NUM;
			pair<int, int> p = make_pair(a, b);

			t.addEdge(a, b);

			// Search for a random "new" edge everytime
			while (container.find(p) != container.end()
					|| t.isCyclic() == true)
			{
				t.removeEdge(a, b);

				a = rand() % NUM;
				b = rand() % NUM;
				p = make_pair(a, b);
				t.addEdge(a, b);
			}
			container.insert(p);
		}

		for (it=container.begin(); it!=container.end(); ++it)
			printf("%d %d %d\n", it->first+1, it->second+1, rand() % 15 + 1);

		container.clear();
		printf("\n");
	}

	// Uncomment the below line to store
	// the test data in a file
	// fclose(stdout);
	return(0);
}
