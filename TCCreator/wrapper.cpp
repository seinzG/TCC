#include "wrapper.h"

Wrapper::Wrapper() {}

QString Wrapper::callScript(QString script, QString args) {
    QProcess process;
    process.setProcessChannelMode(QProcess::MergedChannels);
    QString exe = "python3 "+script+" "+args;
    process.start(exe);
    process.waitForFinished(-1);
    QString output(process.readAllStandardOutput());
    qDebug() << output << endl;
    return output;
}

QString Wrapper::createToken() {
    return callScript("createToken.py", "");
}

// QString Wrapper::getOwners() {
//     return callScript("getOwners.py", "");
// }

QStringList Wrapper::getSheets() {
    QString sResult = callScript("getSheets.py", "");
    return sResult.left(sResult.length()-1).split("\n");
}

QString Wrapper::createTestID() {
    QString sResult = callScript("getTestCaseID.py", "DRC");
    QString last = this->parseResult(sResult).last();
    //TODO: Update last number
    return last;
}

QStringList Wrapper::parseResult(QString result) {
    qDebug() << result << endl;
    result.remove('\'');
    result = result.left(result.length() - 2);
    return result.split("] [");
}
