//
// Created by Joseph Krueger on 9/26/22.
//

#include "gtest/gtest.h"
#include "DataReader.h"

//==================================================
TEST(ConstructorTests, TestFilePath)
{
    DataReader TestReader("test");
    ASSERT_EQ(TestReader.GetFilePath(), "test");
}

TEST(ConstructorTests, TestNoPath)
{
    DataReader TestReader("");
    ASSERT_EQ(TestReader.GetFilePath(), "");
}