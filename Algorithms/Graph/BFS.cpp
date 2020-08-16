//BFS using Adjacency List
//STL for clean and short code
//O(V+E)
//Maximum Vertex predefined

#define LL                  long long
#define UL                  unsigned long long
#define PI                  acos(-1.0)
#define Di(x)               int x;scanf("%d",&x)
#define Si(x)               scanf("%d",&x);
#define So(x)               printf("%d",x)
#define pb                  push_back
#define mp                  make_pair
#define mset(name,value)    memset(name,value,sizeof(name))
#define IO                  ios_base::sync_with_stdio(0);cin.tie(0)
#define MOD                 1000000007
#define READ                freopen("in.txt","r",stdin)
#define WRITE               freopen("write.txt","w",stdout)
//----------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;

int V; //No of vertex. Must be defined in main function and smaller than V_max
int V_max = 1000; //Maximum Vertex must be pre-defined for static allocation

vector<int> Adj[V_max]; //Adjacency list, [Vertex ID][Iteration over Adjacent nodes]
vector<bool> visited;
vector<int> parent;
vector<int> level;

void BFS(int source)
{
    for(int i=0; i<V; i++) //initializing parent, depth (level) and visited list
    {
        visited.push_back(false);
        parent.push_back(-1);
        level.push_back(-1);
    }


    queue<int> Q;    //Pushing Source Node , 3 operation after pushing, update depth,parent and visited array
    Q.push(source);
    visited[source] = true;
    level[source] = 0;
    while(Q.size())
    {
        int Current_Node = Q.front();
        cout << "Current_Node : " << Current_Node+1<<endl;
        Q.pop();
        for(int i = 0; i < Adj[Current_Node].size(); i++)
        {
            if(!visited[Adj[Current_Node][i]])
            {
                visited[Adj[Current_Node][i]] = true;
                level[Adj[Current_Node][i]] = level[Current_Node]+1;
                parent[Adj[Current_Node][i]] = Current_Node;
                Q.push(Adj[Current_Node][i]);
            }
        }
    }
}

int main()
{
    V = 6;
    for(int i = 0 ; i < 7; i++)
    {
        int u,v;
        cin >> u >> v;
        Adj[u-1].push_back(v-1);
        Adj[v-1].push_back(u-1);
    }
    BFS(3);
    for(int i = 0; i < V ; i++)
        cout << level[i] << endl;
}













