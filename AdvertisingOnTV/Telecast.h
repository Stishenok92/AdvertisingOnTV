#pragma once
#include "Header.h"

class Telecast                          //телепередача
{
private:
    std::string numberChannel;          //номер канала
    std::string name;                   //название передачи
    std::string airTime;                //эфирное время
    double costMinuteAds;               //стоимость минуты рекламного времени
    size_t maxMinuteAds;                //максимальная длительность рекламы в минутах
    size_t pause;                       //всего пауз
    std::string surnameHost;            //фамилия ведущего
public:
    Telecast() = default;
    Telecast(std::string, std::string, std::string, double, size_t, size_t, std::string);
    ~Telecast() = default;
    
    std::string getName() const { return name; }
    std::string getNumberChannel() const { return numberChannel; }
    std::string getAirTime() const { return airTime; }
    double getCostMinuteAds() const { return costMinuteAds; }
    size_t getMaxMinuteAds() const { return maxMinuteAds; }
    size_t getPause() const { return pause; }
    std::string getSurnameHost() const { return surnameHost; }
    
    void setNumberChannel(const std::string& numberChannel) { this->numberChannel = numberChannel; }
    void setName(const std::string name) { this->name = name; }
    void setAirTime(const std::string airTime) { this->airTime = airTime; }
    void setCostMinuteAds(const double costMinuteAds) { this->costMinuteAds = costMinuteAds; }
    void setMaxMinuteAds(const size_t maxMinuteAds) { this->maxMinuteAds = maxMinuteAds; }
    void setPause(const size_t pause) { this->pause = pause; }
    void setSurnameHost(const std::string surnameHost) { this->surnameHost = surnameHost; }
        
    friend std::istream& operator>>(std::istream& in, Telecast&);
    friend std::ostream& operator<<(std::ostream& out, const Telecast&);
    friend std::ofstream& operator<<(std::ofstream& out, const Telecast&);
};

Telecast:: Telecast(std::string numberChannel, std::string name, std::string airTime, double costMinuteAds, size_t maxMinuteAds, size_t pause, std::string surnameHost)
{
    this->numberChannel = numberChannel;
    this->name = name;
    this->airTime = airTime;
    this->costMinuteAds = costMinuteAds;
    this->maxMinuteAds = maxMinuteAds;
    this->pause = pause;
    this->surnameHost = surnameHost;
}

std::istream& operator>>(std::istream& in, Telecast& telecast)
{
    in >> telecast.numberChannel >> telecast.name >> telecast.airTime >> telecast.costMinuteAds
    >> telecast.maxMinuteAds >> telecast.pause >> telecast.surnameHost;
    return in;
}

//для вывода на консоль
std::ostream& operator<<(std::ostream& out, const Telecast& telecast)
{
    out
    << std::setw(10) << telecast.numberChannel
    << std::setw(25) << telecast.name
    << std::setw(15) << telecast.airTime
    << std::setw(15) << telecast.costMinuteAds
    << std::setw(15) << telecast.maxMinuteAds
    << std::setw(10) << telecast.pause
    << std::setw(15) << telecast.surnameHost;
    return out;
}

//для сохранения в файл
std::ofstream& operator<<(std::ofstream& out, const Telecast& telecast)
{
    out
    << telecast.numberChannel << " "
    << telecast.name << " "
    << telecast.airTime << " "
    << telecast.costMinuteAds << " "
    << telecast.maxMinuteAds << " "
    << telecast.pause << " "
    << telecast.surnameHost << " ";
    return out;
}
