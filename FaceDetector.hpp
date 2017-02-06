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

namespace gm
{

class FaceDetector
{
public:
    FaceDetector(std::string _detector_path);
#ifdef TARGET_OS_X
    void executeVideoCapture();
#endif
    void processImage(cv::Mat &_image);
    std::shared_ptr<cv::CascadeClassifier> m_cascade;
};
}

#endif /* FaceDetector_hpp */
