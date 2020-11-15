#ifndef THERMOSTAT_H
#define THERMOSTAT_H
#include "device.h"
#include "abstractmeasurement.h"
#include "measurementtemplate.h"
#include <QObject>
#include <random>
#include <thermostatproxyinterface.h>
#include <chrono>
#include <thread>

class Thermostat : public Device, public ThermostatProxyInterface
{
    Q_OBJECT
public:

    Thermostat(QString name);
    int getUpdateFrequency() ;
    void setUpdateFrequency(int value);
    std::string unitofMeasure() ;
    void setUnitofMeasure(std::string unitofMeasure);
    void setStartingTemperature(double starttemp);
    double getStartingTemperature();
    MeasurementTemplate<double> *lastMeasurement();
    void setlastMeasurement(double value);
    void storelastMeasurements(double addvalue);
    void setthesetpoint(double temp);
    MeasurementTemplate<std::vector<double>> *last5Measurement();
    MeasurementTemplate<double> *setpoint();
    void setcurrentstate(std::string state);
    MeasurementTemplate<double> *currentState();
    void warmer(double amount);
    void cooler(double amount);
    void update();
    double randomDouble();

    std::string deviceType();
    Device *realDevice();

private:
    QString Name;
    QString IP_Address;
    QString Port;
    int Value = 3;
    std::string cstate ="";
    double StartTemperature;
    std::string UoM ="";
    double thesetpoint;
    MeasurementTemplate<double> *mt;
    MeasurementTemplate<std::vector<double>> *mt1;
    double plusminus = 0.00;
    double currentvalue = 0.00;
    std::vector<double> last5values;
    double lastvalue = 0.00;
    double Temp = 0.00;
    std::mt19937 _randomGenerator{uint32_t(time(nullptr))}; //random nuber generator
    std::uniform_real_distribution<double> _realDistribution{0.0, 0.5};





};

#endif // THERMOSTAT_H
