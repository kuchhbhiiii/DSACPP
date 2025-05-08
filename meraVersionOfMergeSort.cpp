#include <iostream>
#include <vector>
using namespace std;

//pointer version
void merge(vector<int> &v, int s, int mid, int e){
    vector<int> temp;
    
    int left = s;
    int right = mid + 1;
    
    while(left <= mid && right <= e){
        if(v[left] < v[right]){
            temp.push_back(v[left++]);
        }else{
            temp.push_back(v[right++]);
        }
    }
    
    while(left<=mid) temp.push_back(v[left++]);
    while(right<=e) temp.push_back(v[right++]);
    
    for(int i = 0; i<temp.size(); i++){
        v[s++] = temp[i];
    }
    

}

// void merge(vector<int> &v, int s, int mid, int e){
//     vector<int> v1;
//     vector<int> v2;
    
//     int left = s;
//     int right = mid + 1;
//     while(left<=mid){
//         v1.push_back(v[left++]);
//     }
    
//     while(right <= e){
//         v2.push_back(v[right++]);
//     }
    
//     int mainVecIndex = s;
//     int vec1Size = v1.size();
//     int vec2Size = v2.size();
//     int index1 = 0, index2 = 0;
    
//     while(vec1Size && vec2Size){
//         if(v1[index1] < v2[index2]){
//             v[mainVecIndex++] = v1[index1++];
//             vec1Size--;
//         }else{
//             v[mainVecIndex++] = v2[index2++];
//             vec2Size--;
//         }
//     }
    
//     while(vec1Size){
//         v[mainVecIndex++] = v1[index1++];
//         vec1Size--;
//     }
//     while(vec2Size){
//         v[mainVecIndex++] = v2[index2++];
//         vec2Size--;
//     }
    
    
// }

void mergeSort(vector<int> &v, int s, int e){
    
    //base case
    if(s>=e) return;
    
    int mid = s + (e - s) / 2;
    
    mergeSort(v, s, mid); //left part
    mergeSort(v, mid + 1, e); //right part
    
    merge(v, s, mid, e);
}


int main() {
    
    vector<int> v = {2, 8, 9, 7, 4, 5, 1};
    
    mergeSort(v, 0, v.size() - 1);
    
    cout << "sort: " << endl;
    
    for(int val : v){
        cout << val << " ";
    }

    return 0;
}
