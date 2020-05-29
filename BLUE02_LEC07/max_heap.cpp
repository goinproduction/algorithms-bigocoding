#include<iostream>
#include<vector>
using namespace std;
vector<int> h;
void maxHeapify(int pos){
    int max = pos;
    int left = pos*2 + 1;
    int right = pos*2 + 2;
    if(left < h.size() && h[left] > h[max]){
        max = left;
    }
    if(right < h.size() && h[right] > h[max]){
        max = right;
    }
    if (max != pos){
        swap(h[max], h[pos]);
        maxHeapify(max);
    }
}
void buildHeap(int n){
    for(int i = n / 2 - 1; i>=0; i--){
        maxHeapify(i);
    }
}
int top(){
    return h[0];
}
void push(int val){
    h.push_back(val);
    int i = (h.size() - 1);
    while(i != 0 && h[(i-1)/2] < h[val]){
        swap(h[(i-1)/2], h[val]);
        i = (i-1/2);
    }
}
void pop(int val){
    int length = h.size();
    if (length == 0){
        return;
        }
        h[0] = h[length - 1];
        h.pop_back();
        maxHeapify(0);  
}
int main(){
    h = {7, 12, 6, 10, 17, 15, 2, 4};
    buildHeap(h.size());
    for(int i=0; i<h.size(); i++){
        cout << h[i] <<" ";
    }
    return 0;
}
