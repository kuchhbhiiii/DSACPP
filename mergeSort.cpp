#include <iostream>
#include <vector>
using namespace std;

//pointer approach
void merge(vector<int>& v, int s, int mid, int e) {
    vector<int> temp;
         
    int left = s, right = mid + 1;

    while (left <= mid && right <= e) {
        if (v[left] < v[right]) {
            temp.push_back(v[left++]);
        } else {
            temp.push_back(v[right++]);
        }
    }

    while (left <= mid) temp.push_back(v[left++]);
    while (right <= e) temp.push_back(v[right++]);

    
    for (int i = 0; i < temp.size(); i++) {
        v[s + i] = temp[i];  
    }
}


// array approach 

void merge(vector<int> &v, int s, int mid, int e){
    int len1 = mid - s + 1;
    int len2 = e - mid;

    vector<int> v1(len1);
    vector<int> v2(len2);

    // Copy values
    for(int i = 0; i < len1; i++) v1[i] = v[s + i];
    for(int i = 0; i < len2; i++) v2[i] = v[mid + 1 + i];

    int index1 = 0, index2 = 0;
    int mainVecIndex = s;
   
  //merge two sorted array
    while(index1 < len1 && index2 < len2){
        if(v1[index1] < v2[index2]){
            v[mainVecIndex++] = v1[index1++];
        } else {
            v[mainVecIndex++] = v2[index2++];
        }
    }

    while(index1 < len1) v[mainVecIndex++] = v1[index1++];
    while(index2 < len2) v[mainVecIndex++] = v2[index2++];
}



void mergeSort(vector<int> &v, int s, int e){
    
    
    if(s >= e) return;
    
    int mid = s + (e - s) / 2;
    
    mergeSort(v, s, mid); //leftPart
    mergeSort(v, mid + 1, e); //rightPart
    
    merge(v, s, mid, e);
    
}

int main() {
  
    vector<int> v = { 2, 9, 32, 4, 9, 23, 43};
    

    mergeSort(v, 0, v.size() - 1);
    
    cout << "sorted: " << endl;
    
    for(int val : v){
        cout << val << " ";
    }
    return 0;
}

