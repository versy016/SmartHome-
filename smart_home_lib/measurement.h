#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <QMetaType>
#include "lightswitch.h"
#include "thermostat.h"
#include "iomanip"
#include "device.h"
/**
 * @brief The Measurement class
 *
 * TODO: This is just a placeholder so that the MessageFactory can
 * reference it. You need to implement it properly.
 */
template <class T>
class Measurement
{

public:
    T value;
    Measurement();
    Measurement(T type);
    Device deviceName();
    T measurementType();
//    LightSwitch on_off(bool onoff);
//    void brightness_level(int val);
//    void temperature (double val, std::_Setprecision());
//    void temperature_setpoint(double, std::_Setprecision());
//    Thermostat thermostat_state(int val);
//    //sprinkler state(e
//    void schedule_time(QDateTime);
//    void schedule_duration(double val, std::_Setprecision());
//    void total_water_usage(double val, std::_Setprecision());
//    QDateTime timestamp();
//    QVariant value();
//    std::string unitOfMeasure();
    bool isFiltered();
    Measurement rawMeasurement();

private:
    T type;
};

// You may need this to make it compatiable with QVariant
// You may also need to use it on each instantiation of the
// template subclass.
Q_DECLARE_METATYPE(Measurement<int>)

#endif // MEASUREMENT_H
