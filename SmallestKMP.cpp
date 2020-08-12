#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string a, b;
		cin>>a;
		cin>>b;
		vector<int> v(26, 0);
		for(int i = 0; i<a.size(); i++){
			v[(int)(a[i]-'a')]++;
		}
		for(char i : b)
			v[(int)(i-'a')]--;

		string out;
		bool dece = false;
		for(int i=0; i<b.size()-1;i++){
			if(b[i] != b[i+1]){
				if(b[i] > b[i+1])
					dece = true;
				break;
			}
		}
		
		int count=0;
		bool once = true;
		for(int i=0; i<a.size()-b.size(); i++){
			while(v[count]==0){
				if(count+(int)'a' == (int)b[0] && once){
    				out+=b;
    				once=false;
    			}
				count++;
			}
			if(count+(int)'a' == (int)b[0] && dece && once){
				out+=b;
				once=false;
			}
			out+=(char)((int)'a'+count);
			v[count]--;
		}
		if(out.size() < a.size())
		    out+=b;
		cout<<out<<'\n';
	}
}

