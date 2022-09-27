// Written by Joseph Krueger

#include <iostream>
#include "src/DataReader.h"
#include <vector>
#include "src/Worldle.h"

//==================================================
int main() {
    // instructions
    std::cout<<"=========================================="<<std::endl;
    std::cout<<"Welcome to Worldle. Guess the Country"<<std::endl<<
               "out of the 150 most populated countries "<<std::endl<<
               "in 10 guesses or less. Capitalize any "<<std::endl<<
               "words in the country name. You will be"<<std::endl<<
               "given feedback based on name, population,"<<std::endl<<
               "and area after each guess. When getting " <<std::endl<<
               "feedback on the number of letters, spaces "<<std::endl<<
               "are included. Good luck!"<<std::endl;
    std::cout<<"=========================================="<<std::endl;
    DataReader reader("src/countryData.csv");
    reader.Read();
    std::vector<DataReader::Country> countryData = reader.GetData();
    Worldle game(countryData);
    DataReader::Country USA;
    USA.name = "United States";
    USA.population = 331341050;
    USA.area = 9147420;
    game.SetTargetCountry(USA);
    bool result = game.Play();
    if (result)
    {
        std::cout<<"Congrats! You guessed the target country: "<<game.GetTargetCountry()<<std::endl;
    }
    else
    {
        std::cout<<"You did not guess the target country. The answer was: "<<game.GetTargetCountry()<<std::endl;
    }

    return 0;
}
