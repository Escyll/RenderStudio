#include "Camera.h"

#include <QDataStream>

int Camera::nextId = 0;

Camera::Camera(QObject *parent) : QObject(parent)
{

}

int Camera::id() const
{
    return m_id;
}

void Camera::saveToDataStream(QDataStream& out) const
{
    qint64 id = m_id;
    out << id;
}

void Camera::readFromDataStream(QDataStream& in)
{
    qint64 id;
    in >> id;
    m_id = static_cast<int>(id);
}

QDataStream& operator <<(QDataStream& out, const Camera& camera)
{
    camera.saveToDataStream(out);
    return out;
}

QDataStream& operator >>(QDataStream& in, Camera& camera)
{
    camera.readFromDataStream(in);
    return in;
}

QDataStream& operator <<(QDataStream&out, const QList<Camera*>& cameraList)
{
    out << static_cast<qint64>(cameraList.count());
    foreach (auto camera, cameraList) {
        out << camera;
    }
    return out;
}

QDataStream& operator >>(QDataStream&in, QList<Camera*>& cameraList)
{
    qint64 count;
    in >> count;
    for (auto i = 0; i < count; i++)
    {
        auto camera = new Camera;
        in >> *camera;
    }
    return in;
}
