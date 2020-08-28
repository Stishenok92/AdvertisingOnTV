#pragma once
#include "Header.h"

class Discount
{
private:
    std::string nameCompany;
    size_t discount;
public:
    Discount() = default;
    Discount(std::string, size_t);
    ~Discount() = default;
    
    std::string getNameCompany() const { return nameCompany; }
    size_t getDiscount() const { return discount; }
    
    void setNameCompany(std::string const nameCompany) { this->nameCompany = nameCompany; }
    void setDiscount(size_t const discount) { this->discount = discount; }
    
    friend std::istream& operator>>(std::istream& in, Discount&);
    friend std::ostream& operator<<(std::ostream& out, const Discount&);
    friend std::ofstream& operator<<(std::ofstream& out, const Discount&);
};

Discount:: Discount(std::string nameCompany, size_t discount)
{
    this->nameCompany = nameCompany;
    this->discount = discount;
}

std::istream& operator>>(std::istream& in, Discount& discount)
{
    in >> discount.nameCompany >> discount.discount;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Discount& discount)
{
    out
    << std::setw(15) << discount.nameCompany
    << std::setw(15) << discount.discount;
    return out;
}

std::ofstream& operator<<(std::ofstream& out, const Discount& discount)
{
    out
    << discount.nameCompany << " "
    << discount.discount << " ";
    return out;
}
