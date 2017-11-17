/************************************\
Author: Guy
File name: generator.h
purpose: export functions of generator.c
remarks: 
\************************************/

#include <array>
#include <vector>
#include <algorithm>
#include <vector>
#include <array>
#include <iostream>

#ifndef __GENERATOR_H__
#define __GENERATOR_H__

#include "person.h"
#include "product-iterator/include/product_iterator.hpp"

namespace generator
{
	template <typename T, int n>
	void get_permutations(std::array<T, n> &input_array, std::vector<std::array<T, n> > &output_vector)
	{
		output_vector.clear();
		std::sort(input_array.begin(), input_array.end());
		do{
			output_vector.push_back(input_array);
		} while(std::next_permutation(input_array.begin(), input_array.end()));
	}

	// shamlessly stolen from product-iterator-master/include/product_iterator.hpp to wrap in 'generator' namespace
	template <class... Containers>
	product_iterator<Containers...>
	make_product_iterator(Containers const&... containers) {
	  return product_iterator<Containers...>(containers...);
	}

}

#endif /*__GENERATOR_H__*/