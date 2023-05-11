#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>
#include <QDebug>
#include <QMessageBox>
using namespace std;
#include <QMessageBox>
#include <iostream>
#include <vector>


bool binarySearch(int array[], int left, int right, int x)
{

    while (left <= right) {
        int temp = left + (right - left) / 2;
        if (array[temp] == x)
        {
        return true;
        }
        if (array[temp] < x)
        {
            left = temp + 1;
        }
        else
        right = temp - 1;
    }
    return false;
}


void showMessage(QString message, QWidget *parent = nullptr)
{
    QMessageBox::information(parent, "Message", message);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BinarySearch_clicked()
{

}


void MainWindow::on_GenerateData_clicked()
{
  ui->listWidget->clear();
  int size=0;
  if(ui->textEdit_2->toPlainText().toInt()>=0)
  {
    size=ui->textEdit_2->toPlainText().toInt();
  }
  else
  {
      showMessage("enter a number greater than 0 please");
  }
  ui->label->setText("The Dataset size is: "+QString::number(size));
    array=new int[size];
    srand(time(0));
    for(int i=0;i<size;i++)
    {
        array[i]=rand()%1001;
        ui->listWidget->addItem(QString::number(array[i]));
    }
}
void MainWindow::on_MergeSort_clicked()
{
    sorted=true;
    ui->label_2->setText("Sorting using Merge Sort");
    int size=ui->textEdit_2->toPlainText().toInt();
 mergearray=new int[size];
ui->listWidget->clear();
ui->listWidget->addItem("merge sort");
for(int i=0;i<size;i++)
{
    mergearray[i]=array[i];
}
    std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
    mergeSort(mergearray,0,size-1);
    std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
   sorttime=duration.count();
    for(int i=0;i<size;i++)
    {
     QListWidgetItem* item = new QListWidgetItem();
     item->setText(QString::number(mergearray[i]));
     ui->listWidget->addItem(item);
    }
}


void MainWindow::on_STLSort_clicked()
{
    sorted=true;
    ui->label_2->setText("Sorting using STL Sort");
    int size=ui->textEdit_2->toPlainText().toInt();

    stlarray=new int[size];
    for(int i=0;i<size;i++)
    {
        stlarray[i]=array[i];
    }
    std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
    std::sort(stlarray,stlarray+size);
    std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
   sorttime=duration.count();
   ui->listWidget->clear();
   ui->listWidget->addItem("STL sort");
 for(int i=0;i<size;i++)
 {
     QListWidgetItem* item = new QListWidgetItem();
    item->setText(QString::number(stlarray[i]));
     ui->listWidget->addItem(item);
 }

}

void MainWindow::on_pushButton_clicked()
{
    ui->label_3->setText("Using: Normal Search...");
    choice=true;
    //normal
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->label_3->setText("Using: Binary Search...");
    choice=false;
    //binary
}

bool normalsearch(int *array,int size,int find)
{
    for(int i =0;i<size;i++)
    {
        if(array[i]==find)
            return true;
    }
    return false;
}
void MainWindow::on_pushButton_6_clicked()
{
    int find=ui->textEdit->toPlainText().toInt();
    int size=ui->textEdit_2->toPlainText().toInt();
    if(ui->textEdit->toPlainText()=="")
    {
        showMessage("enter a number to search for");

    }
    else
    {

bool check;
    if (choice)
    {

          std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
          check=normalsearch(mergearray,size,find);
           std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();
           std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);


        if(check)
        {
          showMessage("number found after using normal search, time taken: "+QString::number(duration.count())+" nanoseconds and sort time: "+QString::number(sorttime));
        }
        else
        {
            showMessage("not found after using normal search"+QString::number(duration.count())+" nanoseconds and sort time: "+QString::number(sorttime));
        }
    }

    else
    {

        std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
          check=binarySearch(mergearray,0,size-1,find);
           std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();
           std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
        if(check)
        {
          showMessage("number found after using binary search , time taken:"+QString::number(duration.count())+" nanoseconds and sort time: "+QString::number(sorttime));
        }
        else
        {
            showMessage("not found after using binary search, time taken:"+QString::number(duration.count())+" nanoseconds and sort time: "+QString::number(sorttime));
        }

    }
    }
}

