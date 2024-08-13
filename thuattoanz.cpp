#include<bits/stdc++.h>
using namespace std;

void z1(string s, int *z) {	
	int n  = s.size(); 
	int left = 0, right = 0;
	for (int i = 1; i < n; i++) {	
		if (i > right) {
			left = right = i;
			while (right < n && s[right - left] == s[right])
				right++;
			z[i] = right - left; 
			right--;
		} else if (z[i - left] < right - i + 1) {
			z[i] = z[i - left];
		} else { 
			left = i;
			while (right < n && s[right - left] == s[right])
				right++;
			z[i] = right - left; 
			right--;
		}
	}
}

int aglo(string t, string p, int *z) {	
	int count = 0;
	int p_size = p.size(), t_size = t.size();
	string s = p + "$" + t;
	int n = s.size(); 
	z1(s, z);
	for(int i = 0; i < n; i++) {
		if(z[i] == p_size) {
			count++;
		}
	}
	return count;
}

int main() {	
	string p = "viet";
	string t = "ban viet o viet nam";
	int n = p.size() + t.size() + 1;
	int *z = new int[n]();  
	cout << aglo(t, p, z)<< endl;
	for(int i = 0; i < n; i++) {
		cout << z[i] << " ";
	}
	cout << endl;

	delete[] z;  
	return 0;
}
