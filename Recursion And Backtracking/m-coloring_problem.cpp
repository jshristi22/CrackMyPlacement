// leetcode
// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

class Solution{
private:
    bool isNodeSafe(int node,bool graph[101][101], int n, int color[], int c){
        
        for(int k = 0; k<n; k++){
            if(k != node && graph[k][node] == 1 && color[k] == c){
                return false;
            }
        }
        return true;
    }
    
private: 
    bool find(int node, bool graph[101][101], int m, int n, int color[]){
        if(node == n) return true;
        
        for(int k = 1; k <=m; k++){
            if(isNodeSafe(node, graph, n, color, k)){
                color[node] = k;
                if(find(node +1, graph, m, n, color))  return true;
                color[node] = 0;
            }
        }
        return false;
    }
public: 
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n] = {0};
        if(find(0, graph, m, n, color)) return true;
        return false;
    }

};