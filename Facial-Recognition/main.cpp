#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core.hpp>

#include <iostream>
#include <vector>

int main()
{
    cv::CascadeClassifier recognition;

    cv::Mat frame;
    cv::VideoCapture capture;

    recognition.load("haarcascade_frontalface_default.xml");
    capture.open(0, cv::CAP_ANY);

    while (true)
    {
        capture.read(frame);

        std::vector<cv::Rect> faces;
        recognition.detectMultiScale(frame, faces, 1.3, 5);

        for (int i = 0; i < faces.size(); i++) { cv::rectangle(frame, faces[i].tl(), faces[i].br(), cv::Scalar(255, 255, 255), 2); }

        cv::imshow("Facial Recognition", frame);
        cv::waitKey(1);
    }

    return 0;
}
