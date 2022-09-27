//
// Created by Joseph Krueger on 9/27/22.
//
#pragma once
#include "DataReader.h"
#include <vector>

//==================================================
class Worldle {

public:
    explicit Worldle(std::vector<DataReader::Country> data);
    bool Play();
    std::string GetTargetCountry(){return Target.name;}

    // used for testing
    void SetTargetCountry(DataReader::Country country){Target = country;}

private:
    int MAX_GUESSES = 9;
    int GuessNum = 0;

    DataReader::Country Target;
    std::vector<DataReader::Country> CountryData;

    void MakeGuess(std::string guess);
    bool Win = false;

    std::vector<std::string> Guesses;
    std::vector<std::vector<std::string>> Feedback;

};


