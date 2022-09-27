// Written by Joseph Krueger

#pragma once
#include <string>
#include <vector>
#include <tuple>

//==================================================
class DataReader {

public:
    DataReader(){};
    DataReader(std::string path){file = path;}
    bool Read();

    struct Country
    {
        std::string name;
        int population;
        int area;
    };

    std::vector<Country> GetData(){return countryData;}
    std::string GetFilePath(){return file;}
    void setFileName(std::string filename){file = filename;}

private:
    std::string file;
    std::vector<Country> countryData;

};
