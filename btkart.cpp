#include "btkart.h"


BTKart::BTKart(const QString& configFile) {
    m_map    = new QamModbusMap( QamModbusMap::ClientMode, this ) ;
    cout << configFile.toStdString() << endl;
    int thing = 0;
    bool lol = m_map->loadMap( configFile );

    while(lol == false)
    {
        qSleep(1000);
        if(thing >= 5) {
        cerr << "pb fichier csv non trouve" << endl;
        exit(-1) ;
        }
        thing++;

    }
    m_map->setVerbose( true ) ;

    m_table = QamModbusMap::HoldingRegister ;

    //client TCP

    m_client = new QamTcpClient( m_map, this ) ;

    m_client->sockConnect( m_map->host(), m_map->port() ) ;

    connect(m_notifier, SIGNAL(request(int)), this, SLOT(response()) ) ;
}
#ifdef Q_OS_WIN
#include <windows.h> // for Sleep
#endif
void BTKart::qSleep(int ms)
{
    //QTEST_ASSERT(ms > 0);

#ifdef Q_OS_WIN
    Sleep(uint(ms));
#else
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
#endif
}
float BTKart::getSpeed(){
    m_table = QamModbusMap::HoldingRegister;


    return m_map->localValue(m_table, "vit_kart").toFloat();
}

float BTKart::getCoupleSimu(){
    m_table = QamModbusMap::HoldingRegister;

    //QTextStream	in(stdin) ;
    //QString line = in.readLine() ;
    //QStringList parse = line.split( QRegExp("\\s+") ) ;

    return m_map->value(m_table, "couple_simu").toFloat();
}

float BTKart::getVitSimu(){
    m_table = QamModbusMap::HoldingRegister;

    QTextStream	in(stdin) ;
    QString line = in.readLine() ;
    QStringList parse = line.split( QRegExp("\\s+") ) ;

    return m_map->localValue(m_table, "vit_simu").toFloat();
}

float BTKart::getCoupleKart(){
    m_table = QamModbusMap::HoldingRegister;

    QTextStream	in(stdin) ;
    QString line = in.readLine() ;
    QStringList parse = line.split( QRegExp("\\s+") ) ;

    return m_map->localValue(m_table, "couple_kart").toFloat();
}

float BTKart::getPuissKart(){
    m_table = QamModbusMap::HoldingRegister;

    QTextStream	in(stdin) ;
    QString line = in.readLine() ;
    QStringList parse = line.split( QRegExp("\\s+") ) ;

    return m_map->localValue(m_table, "puiss_kart").toFloat();
}

float BTKart::setWeight(float weight)
{
    m_table = QamModbusMap::HoldingRegister;

  //  QTextStream	in(stdin) ;
  //  QString line = in.readLine() ;
  //  QStringList parse = line.split( QRegExp("\\s+") ) ;
//qDebug()<< "masse_pilot " << QString::number(weight) <<endl;
    m_map->setValue(m_table, "masse_pilot",QString::number(weight));
    //beta  relire

    return m_map->QamModbusMap::value(m_table, "masse_pilot").toFloat();
}

float BTKart::setConsCouple(float couple_sim)
{
    m_table = QamModbusMap::HoldingRegister;

  //  QTextStream	in(stdin) ;
  //  QString line = in.readLine() ;
  //  QStringList parse = line.split( QRegExp("\\s+") ) ;

    m_map->setValue(m_table, "cons_couple",QString::number(couple_sim));

    return m_map->QamModbusMap::remoteValue(m_table, "cons_couple").toFloat();
}


float BTKart::setConsPente(float pente)
{
    m_table = QamModbusMap::HoldingRegister;

  //  QTextStream	in(stdin) ;
  //  QString line = in.readLine() ;
  //  QStringList parse = line.split( QRegExp("\\s+") ) ;

    m_map->setValue(m_table, "cons_pente",QString::number(pente));

    return m_map->QamModbusMap::localValue(m_table, "cons_pente").toFloat();
}


