#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QWidget>
#include <QTime>
#include <opencv2/core/core_c.h>
#include <opencv2/highgui/highgui_c.h>

#include<opencv2/opencv.hpp>
#include<opencv/cv.h>
#include<opencv/highgui.h>
#include<QDateTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);
    void timerEvent(QTimerEvent *event);
    void paintEvent(QPaintEvent *event);
private slots:


    void on_playbtn_clicked();


void changeEvent(QEvent *event);


    void on_slchk_clicked();

    void on_pausechk_clicked();

    void on_lradio_clicked();

    void on_rradio_clicked();

private:
    Ui::MainWindow *ui;
    CvCapture* capture;
    int timerId;
int key=1,f3=0,f4=0;
    int saveicr=1;
    int flag=1,f=1,f2=0;
int rec=0;
int pbtn=0;
int fpp=1;
int fsl=0;
int fhide=0;
   // int b[150][150],g[150][150],r[150][150];
    int cnt3=0,cnt4=0,cnt5=0,cnt6=0;
    int frameRate; // input frame rate
    QPixmap pixmap;
    int nframes=0; // used to calculate actual frame rate
    QTime time; // used to calculate actual frame rate
    // convert image format
    QImage IplImage2QImage(const IplImage *iplImage);
    CvVideoWriter *writer;
CvSize size;
bool first=true;
IplImage *currentFrame, *currentFrame_grey, *differenceImg, *oldFrame_grey,*currentFrame1;
  IplImage* differenceImg2;
CvRect rect;
CvSeq* contours = 0;
CvMemStorage* storage = NULL;
int recflag=0;
int cn=0;
};
#endif // MAINWINDOW_H
