// 1
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis;

void bfs(int s){
    queue<int> q;
    vis.assign(adj.size(),0);
    q.push(s); vis[s]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        cout<<u<<" ";
        for(int v:adj[u]) if(!vis[v]){
            vis[v]=1; q.push(v);
        }
    }
    cout<<endl;
}

void dfsRec(int u){
    vis[u]=1; cout<<u<<" ";
    for(int v:adj[u]) if(!vis[v]) dfsRec(v);
}

void dfs(int s){
    vis.assign(adj.size(),0);
    dfsRec(s);
    cout<<endl;
}

struct DSU{
    vector<int> p;
    DSU(int n){ p.resize(n); iota(p.begin(),p.end(),0); }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    void unite(int a,int b){ a=find(a); b=find(b); if(a!=b) p[b]=a; }
};

int kruskal(int V, vector<tuple<int,int,int>>& e){
    sort(e.begin(),e.end());
    DSU d(V);
    int cost=0;
    for(auto &x:e){
        int w,u,v; tie(w,u,v)=x;
        if(d.find(u)!=d.find(v)){
            d.unite(u,v); cost+=w;
        }
    }
    return cost;
}

int prim(int V, vector<vector<pair<int,int>>>& g){
    vector<int> vis(V,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    int cost=0;
    while(!pq.empty()){
        auto t=pq.top(); pq.pop();
        int w=t.first, u=t.second;
        if(vis[u]) continue;
        vis[u]=1; cost+=w;
        for(auto &p:g[u]) pq.push({p.second,p.first});
    }
    return cost;
}

vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& g, int s){
    vector<int> dist(V,1e9);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[s]=0; pq.push({0,s});
    while(!pq.empty()){
        auto t=pq.top(); pq.pop();
        int d=t.first,u=t.second;
        if(d!=dist[u]) continue;
        for(auto &p:g[u]){
            int v=p.first,w=p.second;
            if(dist[v]>d+w){
                dist[v]=d+w; pq.push({dist[v],v});
            }
        }
    }
    return dist;
}

int main(){
    int V,E; 
    cin>>V>>E;

    adj.assign(V,{});
    vector<vector<pair<int,int>>> wg(V);
    vector<tuple<int,int,int>> edges;

    for(int i=0;i<E;i++){
        int u,v,w; 
        cin>>u>>v>>w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        wg[u].push_back({v,w});
        wg[v].push_back({u,w});
        edges.push_back({w,u,v});
    }

    int start; cin>>start;

    bfs(start);
    dfs(start);
    cout<<kruskal(V,edges)<<endl;
    cout<<prim(V,wg)<<endl;

    vector<int> dist=dijkstra(V,wg,start);
    for(int x:dist) cout<<x<<" ";
}


// Additional questions 1
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;

void dfs(int u){
    vis[u]=1;
    for(int x:g[u]) if(!vis[x]) dfs(x);
}

int main(){
    int V,E; 
    cin>>V>>E;
    g.resize(V);
    vis.assign(V,0);
    for(int i=0;i<E;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt=0;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            cnt++;
            dfs(i);
        }
    }
    cout<<cnt;
}


// Additional questions 2
#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> a(m,vector<int>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];

    vector<vector<int>> dist(m,vector<int>(n,1e9));
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

    dist[0][0]=a[0][0];
    pq.push({a[0][0],{0,0}});

    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};

    while(!pq.empty()){
        auto t=pq.top(); pq.pop();
        int d=t.first;
        int x=t.second.first, y=t.second.second;
        if(d!=dist[x][y]) continue;

        for(int k=0;k<4;k++){
            int nx=x+dx[k], ny=y+dy[k];
            if(nx>=0 && ny>=0 && nx<m && ny<n){
                int nd=d+a[nx][ny];
                if(nd<dist[nx][ny]){
                    dist[nx][ny]=nd;
                    pq.push({nd,{nx,ny}});
                }
            }
        }
    }

    cout<<dist[m-1][n-1];
}


// Additional questions 3
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,E,K;
    cin>>N>>E>>K;
    vector<vector<pair<int,int>>> g(N+1);
    for(int i=0;i<E;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    vector<int> dist(N+1,1e9);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[K]=0;
    pq.push({0,K});
    while(!pq.empty()){
        auto t=pq.top(); pq.pop();
        int d=t.first,u=t.second;
        if(d!=dist[u]) continue;
        for(auto &p:g[u]){
            int v=p.first,w=p.second;
            if(dist[v]>d+w){
                dist[v]=d+w;
                pq.push({dist[v],v});
            }
        }
    }
    int ans=0;
    for(int i=1;i<=N;i++){
        if(dist[i]==1e9){
            cout<<-1;
            return 0;
        }
        ans=max(ans,dist[i]);
    }
    cout<<ans;
}


// Additional questions 4
#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> a(m,vector<int>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];

    vector<vector<int>> vis(m,vector<int>(n,0));
    int cnt=0;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==1 && !vis[i][j]){
                cnt++;
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j]=1;
                while(!q.empty()){
                    auto p=q.front(); q.pop();
                    int x=p.first, y=p.second;
                    for(int k=0;k<4;k++){
                        int nx=x+dx[k], ny=y+dy[k];
                        if(nx>=0 && ny>=0 && nx<m && ny<n){
                            if(a[nx][ny]==1 && !vis[nx][ny]){
                                vis[nx][ny]=1;
                                q.push({nx,ny});
                            }
                        }
                    }
                }
            }
        }
    }

    cout<<cnt;
}

