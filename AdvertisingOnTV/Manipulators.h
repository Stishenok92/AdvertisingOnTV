#pragma once
#include "Header.h"

std::ostream& manipHeaderTelecast(std::ostream&);
std::ostream& manipHeaderTelecastNotIndex(std::ostream&);
std::ostream& manipHeaderAdvertiser(std::ostream&);
std::ostream& manipHeaderAdvertiserNotIndex(std::ostream&);
std::ostream& manipHeaderDiscount(std::ostream&);
std::ostream& manipHeaderDiscountNotIndex(std::ostream&);
std::ostream& manipHeaderOrder(std::ostream&);
std::ostream& manipHeaderOrderNotIndex(std::ostream&);
std::ostream& manipTailTelecast(std::ostream&);
std::ostream& manipTailTelecastNotIndex(std::ostream&);
std::ostream& manipTailAdvertiser(std::ostream&);
std::ostream& manipTailAdvertiserNotIndex(std::ostream&);
std::ostream& manipTailDiscount(std::ostream&);
std::ostream& manipTailDiscountNotIndex(std::ostream&);
std::ostream& manipTailOrder(std::ostream&);
std::ostream& manipTailOrderNotIndex(std::ostream&);

std::ostream& manipHeaderTelecast(std::ostream& out)
{
    out << "\n" << std::left << std::setfill('-') << std::setw(114) << "-" << "\n" << std::setfill(' ')
    << std::setw(10) << "№"
    << std::setw(10) << "Channel"
    << std::setw(25) << "Telecast"
    << std::setw(15) << "AirTime"
    << std::setw(15) << "CostMinutes"
    << std::setw(15) << "MaxMinutes"
    << std::setw(10) << "Pauses"
    << std::setw(15) << "Surname" << "\n"
    << std::left << std::setfill('-') << std::setw(114) << "-" << "\n" << std::setfill(' ');
    return out;
}

std::ostream& manipHeaderTelecastNotIndex(std::ostream& out)
{
    out << "\n" << std::left << std::setfill('-') << std::setw(104) << "-" << "\n" << std::setfill(' ')
    << std::setw(10) << "Channel"
    << std::setw(25) << "Telecast"
    << std::setw(15) << "AirTime"
    << std::setw(15) << "CostMinutes"
    << std::setw(15) << "MaxMinutes"
    << std::setw(10) << "Pauses"
    << std::setw(15) << "Surname" << "\n"
    << std::left << std::setfill('-') << std::setw(104) << "-" << "\n" << std::setfill(' ');
    return out;
}

std::ostream& manipHeaderAdvertiser(std::ostream& out)
{
    out << "\n" << std::left << std::setfill('-') << std::setw(40) << "-" << "\n" << std::setfill(' ')
    << std::setw(10) << "№"
    << std::setw(15) << "Company"
    << std::setw(15) << "Product"
    << "\n"
    << std::left << std::setfill('-') << std::setw(40) << "-" << "\n" << std::setfill(' ');
    return out;
}

std::ostream& manipHeaderAdvertiserNotIndex(std::ostream& out)
{
    out << "\n" << std::left << std::setfill('-') << std::setw(30) << "-" << "\n" << std::setfill(' ')
    << std::setw(15) << "Company"
    << std::setw(15) << "Product"
    << "\n"
    << std::left << std::setfill('-') << std::setw(30) << "-" << "\n" << std::setfill(' ');
    return out;
}

std::ostream& manipHeaderDiscount(std::ostream& out)
{
    out << "\n" << std::left << std::setfill('-') << std::setw(35) << "-" << "\n" << std::setfill(' ')
    << std::setw(10) << "№"
    << std::setw(15) << "Company"
    << std::setw(15) << "Discount" << "\n"
    << std::left << std::setfill('-') << std::setw(35) << "-" << "\n" << std::setfill(' ');
    return out;
}

