// �����ޱ��������ж�
ll q_mul(ll a, ll b, ll mod) {    //��˷� ���ڿ����ݵĶ���˼�� 
	ll ans = 0;                    //���ڿ��ǵ�ȡģ���ܴ� �����ݻ���� 
	while (b) {                    //����ʹ�ø÷��� 
		if (b & 1)                    //������д���Ƿǵݹ�� 
			ans = (ans + a) % mod;
		a = a * 2 % mod;
		b >>= 1;
	}
	return ans;
}

ll q_pow(ll a, ll n, ll mod)
//a^b % mod
{
	ll ret = 1;
	ll tmp = a % mod;
	while (n)
	{
		if (n & 1)//ret = ret * tmp % mod;
			ret = q_mul(ret, tmp, mod);
		//tmp = tmp * tmp % mod;
		tmp = q_mul(tmp, tmp, mod);
		n >>= 1;
	}return ret;
}

bool Miller_Rabbin(ll n, ll a) {//�������������жϺ�������
	ll d = n - 1, s = 0, i;
	while (!(d & 1)) {            // �Ȱ�(2^s)*d ����� 
		d >>= 1;
		s++;
	}
	ll t = q_pow(a, d, n);    //a^dȡһ�����ж� 
	if (t == 1 || t == -1)        //һ��һ�������������������� 
		return 1;
	for (i = 0; i < s; i++) {                //���ǵĻ���������s��2 
		if (t == n - 1)            //(n-1)*(n-1)%n=1 ��һ�����Ż� 
			return 1;
		t = q_mul(t, t, n);    // ��� 
	}
	return 0;
}

bool is_prime(ll n) {

	if (n < 2) return 0;
	else if (n == 2) return 1;
	else {
		if (!n % 2)return 0;
	}


	ll i, tab[4] = { 3,4,7,11 };//����Ӧ��ȡ[1,n]���������� 
	for (i = 0; i < 4; i++) {                //��һ���⼸��������,����Ҫ̫������� 
		if (n == tab[i])
			return 1;        //С�ж�С�Ż�~ 
		if (!n % tab[i])
			return 0;
		if (n > tab[i] && !Miller_Rabbin(n, tab[i]))
			return 0;
	}
	return 1;
}ll n;



 //------------------------����Ϊ�����������������б�-----------------------------------------------------------------------------------------
//   -------------------------
bool isPrime(int n)
{    //����1��ʾ�ж�Ϊ������0Ϊ���������ڴ�û�н��������쳣���
	double n_sqrt;
	if (n == 2 || n == 3) return true;
	if (n % 6 != 1 && n % 6 != 5) return false;
	n_sqrt = floor(sqrt((double)n));
	for (int i = 5; i <= n_sqrt; i += 6)
	{
		if (n % (i) == 0 | n % (i + 2) == 0) return false;
	}
	return true;
}