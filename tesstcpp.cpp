#include<bits/stdc++.h>
using namespace std ;
// chon 2 mang lai voi nhau 
void merg(int a[], int l , int m , int r)
{
	vector<int> x(a + l, a + m + 1);
	vector<int> y(a +m + 1,a + r + 1);
	int i =0,j=0;
	while(i<x.size() && j<y.size())
	{
		if(x[i]<=y[j])
		{
			a[l]=x[i];l++;i++;
		}
		else
		{
			a[l]=y[j];l++;j++;
		}
	}
	while(i<x.size())
	{
		a[l]=x[i];l++;i++;
	}
	while(j<y.size())
	{
		a[l]=y[j];l++;j++;
	}
}
void mergSort(int a[], int l , int r)
{
	if(l>=r)
	{
		return ;
	}
	else
	{
		int m = (l+r)/2 ;
		mergSort(a,l,m);
		mergSort(a,m+1,r);
		merg(a,l,m,r);
	}
}
int main()
{
	int a[3000];
	int n=3000;
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		a[i]=rand()%3000;
	}
	mergSort(a,0,n-1);
	for(int x : a)
	{
		cout<<setw(10)<<x<<setw(10);
	}
}
