/*
Bài tập 4: Cho danh b chứa thông tin về n chuyến bay của 1 hãng hàng không, thông 
tin về mỗi chuyến bay gồm số hiệu chuyến bay (ví dụ: VN005), giá vé, số ghế ngồi.
- Thiết kế thuật toán A1 để hiển thị ra màn hình tất cả các chuyến bay có giá vé 
trên 700000 bằng phương pháp đệ quy.
- Thiết kế thuật toán A2 để tìm và trả về chuyến bay có giá vé thấp nhất trong danh 
sách b bằng chiến lược chia để trị.
- Thiết kế thuật toán A3 để liệt kê tất cả các phương án khác nhau để chọn ra 4 
chuyến bay từ danh sách b bằng phương pháp quay lui.
- Viết chương trình thực hiện
*/
#include<bits/stdc++.h>
using namespace std ;
int n =6,k=4 ;
int a[100],dem=0;
struct ChuyenBay {
	string shChuyenBay;
	int giave ;
	int soGheNgoi ;
	
};
vector<ChuyenBay> b1;
void showData(ChuyenBay cb){
	cout<<setw(20)<<cb.shChuyenBay;
	cout<<setw(20)<<cb.giave;
	cout<<setw(20)<<cb.soGheNgoi;
	cout<<endl;
}
void showTitle()
{	
	cout<<setw(20)<<"So hieu chuyen bay";
	cout<<setw(20)<<"Gia tien";
	cout<<setw(20)<<"So ghe ngoi";
	cout<<endl;
}
void showList(vector<ChuyenBay> v, int n)
{	showTitle();
	for(int i=0;i<n;i++)
	{
		showData(v[i]);
	}
}
void fakeData(vector<ChuyenBay> &v)
{	
	ChuyenBay cb1,cb2,cb3,cb4,cb5,cb6;
	cb1.shChuyenBay="VND001";cb1.giave=1000000;cb1.soGheNgoi=120;v.push_back(cb1);
	cb2.shChuyenBay="VND002";cb2.giave=700001;cb2.soGheNgoi=80;v.push_back(cb2);
	cb3.shChuyenBay="VND003";cb3.giave=500000;cb3.soGheNgoi=200;v.push_back(cb3);
	cb4.shChuyenBay="VND004";cb4.giave=490000;cb4.soGheNgoi=143;v.push_back(cb4);
	cb5.shChuyenBay="VND005";cb5.giave=200000;cb5.soGheNgoi=212;v.push_back(cb5);
	cb6.shChuyenBay="VND006";cb6.giave=200000;cb6.soGheNgoi=450;v.push_back(cb6);
}
void A1(vector<ChuyenBay> v,int n)
{
	if(n<0)
	{
		return ;
	}
	else
	{
		if(v[n].giave>700000)
		{
			showData(v[n]);
		}
		A1(v,n-1);
	}
}
int A2(vector<ChuyenBay> v , int l, int r)
{
	if(l>=r)
	{
		return v[l].giave;
	}else
	{
		int m =(l+r)/2;
		int min1 = A2(v,l,m);
		int min2 = A2(v,m+1,r);
		return min(min1,min2);
	}
}
int showkq()
{	dem++;
	for(int i=1 ;i<=k;i++)
	{
		cout<<setw(10)<<b1[a[i]-1].shChuyenBay;
		cout<<setw(10)<<b1[a[i]-1].soGheNgoi<<"|";
				
	}
	cout<<endl;
}
void A3(int i)
{
	for(int j=a[i-1]+1;j<=n-k+i;j++)
	{
		a[i]=j;
		if(i==k)
		{
			showkq();
		}else
		{
			A3(i+1);
		}
	}
}
int main()
{
	int n =6;
	int min;
	vector<ChuyenBay> b;
	fakeData(b);
	b1=b;
	showList(b,n);
	cout<<"Cac chuyen bay co gia ve lon hon 700000 : "<<endl;
	cout<<"|-----------------------------------------------------------|"<<endl;
	showTitle();
	A1(b,n-1);
	min=A2(b,0,n-1);
	cout<<"Cac chuyen bay co gia ve thap nhat la  : "<<endl;
	cout<<"|-----------------------------------------------------------|"<<endl;
	for(ChuyenBay x : b)
	{
		if(x.giave==min)
		{
			showData(x);
		}
	}
	cout<<"Cac so cach tron 4 chuyen bay tu 6 chuyen bay la  : "<<endl ;
	cout<<"|-----------------------------------------------------------|"<<endl;\
	cout<<endl;
	A3(1);
	cout<<"Co tong cong  "<<dem<<" cach chon !";
}
