#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QtGui>
//#include<webcam.h>
#include<stdio.h>
#include<iostream>
#include<QMessageBox>
#include<process.h>
#include<stdlib.h>
using namespace std;
using namespace cv;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   int dev=0,fps=25;
   timerId = 0;flag=1;
   frameRate = fps;
   capture = cvCaptureFromCAM(0);
   //capture = cvCaptureFromCAM(0);
   cvSetCaptureProperty(capture,
   CV_CAP_PROP_FRAME_WIDTH, 500);
   cvSetCaptureProperty(capture,
   CV_CAP_PROP_FRAME_HEIGHT, 300);

   currentFrame = cvQueryFrame(capture);

         //Size of the image.


         //Images to use in the program.


  size = cvSize(
                        (int)cvGetCaptureProperty( capture,
                                                  CV_CAP_PROP_FRAME_WIDTH),
                        (int)cvGetCaptureProperty( capture,
                                                  CV_CAP_PROP_FRAME_HEIGHT)
                        );
   currentFrame_grey = cvCreateImage( size, IPL_DEPTH_8U, 1);
   writer=cvCreateVideoWriter("d:\\record.avi",CV_FOURCC('X','2','6','4'),frameRate,size);




}

void MainWindow::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::WindowStateChange) {
        if(isActiveWindow()    ) {
           /* this->hide();
            event->ignore();*/

            if(fhide==0)
                fhide=1;
            else
                fhide=0;
        }

    }
}

MainWindow::~MainWindow()
{
    delete ui;
    cvReleaseVideoWriter( &writer );
    cvReleaseCapture(&capture);
    cvReleaseImage(&oldFrame_grey);
           cvReleaseImage(&differenceImg);
           cvReleaseImage(&differenceImg2);
           cvReleaseImage(&currentFrame);
           cvReleaseImage(&currentFrame_grey);
           //cvReleaseCapture(&cam);

}

void MainWindow::showEvent(QShowEvent *event)
{
   /* QMessageBox mb;
mb.setVisible(false);

    mb.exec();*/
nframes = 0; // init
timerId = startTimer(1000 / frameRate); // in msec
time.start(); // start time
}
void MainWindow::hideEvent(QHideEvent *event)
{
killTimer(timerId);

}

