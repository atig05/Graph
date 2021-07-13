#include<bits/stdc++.h>
using namespace std;
int find(vector<char> s,char a){
	for(int i=0;i<s.size();i++){
		if(s[i]==a)
			return i;
	}
	return -1;
}
class graph{
	int **G;
	
	vector<char> vset;
	int v;
	
	public:
	graph(int n){
		G=(int**)malloc(sizeof(int*)*n);
		v=n;
	}
	void show(){
		int n=vset.size();
		for(int i=0;i<vset.size();i++)
			cout<<" "<<vset[i];
		cout<<endl;
		for(int i=0;i<n;i++){
			cout<<vset[i];
			for(int j=0;j<n;j++)
				cout<<" "<<G[i][j];
			cout<<endl;
		}
	}

	void add_vertex_set(vector<char> &a){
		vset=a;
	}
	void in(int **a){
		G=a;
	}
	void BFS(){
		char a;
		cout<<"Enter what vertex you want to take as root-";
		cin>>a;
		bool visit[vset.size()];
		for(int i=0;i<vset.size();i++)
			visit[i]=false;
		queue<int> q;
		
		int t=find(vset,a);
		q.push(t);
		
		visit[t]=true;
		while(!q.empty()){
			
			t=q.front();

			cout<<vset[t]<<" ";
			for(int i=0;i<vset.size();i++){
				if(G[t][i]==1 && visit[i]==false){
					q.push(i);
					visit[i]=true;
				}
			}
			q.pop();
		}
		for(int i=0;i<vset.size();i++){
			if(!visit[i])
				cout<<vset[i]<<" ";
		}
		cout<<endl;
	}
	
	void show_vertex(){
		for(int i=0;i<vset.size();i++)
			cout<<vset[i]<<" ";
		cout<<endl;
	}
	void DFS(){
		//show();
		int v=vset.size();
		char a;
		cout<<"Enter what vertex you want to take as root-";					
		cin>>a;
	    int	t=find(vset,a);
		bool visit[v];
		for(int i=0;i<v;i++)
			visit[i]=false;		
		stack<int> s;
		s.push(t);
		vector<int> b;
		visit[t]=true;
		int c=1;
		cout<<vset[t]<<" ";
		while(c!=v){
		//	cout<<vset[t]<<" ";
			t=s.top();
			b.push_back(t);
			bool flag=false;
			for(int i=0;i<v;i++){
				if(visit[i]!=true && G[t][i]==1){
					flag=true;
					s.push(i);
					cout<<vset[i]<<" ";
					visit[i]=true;
					c++;
					break;
				}
			}
			if(!flag)
				break;
		}
	//	
		s.pop();
		while(c!=v){
			t=s.top();
			//b.push_back(t);
			int cou=0;
			for(int i=0;i<v;i++){
				if(visit[i]!=true &&G[t][i]==1){
					cout<<vset[i]<<" ";
					s.push(i);
					visit[i]=true;
					c++;
					cou=1;
					break;
				}
			}
			if(cou==0)
				s.pop();
		}
	cout<<endl;
	}
	void DFS_recurssive(char a,bool visit[]){
		int t=find(vset,a);
		visit[t]=1;
		cout<<vset[t]<<" ";
		for(int i=0;i<v;i++){
			if(G[t][i] && !visit[i])
				DFS_recurssive(vset[i],visit);
		}
		return;
	}
	void DFS_rec(){
		show();
		int v=vset.size();
		char a;
		cout<<"Enter what vertex you want to take as root-";					
		cin>>a;
	    int	t=find(vset,a);
		bool visit[v];
		for(int i=0;i<v;i++)
			visit[i]=false;			
		DFS_recurssive(a,visit)	;
		cout<<endl;
	}
};
graph read_file(){
	int n;
	fstream g;
	g.open("gg.txt",ios::in);
	g>>n;
	vector<char> k;
	for(int i=0;i<n;i++){
		char h;
		g>>h;
		k.push_back(h);
	}
		
	
	graph A=graph(n);
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
	cout<<"DFS"<<endl;
//	g.adj_vertex();
	g.DFS();
	cout<<endl<<"BFS"<<endl;
	g.BFS();
	g.DFS_rec();
}

