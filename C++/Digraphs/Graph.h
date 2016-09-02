#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>

using namespace std;

class GraphNode{
public:
	int nodeID; //ID of node; makes it easy to find the node in the array
	vector<GraphNode*> adj; //List of nodes it points to
	bool visitedA; //true if already visited
	bool visitedB;
	int shortestPath;
	GraphNode(int id = -1, GraphNode *adjList = NULL):
		nodeID(id){visitedA = false; visitedB = false; adj.push_back(adjList); shortestPath=0;}

	void resetFlags()
	{
		visitedA=false;
		visitedB=false;
	}

}; //GraphNode

class Graph{
protected:
	GraphNode *G; //Array of nodes in graph - will be given space once the size is known
	int nodeCt; //Size of G
	int edgeCt;
	
	void setID(int num){
		for(int i = 0; i < num; i++){
			G[i].nodeID = i;
			G[i].adj.clear();
		}
	}

	void reset(){
		for(int i = 0; i < nodeCt; i++) {
			G[i].visitedA = false;
			G[i].visitedB = false;
		}
	}

	bool all_visited(){
		for(int i = 0; i < nodeCt; i++){
			if(G[i].visitedA == false && G[i].visitedB == false) return false;
		}
		return true;
	}

	int unvisited_adj(){
		for(int i = 0; i < nodeCt; i++){
			if(G[i].visitedA == false) return i;
		}
		return -1;
	}


public:
	Graph(){
		nodeCt = 0;
		edgeCt = 0;
		G = NULL;
	}
	Graph(int size) {G = new GraphNode[size]; nodeCt = size;}; //create node array
	string toString(string label, ostream & fout);
	void BuildGraph(istream & inf);

	void read_file(string file){

		ifstream in(file);

		if(!in) return;

		string to_n, from_n;
		string s;

		in>>nodeCt>>edgeCt;

		G = new GraphNode[nodeCt];
		setID(nodeCt);

		for(int i = 0; i < edgeCt; i++){
			in>>from_n>>to_n;

			int from = atoi(&from_n[0]);
			int to = atoi(&to_n[0]);
			GraphNode * secondNode = new GraphNode(to);
			if(G[from].nodeID == -1)
			{
				G[from]=*(new GraphNode(from)); //add a loop to reach NULL
			}
			G[from].adj.push_back(&G[to]);

		}
		in.close();
	}

	void list_print(){
		for(int i = 0; i < nodeCt; i++){
			if(G[i].nodeID < nodeCt) {
				cout<<G[i].nodeID<<"--->";
				if(G[i].adj.empty()) cout<<'0';
				else 
				{
					for(int j=0; j< G[i].adj.size();j++)
					{
						cout<<G[i].adj[j]->nodeID<<" ";
					}
				}
			}

			cout<<endl;
		}
	}

	//Shortest Common Ancestor
	int SCA(int node1, int node2, bool print){
		reset();
		int shortest_common;
		vector<int> path1, path2;
		stack<GraphNode> stacky;
		GraphNode * temp = &G[node1];
		stacky.push(*temp);
		int currPath=0;
		/*for(int i = 1; i <= nodeCt; i++){
			
			temp->visitedA = true;
			temp->shortestPath=currPath;
			currPath++;
			path1.push_back(temp->nodeID);
			if(temp->nodeID==0)
				break;
			if(temp->adj.front() ==temp->adj.back())
				temp = temp->adj.front;
			else
				for(int j=0; j<temp->adj.size();j++)

		}*/
		nonDivergingPaths(node1,path1, true);
		nonDivergingPaths(node2,path2, false);
		/*temp=&G[node2];
		for(int i = 1; i <= nodeCt; i++){
			temp->visitedB = true;
			path2.push_back(temp->nodeID);
			if(temp->nodeID==0)
				break;
			if(temp->visitedA == true)
				break;
			temp = temp->adj;
		}*/
		
		int length = 0;
		if(print)
		cout<<"Shortest Ancestral Path: ";

		for(int i=0; i<path1.size(); i++)
		{
			if(print)
			cout<<path1[i]<<' ';
			if(path1[i]==path2[path2.size()-1]){
				length = i + path2.size();
				break;
			}
		}
		if(print)
		for(int k = path2.size()-1; k > 0; k--){
			cout<<path2[k-1]<<' ';
		}
		if(print){
		cout<<endl;
		
		cout<<"Shortest Common Ancestor: "<<path2[path2.size()-1]<<endl;
		cout<<"Associated Length: "<<length<<endl<<endl;}
		return length;
	}
	void nonDivergingPaths(int node1, vector<int>&path1, bool isvisitedA)
	{
		path1.push_back(node1);
		if(G[node1].nodeID==0)
			return;
		
		if( isvisitedA)
			G[node1].visitedA=true;
		else
			G[node1].visitedB=true;
		if(G[node1].visitedA==true&&G[node1].visitedB==true)
			return;
		if(G[node1].adj.front()==G[node1].adj.back())
		{
			nonDivergingPaths(G[node1].adj[0]->nodeID, path1, isvisitedA);
			return;
		}
		nonDivergingPaths(divergingPaths(node1),path1, isvisitedA);
	}
	int divergingPaths(int node1)
	{
		int nodereturn= G[node1].adj[0]->nodeID;
		int shortest = pathLengthtoRoot(G[node1].adj[0]->nodeID);
		for(int i=0; i < G[node1].adj.size();i++)
		{
			int temp = pathLengthtoRoot(G[node1].adj[i]->nodeID);
			if(temp<shortest)
				nodereturn=G[node1].adj[i]->nodeID;
		}

		return nodereturn;
	}
	int pathLengthtoRoot(int node1)
	{
		if(G[node1].nodeID==0)
			return 1;
		int shortest = pathLengthtoRoot(G[node1].adj[0]->nodeID);
		for(int i=0; i < G[node1].adj.size();i++)
		{
			int temp = pathLengthtoRoot(G[node1].adj[i]->nodeID);
			if(temp<shortest)
				shortest=temp;
		}

		return shortest+1;
	}
	int outCast(int numofNodes, vector<int> listof)
	{
		int outcast=0;
		int returnoutcast;
		for (int i = 0; i < numofNodes; i++)
		{
			int dsubi=finddsubi(listof[i], listof);
			if(dsubi>outcast)
			{
				outcast=dsubi;
				returnoutcast=listof[i];
			}
		}
		return returnoutcast;
	}
	int finddsubi(int x, vector<int> listof )
	{
		int dsubi=0;
		for(int i=0; i<listof.size();i++)
		{
			dsubi +=SCA(x,listof[i], false);
		}
		return dsubi;
	}
};