
#include "street.h"

namespace street
{

	Street::Street(const std::array<person::property_values_t, person::kNeighborCount> &raw_street)
	: raw_street(raw_street)
	{
	
	}

	Street::~Street()
	{

	}

	person::person_number_t Street::getPersonByProperties(person::PropertyNameIndex index, person::PropertyValue wanted_property_value)
	{
		const person::property_values_t& relevant_values = this->raw_street[index];
		for (person::person_number_t value_index = 0; value_index < relevant_values.size(); ++value_index)
		{
			if (relevant_values[value_index] == wanted_property_value)
				return value_index;
		}
		throw(std::invalid_argument(std::string("wanted_property_value: " + std::to_string(wanted_property_value))));
	}

	bool Street::assurePersonProperties(person::person_number_t person_number,
								person::PropertyNameIndex to_assure_property_name_index,
								person::PropertyValue to_assure_property_value)
	{
		return this->raw_street[to_assure_property_name_index][person_number] == to_assure_property_value;
	}

	bool Street::assurePersonProperties(person::PropertyNameIndex to_find_property_name_index,
										person::PropertyValue to_find_property_value,
										person::PropertyNameIndex to_assure_property_name_index,
										person::PropertyValue to_assure_property_value)
	{
		return assurePersonProperties(
			getPersonByProperties(to_find_property_name_index, to_find_property_value),
			to_assure_property_name_index,
			to_assure_property_value);
	}

	bool Street::assureLeftNeighborProperties(person::person_number_t person_number,
										person::PropertyNameIndex to_assure_property_name_index,
										person::PropertyValue to_assure_property_value)
	{
		if(hasLeftHouse(person_number))
		{
			return assurePersonProperties(
				getLeftHouse(person_number),
				to_assure_property_name_index,
				to_assure_property_value
			);
		}
		return false;
	}

	bool Street::assureRightNeighborProperties(person::person_number_t person_number,
										person::PropertyNameIndex to_assure_property_name_index,
										person::PropertyValue to_assure_property_value)
	{
		if(hasRightHouse(person_number))
		{
			return assurePersonProperties(
				getRightHouse(person_number),
				to_assure_property_name_index,
				to_assure_property_value
			);
		}
		return false;
	}

	bool Street::assureANeighborProperties(person::PropertyNameIndex to_find_property_name_index,
										person::PropertyValue to_find_property_value,
										person::PropertyNameIndex to_assure_property_name_index,
										person::PropertyValue to_assure_property_value)
	{
		person::person_number_t person_number = getPersonByProperties(to_find_property_name_index, to_find_property_value);
		if (hasLeftHouse(person_number) &&  hasRightHouse(person_number))
		{
			return (assureLeftNeighborProperties(person_number, to_assure_property_name_index, to_assure_property_value)
				||
				assureRightNeighborProperties(person_number, to_assure_property_name_index, to_assure_property_value));
		}

		//has only one neighbor
		if(hasLeftHouse(person_number))
		{
			return assureLeftNeighborProperties(person_number, to_assure_property_name_index, to_assure_property_value);
		}

		if(hasRightHouse(person_number))
		{
			return assureRightNeighborProperties(person_number, to_assure_property_name_index, to_assure_property_value);
		}

		throw(std::runtime_error("have no left or right neighbors!"));
	}

	bool Street::hasLeftHouse(person::person_number_t person_number)
	{
		return person_number != Street::min_house_index;
	}
	bool Street::hasRightHouse(person::person_number_t person_number)
	{
		return person_number != Street::max_house_index;
	}
	person::person_number_t Street::getLeftHouse(person::person_number_t person_number)
	{
		return (person_number-1);
	}
	person::person_number_t Street::getRightHouse(person::person_number_t person_number)
	{
		return (person_number+1);
	}
}