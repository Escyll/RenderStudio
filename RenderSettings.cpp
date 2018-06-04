#include "RenderSettings.h"

#include <QDataStream>

RenderSettings::RenderSettings(QObject *parent) : QObject(parent)
{

}

bool RenderSettings::antiAliasing() const
{
    return m_antiAliasing;
}

void RenderSettings::setAntiAliasing(bool antiAliasing)
{
    m_antiAliasing = antiAliasing;
    emit antiAliasingChanged();
}

void RenderSettings::saveToDataStream(QDataStream& out) const
{
    out << m_antiAliasing;
}

void RenderSettings::readFromDataStream(QDataStream& in)
{
    bool antiAliasing;
    in >> antiAliasing;
    setAntiAliasing(antiAliasing);
}

QDataStream& operator <<(QDataStream& out, const RenderSettings& renderSettings)
{
    renderSettings.saveToDataStream(out);
    return out;
}

QDataStream& operator >>(QDataStream& in, RenderSettings& renderSettings)
{
    renderSettings.readFromDataStream(in);
    return in;
}
