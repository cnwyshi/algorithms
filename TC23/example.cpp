heap
#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000003];
int n;
void up(int root){
    if(arr[root]<arr[(root-1)/2]){
        swap(arr[root], arr[(root-1)/2]);
        up((root-1)/2);
    }
    else{
        return;
    }
}
void down(int root){
    while(1){
        int l=root*2+1;
        int r=root*2+2;
        int largest=root;
        if(l<n && arr[l]<arr[root]){
            largest=l;
        }
        if(r<n && arr[largest]>arr[r]){
            largest=r;
        }
        if(largest!=root){
            swap(arr[root], arr[largest]);
            root=largest;
        }
        else
            break;
    }
}
int main(){
    cin>>n;
    int tmp;
    int k=0;
    for(int i=0;i<=n;i++){
        arr[i]=2e9+1;
    }
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp==1){
            cin>>tmp;
            arr[k]=tmp;
            up(k);
            k++;
        }
        else if(tmp==2){
            cout<<arr[0]<<endl;
        }
        else{
            arr[0]=arr[k-1];
            arr[k-1]=2e9+1;
            down(0);
            k--;
        }
        // for(int j=0;j<k;j++){
        //     cout<<arr[j]<<" ";
        // }
        // cout<<endl;
    }

}
heap sorting(solution1)
// from Haoxuan Tong
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> h;

void insert(int node){
    h.push_back(node);
    int index=h.size()-1;
    while (node<h[index/2]){
        int temp=h[index/2];
        h[index/2]=node;
        h[index]=temp;
        index/=2;
    }
}

void pop(){
    int index=h.size()-1;
    h[1]=h[index];
    index=1;
    h.resize(h.size()-1);
    /*for (int i=0;i<h.size();i++){
        cout<<h[i]<<' ';
    }
    cout<<endl;*/
    while (h[index]>h[index*2]&&index*2<h.size()||h[index]>h[index*2+1]&&index*2+1<h.size()){
        //cout<<index<<' '<<h.size()<<endl;
        if (h[index*2]<h[index*2+1]&&index*2<h.size()+1){
            int temp=h[index*2];
            h[index*2]=h[index];
            h[index]=temp;
            index*=2;
        } else if (index*2+1<h.size()+1){
            int temp=h[index*2+1];
            h[index*2+1]=h[index];
            h[index]=temp;
            index=index*2+1;
        }
    }
}

int main(){
    cin>>n;
    h.push_back(0);
    for (int i=1;i<=n;i++){
        int k;
        cin>>k;
        insert(k);
    }
    for (int i=0;i<n;i++){
        cout<<h[1]<<' ';
        pop();
    }
}



heap sorting(solution2)
//using the built-in priority queue

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cur;
    priority_queue<int, vector<int>, greater<int>> pq; //min heap
    scanf("%d", &n);

    // build a queue
    for(int i = 0; i < n; i++) {
        scanf("%d", &cur);
        pq.push(cur);
    }

    // extract-max n times
    while(!pq.empty()) {
        int ans = pq.top();
        pq.pop();
        printf("%d ", ans);
    }
}

median
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, median, current;
    int left = 0, right = 0;
    priority_queue<int> left_pq;
    priority_queue<int, vector<int>, greater<int>> right_pq;
    scanf("%d%d", &n, &median); // the first number is a median itself.
    printf("%d\n", median);
    // from index 2 to the rest
    for(int i = 2; i<= n; i++) {
        scanf("%d", &current);
        if(current > median) {    // if current is greater than median, push to right pq
            right++;
            right_pq.push(current);
        }
        else {                    // if current is less than the median, push to left pq.
            left++;
            left_pq.push(current);
        }

        if(i % 2 == 1) {        // for 3, 5, 7, ...
            if(right == left +2) {    // if right size has two more elements than left, move median to right
                left_pq.push(median);
                median = right_pq.top();
                right_pq.pop();
            }
            else if(left == right + 2) {  // if left size has two more eles than right, move median to left.
                right_pq.push(median);
                median = left_pq.top();
                left_pq.pop();
            }

            right = 0, left = 0;       // reset right and left
            printf("%d\n", median);
        }
    }

    return 0;
}
