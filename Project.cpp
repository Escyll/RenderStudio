#include "Project.h"

#include <QDataStream>
#include <QDebug>
#include <QFile>

Project::Project(QObject *parent)
    : QObject(parent)
    , m_activeCamera(nullptr)
    , m_hasUnsavedData(false)
{
    connect(&m_renderSettings, &RenderSettings::antiAliasingChanged, this, [this] { setHasUnsavedData(false); });
}

QList<Camera*> Project::cameras() const
{
    return m_cameras;
}

void Project::addCamera(Camera* camera)
{
    m_cameras.append(camera);
    camera->setParent(this);
    emit camerasChanged();
}

Camera* Project::activeCamera() const
{
    return m_activeCamera;
}

void Project::setActiveCamera(Camera* activeCamera)
{
    m_activeCamera = activeCamera;
}

RenderSettings* Project::renderSettings()
{
    return &m_renderSettings;
}

bool Project::hasUnsavedData() const
{
    return m_hasUnsavedData;
}

void Project::saveToDataStream(QDataStream& out) const
{
    out << m_cameras;
    out << static_cast<qint64>(m_activeCamera ? m_activeCamera->id() : 0);
    out << m_renderSettings;
}

void Project::readFromDataStream(QDataStream& in)
{
    in >> m_cameras;
    emit camerasChanged();
    qint64 activeCamera;
    in >> activeCamera;
    foreach (auto camera, m_cameras) {
        if (camera->id() == activeCamera)
        {
            m_activeCamera = camera;
            emit activeCameraChanged();
        }
    }
    in >> m_renderSettings;
    emit renderSettingsChanged();
}

void Project::setHasUnsavedData(bool hasUnsavedData)
{
    m_hasUnsavedData = hasUnsavedData;
    emit hasUnsavedDataChanged();
}

QDataStream& operator <<(QDataStream& out, const Project& project)
{
    project.saveToDataStream(out);
    return out;
}

QDataStream& operator >>(QDataStream& in, Project& project)
{
    project.readFromDataStream(in);
    return in;
}
