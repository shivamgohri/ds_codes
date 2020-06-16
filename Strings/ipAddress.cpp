#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5


bool isip4(string IP){
        
    if(IP.length()>15){
        return false;
    }
    
    int count = 0;
    
    for(int i=0; i<IP.length(); i++){
        if( IP[i]=='.' ){
            count++;
        }
    }        
    
    if(count!=3){
        return false;
    }
    
    vector<string> parts;
    
    string res = "";
    
    for(int i=0; i<IP.length(); i++){
        if(IP[i]=='.'){
            if(res.empty()){
                return false;
            }
            parts.push_back(res);
            res = "";
        }
        else{
            if( IP[i]>='0' && IP[i]<='9' ){
                res += IP[i];
            }
            else{
                return false;
            }
        }
    }
    if(res.empty()){
        return false;
    }
    parts.push_back(res);
    
    if(parts.size()!=4){
        return false;
    }
    
    for(int i=0; i<parts.size(); i++){
        
        string s = parts[i];
        
        if(s.length()>3){
            return false;
        }
        
        if(s[0]=='0' && s.length()>1){
            return false;
        }
        
        int num = 0;
        
        for(int j=0; j<s.length(); j++){
            num = (num*10) + (s[j] - '0');
        }
        
        if(num>255){
            return false;
        }            
    }
    
    return true;        
}


bool isip6(string IP){
    
    if(IP.length()>39){
        return false;
    }
    
    int count = 0;
    
    for(int i=0; i<IP.length(); i++){
        if( IP[i]==':' ){
            count++;
        }
    }        
    
    if(count!=7){
        return false;
    }
    
    vector<string> parts;
    
    string res = "";
    
    for(int i=0; i<IP.length(); i++){
        if(IP[i]==':'){
            if(res.empty()){
                return false;
            }
            parts.push_back(res);
            res = "";
        }
        else{
            if( (IP[i]>='0' && IP[i]<='9') || (IP[i]>='a' && IP[i]<='f') || (IP[i]>='A' && IP[i]<='F') ){
                res += IP[i];
            }
            else{
                return false;
            }
        }
    }
    if(res.empty()){
        return false;
    }
    parts.push_back(res);
    
    if(parts.size()!=8){
        return false;
    }
    
    for(int i=0; i<parts.size(); i++){
        
        string s = parts[i];
        
        if(s.length()>4){
            return false;
        }          
    }
    
    return true;        
}


string validIPAddress(string IP) {
    
    if( IP.empty() ){
        return "Neither";
    }
    
    if( isip4(IP)==true ){
        return "IPv4";
    }
    else if( isip6(IP) ){
        return "IPv6";
    }
    else{
        return "Neither";
    }
}


void testcases(){



}


int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	// cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}