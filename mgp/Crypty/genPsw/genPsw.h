#ifndef GENPSW_H
#define GENPSW_H
#include <QString>
#include <cstdlib>
#include <LogIn/LogIn.h>

class generate{
public:
    QString GetRandomString( )
    {
       const QString
       possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
       const int randomStringLength = 32; // assuming you want random strings of 12 characters

       QString randomString;
       for(int i=0; i<randomStringLength; ++i)
       {

           int index = rand() % possibleCharacters.length();
           QChar nextChar = possibleCharacters.at(index);
           randomString.append(nextChar);
       }
       return randomString;
    }
    QString GetRandomStringAll(  QString possibleCharacters, int randomStringLength )
    {

       QString randomString;
       for(int i=0; i<randomStringLength; ++i)
       {

           int index = rand() % possibleCharacters.length();
           QChar nextChar = possibleCharacters.at(index);
           randomString.append(nextChar);
       }
       return randomString;
    }

};

#endif // GENPSW_H
