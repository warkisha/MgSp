#ifndef CRYPTY_H
#define CRYPTY_H

#include <QObject>
#include <QDebug>

//static const QString kEncryptorString = QString("encryption key"); //here is key to crypt/decrypt QString;

class Crypter
{
public:
    QString cryptString(QString toCrypt, QString kEncryptorString )
    {
        QString resultString = "";
        for ( int i = 0; i < toCrypt.length(); i++)
        {
            resultString.append(QString(QChar(toCrypt[i]).unicode()^QChar(kEncryptorString[keyIndex(i, kEncryptorString)]).unicode()));
        }
        return resultString;
    }
    QString decryptString(QString toDecrypt, QString kEncryptorString )
    {
        QString resultString = "";
        for ( int i = 0; i < toDecrypt.length(); i++)
        {
            resultString.append(QString(QChar(toDecrypt[i]).unicode()^QChar(kEncryptorString[keyIndex(i, kEncryptorString)]).unicode()));
        }
        return resultString;
    }
private:
    static int keyIndex(int index, QString kEncryptorString )
    {
        int len = kEncryptorString.length();
        int multiple = index / len;
        if ( index >=  len ) {
            return index - (len * multiple);
        }
        return index;
    }
};



#endif // CRYPTY_H
