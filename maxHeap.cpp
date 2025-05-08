#include <iostream>
#include <vector>
using namespace std;

class MaxHeap{
    vector<int> heap;
    
    int parent(int i){
        return (i - 1) / 2;
    }
    
    int leftChild(int i){
        return i * 2 + 1;
    }
    
    int rightChild(int i){
        return i * 2 + 2;
    }
    
    void heapfyUp(int index){
        while(index > 0 && (heap[parent(index)] < heap[index])){
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }
    
    
    void heapifyDown(int index){
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);
        
        if(heap[largest] < heap[left]){
            largest = left;
        }
        if(heap[largest] < heap[right]){
            largest = right;
        }
        
        if(index != largest){
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }
    
    void heapify(vector<int> &v, int n, int i){
    
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);
        
        if(left < n && v[largest] < v[left]){
            largest = left;
        }
        if(right < n && v[largest] < v[right]){
            largest = right;
        }
        
        if(largest != i){
            swap(v[largest], v[i]);
            heapify(v, n, largest);
        }
    }
 
    
    
    public:
    
    void insert(int value){
        heap.push_back(value);
        heapfyUp(heap.size() - 1);
    }
    
    int removeMax(){
        if(heap.empty()) return -1;
        
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        
        return maxVal;
    }
    
    void buildTree(vector<int> &v){
        int n = v.size();
        for(int i = n / 2 - 1; i >= 0; i--){
            heapify(v, n, i);
        }
    }
    
    void maxHeapSort(vector<int> &v, int n, int i){
        // cout << "size : " << n << endl;
        // int largest = i;
        // int left = leftChild(i);
        // int right = rightChild(i);
        
        // swap(v[largest], v[n - 1]);
        
        // if(left < n && v[largest] < v[left])
        //     largest = left;
            
        // if(right < n && v[largest] < v[right])
        //     largest = right;
            
            
        //     swap(v[largest], v[i]);
        
        
        // if(n == 1){
        //     return;
        // }
        //  maxHeapSort(v, --n, largest);
        
       for(int i = n - 1; i>0; i--){
           swap(v[0], v[i]);
           heapify(v, i, 0);
       }
           
        
    }
    
    void print(){
        for(int val : heap){
            cout << val << " ";
        }
    }
};

int main (){
    
    MaxHeap maxHeap;
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(49);
    maxHeap.insert(90);
    
    maxHeap.print();
    cout << endl;
    
    
    cout << "remove max: " << maxHeap.removeMax() << endl;
    
    maxHeap.print();
    cout << endl;
    
    vector<int> v = {3, 9, 23, 98, 43, 93, 22};
    
    maxHeap.buildTree(v);
    
    cout << "max heap: " << endl;
    for(int val : v){
        cout << val << " ";
    }
    
    cout << endl;
    
    cout << "max heap sort: " << endl;
    int n = v.size();
    maxHeap.maxHeapSort(v, n, 0);
    
    for(int val : v){
        cout << val << " ";
    }
    
    
    return 0;
}
