//
// Created by Stephen Clyde on 3/4/17.
//

#ifndef GEO_REGIONS_CITY_H
#define GEO_REGIONS_CITY_H

// Done: Finish definition for a County class
#include "Region.h"

#include <string>

class City : public Region
{
public:
    City(const std::string data[]);
};
#endif //GEO_REGIONS_CITY_H
