#include<iostream>
#include<string>
using namespace std;

class KMP{
	private:
		string text,pattern;
		int n,m;
		int pi[25];
	public:
		KMP(string t, string p);
		void pi_func();
		void print_pi();
		void match();
};

KMP::KMP(string t, string p){
	text = t;
	pattern = p;
	n = t.length();
	m = p.length();
}

void KMP::pi_func(){
	int j = 0;
	pi[0] = 0;
	
	for(int i=1;i<m;i++){
		while(j > 0 && pattern[i] != pattern[j]){
			j = pi[j];
		}
		if(pattern[i] == pattern[j]){
			j++;
		}
		pi[i] = j;
	}
}

void KMP::print_pi(){
	cout<<"Pi array: "<<endl;
	for(int i=0;i<m;i++){
		cout<<pi[i]<<" ";
	}
	cout<<endl;
}

void KMP::match(){
	int j = 0;
	for(int i=0;i<=n-m;i++){
		do{
			//cout<<i<<" "<<j<<" "<<text[i+j]<<endl;
			if(text[i+j] == pattern[j]){
				j++;
			}
			else{
				if(j>0){
					j=pi[j-1];
				}
				else{
					j = 0;
				}
				break;
			}
		}while(j>0 && j<m);
		
		if(j==m){
			cout<<"pattern found at index "<<i<<endl;
			return;
		}
	}
	cout<<"No match found"<<endl;
}
int main(){
	KMP one("abcababababca","ababababca");
	one.pi_func();
	one.print_pi();
	one.match();
}
