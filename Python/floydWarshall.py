V = int(input("Enter number of vertices"))

INF = -999

def floydWarshall(graph): 

    distance = [[j for j in i] for i in graph] 

    for k in range(V): 

        for i in range(V): 

            for j in range(V): 
 
                distance[i][j] = min(distance[i][j], distance[i][k]+ distance[k][j] ) 
    for dist in distance:
        for d in dist:
            print(d, end=" ")
        print()

print("Enter graph: ")
graph = []
for _ in range(V):
    graph.append(list(map(int, input().split())))

floydWarshall(graph);
