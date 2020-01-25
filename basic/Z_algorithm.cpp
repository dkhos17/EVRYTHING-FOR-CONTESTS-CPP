#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100;
int z[N];
int size; // search string size

void z_function(string res) { 
	int n = (int) res.length();
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r) z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && res[z[i]] == res[i+z[i]]){
			++z[i];
		}
		if (i+z[i]-1 > r) {
			l = i;
			r = i+z[i]-1;
		}
	}
}

void printIndex(int s){
	for(int i = size ; i < s ; i++){
		if(z[i] == size){
			cout << i - size - 1 << endl;
			return;
		}
	}
	cout<<"-1"<<endl;
}

int main(){
	cin>>size;
	string s1 , s2 , res;
	cin>>s1>>s2;
	res = s1; 
	res += '$'; 
	res += s2; 
	res += s2;
	z_function(res);
	printIndex(res.size());
	return 0;
}

