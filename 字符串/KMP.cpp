//KMP
struct KMP
{
	int NEXT[MAXN];
	void GetNext(char* p)
	{
		int pLen = strlen(p);
		NEXT[0] = -1;
		int k = -1;
		int j = 0;
		while (j < pLen - 1)
		{
			//p[k]��ʾǰ׺��p[j]��ʾ��׺
			if (k == -1 || p[j] == p[k])
			{
				++k;
				++j;
				NEXT[j] = k;
			}
			else
			{
				k = NEXT[k];
			}
		}
	}
	int find(char* s, char* p)
	{
		int i = 0;
		int j = 0;
		int sLen = strlen(s);
		int pLen = strlen(p);
		while (i < sLen && j < pLen)
		{
			//�����j = -1�����ߵ�ǰ�ַ�ƥ��ɹ�����S[i] == P[j]��������i++��j++    
			if (j == -1 || s[i] == p[j])
			{
				i++;
				j++;
			}
			else
			{
				//�����j != -1���ҵ�ǰ�ַ�ƥ��ʧ�ܣ���S[i] != P[j]�������� i ���䣬j = NEXT[j]    
				//NEXT[j]��Ϊj����Ӧ��NEXTֵ      
				j = NEXT[j];
			}
		}
		if (j == pLen)
			return i - j;
		else
			return -1;
	}
}kmp;
