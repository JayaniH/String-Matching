#include<iostream>
#include<string>
using namespace std;

class NaiveMatcher{
	private:
		string text,pattern;
		int n,m;
	public:
		NaiveMatcher(string t, string p);
		void match();
};

NaiveMatcher::NaiveMatcher(string t, string p){
	text = t;
	pattern = p;
	n = t.length();
	m = p.length();
}

void NaiveMatcher::match(){
	int j;
	for(int i=0;i<=n-m;i++){
		j=0;
		while(j<m && text[i+j] == pattern[j]){
			cout<<text[j+j]<<endl;
			j++;
		}
		if(j==m){
			cout<<"pattern found at index "<<i<<endl;
			return;
		}
	}
	cout<<"No match found"<<endl;
}

int main(){
	NaiveMatcher one("abcdef","def");
	one.match();
}
