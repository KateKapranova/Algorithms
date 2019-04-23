#include <bits/stdc++.h>

using namespace std;

struct Edge{
    int fromNode;
    int toNode;
    int weight;

};

int getWeight(int x, int y){
    if ((x>=0 && y>=0) ||(x<=0 && y<=0)){
        return abs(abs(x)-abs(y));
    }
    else if (x<0 || y<0){
        return abs(abs(x)+abs(y));
    }
}

int findRoot(vector<int> &vec, int r){
    while(r!=vec[r])
        r=vec[r];
    return r;
}

bool sortFunction (Edge& i, Edge& j) { return (i.weight > j.weight); }

int main() {
	int nodes,edges,from,to;

    cin>>nodes>>edges;

    vector<int> elevation(nodes);
    vector<Edge> weightedEdges(edges);
    for (int i=0;i<nodes;i++){
        cin>>elevation[i];
    }

    for (int k=0; k<edges; k++){
        cin>>from>>to;
        weightedEdges[k].fromNode=from;
        weightedEdges[k].toNode=to;
        weightedEdges[k].weight=getWeight(elevation[from],elevation[to]);
    }
	/*
    cout<<"edge 0: from "<<weightedEdges[0].fromNode<<" to "<< weightedEdges[0].toNode<<" with weight "<<weightedEdges[0].weight<<endl;
    cout<<"edge 1: from "<<weightedEdges[1].fromNode<<" to "<< weightedEdges[1].toNode<<" with weight "<<weightedEdges[1].weight<<endl;
    cout<<"edge 2: from "<<weightedEdges[2].fromNode<<" to "<< weightedEdges[2].toNode<<" with weight "<<weightedEdges[2].weight<<endl;
    cout<<"edge 3: from "<<weightedEdges[3].fromNode<<" to "<< weightedEdges[3].toNode<<" with weight "<<weightedEdges[3].weight<<endl;
    cout<<"edge 4: from "<<weightedEdges[4].fromNode<<" to "<< weightedEdges[4].toNode<<" with weight "<<weightedEdges[4].weight<<endl;*/

    sort(weightedEdges.begin(),weightedEdges.end(),sortFunction);
    //cout<<"sorted"<<endl;
    /*cout<<"edge 0: from "<<weightedEdges[0].fromNode<<" to "<< weightedEdges[0].toNode<<" with weight "<<weightedEdges[0].weight<<endl;
    cout<<"edge 1: from "<<weightedEdges[1].fromNode<<" to "<< weightedEdges[1].toNode<<" with weight "<<weightedEdges[1].weight<<endl;
    cout<<"edge 2: from "<<weightedEdges[2].fromNode<<" to "<< weightedEdges[2].toNode<<" with weight "<<weightedEdges[2].weight<<endl;
    cout<<"edge 3: from "<<weightedEdges[3].fromNode<<" to "<< weightedEdges[3].toNode<<" with weight "<<weightedEdges[3].weight<<endl;
    cout<<"edge 4: from "<<weightedEdges[4].fromNode<<" to "<< weightedEdges[4].toNode<<" with weight "<<weightedEdges[4].weight<<endl;*/

    //Implementation of UNION-FIND with compressed size
    vector<int> Roots(nodes);
    vector<int> Size(nodes);
    
    //at the start all nodes are represented as forest
    for(int i=0;i<nodes;i++){
        Roots[i]=i;
        Size[i]=1;
    }
    	
    int index=edges-1;int node1,node2,root1,root2,elevatorsCount=0;
	while(weightedEdges.size()>0){
    //while(unitedNodes.size()<=nodes){
		node1 = weightedEdges[index].fromNode;
        node2 = weightedEdges[index].toNode;
        
        //if nodes don't belong to the same set, we unite them
        root1=findRoot(Roots,node1);
        root2=findRoot(Roots,node2);
        if(root1!=root2){
            //update number of elevators needed
            elevatorsCount+=weightedEdges[index].weight;
            //union operation
            if (Size[root1]<Size[root2]) {
                Roots[root1]=root2;
                Size[root2]+=Size[root1];
            }
            else {
                Roots[root2]=root1;
                Size[root1]+=Size[root2];
            }
        }
        
		weightedEdges.pop_back();
        index-=1;
    }
    cout<<elevatorsCount<<endl;
    ios::sync_with_stdio(false);
    return 0;
}
