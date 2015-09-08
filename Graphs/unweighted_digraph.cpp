//unweighted digraph
#include<cstdio>
#include<vector>
#include<list>
#include<utility>
using namespace std;

int main(){
    int vertices, edges, v1, v2;
    printf("Enter no. of vertices: ");
    scanf("%d", &vertices);
    printf("Enter no. of edges: ");
    scanf("%d", &edges);
    vector<list< int > > adjacencylist(vertices +1);
    for(int i=1; i<=edges; i++){
        scanf("%d%d", &v1,&v2);
        adjacencylist[v1].push_back(v2);
    }
    for(int i=1; i<adjacencylist.size(); i++){
        printf("adjacencylist[%d]", i);
        list< int >::iterator itr = adjacencylist[i].begin();
        while(itr != adjacencylist[i].end()){
            printf("-> %d", *itr);
            itr++;
        }
        printf("\n");
    }
    return 0;
}
