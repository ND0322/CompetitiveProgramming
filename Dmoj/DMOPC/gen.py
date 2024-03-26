# A Python3 program to generate test cases for
# an unweighted tree
import random

# Define the number of runs for the test data
# generated
RUN = 1

# Define the maximum number of nodes of the tree
MAXNODE = 5

# Define the maximum weight of edges
MAXWEIGHT = 15

class Tree:
	def __init__(self, V):
		self.V = V
		self.adj = [[] for i in range(V)]

	def addEdge(self, v, w):
		self.adj[v].append(w)

	def removeEdge(self, v, w):
		for i in self.adj[v]:
			if i == w:
				self.adj[v].remove(i)
				break
		return

	# This function is a variation of DFSUytil() in
	# https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
	def isCyclicUtil(self, v, visited, recStack):
		visited[v] = True
		recStack[v] = True

		# Recur for all the vertices adjacent to this vertex
		for i in self.adj[v]:
			if visited[i] == False and self.isCyclicUtil(i, visited, recStack):
				return True
			elif recStack[i]:
				return True

		# remove the vertex from recursion stack
		recStack[v] = False

		return False

	# Returns true if the graph contains a cycle, else false.
	# This function is a variation of DFS() in
	# https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
	def isCyclic(self):
		# Mark all the vertices as not visited and not part
		# of recursion stack
		visited = [False] * self.V
		recStack = [False] * self.V

		# Call the recursive helper function to detect cycle
		# in different DFS trees
		for i in range(self.V):
			if visited[i] == False:
				if self.isCyclicUtil(i, visited, recStack) == True:
					return True

		return False

for i in range(RUN):
	NUM = 1 + random.randint(0, MAXNODE-1)

	# First print the number of vertices/nodes
	print(NUM)
	t = Tree(NUM)

	# Then print the edges of the form (a b)
	# where 'a' is parent of 'b'
	for j in range(NUM-1):
		a = random.randint(0, NUM-1)
		b = random.randint(0, NUM-1)

		t.addEdge(a, b)

		# Search for a random "new" edge everytime
		while t.isCyclic() == True or a == b:
			t.removeEdge(a, b)
			a = random.randint(0, NUM-1)
			b = random.randint(0, NUM-1)
			t.addEdge(a, b)

	# Then print the weights of the form (a b wt)
	for j in range(NUM-1):
		a = random.randint(0, NUM-1)
		b = random.randint(0, NUM-1)
		wt = 1 + random.randint(0, MAXWEIGHT-1)
		print(f"{a+1} {b+1} {wt}")

	print()
