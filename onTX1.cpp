#include<bits/stdc++.h>
using namespace std ;
struct HocSinh {
	string ten;
	string hoDem;
	int namSinh;
	string diaChi;
};
int n,dem=0;
vector<HocSinh> b;
string ten;
void showTitle()
{
	cout<<setw(15)<<"Ten";
	cout<<setw(15)<<"ho dem";
	cout<<setw(15)<<"nam sinh";
	cout<<setw(15)<<"dia chi";
	cout<<endl;
}
void showDaTa(HocSinh hs)
{
	cout<<setw(15)<<hs.ten;
	cout<<setw(15)<<hs.hoDem;
	cout<<setw(15)<<hs.namSinh;
	cout<<setw(15)<<hs.diaChi;
	cout<<endl;
}
void fakeDaTa()
{
	HocSinh hs1,hs2,hs3,hs4,hs5,hs6;
	hs1.ten="anh";hs1.hoDem="phi hoang";hs1.namSinh=2003;hs1.diaChi="ha noi";b.push_back(hs1);
	hs2.ten="duy";hs2.hoDem="nguyen ba";hs2.namSinh=2004;hs2.diaChi="son la";b.push_back(hs2);
	hs3.ten="bo";hs3.hoDem="hoang van";hs3.namSinh=2001;hs3.diaChi="bac ninh";b.push_back(hs3);
	hs4.ten="hiep";hs4.hoDem="nguyen manh";hs4.namSinh=2004;hs4.diaChi="hai duong";b.push_back(hs4);
	hs5.ten="cuong";hs5.hoDem="le manh";hs5.namSinh=2019;hs5.diaChi="ha noi";b.push_back(hs5);
	hs6.ten="anh";hs6.hoDem="dang trong";hs6.namSinh=2000;hs6.diaChi="ha giang";b.push_back(hs6);
}
void showList()
{
	showTitle();
	for(HocSinh x: b)
	{
		showDaTa(x);
	}
}
void merg(vector<HocSinh> &v , int l, int m , int r)
{
	vector<HocSinh> x (v.begin() + l,v.begin() + m + 1);
	vector<HocSinh> y (v.begin() + m + 1,v.begin() + r + 1);
	int i=0,j=0;
	while(i<x.size() && j<y.size())
	{
		if((x[i].ten.compare(y[j].ten))<=0)
		{
			v[l]=x[i];l++;i++;
		}
		else
		{
			v[l]=y[j];l++;j++;
		}
	}
	while(i<x.size())
	{
		v[l]=x[i];l++;i++;
	}
	while(j<y.size())
	{
		v[l]=y[j];l++;j++;
	}
}
void mergSort(vector<HocSinh> &v, int l, int r)
{
	if(l>=r)
	{
		return ;
	}
	else
	{
		int m =(l+r)/2;
		mergSort(v,l,m);
		mergSort(v,m+1,r);
		merg(v,l,m,r);
	}
}
void timKiem(vector<HocSinh> v , int l, int r)
{
	if(l>=r)
	{
		if(ten.compare(v[l].ten)==0)
		{	
			if(dem==1)
			{
				return;
			}
			else
			{
				dem++;
				showTitle();
				showDaTa(v[l]);
			}
		}
	}
	else
	{
		int m = (l+r)/2;
		timKiem(v,l,m);
		timKiem(v,m+1,r);
	}
}
int main()
{
	n=6;
	fakeDaTa();
	cout<<"|---------------------------------------------------------------------------------------| \n";
	showList();
	cout<<"Danh sach sau khi duoc sap xep : \n";
	mergSort(b,0,n-1);
	cout<<"|---------------------------------------------------------------------------------------| \n";
	showList();
	cout<<"|---------------------------------------------------------------------------------------| \n";
	cout<<"Nhap ten can tim kiem : \n";
	getline(cin,ten);
	timKiem(b,0,n-1);
	if(dem==0)
	{
		cout<<"Khong co sinh vien ten la : "<<ten<<endl;
	}
	

	
	
}