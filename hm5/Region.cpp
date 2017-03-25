//
// Created by Stephen Clyde on 3/4/17.
//

#include "Region.h"
#include "Utils.h"
#include "World.h"
#include "Nation.h"
#include "State.h"
#include "County.h"
#include "City.h"

#include <iomanip>
#include <iostream>

const std::string regionDelimiter = "^^^";
const int TAB_SIZE = 4;
unsigned int Region::m_nextId = 0;

Region* Region::create(std::istream &in)
{
    Region* region = nullptr;
    std::string line;
    std::getline(in, line);
    if (line!="")
    {
        region = create(line);
        if (region!= nullptr)
            region->loadChildren(in);
    }
    return region;
}
Region* Region::create(const std::string& data)
{
    Region* region = nullptr;
    std::string regionData;
    unsigned long commaPos = (int) data.find(",");
    if (commaPos != std::string::npos)
    {
        std::string regionTypeStr = data.substr(0,commaPos);
        regionData = data.substr(commaPos+1);

        bool isValid;
        RegionType regionType = (RegionType) convertStringToInt(regionTypeStr, &isValid);

        if (isValid)
        {
            region = create(regionType, regionData);
        }

    }

    return region;
}

Region* Region::create(RegionType regionType, const std::string& data)
{
    Region* region = nullptr;
    std::string fields[3];
    if (split(data, ',', fields, 3)) {

        // Create the region based on type
        switch (regionType) {
            case WorldType:
                region = new World();
                break;
            case NationType:
                region = new Nation(fields);
                break;
       // Done: Add cases for State, County, and City
            case StateType:
                region = new State(fields);
                break;
            case CountyType:
                region = new County(fields);
                break;
            case CityType:
                region = new City(fields);
                break;
            default:
                break;
        }

        // If the region isn't valid, git ride of it
        if (region != nullptr && !region->getIsValid()) {
            delete region;
            region = nullptr;
        }
    }

    return region;
}

std::string Region::regionLabel(RegionType regionType)
{
    std::string label = "Unknown";
    switch (regionType)
    {
        case Region::WorldType:
            label = "World";
            break;
        case Region::NationType:
            label = "Nation";
            break;
        case Region::StateType:
            label = "State";
            break;
        case Region::CountyType:
            label = "County";
            break;
        case Region::CityType:
            label = "City";
            break;
        default:
            break;
    }
    return label;
}

Region::Region() { }

Region::Region(RegionType type, const std::string data[]) :
        m_id(getNextId()), m_regionType(type), m_isValid(true)
{
    m_name = data[0];
    m_population = convertStringToUnsignedInt(data[1], &m_isValid);
    if (m_isValid)
        m_area = convertStringToDouble(data[2], &m_isValid);
    RegionType child;
}

Region::~Region()
{
    // Done: cleanup any dynamically allocated objects
    for (int x = 0; x < m_subRegionsNext; x++){
        delete sub[x];
    }
}


std::string Region::getRegionLabel() const
{
    return regionLabel(getType());
}

unsigned int Region::computeTotalPopulation()
{
    // Done: implement computeTotalPopulation, such that the result is m_population + the total population for all sub-regions
    unsigned int total;
    for(int x = 0; x < m_subRegionsNext;x++){
        total += sub[x]->computeTotalPopulation() + m_population;
    }

    if(m_subRegionsNext == 0){
        total = m_population;
    }


    return total;
}

void Region::removeRegion(int id){
    for(int x = 0; x < m_subRegionsNext; x++){
        if(sub[x]->m_id == id){
            delete sub[x];
            sub[x] = nullptr;
            sub.erase(sub.begin() + x);
            m_subRegionsNext--;
        }
    }
}

Region* Region::getRegion(int id) {
    Region* temp = nullptr;
    for(int x = 0; x < m_subRegionsNext; x++){
        if(sub[x]->m_id == id){
            temp = sub[x];
        }
    }
    return temp;
}

void Region::list(std::ostream& out)
{
    out << std::endl;
    out << getName() << ":" << std::endl;

    // Done: implement the loop in the list method
    for(int x = 0; x < m_subRegionsNext; x++){
        out << std::to_string(sub[x]->getId()) << " " << sub[x]->getName() << std::endl;
    }
    // foreach subregion, print out
    //      id    name
}

void Region::display(std::ostream& out, unsigned int displayLevel, bool showChild)
{
    if (displayLevel>0)
    {
        out << std::setw(displayLevel * TAB_SIZE) << " ";
    }

    unsigned totalPopulation = computeTotalPopulation();
    double area = getArea();
    double density = (double) totalPopulation / area;

    // Done: compute the totalPopulation using a method

    out << std::setw(6) << getId() << "  "
        << getName() << ", population="
        << totalPopulation
        << ", area=" << area
        << ", density=" << density << std::endl;

    if (showChild)
    {
        // Done: implement loop in display method
        for (int x = 0; x < m_subRegionsNext; x++){
            //out << std::to_string(sub[x]->getId()) << " " << sub[x]->getName() << std::endl;
            sub[x]->display(std::cout, displayLevel + 1, showChild);
        }
        // foreach subregion
        //      display that subregion at displayLevel+1 with the same showChild value
    }
}

void Region::save(std::ostream& out)
{
/*    if (getType() == WorldType) {
        out << getType()
            << "," << getName()
            << "," << getPopulation()
            << "," << getArea()
            << std::endl;
    }
*/
    // Done: implement loop in save method to save each sub-region
    //^Calling done but havent tested
    for (int x = 0; x < m_subRegionsNext; x++){
        out << sub[x]->getType()
            << "," << sub[x]->getName()
            << "," << sub[x]->getPopulation()
            << "," << sub[x]->getArea()
            << std::endl;
        sub[x]->save(out);
        out << regionDelimiter << std::endl;
    }
    // foreach subregion,
    //      save that region
/*    if (getType() == WorldType) {
        out << regionDelimiter << std::endl;
    } */
}

void Region::validate()
{
    m_isValid = (m_area!=UnknownRegionType && m_name!="" && m_area>=0);
}

void Region::loadChildren(std::istream& in)
{
    std::string line;
    bool done = false;
    while (!in.eof() && !done)
    {
        std::getline(in, line);
        line = trim(line);
        if (line==regionDelimiter)
        {
            done = true;
        }
        else
        {
            Region* child = create(line);
            if (child!= nullptr)
            {
                // Done: Add the new sub-region to this region
                sub.push_back(child);
                m_subRegionsNext++;
                child->loadChildren(in);


            }
        }
    }
}

unsigned int Region::getNextId()
{
    if (m_nextId==UINT32_MAX)
        m_nextId=1;

    return m_nextId++;
}