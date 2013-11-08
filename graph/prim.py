import sys

read = lambda:sys.stdin.readline().strip()

INF = 987654321

class Graph:
    verties = set()
    edges = []
    adj = {}

    def add(self, edge) :
        self.verties.add(edge[0])
        self.verties.add(edge[1])
        self.edges.append((int(edge[2]), edge[0], edge[1]))
        
        if edge[0] in self.adj:
            self.adj[edge[0]].append((edge[1], int(edge[2])))
        else :
            self.adj[edge[0]] = [(edge[1], int(edge[2]))] 
        
def prim(graph, start):
    selected = []
    result = 0
    added = {key:False for key in graph.verties}
    minWeight = {key:INF for key in graph.verties}
    parents = {key:None for key in graph.verties}

    minWeight[start] = 0
    parents[start] = start

    for _ in graph.verties:
        cv = None
        for v in graph.verties:
            if not added[v] and (not cv or minWeight[cv] > minWeight[v]):
                cv = v
    
        if parents[cv] != cv:
            selected.append((parents[cv], cv))

        result = result + minWeight[cv]
        added[cv] = True
        
        if not(cv in graph.adj) : continue
        for edge in graph.adj[cv]:
            v = edge[0]
            weight = edge[1]
            if not added[v] and minWeight[v] > weight:
                parents[v] = cv
                minWeight[v] = weight

    return result

graph = Graph()
for _ in range(int(read())):
    graph.add(read().split())

print(prim(graph, "c"))
