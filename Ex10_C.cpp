#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int main()
{
	int i, j, a[2001], Hash[2000], n, p, h;
	while (~scanf("%d%d", &n, &p))
	{
		int num;
		int sum = 0;//��¼����Ԫ�ظ�����
		memset(Hash, -1, sizeof(Hash));//��ʼ����
		for (i = 0;i<n;i++)
		{
			scanf("%d", &num);
			h = num%p;
			if (Hash[h] == -1)
			{
				Hash[h] = num;
				a[sum++] = h;
			}
			else
			{
				int flag = 0;//����Ƿ�����ͬ�Ĺؼ��֣�
				for (j = 0;j<p;j++)
				{
					if (Hash[j] == num)//�ظ��ؼ��ַ���hash���е�ͬһλ��
					{
						a[sum++] = j;
						flag = 1;
						break;
					}
				}
				if (!flag)
				{
					while (Hash[h%p] != -1)//����̽�ⷨ�����ͻ
						h++;//����ƶ���
					a[sum++] = h%p;
					Hash[h%p] = num;
				}
			}
		}
		for (i = 0;i<sum - 1;i++)
			printf("%d ", a[i]);
		printf("%d\n", a[sum - 1]);
	}
	return 0;
}