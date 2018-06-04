#ifndef APPLICATIONSERVICE_H
#define APPLICATIONSERVICE_H

#include "Project.h"

#include <QObject>

class ApplicationService : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Project* project READ project NOTIFY projectChanged)
public:
    explicit ApplicationService(QObject *parent = nullptr);

    Project* project() const;

signals:
    void projectChanged();
    void promptSaveDialog();

public slots:
    void newProject();
    void loadProject(const QString& fileName);
    void saveProject(const QString& fileName);
    void closeProject();

private:
    QScopedPointer<Project> m_project;
};

#endif // APPLICATIONSERVICE_H
