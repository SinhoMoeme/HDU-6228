# HDU - <a href="https://acm.hdu.edu.cn/showproblem.php?pid=6228" target="_blank">6228</a>
## L - Tree - _The 2017 ACM-ICPC Asia Shenyang Regional Contest_
Consider a un-rooted tree T which is not the biological significance of tree or plant, but a tree as an undirected graph in graph theory with n nodes, labelled from 1 to n. If you cannot understand the concept of a tree here, please omit this problem.

Now we decide to colour its nodes with k distinct colours, labelled from 1 to k. Then for each colour i = 1, 2, · · · , k, define Ei as the minimum subset of edges connecting all nodes coloured by i. If there is no node of the tree coloured by a specified 
colour i, Ei will be empty.

Try to decide a colour scheme to maximize the size of E1 ∩ E2 · · · ∩ Ek, and output its size.

## Input
The first line of input contains an integer T (1 ≤ T ≤ 1000), indicating the total number of test cases.

For each case, the first line contains two positive integers n which is the size of the tree and k (k ≤ 500) which is the number of colours. Each of the following n - 1 lines contains two integers x and y describing an edge between them. We are sure that the
given graph is a tree.

The summation of n in input is smaller than or equal to 200000.

## Output
For each test case, output the maximum size of E1 ∩ E1 ... ∩ Ek.

## Sample
### Input
```
3
4 2
1 2
2 3
3 4
4 2
1 2
1 3
1 4
6 3
1 2
2 3
3 4
3 5
6 2
```

### Output
```
1
0
1
```

---
_By SinhoMoeme_

_題解作者 史行·某萌_

## Summary | 題目大意
There are $T$ test cases.<br>
For each test case, there is a un-rooted tree with $n$ nodes. You will color the nodes with $k$ colors. You need to give the maximum number of edges which connects to all colors of nodes.

測試資料共 $T$ 組。<br>
對於每一組資料，有一棵 $n$ 節點無根樹，用 $k$ 種顏色上色。請給出連接所有種類顔色節點之邊的數目最大值。

## AC Code | AC程式碼
``` C++
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
```
## Explain | 題目講解


### Variables | 變數


### Functions | 函式


### Other | 其他

