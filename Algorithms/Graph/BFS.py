from collections import defaultdict
from collections import deque
class Graph:
  def __init__(self,v):
    self.v = v
    self.E = [[] for i in range(self.v)]
  def insert_edge(self,u,v):
    self.E[u].append(v)
    self.E[v].append(u)

def BFS(source, Graph, cost = 1):
  not_visited = defaultdict(lambda:True)
  parent = defaultdict(lambda:-1)
  depth = defaultdict(lambda:-1)

  Q = deque()
  Q.append(source)
  not_visited[source] = False
  depth[source] = 0
  while(len(Q)):
    Vertex_Current = Q.popleft()
    for connected in G.E[Vertex_Current]:
      if(not_visited[connected]):
        not_visited[connected] = False
        parent[connected] = Vertex_Current
        depth[connected] = depth[Vertex_Current]+cost
        Q.append(connected)
      
  return depth

G = Graph(6)

G.insert_edge(0,2)
G.insert_edge(0,1)
G.insert_edge(0,4)
G.insert_edge(2,3)
G.insert_edge(3,5)
G.insert_edge(4,5)

depth = BFS(5,G)

for i in range(6):
  print(depth[i])

