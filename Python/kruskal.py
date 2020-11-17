#Function that creates a matrix  with a single value (i utilize 0 in this case).
def matrix (nRow,nColumns, value):
    matrix = []
    for i in range(nRow):
        row = []
        for j in range(nColumns):
            row.append(value)
        matrix.append(row)
    return matrix


#This function creates 3 lists. Each list representes: the first vector, the second vector and the weight between them.
def newConj(nRows,nColumns,matrixAux):
    edgesFirst=[]
    edgesSecond=[]
    weight=[]
    for i in range (nRows):
        for j in range (nColumns):
            if (matrixAux[i][j]!=0):
                edgesFirst.append(i)
                edgesSecond.append(j)
                weight.append(matrixAux[i][j])
                matrixAux[i][j]=0
                matrixAux[j][i]=0
    return edgesFirst,edgesSecond,weight

#Function that prints the adjacency matrix.
def printMatrix (nRows,nColumns, matrix):
    for i in range(nRows):
        rowPrint = ""
        for j in range(nColumns):
            rowPrint += str(matrix[i][j])
            if(j<nColumns-1):
                rowPrint += ","
        print(rowPrint)

#Function that utilizes Kruskal's Algorithm to find the adjacency matrix of the minimum spanning tree of a graph.
def kruskal(nRows,nColumns,matrixAdj):
    vFirst, vSecond, weights = newConj(nRows,nColumns,matrixAdj)
    positionsV=[]
    for i in range (nRows):
        positionsV.append(i)
    matrixKruskal = matrix(nRows,nColumns,0)
    edges=[]
    firsts=0
    while firsts!=(nRows-1):
        #print(idas)
        minw = float("inf")
        v1 = 0
        v2 = 0
        positionMin=0
        for i in range(len(weights)):
            if (weights[i] < minw and (i not in edges)):
                minw = weights[i]
                v1 = vFirst[i]
                v2 = vSecond[i]
                positionMin=i
        edges.append(positionMin)
        if(positionsV[v1]!=positionsV[v2]):
            matrixKruskal[v1][v2]=minw
            matrixKruskal[v2][v1]=minw
            firsts += 1
            for k in range(len(positionsV)):
                if positionsV[k]==positionsV[v2]:
                    positionsV[k]=positionsV[v1]
    return matrixKruskal

#We start with  the adjacency matrix of a weighted graph.
adjacencyMatrix = [[0, 0, 1, 0, 0], [0, 0, 3, 0, 1], [1, 3, 0, 5, 2], [0, 0, 5, 0, 4], [0, 1, 2, 4, 0]]
nRows=len(adjacencyMatrix[0])
nColumns=len(adjacencyMatrix)
#Here we utilize a function to get the minimum spanning tree's adjacency matrix for the original graph's adjacency matrix.
finalMatrix=kruskal(nRows,nColumns,adjacencyMatrix)
#Now we just print the new adjacency matrix.
printMatrix(nRows,nColumns,finalMatrix)
