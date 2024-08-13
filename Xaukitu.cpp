#include<bits/stdc++.h>
using namespace std ;
struct laptop {
	string tenHang ;
	string cauHinh;
	int gia ;
	
	laptop(string tenHang, string cauHinh, int gia){
		this->tenHang=tenHang;
		this->cauHinh=cauHinh;
		this->gia=gia;
	}
};
void showTitle()
{
	cout<<setw(15)<<"Ten hang sx";
	cout<<setw(55)<<"Cau hinh ";
	cout<<setw(15)<<"gia ban";
	cout<<endl;
}
void showData(laptop lt)
{
	cout<<setw(15)<<lt.tenHang;
	cout<<setw(55)<<lt.cauHinh;
	cout<<setw(15)<<lt.gia;
	cout<<endl;
}
void taoDs(vector<laptop> &list)
{
	laptop l1("ASUS","CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB",15000000);list.push_back(l1);
	laptop l2("HP","CPU 2.7GHz upto 4GHz-RAM 12GB-HDD 512GB",9000000);list.push_back(l2);
	laptop l3("DELL","CPU 3.2GHz upto 5.5GHz-RAM 16GB-SSD 512GB",22000000);list.push_back(l3);
	laptop l4("ACER","CPU 2.8GHz upto 3.5GHz-RAM 8GB-SSD 256GB",11000000);list.push_back(l4);
	laptop l5("LG","CPU 2.1GHz upto 3.5GHz-RAM 8GB-HDD 256GB",12000000);list.push_back(l5);
}
void showDs(vector<laptop> list)
{	showTitle();
	for(laptop l : list)
	{
		showData(l);
	}
}
int in_char_tostring(char c, string s)
{
	for(int i=0;i<s.size();i++)
	{
		if(c==s[i])
		{
			return i;
		}
	}
	return -1;
}
int boyer_moore(string p , string t)
{
	int v = p.size();int i =v-1;
	while(i<t.size())
	{
		int k = v-1;
		while(k>-1  && t[i]==p[k])
		{
			i--;k--;
		}
		if(k<0)
		{
			return 1;
		}
		int x = in_char_tostring(t[i],p);
		if(x<0)
		{
			i=i+v;
		}else
		{
			i=i+v-x-1;
		}	
	}
	return 0;	
}
int countR16(vector<laptop> v )
{	int count = 0;
	for(int i=0;i<v.size();i++)
	{
		if(boyer_moore("RAM 16GB",v[i].cauHinh))
		{
			count++;
		}
	}
	return count++;
}
int A2(vector<laptop> v , vector<laptop> &ssd)
{
	int count = 0;
	for(int i=0;i<v.size();i++)
	{
		if(boyer_moore("SSD",v[i].cauHinh))
		{
			count++;
			ssd.push_back(v[i]);
		}
	}
	return count++;
}
int main()
{
	int n =5;
	vector<laptop> v,result ;
	taoDs(v);
	showDs(v);
	cout<<"So may tinh co cau hinh RAM 16GB la : "<<countR16(v)<<endl;
	cout<<"Co "<<A2(v,result)<<" may tinh su dung SDD"<<endl;
	showDs(result);
	

	return 0;
}


