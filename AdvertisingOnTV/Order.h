#pragma once
#include "Header.h"

class Order: public Advertiser, public Telecast
{
private:
    std::string airDay;
    size_t duration;
    double price;
public:
    Order() = default;
    Order(const Telecast&, const Advertiser&, const size_t discount, const size_t duration, const std::string);
    ~Order() = default;
    
    std::string getAirDay() const { return airDay; }
    double getPrice() const { return price; }
    size_t getDuration() const { return duration; }
    void setAirDay(std::string const airDay) { this->airDay = airDay; }
    void setPrice(double const price) { this->price = price; }
    void setDuration(size_t const duration) { this->duration = duration; }
    
    friend std::istream& operator>>(std::istream& in, Order&);
    friend std::ostream& operator<<(std::ostream& out, const Order&);
    friend std::ofstream& operator<<(std::ofstream& out, const Order&);
};

Order:: Order(const Telecast& telecast, const Advertiser& advertiser, const size_t discount, const size_t duration, const std::string data)
{
    (Telecast&)*this = telecast;
    (Advertiser&)*this = advertiser;
    this->duration = duration;
    this->airDay = data;
    this->setDiscount(discount);
    this->price = (duration * getCostMinuteAds()) * (static_cast<double>(100 - getDiscount())/100);
}

std::istream& operator>>(std::istream& in, Order& order)
{
    in >> static_cast<Advertiser&>(order);
    in >> static_cast<Telecast&>(order);
    in >> order.airDay >> order.duration >> order.price;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Order& order)
{
    out
    << std::setw(15) << order.getAirDay()
    << std::setw(15) << order.getAirTime()
    << std::setw(15) << order.getSurnameHost()
    << std::setw(25) << order.getName()
    << std::setw(15) << order.getNameCompany()
    << std::setw(20) << order.getNameProduct()
    << std::setw(15) << order.getDuration()
    << std::setw(15) << order.getCostMinuteAds()
    << std::setw(15) << order.getDiscount()
    << std::setw(15) << std::fixed << std::setprecision(0) << order.getPrice();
    return out;
}

std::ofstream& operator<<(std::ofstream& out, const Order& order)
{
    out
    << order.getNameCompany() << " "
    << order.getDiscount() << " "
    << order.getNameProduct() << " "
    << order.getNumberChannel() << " "
    << order.getName() << " "
    << order.getAirTime() << " "
    << order.getCostMinuteAds() << " "
    << order.getMaxMinuteAds() << " "
    << order.getPause() << " "
    << order.getSurnameHost() << " "
    << order.getAirDay() << " "
    << order.getDuration() << " "
    << std::fixed << std::setprecision(0) << order.getPrice() << " ";
    return out;
}
