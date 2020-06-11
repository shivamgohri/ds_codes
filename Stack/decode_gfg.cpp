//https://practice.geeksforgeeks.org/problems/decode-the-string/0
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void testcases(){

	string str;
	cin>> str;

	stack<int> integerstack; 
    stack<char> stringstack; 
    string temp = "", result = ""; 
  
    // Traversing the string 
    for (int i = 0; i < str.length(); i++) 
    { 
        int count = 0; 
  
        // If number, convert it into number 
        // and push it into integerstack. 
        if (str[i] >= '0' && str[i] <='9') 
        { 
            while (str[i] >= '0' && str[i] <= '9') 
            { 
                count = count * 10 + str[i] - '0'; 
                i++; 
            } 
  
            i--; 
            integerstack.push(count); 
        } 
  
        // If closing bracket ']', pop elemment until 
        // '[' opening bracket is not found in the 
        // character stack. 
        else if (str[i] == ']') 
        { 
            temp = ""; 
            count = 0; 
  
            if (! integerstack.empty()) 
            { 
                count = integerstack.top(); 
                integerstack.pop(); 
            } 
  
            while (! stringstack.empty() && stringstack.top()!='[' ) 
            { 
                temp = stringstack.top() + temp; 
                stringstack.pop(); 
            } 
  
            if (! stringstack.empty() && stringstack.top() == '[') 
                stringstack.pop(); 
  
            // Repeating the popped string 'temo' count 
            // number of times. 
            for (int j = 0; j < count; j++) 
                result = result + temp; 
  
            // Push it in the character stack. 
            for (int j = 0; j < result.length(); j++) 
                stringstack.push(result[j]); 
  
            result = ""; 
        } 
  
        // If '[' opening bracket, push it into character stack. 
        else if (str[i] == '[') 
        { 
            if (str[i-1] >= '0' && str[i-1] <= '9') 
                stringstack.push(str[i]); 
  
            else
            { 
                stringstack.push(str[i]); 
                integerstack.push(1); 
            } 
        } 
  
        else
            stringstack.push(str[i]); 
    } 
  
    // Pop all the elmenet, make a string and return. 
    while (! stringstack.empty()) 
    { 
        result = stringstack.top() + result; 
        stringstack.pop(); 
    } 
  
    cout<< result;
}


int main(){

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);    cout.tie(NULL);

	int t = 1;
	cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}