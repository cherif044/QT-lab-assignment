#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <algorithm>
#include <QMainWindow>
#include <utility>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int *array=NULL;
    bool sorted=false;;
    int partition ( int a[] , int start,int end)
    {

        int pivot = a[end];
        int pIndex = start;
        for (int i= start; i<end;i++)
        {
            if (a[i]< pivot)
            {
                std::swap(a[i], a[pIndex]);
                pIndex++;
            }
        }
        std::swap (a[pIndex],a[end]);
        return pIndex;
    }
    bool choice;
    int *mergearray,*stlarray;
    double sorttime;
    void mergeSort(int arr[], int start, int end) {
      if (start< end) {

        int m = (start+ end) / 2;


        mergeSort(arr, start, m);
        mergeSort(arr, m + 1, end);


        merge(arr, start, m, end);
      }
    }
    void merge(int arr[], int start, int m, int end) {
      int i = start;
      int j = m + 1;
      int k = start;


      int *temp=new int[end+1];

      while (i <= m && j <= end) {
        if (arr[i] <= arr[j]) {
          temp[k] = arr[i];
          i++;
          k++;
        } else {
          temp[k] = arr[j];
          j++;
          k++;
        }

      }


      while (i <= m) {
        temp[k] = arr[i];
        i++;
        k++;

      }

      while (j <= end) {
        temp[k] = arr[j];
        j++;
        k++;
      }

      /* Copy the temp array to original array */
      for (int p = start; p <= end; p++) {
        arr[p] = temp[p];
      }
    }

private slots:
    void on_BinarySearch_clicked();

    void on_GenerateData_clicked();

    void on_MergeSort_clicked();


    void on_STLSort_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
