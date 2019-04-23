#include <bits/stdc++.h>

using namespace std;

struct Moats{
    int fromNode;
    int toNode;
};

int main(){
	int nodes, edges,from,to,current;
	cin >> nodes >> edges;
	
	vector<Moats> existingEdges(edges);

	for(int i=0;i<edges;i++){
		cin>>from>>to;
        existingEdges[i].fromNode=from;
        existingEdges[i].toNode=to;
	}
	
	vector<bool> visited(nodes);
	list<int> queue;
	
	for(int i=0;i<nodes;i++){
		visited[i]=false;
	}
	/*
	for (int i=0;i<edges;i++){
		cout<<existingEdges[i].fromNode<<" "<<existingEdges[i].toNode<<endl;
	}
	*/
	
	
	//BFS
	visited[0]=true;
	queue.push_back(0);
	
	while(!queue.empty()){
		current=queue.front();
		//cout<<"queue front element is: "<<current<<endl;
				
		for(int k=0;k<edges;k++){
			if (existingEdges[k].fromNode==current && visited[existingEdges[k].toNode]==false){
				//cout<<"test1"<<endl;
				visited[existingEdges[k].toNode]=true;
				queue.push_back(existingEdges[k].toNode);
				//cout<<"size of queue: "<<queue.size()<<endl;
			}
			else if (existingEdges[k].toNode==current && visited[existingEdges[k].fromNode]==false){
				visited[existingEdges[k].fromNode]=true;
				queue.push_back(existingEdges[k].fromNode);
			}
		}
		queue.pop_front();
		//cout<<"size of queue: "<<queue.size()<<endl;
		
	}

	for(int i=0;i<nodes;i++){
		//cout<<"test2"<<endl;
		if (visited[i]==false){
			cout<<0<<endl;
			return 0;
		}	
		
	}
	
	
	cout<<1<<endl;
	ios::sync_with_stdio(false);

    return 0;
}