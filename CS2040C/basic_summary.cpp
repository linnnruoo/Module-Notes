	/* 
	 * CS2040C compiled algorithm
	 *
	 * Thanks to VisuAlgo, CPP3, Steven Harlim & all his TAs
	 * Thanks to Google, StackOverflow, Github, GeeksForGeeks.... etc
	 *
	 * disclaimer: prone to error due to lack of sleep
	 */
	
	
	/****** bubble sort*****/
	void bubble_sort(){
		for (j=0; j<n-1; j++)
			for(i=0; i<n-j-1; i++)
				if(A[i]>A[i+1])
					swap(A[i], A[i+1]);
	}
	
	
	/****** insertion sort*****/
	void insertion_sort(){
		for(i=1; i<n; i++){
			e = A[i]; j=i;
			while(j>0){
				if(A[j-1]>e) A[j]=A[j-1];
				else break;
			}
		}
	}
	
	
	/****** selection sort*****/
	void selection_sort(){
		int i, j, min_idx;
		
		for(i=0; i<n-1; i++){
			min_idx = i;
			for(j=i+1; j<n; j++){
				if(arr[j]<arr[min_idx]) min_idx=j;
			}
			swap(&arr[min_idx], &arr[i]);
		}
	}
	
	/****** merge sort*****/
	void merge(){
		int N = high-low+1;
		int b[n];
		int left=low, right=mid+1, bIdx=0;
		
		while(left<=mid && right<=high) //merging
			b[bIdx++] = (a[left]<=a[right]) ? a[left++]:a[right++]; 
		while(left<=mid) b[bIdx++] = a[left++];
		while(right<=high) b[bIdx++] = a[right++];
		
		for(int k=0; k<N; k++) a[low+k]=b[k];
	}
	
	void merge_sort(){
		if(low<high) {
			int mid=(low+high)/2;
			merge_sort(a, low, mid);
			merge_sort(a, mid+1, high);
			merge_sort(a, low, mid, high);

		}
	}
	
	
	/****** quick sort*****/
	int partition(int arr[], int i, int j) {
		int p=arr[i];
		int m=i;
		for(int k=i+1; k<=j; k++){
			if(arr[k]<p){
				m++;
				swap(a[k], a[m]);
			}
		}
		swap(a[i], a[m]);
		
		return m;
	}
	
	void quick_sort(int arr[], int low, int high){
		if(low<high){
			int pivotIdx = partition(a, low, high); //O(N)
			quick_sort(a, low, pivotIdx-1); //recursively sort left subarr
			quick_sort(a, pivotIdx+1, high);//then sort right subarr
		}
	}
	
	/***random quick sort*****/
	int partition(int arr[], int i, int j) {
		int p=arr[i];
		int m=i;
		for(int k=i+1; k<=j; k++){
			if(arr[k]<p){
				m++;
				swap(a[k], a[m]);
			}
		}
		swap(a[i], a[m]);
		
		return m;
	}
	
	int random_pivoting(int arr[], int i, int j) {
		srand(time(NULL));
		int random = i + rand()%(j-i);
		
		swap(a[random], a[j]);
		
		return partition(arr, i, j);
	}
	
	void quick_sort(int arr[], int low, int high){
		if(low<high){
			int pivotIdx = random_pivoting(a, low, high); //O(N)
			quick_sort(a, low, pivotIdx-1); //recursively sort left subarr
			quick_sort(a, pivotIdx+1, high);//then sort right subarr
		}
	}
	
	
	/******* dfs *****/
	void dfs(int vertex_id) {
		if (visited[vertex_id]) return;
		visited[vertex_id] = true;
		
		for(int i=0; i<adjList[Vertex_id].size(); i++){
			dfs(adjList[vertex_id][i]);
		}
	}


	/****** bfs *****/
	void bfs(int source_v){
		queue<int> q;
		visited[source_v] = 1;
		
		q.push(source_v);
		while(!q.empty()){
			int v = q.front(); q.pop();
			for(auto& it : adjList[v]){
				if(visited[it]) continue;
				q.push(it);
				visited[it] = 1;
			}
		}
	}
	
	/*******dfs (detect circle) *****/
	void dfs(string place){
		status[place] = 1; //exploring

		for(auto &neighbours: cities[place]){

			if(status[neighbours]==0) dfs(neighbours); //to visit the neighbours
			else if(status[neighbours]==1) { //explored
				found = true;
			}
		}

		status[place] = 2; //fully visited
	}
	
	/*******find connected components *****/
	void findCC() {
		int CC=0;
		
		for(auto&u : map) status[u]=0;
		for(auto&u : map){
			if(status[u]==0) {
				CC++;
				dfs(u);//floodfill all the v in that CC
		}
	}
	
	
	/****topo sort*****/
	void toposort(){
		queue<int> Q;
		/*Finding the verticies v with no incoming edges*/
		/*Adding v with no incoming edge to queue Q*/
		while (!Q.empty()){
			int u = Q.front(); Q.pop();
			for(auto& x : AdjList[u]){
				/*deleting edge u -> x*/
				if (/*x has no incoming edge*/) Q.push(x);
			}
		}
	}
	
	
	/****bellman_ford 1*****/
	void bellmanford(int s){
		dist[s] = 0; //others == INF
		for(int i=0; i<N-1; i++){
			for(int j=0; j<E; j++){
				//relax
				dist[v] = min(dist[v], dist[u]+w);
			}
		}
	}
	
	
	/****finding negative cycle*****/
	void bellman_ford(){
		dist[s]=0;
		
		for(int i=1; i<V; i++){
			for(auto&x : egdeList){
				//if tuple is used
				u = get<0>(x);
				v = get<1>(x);
				w = get<2>(x);
				
				//relax
				dist[v] = min(dist[v], dist[u]+w);
			}
		}			
	}
	
	
	void find_negative_cycle(){
		bellman_ford();
		bool negative_cycle=false;
		
		for(int i=1; i<V; i++){
			//if tuple is used
				u = get<0>(x);
				v = get<1>(x);
				w = get<2>(x);
				
				//relax
				if(dist[u]!=INF && d[v] > d[u]+w) {
					negative_cycle = true;
				}
		}
		
	}
	
	/****** dijkstra*****/
	typedef pair<int, int> pi;
	vector<pi> adjList[MAX];
	int dist[MAX]={INF};
	
	void dijkstra(int source_v){
		priority_queue<pi, vector<pi>, greater<pi>> pq;
		
		dist[source_v]=0;
		pq.push({0, source_v});
		
		while(!pq.empty()){
			auto x = pq.top(); pq.pop();
			int curr_v = x.second, curr_w = x.first;
			
			if (visited[curr_v]) continue; //lazy deletion method
			visited[curr_v] = 1;
			
			for(auto& i: adjList[curr_v]){
				if(dist[i.first]==INF || dist[i.first]>curr_w+i.second){
					dist[i.first] = curr_w+i.second;
					pq.push({dist[i.first], i.first});
				}
			}
		}
	}
	
	/****** modified dijkstra*****/
	void modified_dijkstra(int source_v){
		priority_queue<pi, vector<pi>, greater<pi>> pq;
		
		dist[source_v]=0;
		pq.push({0, source_v});
		
		while(!pq.empty()){
			auto x = pq.top(); pq.pop();
			int curr_v = x.second, curr_w = x.first;
			
			if(curr_w>dist[curr_v]) continue; //bellmanford if uncommented
			
			for(auto& i: adjList[curr_v]){
				if(dist[i.first]==INF || dist[i.first]>curr_w+i.second){
					dist[i.first] = curr_w+i.second;
					pq.push({dist[i.first], i.first});
				}
			}
		}
	}
	
	/****** Floyd Warshall*****/
	void Floyd_Warshall(){
		for(int k=0; k<V; k++)
			for(int i=0; i<V; i++)
				for(int j=0; j<V; j++)
					AM[i][j] = min(AM[i][j], AM[i][k]+AM[k][j]);

	}
	
	
	/***** Bipartite checker *******/
	bool bipartite_checker(vectir<vector<int>> AL){
		/*initialising all colours to -1*/
		colour[0] = 1;
		queue<int> q;
		q.push(0);
		
		while(!q.empty()){
			int tempV = q.front();
			q.pop();
			
			for(auto& it : AL[tempV]){
				if(colour[it]==-1){
					colour[it] = 1 - colour[temp];
					q.push(it);
				}else if(colour[it]==colour[temp]) return false;
			}
		}
	
		return true;
	}
	
	
