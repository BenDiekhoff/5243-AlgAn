"""
//***************************************************************
// Program #2 Adjacency List & Matrix Generator for Undirected Graph 
// Name: Ben Diekhoff
// CMPS 5243 Algorithms
// Dr. Halverson
// Date: 04/26/2020
//***************************************************************
/*
This program reads in edges from 3 datafiles. For each file it reads, 
It generates an adjacency list and an adjacency matrix, and prints them
to output files for the lists and matrices. The input files can only be read
once, and the lists and matrices must be printed in lexicographical order.
/******************************************************************/
"""
from collections import defaultdict

# Create a dictionary to hold the adjacency list
# defaultdict allows the program to acess keys that don't already exist in
# the dict.
adjList = defaultdict(list)

# Create a set that will contain each vertex only once.
vertices = set()

# 2D dictionary to hold the adjacency matrix
adjMatrix = defaultdict(dict)

# represents |V|
cardinalV = 0

# List of the graph files to read in.
graphList = ["1.txt","2.txt","3.txt"]

for graph in graphList:
    # Open the input file
    with open(graph) as infile:
        # Get u and v for each line in the file
        for line in infile:
            edge = line.split()
            u = edge[0]
            v = edge[1]

            # Add each vertex to the set so I will have a list of vertices with
            # no repetition
            vertices.add(v)
            vertices.add(u)

            # For the adjacency list:
            # Add the v to the values list in the dict, where the
            #  u is the key. Then I add the u to the list returned  from  v.
            adjList[u].append(v)
            adjList[v].append(u)

            # For the adjacency matrix:
            # Where an edge exists, put a 1 in the matrix
            # When I have read all the edges, I still have to perform more 
            # operations on the matrix. This is done later in the program.
            adjMatrix[u][v] = 1
            adjMatrix[v][u] = 1


    # sort vertices in lexicographic order.
    # if u is a number, it has to be sorted like an int. Python by default
    # says that 11 (as a string) comes before 5 because 5 is greater than 1
    # and it only checks the first digit.
    if u.isnumeric():
        vertices = sorted(vertices, key = int)
    else: 
        vertices = sorted(vertices)

    # Print out the adjacency list based on the lexicographic order of 
    # the vertices
    with open("OutputAdjLists.txt", "a+") as outfile:
        outfile.write("Vertices\t\tAdjacent\n")
                    
        for u in vertices:
            outfile.write(f"\t{u}\t\t\t{' '.join(adjList[u])}")
            outfile.write("\n")
        outfile.write("\n")

    # Go through the entire matrix and add zeros where there are no edges
    # This is necessary because I can only read the file in once, and when I 
    # read it in, I don't know |V| or immediately know every vertex, 
    # so I can't say which edges don't exist on the fly.
    for u in vertices:
        for v in vertices:
            if v not in adjMatrix[u].keys():
                adjMatrix[u][v] = 0
            

    # Print out the adjacency matrix based on the lexicographic order of 
    # the vertices
    with open("OutputAdjMatrix.txt", "a+") as outfile:
        cardinalV = len(vertices)
        outfile.write("   ")  

        # Print column headers    
        for u in vertices:
            outfile.write(u.rjust(3))

        # Print the column header separator(=======)
        outfile.write("\n ") 
        for i in range((cardinalV * 3) + 2): # how many '=' symbols to print 
            outfile.write("=")

        # Print row headers and separators ( | )
        for u in vertices:
            outfile.write("\n")
            outfile.write(u.rjust(2) + "|")
            #Print the adjacency matrix
            for v in vertices:
                outfile.write(str(adjMatrix[u][v]).rjust(3))
        
        outfile.write("\n\n")

    # clear everything before reading in the next file
    adjList.clear()
    adjMatrix.clear()
    vertices = set()
    cardinalV = 0

    

    