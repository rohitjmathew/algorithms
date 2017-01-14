import java.util.*;
import java.lang.*;
import java.io.*;

class Graph
{
    private int V;
    private LinkedList<Integer> adjList[];
    
    Graph(int v){
        V=v;
        adjList = new LinkedList[V];
        for(int i=0;i<V;i++){
            adjList[i] = new LinkedList();
        }
    }
    
    void addEdge(int start, int end){
        adjList[start].add(end);
        // Uncomment below for undirected graphs
        // adjList[end].add(start);
    }
    
    void bfs(int entry){
        boolean visited[] = new boolean[V];
        LinkedList<Integer> queue = new LinkedList();
        visited[entry] = true;
        queue.add(entry);
        while(queue.size()!=0){
            int node = queue.poll();
            System.out.println(node);
            Iterator<Integer> i = adjList[node].listIterator();
            while(i.hasNext()){
                int connectedNode = i.next();
                if(!visited[connectedNode]){
                    visited[connectedNode] = true;
                    queue.add(connectedNode);
                }
            }
        }
    }
    
    // driver
	public static void main (String[] args) throws java.lang.Exception
	{
		Graph g = new Graph(6);
		g.addEdge(0,1);
		g.addEdge(0,5);
		g.addEdge(0,3);
		g.addEdge(1,2);
		g.addEdge(3,2);
		g.addEdge(3,4);
		g.addEdge(5,4);
		g.bfs(0);
	}
}
