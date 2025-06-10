#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3;
int graph[N][N];
vector<int> grph[N];

int main() {
   cout << "Enter data: " << endl;
   int n, m;
   cin >> n >> m;
   
  for(int i = 0; i<m; i++){
      int n1, n2;
      cin >> n1 >> n2;
      
      //adjecency matrix
      graph[n1][n2] = 1;
      graph[n2][n1] = 1;
      
      //adjecency list
      grph[n1].push_back(n2);
      grph[n2].push_back(n1);
  }

   
  cout << "print adjacency matrix graph: " << endl;
   
  for(int i = 0; i<n; i++){
      for(int j = 0; j<n; j++){
         cout <<  graph[i][j] << " ";
      }
      cout << endl;
  }
   
   cout << "print adjecency list graph: " << endl;
   for(int i = 0; i<n; i++){
       cout << "index: " << i << " -> ";
      for(int val : grph[i]){
          cout << val << " ";
      }
      cout << endl;
   }

    return 0;
}
