//
//  FaceDetector.hpp
//  opencv-osx
//
//  Created by Giovanni Murru on 03/02/2017.
//  Copyright © 2017 Giovanni Murru. All rights reserved.
//

#ifndef FaceDetector_hpp
#define FaceDetector_hpp

#import <opencv2/opencv.hpp>
#import <opencv2/video.hpp>
#import <opencv2/objdetect.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <stdio.h>

namespace gm
{

class FaceDetector
{
public:
    FaceDetector(std::string _detector_path);
    void executeVideoCapture();
    void processImage(cv::Mat &_image);
    
    std::shared_ptr<cv::CascadeClassifier> m_cascade;
};
}

#endif /* FaceDetector_hpp */
