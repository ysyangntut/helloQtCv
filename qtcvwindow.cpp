#include "qtcvwindow.h"
#include "ui_qtcvwindow.h"

#include <QFileDialog>
#include <QImage>
#include <QPixmap>

#include <string>

#include <opencv2/opencv.hpp>

QtCvWindow::QtCvWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtCvWindow)
{
    ui->setupUi(this);

    int cvMajorVer = CV_MAJOR_VERSION;
    int cvMinorVer = CV_MINOR_VERSION;
    char buf[1000];
    snprintf(buf, 1000, "OpenCV ver. %d.%d", cvMajorVer, cvMinorVer);
    this->ui->lbOpencvVersion->setText(cv::getBuildInformation().c_str());
}

QtCvWindow::~QtCvWindow()
{
    delete ui;
}


void QtCvWindow::on_pbSelectFile_clicked()
{
    // declare variables
    QString qfilename;
    std::string filename;
    cv::Mat img;

    // select file
    qfilename = QFileDialog::getOpenFileName();

    // show file path
    if (qfilename.length() >= 1) {
        this->ui->edFile->setText(qfilename);
    }
    return;
}

void QtCvWindow::on_pbShowImg_clicked()
{
    cv::Mat img;
    std::string fname;
    // read file
    if (this->ui->edFile->text().length() >= 1) {
        fname = this->ui->edFile->text().toStdString();
        img = cv::imread(fname, cv::IMREAD_COLOR);
    }

    // show image
    if (img.cols > 0 && img.rows > 0)
    {
        int w, h;
        w = this->ui->lbImg->width();
        h = this->ui->lbImg->height();
        QImage qimg(img.data, img.cols, img.rows, img.step, QImage::Format_BGR888);
        QPixmap qpixmap = QPixmap::fromImage(qimg).scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        this->ui->lbImg->setPixmap(qpixmap);
    }
}
