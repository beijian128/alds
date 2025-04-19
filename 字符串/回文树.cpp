//������
const int MAXN = 3e5 + 10;// n(�ռ临�Ӷ�o(n*ALP)),ʵ�ʿ�n����
const int ALP = 26;
struct PAM { // ÿ���ڵ����һ�����Ĵ�
	int next[MAXN][ALP]; // nextָ��,����Trie��
	int fail[MAXN]; // failʧ���׺����  //ָ�� ����ĺ�׺
	int cnt[MAXN]; // �˻��Ĵ����ָ���
	int num[MAXN];//fail ���ĳ���  //���� ��λ��Ϊ��β�� �Ļ��Ĵ� ����
	int len[MAXN]; // ���Ĵ�����
	int s[MAXN]; // �����ӵ��ַ�
	int last; //ָ����һ���ַ����ڵĽڵ㣬������һ��add
	int n; // ������ַ�����
	int p; // �ڵ����
	int newnode(int w) { // ��ʼ���ڵ㣬w=����
		for (int i = 0; i < ALP; i++)
			next[p][i] = 0;
		cnt[p] = 0;
		num[p] = 0;
		len[p] = w;
		return p++;
	}
	void init() {
		p = 0;
		newnode(0);
		newnode(-1);
		last = 0;
		n = 0;
		s[n] = -1; // ��ͷ��һ���ַ�����û�е��ַ�����������
		fail[0] = 1;
	}
	int get_fail(int x) { // ��KMPһ����ʧ�����һ���������
		while (s[n - len[x] - 1] != s[n]) x = fail[x];
		return x;
	}
	void add(int c) {
		c -= 'a';
		s[++n] = c;
		int cur = get_fail(last);
		if (!next[cur][c]) {
			int now = newnode(len[cur] + 2);
			fail[now] = next[get_fail(fail[cur])][c];
			next[cur][c] = now;
			num[now] = num[fail[now]] + 1;
		}
		last = next[cur][c];
		cnt[last]++;
	}
	void count() {
		// ���ͳ��һ��ÿ���ڵ���ָ���
		// �����ۼӶ��ӵ�cnt,����SAM��parent��
		// ����parent���˹�ϵ
		for (int i = p - 1; i >= 0; i--)
			cnt[fail[i]] += cnt[i];
	}
}pam;
char s[MAXN];
 /*
	pam.init();
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; i++)pam.add(s[i]);
 */