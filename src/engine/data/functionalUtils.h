/*
 * functional.h
 *
 *  Created on: Dec 8, 2015
 *      Author: daniel
 */

#ifndef ENGINE_DATA_FUNCTIONALUTILS_H_
#define ENGINE_DATA_FUNCTIONALUTILS_H_

#include <vector>
#include <functional>

template <class T, class U, class Function>
std::vector<T> fmap(Function fn, const std::vector<U>& v)
{
	std::vector<T> res;
	res.resize(v.size());
	std::transform(v.begin(), v.end(), res.begin(), fn);
	return res;
}

template <class T, class Function>
std::vector<T> filter(Function fn, const std::vector<T>& v)
{
	std::vector<T> res;
	for(const T& item: v)
	{
		if(fn(item))
		{
			res.push_back(item);
		}
	}
	return res;
}

template <class T, class U, class Function>
T foldl(Function fn, T initValue, const std::vector<U>& v)
{
	T res = initValue;
	for(const U& item: v)
	{
		res = fn(res, item);
	}
	return res;
}

template <class T, class Function>
std::vector<T> createVector(size_t size, Function fillerFn)
{
	std::vector<T> res(size);
	int count = 0;
	for(T& item: res)
	{
		item = fillerFn(count);
		++count;
	}
	return res;
}


#endif /* ENGINE_DATA_FUNCTIONALUTILS_H_ */
