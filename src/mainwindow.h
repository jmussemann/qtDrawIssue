#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QTimer>
#include <QShortcut>
#include <QTextBrowser>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:


private:
    Ui::MainWindow *ui;
    QTimer *m_timer;
    double m_renderTimeHTML;

    QDateTime m_appStartTime;
protected slots:

   void update();
   void rateChanged(bool);
};
#endif
