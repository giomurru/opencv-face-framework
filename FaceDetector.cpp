//
//  FaceDetector.cpp
//  opencv-osx
//
//  Created by Giovanni Murru on 03/02/2017.
//  Copyright © 2017 Giovanni Murru. All rights reserved.
//

#include "FaceDetector.hpp"

#include <stdio.h>

using namespace cv;
using namespace std;

namespace gm
{
    FaceDetector::FaceDetector(std::string _detector_path)
    {
        m_cascade = std::make_shared<cv::CascadeClassifier>();
        m_cascade->load(_detector_path.c_str());
    }

#if !TARGET_OS_IPHONE
    void FaceDetector::executeVideoCapture()
    {
        cv::VideoCapture cap;
        
        cap.open(0);
        
        cap.set(CV_CAP_PROP_FRAME_WIDTH,320);
        cap.set(CV_CAP_PROP_FRAME_HEIGHT,240);
        
        if( !cap.isOpened() )
        {
            std::cerr << "***Could not initialize capturing...***\n";
            std::cerr << "Current parameter's value: \n";
        }
        
        cv::Mat frame;
        while(true)
        {
            cap >> frame;
            if(frame.empty()){
                std::cerr<<"frame is empty"<<std::endl;
                break;
            }
            
            this->processImage(frame);
            
            cv::imshow("", frame);
            cv::waitKey(10);
        }
    }
#endif
    void FaceDetector::processImage(cv::Mat &_image)
    {
        
        
        cvSetErrMode( CV_ErrModeParent );
        
        //(const Mat& img, CV_OUT vector<Rect>& foundLocations,
        //double hitThreshold=0, Size winStride=Size(),
        //Size padding=Size(), double scale=1.05,
        //double finalThreshold=2.0, bool useMeanshiftGrouping = false)
        
        
        int flags = cv::CASCADE_FIND_BIGGEST_OBJECT | cv::CASCADE_DO_ROUGH_SEARCH;
        std::vector<cv::Rect> faces;
        cv::Size minFeatureSize = cv::Size(20, 20);
        Mat gray_image;
        if (_image.channels() > 1)
        {
            cvtColor(_image, gray_image, CV_BGR2GRAY );
        }
        m_cascade->detectMultiScale( gray_image, faces, 1.3, 7, flags, minFeatureSize);
        gray_image.release();
        //    faces   = cvHaarDetectObjects( &tmp_image, _cascade, storage, ( float )1.2, 2, CV_HAAR_DO_CANNY_PRUNING, cvSize( 20, 20 ) );
        
        if (faces.size() > 0)
        {
            for(int i = 0; i < faces.size(); i++ )
            {
                cv::Rect rect = faces[i];
                rectangle(_image, cv::Point(rect.x, rect.y), cv::Point(rect.x+rect.width, rect.y+rect.height), Scalar(0,255,0,255), 4);
            }
        }
    }
}