void MainWindow::timerEvent(QTimerEvent *event)
{
    int cnt1,cnt2=0;
    cnt1=10000; f=1;
    storage=cvCreateMemStorage(0);
if (event->timerId() == timerId && flag==1 )
{

/*IplImage* gray = cvQueryFrame(capture);
IplImage *frame = cvCreateImage(cvGetSize(gray),IPL_DEPTH_8U,1);*/
    currentFrame=cvQueryFrame(capture);
   /* currentFrame1=cvCreateImage(cvSize(100,100),currentFrame->depth,currentFrame->nChannels);

     cvResize(currentFrame,currentFrame1,CV_INTER_LINEAR);*/

cvCvtColor(currentFrame,currentFrame_grey,CV_RGB2GRAY);

        //Mat m=cvarrToMat(frame);

        if(first) //Capturing Background for the first time
             {
                    differenceImg = cvCloneImage(currentFrame_grey);
                    oldFrame_grey = cvCloneImage(currentFrame_grey);
                    cvConvertScale(currentFrame_grey, oldFrame_grey, 1.0, 0.0);
                    first = false;

             }
        if(!first){
             //Minus the current frame from the moving average.
             cvAbsDiff(oldFrame_grey,currentFrame_grey,differenceImg);

             //bluring the differnece image
             cvSmooth(differenceImg, differenceImg, CV_BLUR);


    cvThreshold(differenceImg,differenceImg,10,250,CV_THRESH_BINARY);

       differenceImg2=cvCreateImage(cvSize(100,100),differenceImg->depth,differenceImg->nChannels);
    cvResize(differenceImg,differenceImg2,CV_INTER_LINEAR);
   int cntcurr1=0,cntcurr2=0; cn++;
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {

            if(differenceImg2->imageData[differenceImg2->widthStep * i + j * 3]==0 && differenceImg2->imageData[differenceImg2->widthStep * i + j * 3+1]==0 && differenceImg2->imageData[differenceImg2->widthStep * i + j * 3+2]==0)
            {
               cnt2++;


            }

        }

    }






    if(f3!=0)
    {
     f3++;
    }
    if(f3==3)
    {
    f3=0;
    }
    if(f4!=0)
    {
     f4++;
    }
    if(f4==4)
    {
    f4=0;
    }
//cout<<fhide<<endl;
    //Hand gesture slide


    if(fsl==1)
    {
       /* if(cnt5>9990 && f4==0)
        {
            if(key==0)
            {
                key=1;

            }
            else
                key=0;
        }*/






          if(cnt2<1500 && f3==0)
          {
              f3++;
              cout<<"  "<<cnt6<<"  --->------>-------------------->>>>>>"<<endl;
              INPUT ip;

              // Pause for 5 seconds.


              // Set up a generic keyboard event.
              ip.type = INPUT_KEYBOARD;
              ip.ki.wScan = 0; // hardware scan code for key
              ip.ki.time = 0;
              ip.ki.dwExtraInfo = 0;

              // Press the "A" key

             //keycode for left control
              if(key==1)
                  ip.ki.wVk = 0x27;
              else
                  ip.ki.wVk = 0x25;

              ip.ki.dwFlags = 0; // 0 for key press
              SendInput(1, &ip, sizeof(INPUT));

              // Release the "A" key
              ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
              SendInput(1, &ip, sizeof(INPUT));

             // cnt5=0;
          }



    }


//end hand gesture slide













    if(cnt2>9985){
        f=0;rec=0;f2=1;
        ui->stataslbl->setText("Paused");
    }
    else{
        ui->stataslbl->setText("started");
rec=1;
    }





    //play & pause video
         if(cnt2>=9900 && fpp==1 && fhide==1 && pbtn==1)
         {

             fpp=0;
             INPUT ip;
             cout<<"pause"<<endl;
             // Pause for 5 seconds.


             // Set up a generic keyboard event.
             ip.type = INPUT_KEYBOARD;
             ip.ki.wScan = 0; // hardware scan code for key
             ip.ki.time = 0;
             ip.ki.dwExtraInfo = 0;

             // Press the "A" key

                 ip.ki.wVk = 0x20;

             ip .ki.dwFlags = 0; // 0 for key press
             SendInput(1, &ip, sizeof(INPUT));

             // Release the "A" key
             ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
             SendInput(1, &ip, sizeof(INPUT));
         }

             if(fpp==0 && cnt2<9000 && fhide==1 && pbtn==1)
             {
                 fpp=1;
                 cout<<"play"<<endl;
                 INPUT ip;

                 // Pause for 5 seconds.


                 // Set up a generic keyboard event.
                 ip.type = INPUT_KEYBOARD;
                 ip.ki.wScan = 0; // hardware scan code for key
                 ip.ki.time = 0;
                 ip.ki.dwExtraInfo = 0;

                 // Press the "A" key

                     ip.ki.wVk = 0x20;

                 ip.ki.dwFlags = 0; // 0 for key press
                 SendInput(1, &ip, sizeof(INPUT));

                 // Release the "A" key
                 ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
                 SendInput(1, &ip, sizeof(INPUT));
             }


    //end pause play video








    cvFindContours( differenceImg, storage, &contours,sizeof(CvContour),CV_RETR_LIST,CV_CHAIN_APPROX_SIMPLE,cvPoint(0,0) );
CvSeq* circles=cvHoughCircles(differenceImg,storage,CV_HOUGH_GRADIENT,4,1,100,20,1,10);






for (int i = 0; i < circles->total; i++) {
       float *p = (float*)cvGetSeqElem(circles, i);
       CvPoint center = cvPoint(cvRound(p[0]),cvRound(p[1]));
       CvScalar val = cvGet2D(differenceImg, center.y, center.x);
       if (val.val[0] < 1) continue;
       //cvCircle(currentFrame,  center, cvRound(p[2]),             CV_RGB(0,255,0), 1, CV_AA, 0);
        cvCircle(currentFrame,  center, 2,             CV_RGB(0,255,0), 1, CV_AA, 0);


    }



/*


       for(; contours!=0; contours = contours->h_next)
             {
                    rect = cvBoundingRect(contours, 0); //extract bounding box for current contour

                    //drawing rectangle
                   // cout<<"     "<<rect.height<<"   "<<rect.width<<endl;
                    if(rect.width>25 && rect.height>25){
                    cvRectangle(currentFrame,
                                 cvPoint(rect.x, rect.y),
                                 cvPoint(rect.x+rect.width, rect.y+rect.height),
                                 cvScalar(0, 0, 255, 0),
                                 1, 8, 0);
                    }

             }

*/
if(f==1)
{

    if(rec==1 && recflag==1)
    {

     QDateTime dateTime = QDateTime::currentDateTime();
         QString dateTimeString = dateTime.toString();
         QByteArray ba=dateTimeString.toLocal8Bit();
cvCircle(currentFrame,cvPoint(250,28),1,cvScalar(0,0,255,0),2);
cvCircle(currentFrame,cvPoint(250,28),3,cvScalar(0,0,0,0),1);
     CvFont font;
     cvInitFont(&font, CV_FONT_HERSHEY_DUPLEX, 0.2,0.3);

     cvPutText(currentFrame,ba.data(),cvPoint(130,30),&font,cvScalar(0,80,255,150));
      ui->recordlbl->setText("Recording...");
     cvWriteFrame(writer, currentFrame );
    }

QImage image = IplImage2QImage(currentFrame); // convert
pixmap = QPixmap::fromImage(image); // convert
ui->scrn->setPixmap(pixmap);
}
else
    if(f2==1 && f==0)
    {
        ui->recordlbl->setText("");
        CvFont font1;
        cvInitFont(&font1, CV_FONT_HERSHEY_COMPLEX, 0.6,0.7);
        cvPutText(currentFrame,"No Motion Detected",cvPoint(30,90),&font1,cvScalar(240,240,240,150));
        QImage image = IplImage2QImage(currentFrame); // convert
        pixmap = QPixmap::fromImage(image); // convert
        ui->scrn->setPixmap(pixmap);
        f2=0;

    }

cvConvertScale(currentFrame_grey, oldFrame_grey, 1.0, 0.0);

             //clear memory and contours
            // cvClearMemStorage( storage );
           //  contours = 0;

             //press Esc to exit
    }


//repaint(); // immediate repaint
if (++nframes == 50)
{
qDebug("frame rate: %f", // actual frame rate
(float) nframes * 1000 / time.elapsed());
nframes = 0;
time.restart();
}
}
else
QWidget::timerEvent(event);
}

