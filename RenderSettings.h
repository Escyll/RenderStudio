#ifndef RENDERSETTINGS_H
#define RENDERSETTINGS_H

#include <QDataStream>
#include <QObject>

class RenderSettings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool antiAliasing READ antiAliasing WRITE setAntiAliasing NOTIFY antiAliasingChanged)
public:
    explicit RenderSettings(QObject *parent = nullptr);

    bool antiAliasing() const;
    void setAntiAliasing(bool antiAliasing);

    void saveToDataStream(QDataStream& out) const;
    void readFromDataStream(QDataStream& in);

signals:
    void antiAliasingChanged();

public slots:

private:
    bool m_antiAliasing;
};

QDataStream& operator <<(QDataStream& out, const RenderSettings& renderSettings);
QDataStream& operator >>(QDataStream& in, RenderSettings& renderSettings);

#endif // RENDERSETTINGS_H
