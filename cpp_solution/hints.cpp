#include "hints.h"

/***********************************************************************************\
hints:
1. brit lives in red House
2. swede keeps dog as Pet
3. dane drinks tea 
4. green house to the left of the white house next to it 
5. green owner drinks coffee
6. the person who smokes pall mall rears birds
7. the owner of the yellow house smokes Dunhill
8. the owner living in the house in the center drinks milk
9. the norwegian lives in the first house
10. the man who smokes blend lives next to the one who keeps cats 
11. the man who keeps horses lives next to the man who smokes dunhill 
12. the owner who smokes blue master drinks beer
13. the german smokes prince 
14. the norwegian lives next to the blue house
15. the man who smokes blend has a neigbor who drinks water
\***********************************************************************************/

namespace hints
{
	/* brit lives in red House */
	bool hint1(street::Street &street)
	{
		return street.assurePersonProperties(person::kIndexNationality, person::kBrit, person::kIndexHouseColor, person::kRed);
	}

	/* swede keeps dog as Pet */
	bool hint2(street::Street &street)
	{
		return street.assurePersonProperties(person::kIndexNationality, person::kSwede, person::kIndexPet, person::kDog);
	}

	/* dane drinks tea  */
	bool hint3(street::Street &street)
	{
		return street.assurePersonProperties(person::kIndexNationality, person::kDane, person::kIndexBeverage, person::kTea);
	}

	/* green house to the left of the white house next to it  */
	bool hint4(street::Street &street)
	{
		return street.assureLeftNeighborProperties(street.getPersonByProperties(person::kIndexHouseColor, person::kWhite),
		 										   person::kIndexHouseColor,
		 										   person::kGreen);
	}

	/* green owner drinks coffee */
	bool hint5(street::Street &street)
	{
		return street.assurePersonProperties(person::kIndexHouseColor, person::kGreen, person::kIndexBeverage, person::kCoffee);
	}

	/* the person who smokes pall mall rears birds */
	bool hint6(street::Street &street)
	{
		return street.assurePersonProperties(person::kIndexCigar, person::kPallMall, person::kIndexPet, person::kBird);
	}

	/* the owner of the yellow house smokes Dunhill */
	bool hint7(street::Street &street)
	{
		return street.assurePersonProperties(person::kIndexHouseColor, person::kYellow, person::kIndexCigar, person::kDunhill);
	}

	/* the owner living in the house in the center drinks milk */
	bool hint8(street::Street &street)
	{
		return street.assurePersonProperties(street::Street::middle_house, person::kIndexBeverage, person::kMilk);
	}

	/* the norwegian lives in the first house */
	bool hint9(street::Street &street)
	{
		return street.assurePersonProperties(street::Street::first_house, person::kIndexNationality, person::kNorwegian);
	}

	/* the man who smokes blend lives next to the one who keeps cats  */
	bool hint10(street::Street &street)
	{
		return street.assureANeighborProperties(person::kIndexCigar, person::kBlend, person::kIndexPet, person::kCat);
	}

	/* the man who keeps horses lives next to the man who smokes dunhill  */
	bool hint11(street::Street &street)
	{
		return street.assureANeighborProperties(person::kIndexPet, person::kHorse, person::kIndexCigar, person::kDunhill);
	}

	/* the owner who smokes blue master drinks beer */
	bool hint12(street::Street &street)
	{
		return street.assurePersonProperties(person::kIndexCigar, person::kBlueMaster, person::kIndexBeverage, person::kBeer);
	}

	/* the german smokes prince  */
	bool hint13(street::Street &street)
	{
		return street.assurePersonProperties(person::kIndexNationality, person::kGerman, person::kIndexCigar, person::kPrince);
	}

	/* the norwegian lives next to the blue house */
	bool hint14(street::Street &street)
	{
		return street.assureANeighborProperties(person::kIndexNationality, person::kNorwegian, person::kIndexHouseColor, person::kBlue);
	}

	/* the man who smokes blend has a neigbor who drinks water */
	bool hint15(street::Street &street)
	{
		return street.assureANeighborProperties(person::kIndexCigar, person::kBlend, person::kIndexBeverage, person::kWater);
	}


	bool run_hints(street::Street &street)
	{	
		static std::array<std::function<bool(street::Street&)>, 15> hint_array = 
		{
			hint1,
			hint2, 
			hint3, 
			hint5,
			hint6,
			hint7,
			hint8,
			hint9,
			hint12,
			hint13,
			hint4, 	/* looks at neighbor, takes more time, compute towards the end */
			hint10, /* looks at neighbors, takes more time, compute towards the end */
			hint11,	/* looks at neighbors, takes more time, compute towards the end */
			hint14,	/* looks at neighbors, takes more time, compute towards the end */
			hint15	/* looks at neighbors, takes more time, compute towards the end */
		};

		bool passed_hint;
		for(std::function<bool(street::Street&)> &hint : hint_array)
		{
			passed_hint = hint(street);
			if (!passed_hint)
			{
				return false;
			}
		}
		return true;
	}
}