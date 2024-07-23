/*
Bài tập 5: Cho danh sách c gồm n công việc cần thực hiện trong ngày của một công ty, 
thông tin về mỗi công việc gồm mã công việc, thời gian bắt đầu thực hiện, thời gian cần 
thiết để thực hiện công việc (số phút hoặc số giờ cần thiết để thực hiện công việc). Cho 
danh sách L gồm tên của n nhân viên.
- Thiết kế thuật toán A1 để hiển thị ra màn hình tất cả các công việc trong danh 
sách c theo thứ tự ngược lại bằng phương pháp đệ quy.
- Thiết kế thuật toán A2 để đếm và trả về số công việc có thời gian thực hiện không 
quá 30 phút (hoặc 0.5 giờ) trong danh sách b bằng chiến lược chia để trị.
- Thiết kế thuật toán A3 để liệt kê tất cả các phương án khác nhau để giao n công 
việc trong danh sách b cho n nhân viên trong danh sách L bằng phương pháp 
quay lui.
- Viết chương trình thực hiện.
a) Khởi tạo số nguyên dương n sao cho 6 ≤ n ≤ 10. Khởi tạo danh sách c gồm 
n công việc và khởi tạo danh sách nhân viên L (không nhập dữ liệu từ bàn 
phím, dữ liệu có tính thực tiễn).
b) Áp dụng thuật toán A1 để hiển thị danh sách các công việc trong danh 
sách c theo thứ tự ngược lại.
c) Áp dụng thuật toán A2 để đếm số công việc trong danh b có thời gian thực 
hieenh không quá 30 phút, hiển thị kết quả (nếu có).
d) Áp dụng thuật toán A3 để hiển thị tất cả các phương án khác nhau để giao 
n công việc trong danh sách b cho n nhân viên trong danh sách L, mỗi 
phương án hiển thị danh sách gồm tên công việc – tên nhân viên tương 
ứng
*/

#include<bits/stdc++.h>
using namespace std ;

struct CongViec {
	string maCV ;
	string tgBatDau;
	int tgThucHien ;
};
vector<CongViec> c ;
string L[6]={"Nam","Trang","Anh","Hung","Thang","Thao"};
int a[100],use[100],dem,n;
void showTitle()
{
	cout<<"Ma CV";
	cout<<setw(15)<<"Tg bat dau";
	cout<<setw(15)<<"Tg thuc hien";
	cout<<endl;
}
void showDaTa(CongViec cv)
{
	cout<<cv.maCV;
	cout<<setw(15)<<cv.tgBatDau;
	cout<<setw(15)<<cv.tgThucHien;
	cout<<endl;
}
void fakeDaTa()
{
	CongViec cv1,cv2,cv3,cv4,cv5,cv6;
	cv1.maCV="CV001";cv1.tgBatDau="7h";cv1.tgThucHien=40;c.push_back(cv1);
	cv2.maCV="CV002";cv2.tgBatDau="8h";cv2.tgThucHien=65;c.push_back(cv2);
	cv3.maCV="CV003";cv3.tgBatDau="9h30";cv3.tgThucHien=30;c.push_back(cv3);
	cv4.maCV="CV004";cv4.tgBatDau="10h";cv4.tgThucHien=15;c.push_back(cv4);
	cv5.maCV="CV005";cv5.tgBatDau="11h30";cv5.tgThucHien=25;c.push_back(cv5);
	cv6.maCV="CV006";cv6.tgBatDau="12h";cv6.tgThucHien=90;c.push_back(cv6);
}
void showList()
{	showTitle();
	for(CongViec cv : c)
	{
		showDaTa(cv);
	}
}
void showkq()
{
	for(int i=1;i<=n;i++)
	{
		cout<<setw(10)<<c[a[i]-1].maCV<<" - "<<L[i-1]<<"|";
//		cout<<a[i];
	}
	cout<<endl;
}
void A1(int n)
{
	if(n<0)
	{
		return ;
	}
	else
	{
		showDaTa(c[n]);
	}
	A1(n-1);
}
int A2(vector<CongViec> v ,int l, int r)
{
	if(l>=r)
	{
		if(v[l].tgThucHien <=30)
		{
			showDaTa(v[l]);
			dem++;
		}		
	}else
	{
		int m = (l+r)/2;
		A2(v,l,m);
		A2(v,m+1,r);
	}
}

void A3(int i)
{
	for(int j=1;j<=n;j++)
	{
		if(use[j]==0)
		{
			a[i]=j;
			if(i==n)
			{
				showkq();
			}
			else
			{
				use[j]=1;
				A3(i+1);
				use[j]=0;
			}
		}
	}
}
int main(){
	 n =6 ;	
	fakeDaTa();
	showList();	
	cout<<"In nguoc danh sach :\n";
	cout<<"|-------------------------------------------------------------|"<<endl;
	showTitle();
	A1(n-1);
	cout<<"Cong viec co thoi gian nho hon 30p : \n";
	cout<<"|-------------------------------------------------------------|"<<endl;
	showTitle();
	A2(c,0,n-1);
	cout<<"co "<<dem<<"cong viec co thoi gian thuc hien nho 30p \n";
	cout<<"|-------------------------------------------------------------|"<<endl;
	A3(1);
	return 0;
}
