<<<<<<< HEAD
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenu>
#include <iostream>
#include <sstream>



#define PRINT_DRAW_TIME

MainWindow::MainWindow(QWidget *my_parent) :
    QMainWindow(my_parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   m_timer = new QTimer(this);
   connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));

   connect(ui->radioButton_1,SIGNAL(toggled(bool)),this,SLOT(rateChanged(bool)));
   connect(ui->radioButton_10,SIGNAL(toggled(bool)),this,SLOT(rateChanged(bool)));
   connect(ui->radioButton_100,SIGNAL(toggled(bool)),this,SLOT(rateChanged(bool)));


   m_timer->setInterval(10);
   m_timer->start();

   m_appStartTime = QDateTime::currentDateTime();

   //m_appStartTime.setTime_t(1496076201);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update()
{
   std::stringstream sshtml;

   time_t diff = (QDateTime::currentDateTime().toTime_t()) - m_appStartTime.toTime_t();

   int hours = diff/3600;
   int min = (diff%3600) / 60;
   int sec = diff%60;

   sshtml << "This page is a simple QTextEdit that is being filled with HTML text <BR>";
   sshtml << "This page is redrawn every " << m_timer->interval() << " ms <BR>" ;
   sshtml << "This app has been running for " << hours << " h "<< min << " m " << sec << " s<BR>";

   #ifdef PRINT_DRAW_TIME
   sshtml << "<BR>" << "draw time for HTML " << m_renderTimeHTML << " ms";
   #endif

   #ifdef PRINT_DRAW_TIME
   // get start time
   QDateTime start_time = QDateTime::currentDateTime();
   #endif

   ui->htmlpage1->setHtml(sshtml.str().c_str());

   #ifdef PRINT_DRAW_TIME
   // get the time differance and save differance in ms to display next frame
   m_renderTimeHTML = start_time.msecsTo(QDateTime::currentDateTime());

#endif

}

void MainWindow::rateChanged(bool change)
{

   if(change)
   {
      if(ui->radioButton_1->isChecked() )
         m_timer->setInterval(1000);
      if(ui->radioButton_10->isChecked() )
         m_timer->setInterval(100);
      if(ui->radioButton_100->isChecked() )
         m_timer->setInterval(10);
   }

}
=======
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenu>

#include <sstream>



#define PRINT_DRAW_TIME

MainWindow::MainWindow(QWidget *my_parent) :
    QMainWindow(my_parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   m_timer = new QTimer(this);
   connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));

   connect(ui->radioButton_1,SIGNAL(toggled(bool)),this,SLOT(rateChanged(bool)));
   connect(ui->radioButton_10,SIGNAL(toggled(bool)),this,SLOT(rateChanged(bool)));
   connect(ui->radioButton_100,SIGNAL(toggled(bool)),this,SLOT(rateChanged(bool)));


   m_timer->setInterval(10);
   m_timer->start();

   m_appStartTime = boost::posix_time::microsec_clock::universal_time();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update()
{
   std::stringstream sshtml;
   boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();
   boost::posix_time::time_duration rundiff = now - m_appStartTime;

   sshtml << "This page is a simple QTextEdit that is being filled with HTML text <BR>";
   sshtml << "This page is redrawn every " << m_timer->interval() << " ms <BR>" ;
   sshtml << "This app has been running for " << rundiff << "<BR>";

   #ifdef PRINT_DRAW_TIME
   sshtml << "<BR>" << "draw time for HTML " << m_renderTimeHTML << " ms";
   #endif

   #ifdef PRINT_DRAW_TIME
   // get start time
   boost::posix_time::ptime start_time = boost::posix_time::microsec_clock::universal_time();
   #endif

   ui->htmlpage1->setHtml(sshtml.str().c_str());

   #ifdef PRINT_DRAW_TIME
   // get end time
   boost::posix_time::ptime end_time = boost::posix_time::microsec_clock::universal_time();
   // get the differance
   boost::posix_time::time_duration time_diff = end_time - start_time;
   // save differance in ms to display next frame
   m_renderTimeHTML = double(time_diff.fractional_seconds() / 1000 );

#endif

}

void MainWindow::rateChanged(bool change)
{

   if(change)
   {
      if(ui->radioButton_1->isChecked() )
         m_timer->setInterval(1000);
      if(ui->radioButton_10->isChecked() )
         m_timer->setInterval(100);
      if(ui->radioButton_100->isChecked() )
         m_timer->setInterval(10);
   }

}
>>>>>>> 9d18f777fde0dd673667c4b8b8ed4bff591f7162
