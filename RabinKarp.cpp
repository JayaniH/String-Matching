#include<iostream>
#include<string>
#include<cmath>
using namespace std;

#define d 10

class RabinKarp{
	private:
		string text, pattern;
		int n,m,h;
		int p = 0;
		int t = 0;
		int q = 13;
	
	public:
		RabinKarp(string t, string p);
		void search();
};

RabinKarp::RabinKarp(string t, string p){
	text = t;
	pattern = p;
	n = t.length();
	m = p.length();
}

void RabinKarp::search(){
	int j;
	h = ((int)pow(d ,m-1)) % q;
	
	for(int i=0; i<m; i++){
		p = (d*p + (int)pattern[i]) % q;
		t = (d*t + (int)text[i]) % q;  
	}
	
	for(int i=0; i<=n-m; i++){
		//cout<<t<<" "<<p<<endl;
		if(p == t){
			j = 0;
			while(j<m && text[i+j] == pattern[j]){
				//cout<<text[j+j]<<endl;
				j++;
			}
			if(j == m){
				cout<<"pattern found at index "<<i<<endl;
				return;
			}
		}
		if(i<n-m){
			t = (d*(t - (int)text[i]*h) + (int)text[i+m]) % q;
			
			if(t<0){
				t = t + q;
			}
		}
	}
	cout<<"pattern not found"<<endl;
}

int main(){
//	int h = ((int)pow(2,3)) % 3;
//	cout<<h;

	RabinKarp test("babablacksheep", "black");
	test.search();
}
