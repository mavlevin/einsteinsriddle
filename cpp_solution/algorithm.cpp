
#include "algorithm.h"

namespace algorithm
{
	void solve()
	{
		std::array<std::array<person::PropertyValue, person::kPropertyOptions>, person::kNeighborCount> raw_street;

		std::vector<std::array<person::PropertyValue,person::kPropertyOptions> > animals_permutations;
		std::vector<std::array<person::PropertyValue,person::kPropertyOptions> > beverages_permutations;
		std::vector<std::array<person::PropertyValue,person::kPropertyOptions> > cigars_permutations;
		std::vector<std::array<person::PropertyValue,person::kPropertyOptions> > colors_permutations;
		std::vector<std::array<person::PropertyValue,person::kPropertyOptions> > nationalities_permutations;

		std::array<person::PropertyValue, person::kPropertyOptions> animals({person::Values::kCat, person::Values::kBird, person::Values::kDog, person::Values::kFish, person::Values::kHorse});
		std::array<person::PropertyValue, person::kPropertyOptions> beverages({person::Values::kBeer, person::Values::kCoffee, person::Values::kMilk, person::Values::kTea, person::Values::kWater});
		std::array<person::PropertyValue, person::kPropertyOptions> cigars({person::Values::kBlueMaster, person::Values::kDunhill, person::Values::kPallMall, person::Values::kPrince, person::Values::kBlend});
		std::array<person::PropertyValue, person::kPropertyOptions> colors({person::Values::kBlue, person::Values::kGreen, person::Values::kRed, person::Values::kWhite, person::Values::kYellow});
		std::array<person::PropertyValue, person::kPropertyOptions> nationalities({person::Values::kBrit, person::Values::kDane, person::Values::kGerman, person::Values::kNorwegian, person::Values::kSwede});

		generator::get_permutations<person::PropertyValue, person::kPropertyOptions>(animals, animals_permutations);
		generator::get_permutations<person::PropertyValue, person::kPropertyOptions>(beverages, beverages_permutations);
		generator::get_permutations<person::PropertyValue, person::kPropertyOptions>(cigars, cigars_permutations);
		generator::get_permutations<person::PropertyValue, person::kPropertyOptions>(colors, colors_permutations);
		generator::get_permutations<person::PropertyValue, person::kPropertyOptions>(nationalities, nationalities_permutations);

		auto iterator = generator::make_product_iterator(colors_permutations, nationalities_permutations, beverages_permutations, cigars_permutations, animals_permutations);
		auto iterator_end = iterator.get_end();

		#ifdef INFO_COUNT		
			unsigned long count = 0;
			constexpr unsigned long max_count = 24883200000;
		#endif

		int max_hint_reached = 0;
		int index_of_max = 0;
		for(; iterator != iterator_end; ++iterator)
		{
			#ifdef INFO_COUNT
				count++;		
			#endif
			std::array<person::property_values_t, person::kNeighborCount> raw_street({iterator.get<0>(), iterator.get<1>(), iterator.get<2>(), iterator.get<3>(), iterator.get<4>()});
			street::Street current_street(raw_street);

			if (hints::run_hints(current_street))
			{
				//yay found the magic street
				std::cout << "winning street" << std::endl;
				std::cout << current_street << std::endl;
				break;
			}
			

			#ifdef INFO_COUNT
				if((count % (max_count / 100)) == 0)
				{
					#ifdef INFO_COUNT_PERCENT
						std::cout << "done " << (static_cast<float>(count) / static_cast<float>(max_count)) * 100 << "%" << std::endl;
					#else
						std::cout << "done " << count << " / " << max_count << std::endl;
					#endif
				}
			#endif
		}
	}

}
