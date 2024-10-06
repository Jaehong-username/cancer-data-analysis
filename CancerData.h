#pragma once

#include <iostream>

#include <string>

#include <fstream>

#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

class CancerData
{
public:
    CancerData() : countryName(""), cancerRate(0.00)
    {
    }

    CancerData(string countryName, float cancerRate);

    ~CancerData();
    
    CancerData(const CancerData& other);
    
    CancerData& operator=(CancerData& other);

    //Accessor (getter functions)
    string getCountryName();
    float getCancerRate();

    //Modifier (setter functions)
    void setCountryName(string countryName);
    void setCancerRate(float cancerRate);

private:
    string countryName; // the name of the country;
    float cancerRate;   // the cancer rate for the corresponding country;

};

