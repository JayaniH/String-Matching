#include<iostream>
#include<string>
#include<string.h>

using namespace std;

class BoyerMooreHorspool{
	
	private:
		string text,pattern;
		int lenT,lenP;
		int table[123];
		
	public:
		BoyerMooreHorspool(string,string);
		void badMatchTable();
		void match();
		
};

BoyerMooreHorspool::BoyerMooreHorspool(string t,string p){
	
	text = t;
	pattern = p;
	
	lenT = t.length();
	lenP = p.length();
	
}

void BoyerMooreHorspool::badMatchTable(){
	
	for(int j=0;j<123;j++){
		table[j] = lenP;
	}
	
	for(int i=0;i<lenP-1;i++){
		table[(int)pattern[i]] = (lenP - i) - 1;
	}
	
}

void BoyerMooreHorspool::match(){
	
	for(int i=0;i<lenT-lenP+1;i++){
		int j = lenP - 1;
		
		while(j>=0 && text[i+j] == pattern[j]){
			j--;
		}
		
		if(j == -1){
			cout<<"Pattern found at index: "<<i<<endl;
		}
		
		i = i + table[(int)text[i+lenP-1]] - 1;
	}
}

int main(){
	BoyerMooreHorspool str("gcatcgcagagagtatacagtacg", "gcagagag");
	str.badMatchTable();
	str.match();
	
}