void MainWindow::paintEvent(QPaintEvent *event)
{/*
QRectF rect = QRectF(QPoint(), size());
QPainter painter(this);
painter.drawPixmap(rect, pixmap, rect);*/
}

QImage MainWindow::IplImage2QImage(const IplImage *iplImage)
{
int height = iplImage->height;
int width = iplImage->width;
if(iplImage->depth == IPL_DEPTH_8U &&
iplImage->nChannels == 3) // colour image
{
const uchar *qImageBuffer =
(const uchar*) iplImage->imageData;
QImage img(qImageBuffer, width, height,
QImage::Format_RGB888);
return img.rgbSwapped();
}
else if(iplImage->depth == IPL_DEPTH_8U &&
iplImage->nChannels == 1) // gray image
    {
    const uchar *qImageBuffer =
    (const uchar*) iplImage->imageData;
    QImage img(qImageBuffer, width, height,
    QImage::Format_Indexed8);
    QVector<QRgb> colorTable; // set up colour table
    for (int i = 0; i < 256; i++)
    colorTable.append(qRgb(i, i, i));
    img.setColorTable(colorTable);
    return img;
}
else
{
    qWarning() << "Image cannot be converted.";
    return QImage();
}
}


void MainWindow::on_playbtn_clicked()
{
    if(flag==1 && recflag==1)
    {
        flag=1;
        recflag=0;
       ui->recordlbl->setText("");
        ui->playbtn->setText("Resume");
    }
    else
    {
        flag=1;
        recflag=1;
        ui->recordlbl->setText("Recording...");
        ui->playbtn->setText("stop");
    }

}








void MainWindow::on_slchk_clicked()
{

    if(fsl==0){
        fsl=1;
        ui->rradio->setCheckable(true);
        ui->lradio->setCheckable(true);
        ui->lradio->setChecked(true);
        ui->sllbl->setText("Hand Gesture Sliding Started...");
    }
        else{
        fsl=0;
ui->lradio->setCheckable(false);
        ui->rradio->setCheckable(false);
        ui->sllbl->setText("");


    }
}

void MainWindow::on_pausechk_clicked()
{
    if(pbtn==0){
        pbtn=1;
        ui->minlbl->setText("Auto Pause Video Started...\nNote: Please minimize this window \notherwise auto play will not work");
    }
    else{
        pbtn=0;
        ui->minlbl->setText("");
    }

}

void MainWindow::on_lradio_clicked()
{
   key=1;
}

void MainWindow::on_rradio_clicked()
{
    key=0;
}
