//weighted digraph
#include<cstdio>
#include<vector>
#include<list>
#include<utility>

using namespace std;

int main(){
    int vertices, edges, v1, v2, weight;
    printf("Enter no. of vertices: ");
    scanf("%d", &vertices);
    printf("Enter no. of edges: ");
    scanf("%d", &edges);

    vector< list< pair<int, int> > > adjacencyList(vertices + 1);
    for(int i=1; i<=edges; ++i){
        scanf("%d%d%d", &v1, &v2, &weight);
        adjacencyList[v1].push_back(make_pair(v2, weight));
    }
    for(int i=1; i<=adjacencyList.size(); ++i){
        printf("adjacencyList[%d]", i);
        list< pair<int, int> >::iterator itr = adjacencyList[i].begin();
        while(itr != adjacencyList[i].end()){
            printf("-> %d(%d)", (*itr).first, (*itr).second);
            ++itr;
        }
        printf("\n");
    }
    return 0;
}
