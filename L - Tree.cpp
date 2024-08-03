#include<cstdio>
#include<cstring>
#include<vector>
using std::vector;
constexpr size_t MAX=(size_t)2e5+1;
int T,n,k,x,y,ans;
long long a[MAX];
vector<int> g[MAX];
inline void dfs(int p=0,int u=1){
	a[u]=1;
	int v;
	for(int i=0;i<g[u].size();++i){
		v=g[u][i];
		if(v==p) continue;
		dfs(u,v);
		a[u]+=a[v];
	}
	return;
}
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i) g[i].clear();
		for(int i=1;i<n;++i){
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs();
		for(int i=1;i<=n;++i){
			if(a[i]>=k&&n-a[i]>=k) ++ans;
		}
		printf("%d",ans);
		putchar('\n');
	}
	return 0;
}