#include<iostream>
#include<string>

using namespace std;

class KMP{
	private:
		string text,pattern;
		int lenT,lenP;
		int lps[10];
	
	public:
		KMP(string,string);
		void calculateLPS();
		void match();
};

KMP::KMP(string t,string p){
	text = t;
	pattern = p;
	
	lenT = t.length();
	lenP = p.length();
}

void KMP::calculateLPS(){
	
	int len = 0;
	lps[0] = 0;
	
	for(int i=1;i<lenP;i++){
		if(pattern[len] == pattern[i]){
			len++;
			lps[i] = len;
		}else if(len>0){
			len = lps[len-1];
			i--;
		}else{
			lps[i] = 0;
		}
	}
}

void KMP::match(){
	
	int j = 0,count = 0;
	
	for(int i=0;i<lenT;i++){
		if(text[i]==pattern[j]){
			j++;
		}else{
			if(j==0){
				continue;
			}else{
				j = lps[j-1];
				i--;
			}
		}
		
		if(j==lenP){
			cout<<"Pattern found at index: "<<i-j+1<<endl;
			count++;
			j = lps[j-1];
		}
	}
	if(count==0){
		cout<<"Pattern not found"<<endl;
	}
}

int main(){
	KMP str("JAYANI IS MY BEST FRIEND","BEST");
	str.calculateLPS();
	str.match();
}
