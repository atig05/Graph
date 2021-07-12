#include<bits/stdc++.h>
#include<fstream>
#include<stdlib.h>
using namespace std;
class graph{
	int v=0;
	int **G;
	vector<char> vset;
	public:

	graph(int n){
		v=n;
		G=(int**)malloc(n*sizeof(int*));
	}
	void add_vertex_set(vector<char> &a){
		vset=a;
	}
	void in(int **a){
		G=a;
	}
	void show(){
		int n=v;
		cout<<"-----THE adjacency Matrix-----"<<endl;
		for(int i=0;i<n;i++)
			cout<<vset[i]<<" ";
		cout<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cout<<G[i][j]<<" ";
			cout<<endl;
		}
		cout<<"------------------------------"<<endl;		
	}
	int edge(){
		int c=0;
		for(int i=0;i<v;i++){
			for(int j=i;j<v;j++){
				if(G[i][j]==0)
					continue;
				c+=G[i][j];
			}
				
		}
		return c;
	}
	int degree(){
		return 2*edge();
	}
	void adj_vertex(){
		cout<<"-------Adjacent vertices-------"<<endl;
		for(int i=0;i<v;i++){
			for(int j=i;j<v;j++){
				if(G[i][j]!=0)
					cout<<vset[i]<<"-"<<vset[j]<<endl;
			}
		}
	}
};
graph read_file(){
	int n;
	fstream g;
	g.open("gg.txt",ios::in);
	g>>n;
	graph A=graph(n);
	vector<char> k;
	for(int i=0;i<n;i++){
		char f;
		g>>f;
		k.push_back(f);
	}
	A.add_vertex_set(k);	
	int **a=(int **)malloc(n*sizeof(int*));
	for(int i=0;i<n;i++){
		int *f=(int *)malloc(n*sizeof(int));
		for(int j=0;j<n;j++)
			g>>f[j];
		*(a+i)=f;
	}

A.in(a);	
	//A.show();
	return A;
	}
int main(void){
	graph g=read_file();
	g.show();
	cout<<"NO of Edges-"<<g.edge()<<endl;
	cout<<"TOTAL Degree of the graph-"<<g.degree()<<endl;
	g.adj_vertex();
	
}
