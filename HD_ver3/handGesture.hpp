﻿#ifndef _HAND_GESTURE_
#define _HAND_GESTURE_ 

#include <opencv2/imgproc/imgproc.hpp>
#include<opencv2/opencv.hpp>
#include <vector>
#include <string>
#include "main.hpp"
#include "myImage.hpp"

using namespace cv;
using namespace std;

class HandGesture{
	MyImage m;
	vector<Point> contours;
	vector<int> hullI;
	vector<Point> hullP;
	vector<Vec4i> defects;
	Rect bRect;
	int frameNumber;
	
	int mostFrequentFingerNumber;
	int nrOfDefects;

	double bRect_width;
	double bRect_height;
	bool detectIfHand();
	
	void initVectors();
	void getFingerNumber(MyImage *m);//
	void eleminateDefects();
	string bool2string(bool tf);//
	int fontFace;//
	void checkForOneFinger(MyImage *m);//
	float getAngle(Point s, Point f, Point e);//
	vector<int> fingerNumbers;//
	void analyzeContours();//
	string intToString(int number);//
	void computeFingerNumber();//
	vector<int> numbers2Display;//
	void addFingerNumberToVector();//
	Scalar numberColor;//
	int nrNoFinger;///
	float distanceP2P(Point a, Point b);
	void removeRedundantEndPoints(vector<Vec4i> newDefects);
	void removeRedundantFingerTips();
public: 
	HandGesture();
	vector<Point> fingerTips; //vector toa do diem dau ngon tay
	/*HandGesture(MyImage *msrc,vector<Point> contourShape, vector<int> hullInt, vector<Point> hullPoint,
		vector<Vec4i> defectShape, Rect bRectShape, int frNumber);*/
	void setHandGesture(MyImage *msrc, vector<Point> contourShape, vector<int> hullInt, vector<Point> hullPoint,
		vector<Vec4i> defectShape, Rect bRectShape, int frNumber);
	bool isHand;
	vector<Point> getFingerTips(MyImage *m);

};

#endif
