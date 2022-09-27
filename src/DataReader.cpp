// Written by Joseph Krueger

#include "DataReader.h"
#include <iostream>
#include <fstream>
#include <sstream>

//==================================================
bool DataReader::Read() {
    std::ifstream fin(file);
    if(fin.fail())
    {
        std::cout<<"Error reading file "+file<<std::endl;
        return false;
    }

    // indices of file columns we care about
    int countryNameInd = 0;
    int populationInd = 1;
    int landAreaInd = 5;
    int lastCol = 10;

    // will help us traverse the file
    int col = 0;
    int line = 0;
    std::string garbage;

    // discard first time
    std::getline(fin, garbage);

    // reading file
    while (!fin.eof())
    {
        std::string data;
        DataReader::Country country;
        std::getline(fin, data, ',');
        country.name = data;
        std::getline(fin, data, ',');
        country.population = std::stoi(data);
        std::getline(fin, data);
        country.area = std::stoi(data);
        countryData.push_back(country);
    }
    fin.close();

    return true;
}