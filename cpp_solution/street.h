/************************************\
Author: Guy
File name: street.h
purpose: export functions of street.c
remarks: 
\************************************/

#include <array>
#include <exception>
#include <cmath>

#ifndef __STREET_H__
#define __STREET_H__

#include "person.h"

namespace street
{

	class Street
	{
	public:

		Street(const std::array<person::property_values_t, person::kNeighborCount> &raw_street);

		~Street();

		person::person_number_t getPersonByProperties(person::PropertyNameIndex relevant_property, person::PropertyValue wanted_property_value);

		bool assurePersonProperties(person::person_number_t person_number,
								person::PropertyNameIndex to_assure_property_name_index,
								person::PropertyValue to_assure_property_value);

		bool assurePersonProperties(person::PropertyNameIndex to_find_property_name_index,
										person::PropertyValue to_find_property_value,
										person::PropertyNameIndex to_assure_property_name_index,
										person::PropertyValue to_assure_property_value);

		bool assureLeftNeighborProperties(person::person_number_t person_number,
									person::PropertyNameIndex to_assure_property_name_index,
									person::PropertyValue to_assure_property_value);

		bool assureRightNeighborProperties(person::person_number_t person_number,
									person::PropertyNameIndex to_assure_property_name_index,
									person::PropertyValue to_assure_property_value);

		bool assureANeighborProperties(person::PropertyNameIndex to_find_property_name_index,
										person::PropertyValue to_find_property_value,
										person::PropertyNameIndex to_assure_property_name_index,
										person::PropertyValue to_assure_property_value);


		bool hasLeftHouse(person::person_number_t person_number);
		bool hasRightHouse(person::person_number_t person_number);
		person::person_number_t getLeftHouse(person::person_number_t person_number);
		person::person_number_t getRightHouse(person::person_number_t person_number);

		friend std::ostream& operator<<(std::ostream& os, const Street &str)
		{
			os << "Street\n{\n";
			os << "\t|_Person0______|_Person1______|_Person2______|_Person3______|_Person4______|\n";
			for(const person::property_values_t& values : str.raw_street)
			{
				os << "\t" << values << "\n";
			}
			os << "}\n";
			return os;
		}
		static constexpr person::person_number_t first_house = 0;
		static constexpr person::person_number_t middle_house = 2;
	private:
		const std::array<person::property_values_t, person::kNeighborCount> raw_street;
		static constexpr person::person_number_t max_house_index = 4; 
		static constexpr person::person_number_t min_house_index = 0; 
	};

}

#endif /*__STREET_H__*/