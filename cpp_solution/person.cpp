#include "person.h"

namespace person
{

    std::ostream& operator<<(std::ostream& os, const person_t person)
    {
        os << "Person{";
        os << "HouseColor=" << person[kIndexHouseColor];
        os << ", Nationality=" << person[kIndexNationality];
        os << ", Beverage=" << person[kIndexBeverage];
        os << ", Cigar=" << person[kIndexCigar];
        os << ", Pet=" << person[kIndexPet];
        os << "}";
        return os;
    }


    std::ostream& operator<<(std::ostream &os, std::array<person::Values, 5ul> const &person_array)
    {
        os << "|";
        for (unsigned long property_index = 0; property_index < 5ul; ++property_index)
        {
            os << " " << stringify_property_value(person_array[property_index]) << " |";
        }
        return os;
    }

    std::string stringify_property_value(PropertyValue const property_value)
    {
        switch(property_value)
        {
        case (kBlue):
            return "Blue        ";
        case (kGreen):
            return "Green       ";
        case (kRed):
            return "Red         ";
        case (kWhite):
            return "White       ";
        case (kYellow):
            return "Yellow      ";
        case (kBrit):
            return "Brit        ";
        case (kDane):
            return "Dane        ";
        case (kGerman):
            return "German      ";
        case (kNorwegian):
            return "Norwegian   ";
        case (kSwede):
            return "Swede       ";
        case (kBeer):
            return "Beer        ";
        case (kCoffee):
            return "Coffee      ";
        case (kMilk):
            return "Milk        ";
        case (kTea):
            return "Tea         ";
        case (kWater):
            return "Water       ";
        case (kBlueMaster):
            return "BlueMaster  ";
        case (kDunhill):
            return "Dunhill     ";
        case (kPallMall):
            return "AllMall     ";
        case (kPrince):
            return "Prince      ";
        case (kBlend):
            return "Blend       ";
        case (kCat):
            return "Cat         ";
        case (kBird):
            return "Bird        ";
        case (kDog):
            return "Dog         ";
        case (kFish):
            return "Fish        ";
        case (kHorse):
            return "Horse       ";
        default: 
            return std::string("UNKNOWN VALUE: ") + std::to_string(property_value);
        }
    }

}