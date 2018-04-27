# Graphs

Tour Guide System project for CS250.
This system is implemented with an Adjacency Matrix format and uses the following algorithms:
Dijkstra's Algorithm
Prim-Jarnik Algorithm

# Shortest Distance
Uses Dijkstra's Algorithm to find the least expensive trip from a source to a destination in the graph.

# Euler Tour
Uses the Prim-Jarnik Algorithm to create minimum spanning tree that is then traversed using a simple Euler Tour tree traversal method.

# Usage

Type " ./program < 'input file name' " to use the program
Input files must be formatted properly for each part in order to achieve desired results.

The first line of input should contain the part of the project you wish to run: 1 for connected components, 2 for shortest path, and 3 for Euler Tour

The second line should contain the number of cities followed by the number of possible routes through the graph separated by a space

The following lines should contain the two city names that will make up the edges followed by the weight of the edge between them: IND LAX 200.00

If you are using the shortest path functionality add any number of lines containg a source city and a destination city separated by a space. Once you have finished adding paths, add one final line that says END

If you are using the Euler Tour functionality follow the same inputs but instead end the file with the city that will be the root of the Tour.

See tests folder for input referencing.
