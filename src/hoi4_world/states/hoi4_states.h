#ifndef SRC_HOI4WORLD_STATES_HOI4STATES_H
#define SRC_HOI4WORLD_STATES_HOI4STATES_H



#include <map>
#include <vector>

#include "src/hoi4_world/states/hoi4_state.h"



namespace hoi4
{

struct States
{
   std::vector<State> states;
   std::map<int, StateId> province_to_state_id_map;
   std::map<int, StateId> vic3_state_ids_to_hoi4_state_ids;
   std::map<std::string, std::string> hoi4_state_names_to_vic3_state_names;
   std::map<StateId, std::string> hoi4_state_ids_to_owner;
};

}  // namespace hoi4



#endif  // SRC_HOI4WORLD_STATES_HOI4STATES_H
