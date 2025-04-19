//�ж��Ƿ��н� �������һ��� O(n+m)
int scc, top, tot;
vector<int> mp[MAX];
int low[MAX], dfn[MAX], belong[MAX];
int stk[MAX], flag[MAX];
int pos[MAX], degree[MAX], ans[MAX], outflag[MAX], cnt;
vector<int> dag[MAX];
void init(int n)
{
	int i;
	for (i = 0; i < 2 * n; i++)
	{
		mp[i].clear();
		dag[i].clear();
		low[i] = 0;
		dfn[i] = 0;
		stk[i] = 0;
		flag[i] = 0;
		degree[i] = 0;
		outflag[i] = 0;
	}
	scc = top = tot = 0;
}
void tarjan(int x)
{
	int to, i, temp;
	stk[top++] = x;
	flag[x] = 1;
	low[x] = dfn[x] = ++tot;
	for (i = 0; i < mp[x].size(); i++)
	{
		to = mp[x][i];
		if (!dfn[to])
		{
			tarjan(to);
			low[x] = min(low[x], low[to]);
		}
		else if (flag[to]) low[x] = min(low[x], dfn[to]);
	}
	if (low[x] == dfn[x])
	{
		scc++;
		do
		{
			temp = stk[--top];
			flag[temp] = 0;
			belong[temp] = scc;
		} while (temp != x);
	}
}
void add(int x, int y)
{
	mp[x].push_back(y);
}
void topsort(int n)
{
	int i, t;
	queue<int> q;
	cnt = 0;
	for (i = 1; i <= scc; i++)
	{
		if (degree[i] == 0) q.push(i);
		outflag[i] = 0;
	}
	while (!q.empty())
	{
		t = q.front();
		q.pop();
		if (outflag[t] == 0)
		{
			outflag[t] = 1;
			outflag[pos[t]] = 2;
		}
		for (i = 0; i < (dag[t]).size(); i++)
		{
			int to = dag[t][i];
			degree[to]--;
			if (degree[to] == 0) q.push(to);
		}
	}
}
void builddag(int n)
{
	int i, j, to;
	for (i = 0; i < 2 * n; i++)
	{
		for (j = 0; j < (mp[i]).size(); j++)
		{
			to = mp[i][j];
			if (belong[i] != belong[to])
			{
				degree[belong[i]]++;
				dag[belong[to]].push_back(belong[i]);
			}
		}
	}
}
void twosat(int n)
{
	int i;
	for (i = 0; i < 2 * n; i++)
	{
		if (!dfn[i]) tarjan(i);
	}
	for (i = 0; i < n; i++)
	{
		if (belong[2 * i] == belong[2 * i + 1])//�޽� 
		{
			puts("NO");
			return;
		}
	}
	builddag(n);
	topsort(n);
	for (i = 0; i < n; i++) {
		int x = belong[i << 1] > belong[i << 1 | 1];
		printf("%d%c", MAP[i / m][i % m] + x, (i + 1) % m == 0 ? '\n' : ' ');
	}
}