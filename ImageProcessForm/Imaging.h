#pragma once
#include <windows.h>
BYTE* Frame(BYTE* image, int w, int h);
BYTE* Gradient_Magnitude(BYTE* vertical_image, BYTE* horizontal_image, int w, int h);
double* Edge_Degrees(BYTE* vertical_image, BYTE* horizontal_image, int w, int h);
BYTE* Non_Max_Suppression(BYTE* gradient_magnitude,double* edge_degrees, int w, int h);
BYTE* Double_Threshold(BYTE* n_m_suppression, int w, int h);
BYTE* Canny_Image(BYTE* double_threshold, int w, int h);
BYTE* Hough_Transform(BYTE* canny_image, double* edge_degrees, int w, int h);
BYTE* Labeling(BYTE* image, int w, int h);
BYTE* K_Means(BYTE* image, int* hist, int w, int h);
BYTE* Dilation(BYTE* image, int w, int h);
BYTE* Erosion(BYTE* image, int w, int h);
int* Histogram(BYTE* image, int w, int h);
BYTE* Reverse(BYTE* image, int w, int h);
BYTE* Not(BYTE* image, int w, int h);
BYTE* Convolution(BYTE* zoom, int w, int h, double *mask, int mask_size);
BYTE* Zoom(BYTE* cutted, int w, int h);
BYTE* Cut(BYTE* image, int w, int h, int x1, int y1, int x4, int y4);
BYTE* Draw_Line(BYTE* row, int w, int h, int x1, int y1, int x2, int y2);
BYTE* LoadBMP(int% width, int% height, long% size, LPCTSTR bmpfile); 
BYTE* ConvertBMPToIntensity(BYTE* Buffer, int width, int height);
BYTE* ConvertIntensityToBMP(BYTE* Buffer, int width, int height, long% newsize);
bool SaveBMP(BYTE* Buffer, int width, int height, long paddedsize, LPCTSTR bmpfile);
