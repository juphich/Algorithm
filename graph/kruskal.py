import sys

read = lambda:sys.stdin.readline().strip()

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

class SubSet:
    parent = None
    data = None

    def __init__(self, data):
        self.parent = self
        self.data = data

class DisjointSet:
    entries = {}

    def __init__(self, sets):
        for v in sets:
            self.entries[v] = SubSet(v)
    
    def find(self, data):
        target = self.entries[data].parent
        while(target != target.parent):
            target = target.parent

        return target
    
    def merge(self, data1, data2) :
        sub1 = self.find(data1)
        sub2 = self.find(data2)

        sub2.parent = sub1

def kruskal(graph):
    result = 0
    selected = []    
    edges = []

    for key in graph.adj :
        for i in graph.adj[key]:
            v = i[0]
            cost = i[1]
            edges.append((cost, key, v))
    
    edges.sort()
    sets = DisjointSet({key for key in graph.verties})

    for edge in edges:
        cost = edge[0]
        vf = edge[1]
        vt = edge[2]
        if sets.find(vf) == sets.find(vt) : continue
        
        sets.merge(vf, vt)
        selected.append((vf, vt))
        print(selected)
        result = result + cost

    return result
        
count = int(read())
graph = Graph()
for _ in range(count):
    row = read().split()
    graph.add(row)


print(kruskal(graph))
