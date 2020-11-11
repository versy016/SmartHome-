#ifndef SPRINKLERSYSTEM_H
#define SPRINKLERSYSTEM_H

#include "device.h"
#include <QObject>
#include <chrono>
#include <thread>
#include <future>
#include <iostream>
#include "measurementtemplate.h"
#include "abstractmeasurement.h"

class SprinklerSystem : public Device
{
    Q_OBJECT
public:

    SprinklerSystem(QString name);

    int getUpdateFrequency() ;
    void setUpdateFrequency(int value);

    double getWaterConsumptionPerInterval() ;
    void setWaterConsumptionPerInterval(double value);

    double getlifetimeConsumption();
    void setlifetimeConsumption(double value);

    bool getIsOn() ;
    void turnOn();

    void turnOff();

    void schedule(QTime delay, QTime duration);

    void setcurrrentState(std::string state);
    std::vector<MeasurementTemplate<QTime>*> currentState();
    std::vector<MeasurementTemplate<double>*> waterUsage();



private:

    int _updateFrequency = 5;
    double _waterConsumptionPerInterval =  0;
    double totalConsumption;
    bool _isOn  = false;
    QString Name = "";
    QTime Duration;
    QTime Delay;
    std::string thestate = "";
    AbstractMeasurement *am = nullptr;
    std::vector<AbstractMeasurement*> abvector;
    MeasurementTemplate<QTime> *mtstate = nullptr;
    MeasurementTemplate<double> *mtusage = nullptr;
    std::vector<MeasurementTemplate<QTime>*> mtvectorstate;
    std::vector<MeasurementTemplate<double>*> mtvectorusage;

};

#endif // SPRINKLERSYSTEM_H
