//Minimum spanning tree with prim's algorithm
//Greedy Approach
//Input is string , so Hashmap to traverse
//One Unique difference with BFS, if we find a unexplored node with weight, we..
//only push it as a candidate in the priority, we dont immediately mark it as visited (there may be better paths to that node incoming)
//Priority queue to push candidate edges (if node in other size of the edge is not visited, we push it to Queue, makes code highly efficient)
//Check after Pop if vertex connected with Popedd edge is already visited or not (if all small weights are connected to same node, this will arise)
//Maximum Priority Queue Size can be total edge (E) ~ (V^2) //Fully Connected Graph, we must push all possible candidates
//So, Our ..... I got lost calculating the time complexity. Might Update Later 
#include <bits/stdc++.h>
using namespace std;
#define IO          ios_base::sync_with_stdio(0); cin.tie(0);
#define READ        freopen("in.txt", "r", stdin)
#define WRITE       freopen("out.txt", "w", stdout)
//-------------------------------------------------------------------------
class Graph
{
public:
    map<string, vector<pair<int, string > > > E;                        //Maps to Adjacency List where each list node has 2 elements(destination, weight)
    void insert_edge(string source, string destination, int weight)     //Insert weight first, play nice with Priority Queue
    {
        E[source].push_back(make_pair(weight, destination));
        E[destination].push_back(make_pair(weight, source));
    }
};

int MST(Graph &G, string source)     //random source in range
{
    map<string, bool> visited;
    for(auto it = G.E.begin(); it != G.E.end(); it++)                //O(V)
    {
        visited[it->first] = false;
    }
    
    int cost = 0;
    priority_queue<pair<int, string> > PQ;
    PQ.push(make_pair(0,source));
    while(PQ.size())                                            //O(E)
    {
        auto current_node = PQ.top();
        PQ.pop();                                              //O(lg(E))
        if(visited[current_node.second])                       //Probabilistic O(1)
            continue;
        else
            visited[current_node.second] = true;  
        cout << current_node.second << " adding Cost : " << current_node.first*-1 <<endl;
        cost = cost + current_node.first ;
        for(auto it = G.E[current_node.second].begin(); it != G.E[current_node.second].end(); it++) //Wadu HEK
        {
            if(!visited[it->second])
            {
                PQ.push(*it);
            }
        }
    }
    return cost; 
}

int main()
{
    READ;
    WRITE;
    int E;
    cin >> E;
    Graph G;
    while(E--)
    {
        string u,v;
        int w;
        cin >> u >> v >> w;
        G.insert_edge(u,v,w*-1);
    }
    string source;
    cin >> source;
    int cost = MST(G, source);
    cout << cost*-1 << endl;
}