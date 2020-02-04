#include "mainwindow.h"
#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTreeWidget twg;
    QStringList lst;

    lst << "Folders" <<"Used Space";
    twg.setHeaderLabels(lst);
    twg.setSortingEnabled(true);
 /* We will watch memory of directories in disk "C" */
    QTreeWidgetItem* ptwgItem = new QTreeWidgetItem(&twg);
    ptwgItem->setText(0,"Local Disk(C)");
    ptwgItem->setIcon(0,QPixmap(":/drive.bmp"));

    QTreeWidgetItem* ptwgItemDir = 0;
    for (int i =1; i <20; ++i)
    {
        ptwgItemDir = new QTreeWidgetItem(ptwgItem);
        ptwgItemDir->setText(0, "Directory"+QString::number(i));
        ptwgItemDir->setText(1,QString::number(i) + "MB");
        ptwgItemDir->setIcon(0 , QPixmap(":/folder.bmp"));
    }

  /*Set size for main window */
  ptwgItem->setExpanded(true);
  twg.resize(350,310);
  twg.show();

  return a.exec();


  /*
    MainWindow w;
    w.show();
    return a.exec();
    */
}
