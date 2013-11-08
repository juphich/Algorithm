import sys

read = lambda:sys.stdin.readline().strip()

def dfs(graph, v):
    global visited
    visited[v] = True
    print("%s -> " % v),
    
    for i in range(1, len(graph)):
        if not visited[i] and graph[v][i] : 
            dfs(graph, i)

def bfs(graph, v):
    global visited
    queue = []
    visited[v] = True
    queue.append(v)
            
    while(len(queue) > 0):
        c = queue[0]
        queue = queue[1:]
        print("%s ->" % c),
        for n in range(1, len(graph)):
            if not visited[n] and graph[c][n]:
                visited[n] = True
                queue.append(n)

vertices = map(int, read().split())
graph = [[False] * (vertices[0]+1) for _ in range(vertices[0]+1)]

for _ in range(1, vertices[1]+1):
    vertex = map(int,read().split())
    graph[vertex[0]][vertex[1]] = vertex[2]
    #graph[vertex[1]][vertex[0]] = vertex[2]

visited = [False] * (vertices[0]+1)
print("depth first search : "),
dfs(graph, 1)
print("end")

visited = [False] * (vertices[0]+1)
print("breadth first search : "),
bfs(graph, 1)
print("end")
