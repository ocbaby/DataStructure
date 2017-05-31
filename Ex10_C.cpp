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
		int sum = 0;//记录数组元素个数；
		memset(Hash, -1, sizeof(Hash));//初始化；
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
				int flag = 0;//标记是否有相同的关键字；
				for (j = 0;j<p;j++)
				{
					if (Hash[j] == num)//重复关键字放在hash表中的同一位置
					{
						a[sum++] = j;
						flag = 1;
						break;
					}
				}
				if (!flag)
				{
					while (Hash[h%p] != -1)//线性探测法解决冲突
						h++;//向后移动；
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