//�鲢�����������
#include<bits/stdc++.h>
using namespace std;
#define N 1000005
ll a[N], b[N];//bΪ��������
typedef long long ll;
ll merge_sort(ll l, ll r)
{
	ll cnt = 0;
	if (r - l > 0)//�������������Ԫ�ظ�������1��������ָ�
	{
		ll mid = (l + r) / 2;
		ll i = l; //����������±�
		ll p = l, q = mid + 1;
		merge_sort(l, mid);
		merge_sort(mid + 1, r);
		//printf("%d-%d  %d-%d\n",p,mid ,q ,r);
		while (p <= mid || q <= r)//����������ֻҪ��һ���ֲ�Ϊ��
		{
			if (q > r || (p <= mid && a[p] <= a[q]))//��������鸴�Ƶ���������
				b[i++] = a[p++];
			else
			{
				b[i++] = a[q++];
				cnt += mid - p + 1;//������Եĸ����ۼ�����
			}
		}
		for (i = l; i <= r; i++)//��b���ź����Ԫ�ظ��Ƶ�a��
			a[i] = b[i];
	}
	return cnt;
}