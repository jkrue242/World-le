// Written by Joseph Krueger

#include <iostream>
#include "src/DataReader.h"
#include <tuple>
#include <vector>
#include <string>

//==================================================
int main() {
    DataReader reader("src/countryData.csv");
    reader.Read();

    std::vector<DataReader::Country> countryData = reader.GetData();

    return 0;
}