std::ostream& manipHeaderDiscountNotIndex(std::ostream& out)
{
    out << "\n" << std::left << std::setfill('-') << std::setw(30) << "-" << "\n" << std::setfill(' ')
    << std::setw(15) << "Company"
    << std::setw(15) << "Discount" << "\n"
    << std::left << std::setfill('-') << std::setw(30) << "-" << "\n" << std::setfill(' ');
    return out;
}

std::ostream& manipHeaderOrder(std::ostream& out)
{
    out << "\n" << std::left << std::setfill('-') << std::setw(170) << "-" << "\n" << std::setfill(' ')
    << std::setw(10) << "№"
    << std::setw(15) << "AirDay"
    << std::setw(15) << "AirTime"
    << std::setw(15) << "Surname"
    << std::setw(25) << "Telecast"
    << std::setw(15) << "Company"
    << std::setw(20) << "Product"
    << std::setw(15) << "Duration"
    << std::setw(15) << "CostMinute"
    << std::setw(15) << "Discount"
    << std::setw(15) << "Price"
    << "\n"
    << std::left << std::setfill('-') << std::setw(170) << "-" << "\n" << std::setfill(' ');
    return out;
}

std::ostream& manipHeaderOrderNotIndex(std::ostream& out)
{
    out << "\n" << std::left << std::setfill('-') << std::setw(165) << "-" << "\n" << std::setfill(' ')
    << std::setw(15) << "AirDay"
    << std::setw(15) << "AirTime"
    << std::setw(15) << "Surname"
    << std::setw(25) << "Telecast"
    << std::setw(15) << "Company"
    << std::setw(20) << "Product"
    << std::setw(15) << "Duration"
    << std::setw(15) << "CostMinute"
    << std::setw(15) << "Discount"
    << std::setw(15) << "Price"
    << "\n"
    << std::left << std::setfill('-') << std::setw(165) << "-" << "\n" << std::setfill(' ');
    return out;
}

std::ostream& manipTailTelecast(std::ostream& out)
{
    out << std::left << std::setfill('-') << std::setw(114) << "-" << "\n" << std::setfill(' ');
    return out;
}

std::ostream& manipTailTelecastNotIndex(std::ostream& out)
{
    out << std::left << std::setfill('-') << std::setw(104) << "-" << "\n" << std::setfill(' ');
    return out;
}

std::ostream& manipTailAdvertiser(std::ostream& out)
{
    out << std::left << std::setfill('-') << std::setw(40) << "-" << "\n" << std::setfill(' ');
    return out;
}

std::ostream& manipTailAdvertiserNotIndex(std::ostream& out)
{
    out << std::left << std::setfill('-') << std::setw(30) << "-" << "\n" << std::setfill(' ');
    return out;
}

std::ostream& manipTailDiscount(std::ostream& out)
{
    out << std::left << std::setfill('-') << std::setw(35) << "-" << "\n" << std::setfill(' ');
    return out;
}

std::ostream& manipTailDiscountNotIndex(std::ostream& out)
{
    out << std::left << std::setfill('-') << std::setw(30) << "-" << "\n" << std::setfill(' ');
    return out;
}

std::ostream& manipTailOrder(std::ostream& out)
{
    out << std::left << std::setfill('-') << std::setw(170) << "-" << "\n" << std::setfill(' ');
    return out;
}

std::ostream& manipTailOrderNotIndex(std::ostream& out)
{
    out << std::left << std::setfill('-') << std::setw(165) << "-" << "\n" << std::setfill(' ');
    return out;
}

bool checkFile(std::istream& in)
{
    if (!in)
    {
        std::cout << "\nError open file!\n";
        exit(0);
    }
    
    return true;
}

std::string toLower(const std::string& str)
{
    std::string newStr = str;
    
    for (size_t i = 0; i < newStr.size(); i++)
    {
        newStr[i] = tolower(newStr[i]);
    }
    
    return newStr;
}

