#pragma once
#include <utility>
#include <initializer_list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <type_traits>
#include <numeric>

template <typename T>
class ExtArray
{
private:
	std::vector<T> extended_array;
	size_t _size;
public:
	ExtArray(std::initializer_list<T> l) : extended_array(l)
	{
		_size = l.size();
	}

	ExtArray(int size) : _size(size)
	{
		extended_array.resize(_size);
	}

	T& operator[](size_t index)
	{
		return extended_array[index];
	}

	size_t size()
	{
		return _size;
	}

	double mean()
	{
		if (_size == 0)
			return 0;

		double sum = 0;
		for (size_t i = 0; i < _size; i++)
		{
			sum += extended_array[i];
		}

		return sum / _size;
	}

	double mean(size_t begin, size_t end)
	{
		if (begin < 0 || end < 0)
			throw std::invalid_argument("The values ​​of begin and end must be non-negative");	
		
		if (begin >= _size || end > _size)
			throw std::invalid_argument("The values ​​of begin and end must be less than size array");

		if (begin >= end)
			throw std::invalid_argument("The begin values ​​must be less than the end values");

		const size_t range = end - begin;
		
		double sum = 0;
		for (size_t i = begin; i < end; i++)
		{
			sum += extended_array[i];
		}

		return sum / range;
	}

	double median()
	{
		if (_size == 0)
			return 0;

		std::vector<T> temp_array;
		std::copy(extended_array.begin(), extended_array.end(), back_inserter(temp_array));
		std::sort(temp_array.begin(), temp_array.end());
		if (_size % 2 == 1)
		{
			return temp_array[_size / 2];
		}
		else
		{
			return static_cast<double>(temp_array[(_size / 2) - 1] + temp_array[_size / 2]) / 2;
		}
	}

	int checkSum() 
	{
		if constexpr (!std::is_same_v<T, bool> && !std::is_same_v<T, int>)
			throw std::bad_typeid();

		auto it = std::find_if(extended_array.begin(), extended_array.end(), 
			[](T el) { return (el != 1 && el != 0); });

		if (it != extended_array.end())
			throw std::logic_error("The array must contain only 1 or 0");

		return std::accumulate(extended_array.begin(), extended_array.end(), 0); 
	}

	std::pair<T, int> mode()
	{
		if (_size == 0) 
			return std::pair<T, int>(T{}, 0);

		T max = extended_array[0], cmax = 0, rmax = 0;
		for (int i = 0; i < _size; i++) 
		{
			if (cmax > rmax) 
			{
				rmax = cmax;
				max = extended_array[i - 1];
			}
			cmax = 0;
			for (int j = i; j < _size; j++)
			{
				if (extended_array[j] == extended_array[i])
				{
					cmax++;
				}
			}
		}
		return std::pair<T, int>(max, rmax);
	}
};
