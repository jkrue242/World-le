//
// Created by Joseph Krueger on 9/26/22.
//

#include "TestData.h"

//==================================================
void TestData::SetData() {
    DataReader::Country china;
    china.name = "China";
    china.population = 1440297825;
    china.area = 9388211;

    DataReader::Country india;
    india.name = "India";
    india.population = 1382345085;
    india.area = 2973190;

    DataReader::Country us;
    us.name = "United States";
    us.population = 331341050;
    us.area = 9147420;

    DataReader::Country indonesia;
    indonesia.name = "Indonesia";
    indonesia.population = 274021604;
    indonesia.area = 1811570;

    TestData.push_back(china);
    TestData.push_back(india);
    TestData.push_back(us);
    TestData.push_back(indonesia);
}