#ifndef PROJECT_H
#define PROJECT_H

#include "Camera.h"
#include "RenderSettings.h"

#include <QObject>
#include <QList>

class Project : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Camera* activeCamera READ activeCamera WRITE setActiveCamera NOTIFY activeCameraChanged)
    Q_PROPERTY(QList<Camera*> cameras READ cameras NOTIFY camerasChanged)
    Q_PROPERTY(RenderSettings* renderSettings READ renderSettings CONSTANT)
    Q_PROPERTY(bool hasUnsavedData READ hasUnsavedData NOTIFY hasUnsavedDataChanged)
public:
    explicit Project(QObject *parent = nullptr);

    QList<Camera*> cameras() const;
    Q_INVOKABLE void addCamera(Camera* camera);

    Camera* activeCamera() const;
    void setActiveCamera(Camera* activeCamera);

    RenderSettings* renderSettings();
    bool hasUnsavedData() const;

    void saveToDataStream(QDataStream& out) const;
    void readFromDataStream(QDataStream& in);

signals:
    void activeCameraChanged();
    void camerasChanged();
    void renderSettingsChanged();
    void hasUnsavedDataChanged();

private:
    QList<Camera*> m_cameras;
    Camera* m_activeCamera;
    RenderSettings m_renderSettings;
    bool m_hasUnsavedData;

    void setHasUnsavedData(bool hasUnsavedData);
};

QDataStream& operator <<(QDataStream& out, const Project& project);
QDataStream& operator >>(QDataStream& out, Project& project);

#endif // PROJECT_H
