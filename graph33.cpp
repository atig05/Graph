#include<bits/stdc++.h>
#include<fstream>
#define list vector<int>
#include"linkedlist.cpp"
using namespace std;
class graph{
	int v=0;
	//int **G;
	vector<list> G;  ;
	vector<char> vset;
	public:

	graph(int n){
		v=n;
		//G=(linked_list*)malloc(n*sizeof(linked_list));
	}
	void insert_vset(vector<char> k,int n){
		for(int i=0;i<n;i++)
			vset.push_back(k[i]);
	}
	void show_vertex(){
		for(int i=0;i<v;i++)
			cout<<vset[i]<<" ";
		cout<<endl;		
	}
	void in(int **a){
		
		for(int i=0;i<v;i++){
			vector<int> f;
			//int *f=(int *)malloc(v*sizeof(int));
			for(int j=0;j<v;j++){
				if(a[i][j]!=0){
					f.push_back(j);
				}
			}
				G.push_back(f);
		}
	}
	void show(){
		int n=v;
		cout<<"-----THE adjacency list-----"<<endl;
		for(int i=0;i<n;i++){
			cout<<vset[i];
			for(int j=0;j<G[i].size();j++){
				cout<<"->"<<vset[G[i][j]];
			}
			cout<<endl;
		}
		cout<<"------------------------------"<<endl;		
	}
	int edge(){
		int c=0;
		for(int i=0;i<v;i++){
			c+=G[i].size();
				
		}
		return c/2;
	}
	int degree(){
		return 2*edge();
	}
	void adj_vertex(){
		cout<<"-------Adjacent vertices-------"<<endl;
		for(int i=0;i<v;i++){
			for(int j=0;j<G[i].size();j++)
				cout<<vset[i]<<"-"<<vset[G[i][j]]<<endl;
			}
		
	}	
};

graph read_file(){
	int n;
	fstream g;
	g.open("ggg.txt",ios::in);
	g>>n;
	vector<char> k;
	for(int i=0;i<n;i++){
		char h;
		g>>h;
		k.push_back(h);
	}
		
	
	graph A=graph(n);
	A.insert_vset(k,n);
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
