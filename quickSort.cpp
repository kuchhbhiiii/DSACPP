#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &v, int s, int e){
    int pivot = v[s];
    int count = 0;
    for(int i = s + 1; i<=e; i++){
        if(v[i] <= v[s]){
            count++;
        }
    }
    
    int pivotIndex = s + count;
    swap(v[pivotIndex], v[s]);
    
    int i = s, j = e;
    
    while(i < pivotIndex && j > pivotIndex){
        while(v[i] <= v[pivotIndex]) i++;
        while(v[j] > v[pivotIndex]) j--;
        
        if(i < pivotIndex && j > pivotIndex){
            swap(v[i++], v[j--]);
        }
    }
    
    return pivotIndex;
     
}

void quickSort(vector<int> &v, int s, int e){
    if(s >= e) return;
    
    int p = partition(v, s, e);
    
    //left part
    quickSort(v, s, p - 1);
    quickSort(v, p + 1, e);
}

int main() {
   vector<int> v = {8, 3, 2, 9, 10, 1, 5};
   
   quickSort(v, 0, v.size() - 1);
   
   cout << "sorted: " << endl;
   for(int val : v){
       cout << val << " ";
   }

    return 0;
}
