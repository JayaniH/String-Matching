#include<iostream>
#include<string>
#include<math.h>

using namespace std;

class RabinKarp{
	private:
		string text,pattern;
		int lenT,lenP,hashT,hashP;
	
	public:
		RabinKarp(string,string);
		void hash();
		void match();
};

RabinKarp::RabinKarp(string t,string p){
	text = t;
	pattern = p;
	
	lenT = t.length();
	lenP = p.length();
}

void RabinKarp::hash(){
	int x;
	int y;
	hashT = 0;
	hashP = 0;
	for(int i=0;i<lenP;i++){
		x = pattern[i]-'0';
		y = text[i]-'0';
		
		hashP = hashP + (x*(int)pow(10,lenP-i-1));
		hashT = hashT + (y*(int)pow(10,lenP-i-1));
	}
	hashP = hashP%13;
	hashT = hashT%13;
}

void RabinKarp::match(){
	hash();
	int x,y,count=0;
	for(int i=0;i<lenT-lenP+1;i++){
		
		if(hashP==hashT){
			int j=0;
			while(j<lenP){
				if(text[i+j]!=pattern[j]){
					break;
				}
				j++;
			}
			if(j==lenP){
				cout<<"Match found at index: "<<i<<endl;
				count++;
			}
		}else{
			if(i==lenT-lenP){
				break;
			}
			x = text[i]-'0';
			y = text[i+lenP]-'0';

			hashT = (hashT-(x*(int)pow(10,lenP-1))%13)*10+y;
			hashT = ((hashT%13)+13)%13;

		}	
	}
	if(count==0){
		cout<<"No match found";
	}
}

int main(){

	RabinKarp str("2359023141526739921","314152");
	str.match();
}
