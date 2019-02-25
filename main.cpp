#include <bits/stdc++.h>
using namespace std;

bool find_cycle(vector< vector<int> > &V , vector <bool> &visited , vector <bool> &Stack,int curr)
{
    ///we still exploring it's children and we found it again
    ///so .. it's cycle
    if(Stack[curr])
        return 1;

    /// we already explored it and it's children
    /// and the result was negative for finding loops
    if(visited[curr])
        return 0;



    visited[curr]=true;
    Stack[curr]=true;


    for(int i=0;i<V[curr].size();i++)
    {
        if(find_cycle(V,visited,Stack,V[curr][i]))
            return true;
    }

    Stack[curr]  = false ;
    return false;

}


main()
{

    ///graph structure
    vector < vector <int > > V(1001);
    ///visited vector
    vector <bool> visited(1001);
    ///fully discovered or not
    /// (did all children discovered "1" or not "0" )
    vector <bool> Stack(1001);

    ///initially all vertexes are not visited
    fill(visited.begin(), visited.end(), 0);
    fill(Stack.begin(), Stack.end(), 0);

    ///n is number of vertexes
    ///m is number of edges
    int n,m,x,y;
    cin >> n >> m ;

    ///filling Edges
    for(int i=0;i<m;i++)
    {
        cin >> x  >> y;
        V[x-1].push_back(y-1);
    }


    for(int i=0;i<n;i++)
    {
    if(find_cycle(V,visited,Stack,i))
    {
        cout << 1 ;
        return 0;
    }
    }
    cout << 0;


///Complexity is V for looping to the all vertexes
///inside each loop there we do DFS in case the node is not visited
///the complexity is obviously V+E
///so the complexity is the same as DFS Algo
/*
5 7 1 2 2 3 1 3 3 4 1 4 2 5 3 5
*/






}
