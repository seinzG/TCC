#ifndef WRAPPER_H
#define WRAPPER_H
#include <QString>
#include <QProcess>
#include <QDebug>

class Wrapper
{
public:
    Wrapper();
    QString callScript(QString script, QString args);
    QString createToken();
    // QString getOwners();
    QStringList getSheets();
    QString createTestID();
    QStringList parseResult(QString result);
};

#endif // WRAPPER_H
