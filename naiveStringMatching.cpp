#include<iostream>
#include<string>

using namespace std;

class StringMatching{
	private:
		string text,pattern;
		int lenT,lenP;
	public:
		StringMatching(string,string);
		void match();
};

StringMatching::StringMatching(string t,string p){
	text = t;
	pattern = p;
	
	lenT = t.length();
	lenP = p.length();
}

void StringMatching::match(){
	int count = 0;
	for(int i=0;i<lenT-lenP+1;i++){
		int j=0;
		while(j<lenP && text[i+j]==pattern[j]){
			j++;
		}
		if(j==lenP){
			count++;
			cout<<"Patterm found at index: "<<i<<endl;
		}
	}
	if(count==0){
		cout<<"Pattern doesn't exist"<<endl;
	}
}
int main(){
 	StringMatching str("abcdefxyjkdefmnopdefj","def");
 	str.match();
 }
