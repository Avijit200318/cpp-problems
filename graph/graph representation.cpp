// G-2

// we can represent graph using 2 method

// 1. is using 2d array

// n = no of nodes and m = number of edges
// then we have m number of lines that represent how nodes connect to other nodes
// also it is given if the graph is directional or not

int main(){
    int n, m;
    cin >> n>> m;

    int arr[n+1][n+1];

    for(int i = 0; i< m; i++){
        int u, v;
        cin >> u >> v;
        arr[u][v] = 1;
        arr[v][u] = 1;
        // in case of undirected graph
    }
}

// it will take a space complexity of o(n * n)


// 2. method 2 using vector array

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> arr[n+1];

    for(int i= 0; i< m; i++){
        int u, v;
        cin >> u >> v;

        arr[u].push_back(v);
        arr[v].push_back(u); // v -> u
        // if it is directed then just remove one of this line
    }
}

// for this method the space will it take is o(2E) but if it unidirectional graph then o(E)


// 3. weighted graph