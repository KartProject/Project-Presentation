#ifndef BTKART_H
#define BTKART_H
#include "qamtcpclient.h"
#include "qammodbusmap.h"
#include "modipmaster.h"
#include <QSocketNotifier>
#include <iostream>
using namespace std ;

class BTKart : public QObject
{
public:
    //init classe metier avec nom de fichier csv en arg
    explicit BTKart(const QString& configFile);
    //réception données
    float getSpeed();

    float getCoupleSimu();

    float getVitSimu();

    float getCoupleKart();

    float getPuissKart();

    float setWeight(float weight);

    float setConsCouple(float couple_sim);

    float setConsPente(float pente);

private:
    void qSleep(int ms);
    QamModbusMap*				m_map ;
    QamModbusMap::PrimaryTable	m_table ;

    QamTcpClient*		m_client ;
    QSocketNotifier*	m_notifier ;
};

#endif // BTKART_H
