#include "src/hoi4_world/countries/hoi4_country_converter.h"

#include "src/hoi4_world/technology/technologies_converter.h"



std::optional<hoi4::Country> hoi4::CountryConverter::ConvertCountry(const vic3::Country& source_country,
    const std::set<std::string>& source_technologies,
    const mappers::CountryMapper& country_mapper,
    const std::map<int, int>& vic3_state_ids_to_hoi4_state_ids,
    const std::vector<mappers::TechMapping>& tech_mappings)
{
   const auto tag = country_mapper.GetHoiTag(source_country.GetTag());
   if (!tag.has_value())
   {
      return std::nullopt;
   }

   std::optional<int> capital_state;
   if (const std::optional<int> vic3_capital_state = source_country.GetCapitalState(); vic3_capital_state)
   {
      if (const auto state_id_mapping = vic3_state_ids_to_hoi4_state_ids.find(*vic3_capital_state);
          state_id_mapping != vic3_state_ids_to_hoi4_state_ids.end())
      {
         capital_state = state_id_mapping->second;
      }
   }

   const Technologies technologies = ConvertTechnologies(source_technologies, tech_mappings);

   return Country(
       {.tag = *tag, .color = source_country.GetColor(), .capital_state = capital_state, .technologies = technologies});
}