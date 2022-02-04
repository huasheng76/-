#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct product{
	int id;//��� 
	int P;//���� 
	int amt;//���� 
	int fav;//ϲ��ֵ
};
struct rp{
	int P;
	int fav;
	int id;
};
int Max(int a ,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
void backtrack(int X ,int Num ,int dp[] ,bool rr[] ,rp pro[] )
{
	while(X>0)
	{
		for(int i=0;i<Num;i++)
		{
			if(rr[i]==false&&dp[X]==dp[X-pro[i].P-1]+pro[i].fav)
			{
				rr[i]=true;//��Ʒ��ѡ�� 
				backtrack(X-pro[i].P,Num,dp,rr,pro);
			}
		}
		return; 
	}
	return;
}
void checkqq(int qq[] ,int N ,bool rr[] ,rp pro[] ,int Num )
{
	for(int i=0;i<Num;i++)
	{
		if(rr[i]==1)//����Ʒ��ѡ��
		{
			qq[pro[i].id-1]+=1;
		} 
	}
	return;
 } 
int main()
{
	int N;//��Ʒ���� 
	int X;//ӵ�е��ʽ�
	cin>>X>>N; 
	product s[N];
	int output[N];//ÿ����Ʒ����Ҫ�ü��� 
	for(int i=0;i<N;i++)
	{
		cin>>s[i].P>>s[i].amt>>s[i].fav;
		s[i].id=i+1;
	}
	
	int Num=0;
	int Sum=0;
	for(int i=0;i<N;i++)
	{
		Num+=s[i].amt;
		Sum+=s[i].P*s[i].amt;
	}
	
	int temp;
	rp pro[Num];
	int qq=0;
	for(int i=0;i<N;i++)
	{
		temp=s[i].amt;
		while(temp--&&qq<Num)
		{
			pro[qq].fav=s[i].fav;
			pro[qq].id=s[i].id;
			pro[qq].P=s[i].P;
			qq++;
		}
	}
	
	int dp[Sum+1]={0};//dp[x]��ʾ�ʽ�Ϊxʱ������������� 
	for(int i=0;i<Num;i++)
	{
		for(int j=Sum;j>=pro[i].P;j--)
		{
			dp[j]=Max(dp[j],dp[j-pro[i].P]+pro[i].fav);
		}
	}
	for(int j=0;j<=Sum;j++)//���dp 
	{
			cout<<dp[j]<<" ";
	}
	cout<<endl;
	
	bool rr[Num]={false};
	int pp[N]={0};//ÿ����Ʒ������ 
	backtrack(X,Num,dp,rr,pro);	
	checkqq(pp,N,rr,pro,Num);
	int count=0;
	for(int i=0;i<N;i++)
	{
		if(pp[i]!=0)
			count++;
	}
	cout<<dp[X]<<" "<<count<<endl;
	for(int i=0;i<N;i++)
	{
		if(pp[i]!=0)
		{
			cout<<i+1<<" "<<pp[i]<<endl;
		}
	}
	return 0;
}
