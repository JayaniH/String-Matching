#include <iostream>
#include <string>
using namespace std;

#define ALPHABET 123

class Horspool{
	private:
		string text, pattern;
		int n,m;
		int table[ALPHABET];	
	
	public:
		Horspool(string t, string p);
		void HpBc();
		void printHpBc();
		void search();
};

Horspool::Horspool(string t, string p){
	text = t;
	pattern = p;
	n = t.length();
	m = p.length();
}

void Horspool::HpBc(){
	for(int i=0; i<ALPHABET; i++){
		table[i] = m;
	}
	for(int i=0; i<m-1; i++){
		table[(int)pattern[i]] = (m-i)-1;
	}
}

void Horspool::printHpBc(){
	for(int i=0; i<ALPHABET; i++){
		cout<<i<<"\t"<<(char)i<<"\t"<<table[i]<<endl;
	}
}

void Horspool::search(){
	int i = 0;
	int j;
	
	while(i<=n-m){
		//cout<<i<<endl;
		j = m-1;
		
		while(j>0 && (text[i+j] == pattern[j])){
			j--;
		}
		if(j==0){
			cout<<"pattern found at index "<<i<<endl;
			return;
		}
		//cout<<text[i+j]<<endl;
		i = i + table[(int)text[(i+m)-1]];
	}
	cout<<"pattern not found";
}

int main(){
	Horspool test("gcatcgcagagagtatacagtacg", "gcagagag");
	test.HpBc();
//	test.printHpBc();
	test.search();
//	int i=74;
//	cout<<(char)i;
}
