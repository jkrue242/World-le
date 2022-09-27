//
// Created by Joseph Krueger on 9/27/22.
//

#include "Worldle.h"
#include <fstream>
#include <string>
#include <iostream>

//==================================================
Worldle::Worldle(std::vector<DataReader::Country> data) {
    CountryData = data;
    int range = CountryData.size();
    int randomIndex = rand() % range;
    Target = CountryData[randomIndex];
}

//==================================================
bool Worldle::Play()
{
    std::cout<<"Guess #1: "<<std::endl;
    while(GuessNum <= MAX_GUESSES)
    {
        std::string guess;
        std::getline(std::cin, guess);
        MakeGuess(guess);
        if (Win)
        {
            return true;
        }
    }
    return false;
}

//==================================================
void Worldle::MakeGuess(std::string guess)
{
    // checking if guess is in country list
    DataReader::Country guessedCountry;
    bool valid = false;
    for (int i = 0; i < CountryData.size(); i++)
    {
        if(guess == Target.name)
        {
            Win = true;
            valid = true;
            break;
        }
        if (CountryData[i].name == guess)
        {
            guessedCountry = CountryData[i];
            valid = true;
            break;
        }
    }

    // if guess is not within country list, print error
    if (!valid)
    {
        std::cout<<"Not a valid country. Please try again."<<std::endl;
    }

    // if guess is valid
    else
    {
        Guesses.push_back(guess);
        GuessNum++;
        std::vector<std::string> guessFeedback;
        if (!Win)
        {
            int targetSize = Target.name.size();
            int guessedCountrySize = guessedCountry.name.size();
            std::string feed;

            // comparing number of letters in name
            if (targetSize > guessedCountrySize)
            {
                feed = "Target has "+std::to_string(targetSize-guessedCountrySize)+" more letters in its name.";
            }
            else if (targetSize < guessedCountrySize)
            {
                feed = "Target has "+std::to_string(guessedCountrySize-targetSize)+" less letters in its name.";
            }
            else if (targetSize == guessedCountrySize)
            {
                feed = "Target has same number of letters in its name.";
            }
            guessFeedback.push_back(feed);

            // comparing population
            if (Target.population > guessedCountry.population)
            {
                feed = "Target has " +std::to_string(Target.population-guessedCountry.population)+" more population.";
            }
            else if (Target.population < guessedCountry.population)
            {
                feed = "Target has "+std::to_string(guessedCountry.population-Target.population)+" less population.";
            }
            else if (Target.population == guessedCountry.population)
            {
                feed = "Target has same population";
            }
            guessFeedback.push_back(feed);

            // comparing area
            if (Target.area > guessedCountry.area)
            {
                feed = "Target has "+std::to_string(Target.area-guessedCountry.area)+" more area (km^2)";
            }
            else if (Target.area < guessedCountry.area)
            {
                feed = "Target has "+std::to_string(guessedCountry.area-Target.area)+" less area (km^2)";
            }
            else if (Target.area == guessedCountry.area)
            {
                feed = "Target has same area (km^2)";
            }
            guessFeedback.push_back(feed);
        }
        Feedback.push_back(guessFeedback);

        if(!Win)
        {
            // printing feedback
            for(int i = 0; i < Feedback.size(); i++)
            {
                std::cout<<"Guess: "+Guesses[i]<<std::endl;
                for(int j = 0; j < Feedback[i].size(); j++)
                {
                    std::cout<<Feedback[i][j]<<std::endl;
                }
                std::cout<<std::endl;
            }
            std::cout<<"=========================================="<<std::endl;
            std::cout<<"Guess #"+std::to_string(GuessNum+1)<<": "<<std::endl;
        }
    }
}
