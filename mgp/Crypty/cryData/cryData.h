#ifndef CRYDATA_H
#define CRYDATA_H

#include <QString>
#include <Crypty/qblowfish.h>

class cryData{
public:
    QString DecryData(QString psw, QString key){
        QByteArray secretKey;
        secretKey.append(key.toUtf8());
        qDebug() << "...Decry... " << psw << key;
        QBlowfish bf(QByteArray::fromHex(secretKey));
        bf.setPaddingEnabled(true);
        QByteArray pswr = QByteArray::fromHex(psw.toUtf8());
//        pswr.append(psw.toUtf8());
        qDebug() << pswr;
        bf.setPaddingEnabled(true);
        QByteArray decryptedBa = bf.decrypted(pswr);
         qDebug() << decryptedBa;
        QString decryptedString = QString::fromUtf8(decryptedBa.constData(), decryptedBa.size());
        return decryptedString;
    }
    QString CryData(QString key, QString psw){
        QByteArray secretKey;
        qDebug() << "...cry... " << key << psw;
        secretKey.append(key.toUtf8());
        QBlowfish bf(QByteArray::fromHex(secretKey));
        qDebug() << "////    " << QByteArray::fromHex(secretKey);
        bf.setPaddingEnabled(true);// Включить заполнение, чтобы можно было зашифровать байты произвольной длины
        QByteArray cipherText = bf.encrypted(psw.toUtf8());
        QString resPsw = cipherText.toHex();
        qDebug() << "...cry result... " << resPsw;
        return resPsw;
    }
};

#endif // CRYDATA_H
