<<<<<<< HEAD
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}

#if defined(_MSC_VER)
#include <windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR /*lpCmdLine*/, int /*nCmdShow*/)
{
   return main(__argc,__argv);
}
#endif
=======
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}

#if defined(_MSC_VER)
#include <windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR /*lpCmdLine*/, int /*nCmdShow*/)
{
   return main(__argc,__argv);
}
#endif
>>>>>>> 9d18f777fde0dd673667c4b8b8ed4bff591f7162
