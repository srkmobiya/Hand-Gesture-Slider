#-------------------------------------------------
#
# Project created by QtCreator 2014-03-22T11:40:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HandGesture
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
RC_FILE=icon.rc
INCLUDEPATH  += C:\\opencv\\opencv_bin\\install\\include
LIBS += c://opencv/opencv_bin/lib/libopencv_haartraining_engine.a
LIBS += c://opencv/opencv_bin/lib/libopencv_highgui_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_highgui247.dll.a
LIBS += c://opencv/opencv_bin/lib/libopencv_imgproc_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_imgproc247.dll.a
LIBS += c://opencv/opencv_bin/lib/libopencv_legacy_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_legacy247.dll.a
LIBS += c://opencv/opencv_bin/lib/libopencv_ml_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_ml247.dll.a
LIBS += c://opencv/opencv_bin/lib/libopencv_nonfree_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_nonfree247.dll.a
LIBS += c://opencv/opencv_bin/lib/libopencv_objdetect_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_objdetect247.dll.a
LIBS += c://opencv/opencv_bin/lib/libopencv_ocl_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_ocl247.dll.a
LIBS += c://opencv/opencv_bin/lib/libopencv_perf_calib3d_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_perf_core_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_perf_features2d_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_perf_gpu_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_perf_highgui_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_perf_imgproc_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_perf_nonfree_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_perf_objdetect_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_perf_ocl_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_perf_photo_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_perf_stitching_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_perf_superres_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_perf_video_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_photo_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_photo247.dll.a
LIBS += c://opencv/opencv_bin/lib/libopencv_stitching_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_stitching247.dll.a
LIBS += c://opencv/opencv_bin/lib/libopencv_superres_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_superres247.dll.a
LIBS += c://opencv/opencv_bin/lib/libopencv_test_calib3d_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_test_contrib_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_test_core_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_test_features2d_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_test_flann_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_test_gpu_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_test_highgui_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_test_imgproc_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_test_legacy_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_test_ml_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_test_nonfree_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_test_objdetect_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_test_ocl_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_test_photo_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_test_stitching_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_test_superres_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_test_video_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_ts_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_ts247.a
LIBS += c://opencv/opencv_bin/lib/libopencv_video_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_video247.dll.a
LIBS += c://opencv/opencv_bin/lib/libopencv_videostab_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_videostab247.dll.a
LIBS += c://opencv/opencv_bin/lib/libopencv_calib3d_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_calib3d247.dll.a
LIBS += c://opencv/opencv_bin/lib/libopencv_contrib_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_contrib247.dll.a
LIBS += c://opencv/opencv_bin/lib/libopencv_core_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_core247.dll.a
LIBS += c://opencv/opencv_bin/lib/libopencv_features2d_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_features2d247.dll.a
LIBS += c://opencv/opencv_bin/lib/libopencv_flann_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_flann247.dll.a
LIBS += c://opencv/opencv_bin/lib/libopencv_gpu_pch_dephelp.a
LIBS += c://opencv/opencv_bin/lib/libopencv_gpu247.dll.a
