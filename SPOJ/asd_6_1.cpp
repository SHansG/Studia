//Spoj 6.1 Składowe spójne grafu
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;
 
class Pair
{
public:
    int A, B;
    friend ostream &operator<<(ostream &, const Pair &);
    friend istream& operator>>(istream&, const Pair&);
    Pair();
    ~Pair();
};
Pair::Pair()
{
}
 
Pair::~Pair()
{
}
 
ostream& operator<<(ostream& out, const Pair& p)
{
    out << p.A << p.B;
    return out;
}
 
istream& operator>>(istream& in, Pair& p)
{
    in >> p.A >> p.B;
    return in;
}
 
class Graph
{
    int numOfVertices;
    list<int> *adj;
    void dfs(int,bool[],vector<int>&);
public:
    Graph(int numOfVertices);
    void addEdge(int,int);
    void connectedComponents();
};
Graph::Graph(int numOfVertices)
{
    this->numOfVertices = numOfVertices;
    adj = new list<int>[numOfVertices];
}
void Graph::addEdge(int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}
 
void Graph::dfs(int vertex, bool visited[], vector<int> &connectedVertices)
{
    visited[vertex] = true;
    connectedVertices.push_back(vertex);
    //cout << vertex << " ";
    list<int>::iterator i; 
    for(i = adj[vertex].begin(); i != adj[vertex].end(); ++i) 
        if(!visited[*i]) 
            dfs(*i, visited, connectedVertices);    
}
 
void Graph::connectedComponents()
{
    bool *visited = new bool[numOfVertices]; 
    int counter{1};
    vector<int> connectedVertices;
    for(int v = 0; v < numOfVertices; v++) 
    {    
        visited[v] = false; 
    }
    for (int v=1; v<numOfVertices; v++) 
    { 
        if (visited[v] == false) 
        {
            cout << counter <<": ";
            dfs(v, visited,connectedVertices);
            sort(connectedVertices.begin(), connectedVertices.end());
            for(unsigned int i = 0; i < connectedVertices.size(); i++)
            {
            	for(unsigned int j = 0; j < connectedVertices.size(); j++)
            	{
            		if(connectedVertices[i] < connectedVertices[j])
            		{
            			swap(connectedVertices[i], connectedVertices[j]);
            		}
            	}
            }
            for(unsigned int i = 0; i < connectedVertices.size(); i++)
            {
            	cout << connectedVertices[i] << " ";
            }
            cout << "\n";
            counter++;
        }
        connectedVertices.clear();
    }
}
 
int main(){
    int tests{ 0 };
    cin >> tests;
    for (int i = 0; i < tests; i++) {
        vector<Pair> pairs;
        int vertices{ 0 }, max{ 0 };
        cin >> vertices;
        for (int j = 0; j < vertices; j++) {
            Pair p;
            cin >> p;
            pairs.push_back(p);
            if (p.A > max) { max = p.A; }
            if (p.B > max) { max = p.B; }
        }
        Graph g(max+1);
        for(unsigned int j = 0; j < pairs.size(); j++)
        {
            g.addEdge(pairs[j].A, pairs[j].B);
        }
        g.connectedComponents();
        pairs.clear();
    }
    return 0;
}
