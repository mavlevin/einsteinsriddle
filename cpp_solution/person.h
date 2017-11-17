/************************************\
Author: Guy
File name: person.h
purpose: export functions of person.c
remarks: 
\************************************/

#include <array>
#include <iostream>
#include <string>

#ifndef __PERSON_H__
#define __PERSON_H__

namespace person
{

	enum PropertyNameIndex
	{
		kIndexHouseColor,		// 0
		kIndexNationality,		// 1
		kIndexBeverage,			// 2
		kIndexCigar,			// 3
		kIndexPet,				// 4
		kPropertyNameIndexMax /* must be last */
	};

	constexpr int kNeighborCount = 5;
	constexpr int kPropertyOptions = 5;


	enum Values
	{
		kBlue,		// 0
		kGreen,		// 1
		kRed,		// 2
		kWhite,		// 3
		kYellow,	// 4

		kBrit,		// 5
		kDane,		// 6
		kGerman,	// 7
		kNorwegian,	// 8
		kSwede,		// 9

		kBeer,		// 10
		kCoffee,	// 11
		kMilk,		// 12
		kTea,		// 13
		kWater,		// 14

		kBlueMaster,// 15
		kDunhill,	// 16
		kPallMall,	// 17
		kPrince,	// 18
		kBlend,		// 19

		kCat,		// 20
		kBird,		// 21
		kDog,		// 22
		kFish,		// 23
		kHorse		// 24
	};

	typedef Values PropertyValue;

	typedef std::array<PropertyValue, kPropertyNameIndexMax> person_t;
	typedef std::array<PropertyValue, kPropertyOptions> property_values_t;
	typedef unsigned int person_number_t;
	
	std::ostream& operator<<(std::ostream& os, const person_t &person);

	std::ostream& operator<<(std::ostream &os, std::array<person::Values, person::kPropertyOptions> const &person_array);

	template<int n>
    std::ostream& operator<<(std::ostream &os, std::array<person::Values, n> const &person_array)
    {
        os << "|";
        for (unsigned long property_index = 0; property_index < n; ++property_index)
        {
            os << " " << stringify_property_value(person_array[property_index]) << " |";
        }
        return os;
    }

	std::string stringify_property_value(PropertyValue property_value);

}

#endif /*__PERSON_H__*/