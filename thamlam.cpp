#include<bits/stdc++.h>
using namespace std ;
/*Bài tập 1: Chiến lược tham lam
Input:
- Cho một số tiền p và một danh sách d gồm n chiếc quạt bàn khác nhau về giá bán, 
thông tin về mỗi chiếc quạt bàn gồm: tên hãng sản xuất, màu sắc và giá bán.
Output:
- Tính c và s lần lượt là số lượng và danh sách nhiều nhất các quạt bàn có thể mua được 
từ danh sách d với số tiền p.
Yêu cầu thực hiện: 
- Thiết kế thuật toán G1 để tính và trả về c và s theo chiến lược tham lam.
- Viết chương trình thực hiện:
o Khai báo cấu trúc dữ liệu của bài toán.
o Khởi tạo p (0 < p < 1200000), n và danh sách d (5 < n < 12). Yêu cầu dữ liệu 
thể hiện được tính thực tiễn.
o Cài đặt hàm F1 biểu diễn thuật toán G1.
o Sử dụng thuật toán G1 để tính và trả về c và s. Hiển thị các kết quả, trong đó 
mỗi chiếc quạt cần hiển thị tên hãng sản xuất và giá bán */
struct quat{
	string name ;
	string color;
	int price ;
	quat(){
	}
	quat(string name, string color, int price){
		this->name=name;
		this->color=color;
		this->price=price;
		
	}
};
void showTitle()
{
	cout<<setw(15)<<"ten hang";
	cout<<setw(15)<<"mau sac";
	cout<<setw(15)<<"gia ";
	cout<<endl;
}
void showData(quat q){
	cout<<setw(15)<<q.name;
	cout<<setw(15)<<q.color;
	cout<<setw(15)<<q.price;
	cout<<endl;
}
void taoDS(vector<quat> &v)
{
	quat q1("dien co 91","trang",1200000); v.push_back(q1);
	quat q2("toshia","den",900000);v.push_back(q2);
	quat q3("bo quoc phong","trang",400000);v.push_back(q3);
	quat q4("amazon","cam",500000);v.push_back(q4);
	quat q5("lg","den",200000);v.push_back(q5);
}
void showDS(vector<quat> v)
{	
	showTitle();
	for(quat q:v)
	{
		showData(q);
	}
}
bool comparePrice(quat &q1 , quat &q2)
{
	return q1.price<q2.price;
}
int G1(vector<quat> v,vector<quat> &result, int p)
{		int d = p;
	for(int i=0;i<v.size();i++)
	{
		if(v[i].price<=d)
		{
			result.push_back(v[i]);
			d=d-v[i].price;
		}
	}
	return result.size();
}
int main()
{
	vector<quat> v ,result;
	taoDS(v);
	showDS(v);
	sort(v.begin(),v.end(),comparePrice);
	int p ;
	cout<<"nhap vao so tien p: ";
	cin>>p;
	cout<<"co the mua "<<G1(v,result,p)<<" chiec quat :\n";
	showDS(result);
}
