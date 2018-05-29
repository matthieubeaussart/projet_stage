#include "amplificator.h"

Amplificator::Amplificator(QObject *parent) : QObject(parent)
{
    int y=0;
    int i=0;
    char* buffer_r;
    char data[5];
}

void Amplificator::setValueChannel(int value, int channel)
{
    switch(channel) {
    case 1: m_valC1 = value; break;
    case 2: m_valC2 = value; break;
    case 3: m_valC3 = value; break;
    case 4: m_valC4 = value; break;
    case 5: m_valC5 = value; break;
    case 6: m_valC6 = value; break;
    }
}

int Amplificator::getValueChannel(int channel)
{
    switch(channel) {
    case 1: return m_valC1;
    case 2: return m_valC2;
    case 3: return m_valC3;
    case 4: return m_valC4;
    case 5: return m_valC5;
    case 6: return m_valC6;
    }
}

QString Amplificator::ping()
{
    m_trame="rf0011111";
    return(m_trame);
}

char* Amplificator::lecture(int sortie)
{
    if(sortie >= 1 && sortie <= 6) {m_trame = QString("rf52") + QString::number(sortie) + QString("00000");}

    m_trameValSortie = m_trame.toStdString().c_str();

    m_trameValSortieChar=strdup(m_trameValSortie);

    return(m_trameValSortieChar);
}

QString Amplificator::decodeLecture(char* trame)
{
    int y=0;
    int i=0;
    char* buffer_r;
    char data[5];
    buffer_r = trame;
    for(i=6;i<10;i++)
    {
        data[y]=buffer_r[i];
        y++;
    }
    return(data);
}

QString Amplificator::stock(int sortie)
{
    if(sortie >= 1 && sortie <= 6) {m_trame = QString("rf51") + QString::number(sortie) + QString("00000");}
    return(m_trame);
}

QString Amplificator::puissance(QString nb, int sortie)
{
    if(nb.size()==1)
    {
        nb="000"+nb;
    }
    if(nb.size()==2)
    {
        nb="00"+nb;
    }
    if(nb.size()==3)
    {
        nb="0"+nb;
    }

    m_trame=nb;

    if(sortie==1)
    {
        m_trame="rf5010"+m_trame;
    }
    if(sortie==2)
    {
        m_trame="rf5020"+m_trame;
    }
    if(sortie==3)
    {
        m_trame="rf5030"+m_trame;
    }
    if(sortie==4)
    {
        m_trame="rf5040"+m_trame;
    }
    if(sortie==5)
    {
        m_trame="rf5050"+m_trame;
    }
    if(sortie==6)
    {
        m_trame="rf5060"+m_trame;
    }

    return(m_trame);
}

QString Amplificator::plage(QString nb)
{
    m_trame="rf5300000"+nb;
    return(m_trame);
}

QString Amplificator::commutation(int sortie, QString voie)
{
    if(sortie==1)
    {
        m_trame = "rf5410000";
    }
    if(sortie==2)
    {
        m_trame = "rf5420000";
    }
    if(voie=="A")
    {
        m_trame += "0";
    }
    if(voie=="B")
    {
        m_trame += "1";
    }
    return(m_trame);
}

char *Amplificator::puissanceChar(QString puissance)
{
    return const_cast<char*>(puissance.toStdString().c_str());
}

Amplificator::~Amplificator()
{

}
