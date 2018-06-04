#include "ApplicationService.h"
#include "RenderService.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif    
    QGuiApplication app(argc, argv);    
    QQuickStyle::setStyle("Material");

    RenderService renderService;
    ApplicationService applicationService;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("renderService", &renderService);
    engine.rootContext()->setContextProperty("applicationService", &applicationService);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
