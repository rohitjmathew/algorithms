//bfs
#include<cstdio>
#include<vector>
#include<list>
using namespace std;

void bfs(vector<list<int> >, int[], int[], int);

int main(){
    int vertices, edges, v1, v2;
    printf("Enter no. of vertices: ");
    scanf("%d", &vertices);
    printf("Enter no. of edges: ");
    scanf("%d", &edges);
    vector<list<int> > adjacencylist(vertices + 1);
    for(int i=1;i<=edges;i++){
        scanf("%d%d", &v1, &v2);
        adjacencylist[v1].push_back(v2);
    }
    for(int i=1;i<adjacencylist.size();i++){
        printf("adjacencylist[%d]", i);
        list<int>::iterator itr = adjacencylist[i].begin();
        while(itr!=adjacencylist[i].end()){
            printf("->%d", *itr);
            itr++;
        }
        printf("\n");
    }
    int level[vertices+1];
    int parent[vertices+1];
    for(int i=0;i<=vertices;i++){
        level[i] = -1;
        parent[i]= 0;
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &v1);

    bfs(adjacencylist, parent, level, v1);

    for(int i=1; i<=vertices; i++){
        printf("Level of Node %d is %d, Parent is %d\n", i, level[i], parent[i]);
    }
    return 0;
}

void bfs(vector<list<int> > adjacencylist, int parent[], int level[], int start){
    list< int> vertexqueue;
    vertexqueue.push_back(start);
    int lev=0;
    level[start]=lev;
    list<int>::iterator itr;
    while(!vertexqueue.empty()){
        int visitedVertex = vertexqueue.front();
        itr = adjacencylist[visitedVertex].begin();
        while( itr != adjacencylist[visitedVertex].end()){
            if(level[*itr]==-1){
                level[*itr]=lev+1;
                parent[*itr]=visitedVertex;
                vertexqueue.push_back(*itr);
            }
            itr++;
        }
        vertexqueue.pop_front();
        lev++;
    }
}
