// Written by Joseph Krueger

#include <gtest/gtest.h>
#include "TestData.h"
#include <vector>
#include "DataReader.h"
#include <iostream>

//==================================================
TEST(FileReaderTests, TestWithData)
{
    TestData tester;
    tester.SetData();
    DataReader TestReader("testCountries.txt");
    TestReader.Read();

    std::vector<DataReader::Country> testData = tester.TestData;
    std::vector<DataReader::Country> actualData = TestReader.GetData();

    ASSERT_EQ(actualData.size(), testData.size());

    for(int i = 0; i < tester.TestData.size(); i++)
    {
        ASSERT_EQ(testData[i].name, actualData[i].name);
        ASSERT_EQ(testData[i].population, actualData[i].population);
        ASSERT_EQ(testData[i].area, actualData[i].area);
    }
}
