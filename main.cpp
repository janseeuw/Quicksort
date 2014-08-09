//
//  Created by Jonas Anseeuw
//  Copyright (c) 2014 Jonas Anseeuw. All rights reserved.
//

#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

template<typename T>
class QuickSort {
public:
	void sort(vector<T> & v, int l, int r) const{
		if(l < r){
			int pivot = v[l];
			int i = l;
			int j = r;
			while(v[j] > pivot){
				j--;
			}
			while(i < j){
				swap(v[i], v[j]);
				i++;
				while(v[i] < pivot){
					i++;
				}
				j--;
				while(v[j] > pivot){
					j--;
				}
			}
			sort(v, l, j);
			sort(v, j+1, r);
		}
	}
	void operator() (vector<T> & v) const{
		sort(v, 0, v.size()-1);
	}
};

template<typename T>
class QuickSortMedian {
public:
	void sort(vector<T> & v, int l, int r) const{
		std::swap(v[(r-l)/2], v[r-1]);
		if(v[r-1] < v[l]) swap(v[l], v[r-1]);
		if(v[r] < v[l]) swap(v[l], v[r]);
		if(v[r] < v[r-1]) swap(v[r-1], v[r]);
		if(l < r)
		{
			int i = l;
			int j = r-2;
			int pivot = r-1;
			while(v[j]>v[pivot])
				j--;
			while(v[i]<v[pivot])
				i++;
			while(i < j)
			{
				swap(v[i],v[j]);
				j--;
				while(v[j]>v[pivot])
					j--;
				i++;
				while(v[i]<v[pivot])
					i++;
			}
			swap(v[i],v[pivot]);
			sort(v,l,j);
			sort(v,i+1,r);
		}
	}
	void operator() (vector<T> & v) const{
		sort(v, 0, v.size()-1);
	}
};

int main(int argc, const char * argv[])
{
	int temp[] = {16,2,77,29, 6, 19, 15, 88};
	vector<int> array (temp, temp + sizeof(temp) / sizeof(int) );
	
	QuickSort<int> quickSort;
	quickSort(array);
	
	cout << "Sorted array is \n";
	for(int i=0; i<array.size(); i++){
		cout<<array[i]<<" ";
	}
	
    return 0;
}

