/*
 * Evan Hastings
 * Date Submitted:
 * 2121-001
 * Lab 4: Searching and Sorting
 */

#pragma once

#include <vector>
#include <cmath>

template <class T>
int linearSearch(std::vector<T> data, T target){
	
	for(int i = 0; i < data.size(); i++)	{
		
		if(data.at(i) == target)	{
			return i;
		}
	}
	return -1;
}


template <class T>
int binarySearch(std::vector<T> data, T target){

	int middle = floor(data.size() / 2.0);

	if(data.at( middle ) <= target)	{
		
		for(int i = middle; i < (int)data.size(); i++)	{
			
			if(data.at(i) == target)
				return i;
		}

		return -1;
	}
		
	else	{

		for(int i = 0; i < middle; i++)	{
			
			if(data.at(i) == target)
				return i;
		}

		return -1;
	}
}
