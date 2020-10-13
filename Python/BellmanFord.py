def initiate_distance_list(matrix_size, distances, origin_vertex):  # Initiate the distances's list
    inf = float("inf")
    for i in range(matrix_size):
        if i != origin_vertex:
            distances.append(inf)
        else:
            distances.append(0)

    return distances

# Function that receives the adjacency matriz and the origin vertex and returns a list with the shortest paths between the origin vertex and the other vertexs
def bellman_form(adjacency_matrix, origin_vertex):
    origin_vertex -= 1
    distances = []

    distances = initiate_distance_list(len(adjacency_matrix[origin_vertex]), distances, origin_vertex)

    for i in range(len(adjacency_matrix[origin_vertex])-1):
        for u in range(len(adjacency_matrix[origin_vertex])):
            for v in range(len(adjacency_matrix[origin_vertex])):
                if adjacency_matrix[u][v] != 0:
                    sum1 = distances[u] + adjacency_matrix[u][v]
                    if sum1 < distances[v]:
                        distances[v] = sum1

    return distances


def show_distances(distances, origin_vertex):  # Function that shows in the screen the distances
    for i in range(len(distances)):
        print("D(" + str(origin_vertex) + "," + str(i+1) + "): " + str(distances[i]))


adjacency_matrix = [[0, 10, 0, 0, 0, 8], [0, 0, 0, 2, 0, 0], [0, 1, 0, 0, 0, 0], [0, 0, -2, 0, 0, 0], [0, -4, 0, -1, 0, 0], [0, 0, 0, 0, 1, 0]]
origin_vertex = 1
distances = bellman_form(adjacency_matrix, origin_vertex)
show_distances(distances, origin_vertex)
