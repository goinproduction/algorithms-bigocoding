#include<iostream>
#include<vector>
using namespace std;

vector<int> h;

void minHeapify(int x){
    int smallest = x;
    int left = x*2 + 1;
    int right = x*2 + 2;
    if(left < h.size() && h[left] < h[smallest]){
        smallest = left;
    }else if(right < h.size() && h[right] < h[smallest]){
        smallest = right;
    }
    
    if(x != smallest){
        swap(h[x], h[smallest]);
        minHeapify(smallest);
    }
}

void buildHeap(int n){
    for(int i = n/2 -1; i>=0; i--){
        minHeapify(i);
    }
}
int main(){
    h = {7, 12, 6, 10, 17, 15, 2, 4};
    buildHeap(h.size());
    for(int i=0; i<h.size(); i++){
        cout << h[i] <<" ";
    }
    return 0;
}
