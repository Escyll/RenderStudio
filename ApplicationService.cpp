#include "ApplicationService.h"

#include <QDebug>
#include <QFile>
#include <QDataStream>

ApplicationService::ApplicationService(QObject *parent)
    : QObject(parent)
    , m_project(nullptr)
{
}

Project* ApplicationService::project() const
{
    return m_project.data();
}

void ApplicationService::newProject()
{
    qDebug() << "New project";

    if (m_project && m_project->hasUnsavedData())
    {
        emit promptSaveDialog();
    }
    else
    {
        m_project.reset(new Project);
        emit projectChanged();
    }
}

void ApplicationService::loadProject(const QString& fileName)
{
    qDebug() << "Load project";

    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);

    m_project.reset(new Project);

    emit projectChanged();

    in >> *m_project;
    file.close();
}

void ApplicationService::saveProject(const QString& fileName)
{
    qDebug() << "Save project";
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << *m_project;
    file.close();
}

void ApplicationService::closeProject()
{
    qDebug() << "Close project";

    if (m_project && m_project->hasUnsavedData())
    {
        emit promptSaveDialog();
    }
    else
    {
        m_project.reset(nullptr);
        emit projectChanged();
    }
}
