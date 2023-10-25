#include <bits/stdc++.h>
#include "../include/Utils.hpp"

using namespace std;


int Utils::BinarySearch(vector<int> v, int k){
	return BinarySearchRecursion(v, k, 0, v.size()-1);
}

int Utils::BinarySearchRecursion(vector<int> v, int k, int l, int r){
	if(r <= l){
		if(r == l && v[r] == k)	return r;
		else					return -1;
	}				
	
	int mid = l + (r-l)/2;
	if(v[mid] == k)		return mid;
	if(v[mid] > k)		return BinarySearchRecursion(v,k,l,mid-1);
	return BinarySearchRecursion(v,k,mid+1,r);
}