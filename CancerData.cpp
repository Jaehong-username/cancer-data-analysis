#include "CancerData.h"

CancerData::CancerData(string countryName, float cancerRate)
{
    this->countryName = countryName;
    this->cancerRate = cancerRate;
}

CancerData::~CancerData()
{
}

CancerData::CancerData(const CancerData& other)
{
    this->countryName = other.countryName;
    this->cancerRate = other.cancerRate;
}

CancerData& CancerData::operator=(CancerData& other)
{
    if (this != &other)
    {
        this->countryName = other.countryName;
        this->cancerRate = other.cancerRate;
    }
    
    return *this;
}

string CancerData::getCountryName()
{
    return this->countryName;
}

float CancerData::getCancerRate()
{
    return this->cancerRate;
}

void CancerData::setCountryName(string countryName)
{
    this->countryName = countryName;
}

void CancerData::setCancerRate(float cancerRate)
{
    this->cancerRate = cancerRate;
}
