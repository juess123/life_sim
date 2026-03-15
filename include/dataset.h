#ifndef DATASET_H
#define DATASET_H

#include "agent.h"
#include "world_time.h"
#include "actions.h"
#include <fstream>
#include <nlohmann/json.hpp>
void save_dataset(const Agent& a,const SimTime& t,Action act);



#endif