#include <iostream>
#include <vector>
using namespace std;

class MinHeap{
    vector<int> heap;
    
    int parent(int i) {return (i - 1 )/ 2;}
    int leftChild(int i) {return 2 * i + 1;}
    int rightChild(int i) {return 2 * i + 2;}
    
    void heapifyUP(int index){
        while(index > 0 && heap[parent(index)] > heap[index]){
            swap(heap[parent(index)], heap[index]);
            index  = parent(index);
        }
    }
    
    
    void heapifyDown(int index){
        int smallest = index;
        int left = leftChild(index);
        int right = rightChild(index);
        
        if(left < heap.size() &&  heap[smallest] > heap[left]) smallest = left;
        if(right < heap.size() && heap[smallest] > heap[right]) smallest = right;
        
        if(index != smallest){
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }
    
    void heapify(vector<int> &v, int n , int i){
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);
        

        if(left < n && v[smallest] > v[left]){
            smallest = left;
        }
         
        if(right < n && v[smallest] > v[right]){
            smallest = right;
            
        }
            
        
        if(smallest != i){
            swap(v[smallest], v[i]);
            heapify(v, n, smallest);
        }
    }
    
   
    
    
    
    public:
    void insert(int value){
        heap.push_back(value);
        heapifyUP(heap.size() - 1);
    }
    
    
    
    int removeMin(){
        
        if(heap.empty()) return -1;
        
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minVal;
    }
    
    void buildHeap(vector<int> &v){
        int n = v.size();
        for(int i = n / 2 - 1; i >= 0; i--){
            heapify(v, n, i);
        }
    }
    
    
    void minHeapSort(vector<int> &v){
        int n = v.size();
        for(int i = n - 1; i >= 0; i--){
            swap(v[i], v[0]);
            heapify(v, i, 0); 
        }
    }
    

    void print(){
        for(int val : heap){
            cout << val << " ";
        }
    }
};

int main() {
  
    MinHeap minHeap;
    
    minHeap.insert(30);
    minHeap.insert(40);
    minHeap.insert(50);
    minHeap.insert(70);
    minHeap.insert(60);
    minHeap.insert(20);
    
    minHeap.print();
    
    cout << endl;
    
   cout << "remove min: " << minHeap.removeMin() << endl;
   
   minHeap.print();
   cout << endl;
   
   cout << "min heap: " << endl;
   vector<int> v = {2, 8, 9, 0, 7, 21, 22};
   
   minHeap.buildHeap(v);
   
   for(int val : v){
       cout << val << " ";
   }
   
   cout << endl;
   
   cout << "min heap sort: " << endl;
   
   minHeap.minHeapSort(v);
   for(int val : v){
       cout << val << " ";
   }
  
    return 0;
}
