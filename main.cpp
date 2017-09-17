#include <QCoreApplication>
#include <QDebug>

#include "opencv2/opencv.hpp"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    cv::namedWindow("Display window", cv::WINDOW_KEEPRATIO);// Create a window for display,
    for(int i = 0; i < 10; i++)
    {
        qDebug() << "test" << i;
    }

    cv::Mat inputImage = cv::imread("/home/nick/Pictures/ShootingTargets/IMAG0160.jpg");
    if(!inputImage.empty())
    {
        int key = 1;
        while(key != 113)// == press q
        {
            cv::rotate(inputImage, inputImage,1);
            cv::imshow("Display window", inputImage);
            key = cv::waitKey();
        }
    }
    else
        qDebug() << "picture empty";


    return 0;
    return a.exec();
}
