#include <iostream>
#include <vector>
using namespace std;

vector<int> findNLargestElements(const vector<vector<int>>& matrix, int n) {
    vector<int> largestElements;
    // TODO:
    int k = n*n;
    
    //leaf 개수를 k 이상인 가장 작은 2의 제곱수로 맞춤.
    int size =1; 
    while(size<k)size*=2; 

    vector<int> tree(2*size, -1);

    for(int i =0; i<k; i++) tree[size+i]=i;
    auto bigger = [&](int a, int b)->int{
          if(a==-1) return b;
          if(b==-1) return a;
          int rowA = a/n;
          int colA = a%n;
          int rowB= b/n;
          int colB =b%n;

          if(matrix[rowA][colA]>=matrix[rowB][colB]) return a;
          else return b;
    };
    for(int i =size-1;i>=1;i--) tree[i]=bigger(tree[i*2], tree[i*2+1]);
    for(int count = 0; count < n;count++){
        int maxIndex = tree[1];
        int row = maxIndex/n;
        int col = maxIndex%n;
        largestElements.push_back(matrix[row][col]);
        int pos = size + maxIndex;
        tree[pos]=-1;
        pos/=2;
        while(pos>=1){
            tree[pos]=bigger(tree[pos*2], tree[pos*2+1]);
            pos/=2;

        }

    }
     return largestElements;

    }


int main() {
    // Do NOT delete these lines unless you know what you are doing:
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> M(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> M[i][j];
        }
    }

    vector<int> largestElements = findNLargestElements(M, n);

    for (int element : largestElements) {
        cout << element << "\n";
    }

    return 0;
}
