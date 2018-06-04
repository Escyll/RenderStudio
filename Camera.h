#ifndef CAMERA_H
#define CAMERA_H

#include <QDataStream>
#include <QObject>

class Camera : public QObject
{
    Q_OBJECT
public:
    explicit Camera(QObject *parent = nullptr);

    int id() const;

    void saveToDataStream(QDataStream& out) const;
    void readFromDataStream(QDataStream& in);

signals:

public slots:

private:
    static int nextId;
    int m_id;
};

QDataStream& operator <<(QDataStream& out, const Camera& camera);
QDataStream& operator >>(QDataStream& in, Camera& camera);

QDataStream& operator <<(QDataStream& out, const QList<Camera*>& cameraList);
QDataStream& operator >>(QDataStream& in, QList<Camera*>& cameraList);

#endif // CAMERA_H
