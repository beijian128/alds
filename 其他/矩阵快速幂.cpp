// ���������
const ll mod = 1e9 + 7;
struct Matrix
{
	ll A[2][2];
	Matrix(ll a, ll b, ll c, ll d)
	{
		A[0][0] = a; A[0][1] = b;
		A[1][0] = c; A[1][1] = d;
	}
	Matrix()
	{
		A[0][0] = 0; A[0][1] = 0;
		A[1][0] = 0; A[1][1] = 0;
	};
	void  init(ll a, ll b, ll c, ll d)
	{
		A[0][0] = a; A[0][1] = b;
		A[1][0] = c; A[1][1] = d;
	}
}X, Y;
Matrix Matrix_mul(Matrix A, Matrix B) //����˷�   A*B
{
	Matrix res;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				res.A[i][j] += A.A[i][k] * B.A[k][j];
				res.A[i][j] %= mod;
			}
		}
	}
	return res;
}

Matrix Matrix_quick_pow(Matrix a, ll b) //����a ��b�η�
{
	Matrix E(1, 0, 0, 1);// ��λ����
	Matrix base = a;// ���׾���
	Matrix res = E;//���ؾ��� 
	while (b)
	{
		if (b & 1)
		{
			res = Matrix_mul(res, base);
		}
		base = Matrix_mul(base, base);
		b >>= 1;
	}
	return res;
}
ll f(ll n) { return Matrix_mul(Matrix_quick_pow(Y, n - 1), X).A[1][0]; }


int32_t main()
{
	// freopen("in.txt", "r", stdin);
	X.init(0, 0, 0, 0);
	Y.init(0, 0, 0, 0);
	ll n;
	cin >> n;
	cout << f(n);
	return 0;
}