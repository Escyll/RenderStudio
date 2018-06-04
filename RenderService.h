#ifndef RENDERSERVICE_H
#define RENDERSERVICE_H

#include "Project.h"

#include <QObject>

class RenderService : public QObject
{
    Q_OBJECT
public:
    explicit RenderService(QObject *parent = nullptr);

public slots:
};

#endif // RENDERSERVICE_H
