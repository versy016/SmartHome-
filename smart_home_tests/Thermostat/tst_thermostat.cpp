#include <QtTest>
#include <QCoreApplication>
#include "thermostat.h"
// add necessary includes here

class tst_Thermostat : public QObject
{
    Q_OBJECT

public:
    tst_Thermostat();
    ~tst_Thermostat();
private:
    Thermostat ts;
private slots:
    void testID();
    void testIPaddress();
    void testcurrentState();
    void testlastMeasurement();
    void testlast5Measurements();
    void testsetpoint();
    void testtempChange();



};

// Using a macro to ensure the QVERIFY2 has the correct location in the source file
// Otherwise these tests are not very useful.
#define equal(expected, actual, failMessage) \
  ++_assertionCount; \
  if (not (expected == actual)) ++_failureCount; \
  QVERIFY2(expected == actual, failMessage);

tst_Thermostat::tst_Thermostat() : ts("HH")
{

}

tst_Thermostat::~tst_Thermostat()
{

}

void tst_Thermostat::testID()
{
    ts.setDeviceName("Thermostat");
    QCOMPARE(ts.getDeviceName(),"Thermostat");
}

void tst_Thermostat::testIPaddress()
{
    ts.setIPAddressController("Thermostat IP");
    QCOMPARE(ts.getIPAddressController(), "Thermostat IP");
}

void tst_Thermostat::testcurrentState()
{

}
void tst_Thermostat::testlastMeasurement()
{

}
void tst_Thermostat::testlast5Measurements()
{

}
void tst_Thermostat::testsetpoint()
{

}
void tst_Thermostat::testtempChange()
{

}

QTEST_MAIN(tst_Thermostat)

#include "tst_thermostat.moc"
