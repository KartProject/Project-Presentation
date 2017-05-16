#include <QCoreApplication>
#include "btkart.h"

int main(int argc, char *argv[])
{
        BTKart bt("kart_banc.csv");
        //bt.getPower();
        //QString res = QString::number(bt.getSpeed());
        //cout << qPrintable( res ) << endl ;

        QCoreApplication app(argc, argv ) ;

        QStringList	args = QCoreApplication::arguments() ;
        if ( args.size() < 1 ) {
            cerr << "usage: " << qPrintable( args.at(0) ) << "<configFile>" << endl ;
            return -1 ;
        }

    // ModipMaster*	master = new ModipMaster( "kart_banc.csv",  &app ) ;

    // Object::connect(master, SIGNAL(quit()), &app, SLOT(quit()) ) ;

        return app.exec() ;
}
