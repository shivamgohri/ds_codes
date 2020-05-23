#include <bits/stdc++.h>

using namespace std;

int main(){

	int money;
	cin>> money;

	int coins[] = { 1, 2, 5, 10, 20, 100 };
	int n = sizeof(coins)/sizeof(int);

	int ans = 0;

	while(money>0){

		int coin_indx = upper_bound( coins, coins+n, money ) - 1 - coins;
		ans++;
		money = money - coins[coin_indx];
	}

	cout<< ans <<endl;
}