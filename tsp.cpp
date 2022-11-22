#include<bits/stdc++.h>
using namespace std;

#define N 5

struct Node{
    vector<pair<int, int>> path;
    int reducedMatrix[N][N];
    int vertex;
    int cost;
    int level;
};

struct comp{
    bool operator() (Node* lhs, Node* rhs){
        return lhs->cost > rhs->cost;
    }
};

Node* newNode(int parentMatrix[N][N], vector<pair<int, int>> path, int level, int i, int j){
    Node* node = new Node;
    node->level=level;
    node->vertex=j;
    node->path = path;
    if(level!=0){
        node->path.push_back({i, j});
    }
    memcpy(node->reducedMatrix, parentMatrix, sizeof(node->reducedMatrix));//copy parent ka reduced matrix
    for(int k=0; k<N && level!=0; k++){
        node->reducedMatrix[i][k]=INT_MAX;
        node->reducedMatrix[k][j]=INT_MAX;
    }
    node->reducedMatrix[j][0]=INT_MAX;
    return node;
}

void rowReduction(int reducedMatrix[N][N], int row[N]){
   fill_n(row, N, INT_MAX);
    //memset(row, INT_MAX, N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(reducedMatrix[i][j]<row[i]){
                row[i]=reducedMatrix[i][j];
            }
        }
    }
//sabse mmin minus hoga
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(reducedMatrix[i][j]!=INT_MAX && row[i]!=INT_MAX){
                reducedMatrix[i][j]-=row[i];
            }
        }
    }
}

void colReduction(int reducedMatrix[N][N], int col[N]){
    fill_n(col, N, INT_MAX);
    //memset(col, INT_MAX, N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(reducedMatrix[i][j]<col[j]){
                col[j]=reducedMatrix[i][j];
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(reducedMatrix[i][j]!=INT_MAX && col[j]!=INT_MAX){
                reducedMatrix[i][j]-=col[j];
            }
        }
    }
}

int calculateCost(int reducedMatrix[N][N]){
    int cost=0;

    int row[N];
    rowReduction(reducedMatrix, row);

    int col[N];
    colReduction(reducedMatrix, col);

    for(int i=0;i<N;i++){
        if(row[i]!=INT_MAX){
            cost+=row[i];
        }
        if(col[i]!=INT_MAX){
            cost+=col[i];
        }
    }
    return cost;
}

void printPath(vector<pair<int, int>> path){
    for(auto val: path){
        cout<<val.first+1<<" ---> "<<val.second+1<<'\n';
    }
}

int solve(int costMatrix[N][N]){
    priority_queue<Node*, vector<Node*>, comp> pq; //minheap
    vector<pair<int, int>> path; 
    Node* root= newNode(costMatrix, path, 0, -1, 0);
    root->cost=calculateCost(root->reducedMatrix);
    pq.push(root);
    while(!pq.empty()){
        Node* min=pq.top();
        pq.pop();
        int i=min->vertex;
        if(min->level==N-1){
            min->path.push_back({i, 0});
            printPath(min->path);
            return min->cost;
        }

        for(int j=0;j<N;j++){
            if(min->reducedMatrix[i][j]!=INT_MAX){
                Node* child = newNode(min->reducedMatrix, min->path, min->level+1, i, j);
                child->cost=calculateCost(child->reducedMatrix)+ min->cost + min->reducedMatrix[i][j];
                pq.push(child);
            }
        }
        /*for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(min->reducedMatrix[i][j]==INT_MAX){
                    cout<<"INF ";
                }
                else
                cout<<min->reducedMatrix[i][j]<<" ";
            }
            cout<<'\n';
        }*/
        cout<<'\n';
        delete min;
    }
}

int main(){
    int costMatrix[N][N] =
    {
        { INT_MAX, 10, 8, 9, 7 },
        { 10, INT_MAX, 10, 5, 6 },
        { 8, 10, INT_MAX, 8, 9 },
        { 9, 5, 8, INT_MAX, 6 },
        { 7, 6, 9, 6, INT_MAX }
    };

    int ans=solve(costMatrix);
    cout<<"Total min. cost: "<<ans;
    return 0;
}
