#include "mainwindow.h"
#include <QFile>
#include <QDateTime>
#include <QApplication>

void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {

    QFile logFile("logfile.txt");
    if (logFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&logFile);
        QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

        switch (type) {
        case QtDebugMsg:    stream << "DEBUG "; break;
        case QtInfoMsg:     stream << "INFO  "; break;
        case QtWarningMsg:  stream << "WARN  "; break;
        case QtCriticalMsg: stream << "CRIT  "; break;
        case QtFatalMsg:    stream << "FATAL "; break;
        }

        stream << "[" << time << "] " << msg
               << " (File: " << context.file << ", Line: " << context.line << ")" << Qt::endl;
        logFile.close();
    }
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler(messageHandler);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
