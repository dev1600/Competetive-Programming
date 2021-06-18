#include <vector>
#include <list>
#include <iostream>
#include <map>
using namespace std;

map<int,list<pair<int,int>>> graph;

class Graph{

    public:
        void addEdge(int s,int d,int wt)
        {
            graph[s].push_back(make_pair(d,wt));
        }


        void printEdge()
        {
            for(auto x:graph)
            {
                list<pair<int,int>> adjl=x.second;
                int s=x.first;
                for(auto y:adjl)
                    cout<<"source->"s<<s<<" Destination="<<y.first<<" Distance="<<y.second<<endl;
            }
        }
};
int main()
{
    Graph g;
    g.addEdge(0,1,10);
    g.addEdge(0,3,30);
    g.addEdge(1,2,20);
    g.addEdge(2,4,40);
    g.printEdge();
}