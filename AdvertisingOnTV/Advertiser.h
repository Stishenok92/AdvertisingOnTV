#pragma once
#include "Header.h"

class Advertiser: public Discount
{
private:
    std::string nameProduct;
public:
    Advertiser() = default;
    Advertiser(std::string, size_t, std::string);
    ~Advertiser() = default;
    
    std::string getNameProduct() const { return nameProduct; }
    void setNameProduct(std::string const nameProduct) { this->nameProduct = nameProduct; }
    
    friend std::istream& operator>>(std::istream& in, Advertiser&);
    friend std::ostream& operator<<(std::ostream& out, const Advertiser&);
    friend std::ofstream& operator<<(std::ofstream& out, const Advertiser&);
};

Advertiser:: Advertiser(std::string nameCompany, size_t discount, std::string nameProduct)
{
    this->setNameCompany(nameCompany);
    this->setDiscount(discount);
    this->nameProduct = nameProduct;
}

std::istream& operator>>(std::istream& in, Advertiser& advertiser)
{
    in >> static_cast<Discount&>(advertiser);
    in >> advertiser.nameProduct;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Advertiser& advertiser)
{
    out
    << std::setw(15) << advertiser.getNameCompany()
    << std::setw(15) << advertiser.getNameProduct();
    return out;
}

std::ofstream& operator<<(std::ofstream& out, const Advertiser& advertiser)
{
    out
    << advertiser.getNameCompany() << " "
    << advertiser.getDiscount() << " "
    << advertiser.getNameProduct() << " ";
    return out;
}
