#include <Windows.h>
#include <windows.system.h>
#include "atlstr.h"
#include "Imaging.h"
#include "math.h"

#include <stdlib.h>
#include <time.h>
#include <math.h>

#define pi 3.145

BYTE* Frame(BYTE* image, int w, int h) {
	BYTE* frame_image = new BYTE[(w + 2)*(h + 2)];

	for (int y = 0; y < h + 2; y++) {// Sets the zeros.
		for (int x = 0; x < w + 2; x++) {
			if (y == 0 || y == h + 1)
				frame_image[y*(w + 2) + x] = 0;
			else
				if (x == 0 || x == w + 1)
					frame_image[y*(w + 2) + x] = 0;
				else
					frame_image[y*(w + 2) + x] = image[(y - 1)*w + (x - 1)];
		}
	}

	return frame_image;
}
BYTE* Gradient_Magnitude(BYTE* vertical_image, BYTE* horizontal_image, int w, int h) {
	BYTE* gra_mag = new BYTE[w*h];

	for (int p = 0; p < w*h; p++) // Calculate the Gradiant magnitude 
		gra_mag[p] = sqrt(pow(vertical_image[p], 2) + pow(horizontal_image[p], 2));
	
		return gra_mag;
}
BYTE* Non_Max_Suppression(BYTE* gradient_magnitude, BYTE* vertical_image, BYTE* horizontal_image, int w, int h) {
	BYTE* gra_mag = new BYTE[w*h];
	double* edge_degrees = new double[w*h];

	for (int i = 0; i < w*h; i++)
		gra_mag[i] = gradient_magnitude[i];

	for (int p = 0; p < w*h; p++) // Calculate the Edge degrees
		if (vertical_image[p] != 0) // Zero division error !!!
			edge_degrees[p] = atan(horizontal_image[p] / vertical_image[p]) * 180 / pi; //result * 180 / pi --> Convert radian to degree.
		else
			edge_degrees[p] = 0;

	// Non-max suppression
	for (int y = 1; y < h - 1; y++)
		for (int x = 1; x < w - 1; x++)
			// Angel(0) or Angel(180) --> same direction.
			if ((edge_degrees[y*w + x] >= 0 && edge_degrees[y*w + x] <= 22.5) || (edge_degrees[y*w + x] >= 157.5 && edge_degrees[y*w + x] <= 180))
				if (gradient_magnitude[y*w + x] >= gradient_magnitude[y*w + (x - 1)] && gradient_magnitude[y*w + x] >= gradient_magnitude[y*w + (x + 1)]);
				else
					gra_mag[y*w + x] = BYTE(0);
	// Angel(45) 
			else if ((edge_degrees[y*w + x] > 22.5 && edge_degrees[y*w + x] <= 67.5))
				if (gradient_magnitude[y*w + x] >= gradient_magnitude[(y - 1)*w + (x + 1)] && gradient_magnitude[y*w + x] >= gradient_magnitude[(y + 1)*w + (x - 1)]);
				else
					gra_mag[y*w + x] = BYTE(0);
	// Angel(90) 
			else if ((edge_degrees[y*w + x] > 67.5 && edge_degrees[y*w + x] <= 112.5))
				if (gradient_magnitude[y*w + x] >= gradient_magnitude[(y - 1)*w + x] && gradient_magnitude[y*w + x] >= gradient_magnitude[(y + 1)*w + x]);
				else
					gra_mag[y*w + x] = BYTE(0);
	// Angel(135) 
			else if ((edge_degrees[y*w + x] > 112.5 && edge_degrees[y*w + x] < 157.5))
				if (gradient_magnitude[y*w + x] >= gradient_magnitude[(y - 1)*w + (x - 1)] && gradient_magnitude[y*w + x] >= gradient_magnitude[(y + 1)*w + (x + 1)]);
				else
					gra_mag[y*w + x] = BYTE(0);

	return gra_mag;
}
BYTE* Double_Threshold(BYTE* n_m_suppression, int w, int h) {
	//THRESHOL DA SIKINTI VAR!!!!!!!!!!!!!!! (Sabit deger değiştir.)
	BYTE* d_t = new BYTE[w*h];

	for (int p = 0; p < w*h; p++)
		if (n_m_suppression[p] >= BYTE(25) && n_m_suppression[p] < BYTE(50))
			d_t[p] = BYTE(80);  // Weak
		else if (n_m_suppression[p] >= 50)
			d_t[p] = BYTE(255); // Strong
		else
			d_t[p] = BYTE(0);

	return d_t;
}
BYTE* Canny_Image(BYTE* double_threshold, int w, int h) {
	BYTE* hysteresis = new BYTE[w*h];

	// Hysteresis 
	for (int y = 1; y < h - 1; y++)
		for (int x = 1; x < w - 1; x++)
			if (double_threshold[y*w + x] == BYTE(80))
				for (int i = -1; i < 2; i++)
					for (int j = -1; j < 2; j++) {
						if (double_threshold[(y + i)*w + (x + j)] == BYTE(255)) {
							hysteresis[y*w + x] = BYTE(255);
							break;
						}
						else if (i + j == 2) { // If hasn't any 255 value.
							hysteresis[y*w + x] = BYTE(0);
						}
					}
			else
				hysteresis[y*w + x] = double_threshold[y*w + x];

	return hysteresis;
}

BYTE* Reverse(BYTE* image, int w, int h) {
	BYTE* reverse_image = new BYTE[w*h];
	
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
			reverse_image[y*w + x] = image[(h - 1 - y)*w + (w - 1 - x)];
	
	delete image;
	return reverse_image;
}
BYTE* Labeling(BYTE* image, int w, int	h) {
	int* labeled_image = new int[w*h];
	int small_value, big_value;
	int label = 5;
	int col_min, col_max, row_min, row_max;

	for (int i = 0; i < w*h; i++) {
		if (image[i] != BYTE(0)) {
			labeled_image[i] = 1;
		}
		else{
			labeled_image[i] = 0;
		}
	}
	
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (label == 63) // '?' collision situation. (ASCII --> 63)
				label++;
			if (labeled_image[y*w + x] != 0) {
				if (x == 0 && y == 0)
					labeled_image[y*w + x] = label++;
				else if (y == 0)
					labeled_image[y*w + x] = labeled_image[y*w + (x - 1)];
				else if (x == 0)
					labeled_image[y*w + x] = labeled_image[(y - 1)*w + x];
				else {
					if (labeled_image[(y - 1)*w + x] == '?' || labeled_image[y*w + (x - 1)] == '?') {
						if (labeled_image[(y - 1)*w + x] == '?'&&labeled_image[y*w + (x - 1)] == '?')
							labeled_image[y*w + x] = '?';
						else if (labeled_image[y*w + (x - 1)] == '?'&&labeled_image[(y - 1)*w + x] == 0)
							labeled_image[y*w + x] = '?';
						else if (labeled_image[(y - 1)*w + x] == '?'&&labeled_image[y*w + (x - 1)] == 0)
							labeled_image[y*w + x] = '?';
						else if (labeled_image[y*w + (x - 1)] == '?'&&labeled_image[(y - 1)*w + x] != 0)
							labeled_image[y*w + x] = labeled_image[(y - 1)*w + x];
						else if (labeled_image[(y - 1)*w + x] == '?'&&labeled_image[y*w + (x - 1)] != 0)
							labeled_image[y*w + x] = labeled_image[y*w + (x - 1)];
					}
					else {
						if (labeled_image[y*w + (x - 1)] == 0 && labeled_image[(y - 1)*w + x] == 0)
							labeled_image[y*w + x] = label++;
						else if (labeled_image[y*w + (x - 1)] == 0)
							labeled_image[y*w + x] = labeled_image[(y - 1)*w + x];
						else if (labeled_image[(y - 1)*w + x] == 0)
							labeled_image[y*w + x] = labeled_image[y*w + (x - 1)];
						else if (labeled_image[y*w + (x - 1)] == labeled_image[(y - 1)*w + x])
							labeled_image[y*w + x] = labeled_image[y*w + (x - 1)];
						else if (labeled_image[y*w + (x - 1)] != labeled_image[(y - 1)*w + x])
							labeled_image[y*w + x] = '?';
					}
				}

			}
		}
	}

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (labeled_image[y*w + x] == '?') {
				if (labeled_image[(y - 1)*w + x] < labeled_image[y*w + (x - 1)] && labeled_image[(y - 1)*w + x] != 0) {
					small_value = labeled_image[(y - 1)*w + x];
					big_value   = labeled_image[y*w + (x - 1)];
					labeled_image[y*w + x] = small_value;
					for (int i = 0; i < w*h; i++)
						if (labeled_image[i] == big_value)
							labeled_image[i] = small_value; // Sets the small value.
				}
				else if (labeled_image[y*w + (x - 1)] < labeled_image[(y - 1)*w + x] && labeled_image[y*w + (x - 1)] != 0) {
					small_value = labeled_image[y*w + (x - 1)];
					big_value   = labeled_image[(y - 1)*w + x];
					labeled_image[y*w + x] = small_value;
					for (int i = 0; i < w*h; i++)
						if (labeled_image[i] == big_value)
							labeled_image[i] = small_value;
				}
				else { // Equality status.
					if (labeled_image[y*w + (x - 1)] != 0)
						labeled_image[y*w + x] = labeled_image[y*w + (x - 1)];
					else
						labeled_image[y*w + x] = labeled_image[(y - 1)*w + x];
				}
			}
		}
	}

	for (int l = 5; l <= label; l++) {
		col_min = 10000, col_max = -1, row_min = 10000, row_max = -1; 
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if (labeled_image[y*w + x] == l) {
					if (x < col_min)
						col_min = x;
					else if (x > col_max)
						col_max = x;
					if (y < row_min)
						row_min = y;
					else if (y > row_max)
						row_max = y;
				}
			}
		}

		/*

		(1->row_min)		(2->col_min)				(3->col_max)					(4->row_max)
		-------------		
							-										-
							-										-										--->>> For the all labels.
							-										-
							-										-
																						--------------
		
		*/

		for (int y = row_min; y <= row_max; y++) {
			for (int x = col_min; x <= col_max; x++) {
				if (y == row_min || y == row_max)
					image[y*w + x] = BYTE(100);			// Draws the columns.
				else {
					if (x == col_min || x == col_max)
						image[y*w + x] = BYTE(100);		// Draws the rows.
				}
			}
		}
	}

	for (int i = 0; i < w*h; i++)
		if(image[i]!=BYTE(100))
			image[i] = BYTE(labeled_image[i]);

	
	for (int i = 0; i < w*h; i++)
		if (image[i] == BYTE(0))
			image[i] = BYTE(255); // New Background
	
	return image;
			
}

BYTE* K_Means(BYTE* image, int* hist, int w, int h) {
	float t1, t2, temp_t1, temp_t2;
	float total_numerator[] = { 0,0 };
	float total_demonetor[] = { 0,0 };
	float epsilon = 0.003;
	bool clustered = false;
	int black = 0, white = 0;

	srand(time(NULL));
	t1 = rand() % 255;
	t2 = rand() % 255;

	do {
		for (int p = 0; p < 256; p++) {
			if (fabs(p - t1) < fabs(p - t2)) { 
				total_numerator[0] += p * hist[p];
				total_demonetor[0] += hist[p];
	
			}
			else {
				total_numerator[1] += p * hist[p];
				total_demonetor[1] += hist[p];
			}
		}
	
		temp_t1 = total_numerator[0] / total_demonetor[0];
		temp_t2 = total_numerator[1] / total_demonetor[1];

		if (fabs(t1 - temp_t1) < epsilon && fabs(t2 - temp_t2) < epsilon) {
			clustered = true;
		}
		else {
			t1 = temp_t1;
			t2 = temp_t2;
		}

	} while (clustered != true );

	for (int p = 0; p < w*h; p++)
		if (fabs(image[p] - t1) < fabs(image[p] - t2))
			image[p] = BYTE(255);
		else
			image[p] = BYTE(0);


	for (int i = 0; i < w*h; i++)
		if (image[i] == BYTE(0)) // Object control.
			black++;
		else
			white++;

	for (int i = 0; i < w*h; i++)
		if (white > black) // Background is white.
			if (image[i] == BYTE(0))
				image[i] = BYTE(255); // Objects set to white.
			else
				image[i] = BYTE(0);

	return image;
}

BYTE* Dilation(BYTE* image, int w, int h) {
	BYTE* dilated_image = new BYTE[w*h];
	int mask_value = 0;
	int dilation_mask[9] = { 1,1,1,
							 1,1,1,
							 1,1,1 };

	for (int i = 0; i < w*h; i++) {
		dilated_image[i] = BYTE(0);
		if (image[i] == BYTE(255)) // Because the objects are white.
			image[i] = BYTE(1);
		else
			image[i] = BYTE(0);
	}
	
	for (int a = 0; a < 1; a++) { // Dilation time.
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if (image[y*w + x] == BYTE(1)) {
					mask_value = 0;
					for (int i = -1; i < 2; i++) {
						for (int j = -1; j < 2; j++) {
							if (y + i < 0 || x + j < 0 || y + i >= h || y + i >= w);
							else {
								if (dilation_mask[mask_value] == 1 || image[(y + i)*w + (x + j)] == BYTE(1))
									dilated_image[(y + i)*w + (x + i)] = BYTE(1);
							}
							mask_value++;
						}
					}
				}
			}	
		}
		for (int i = 0; i < w*h; i++)
			image[i] = dilated_image[i];
	}
	
	for (int i = 0; i < w*h; i++)
		if (dilated_image[i] == BYTE(1))
			dilated_image[i] = BYTE(255);
		else
			dilated_image[i] = BYTE(0);

	return dilated_image;
}	
BYTE* Erosion(BYTE* image, int w, int h) {
	BYTE* erosion_image = new BYTE[w*h];
	int count_1 = 0;
	int mask[9] = { 1,1,1,
					1,1,1,
					1,1,1 };

	for (int i = 0; i < 9; i++)
		if (mask[i] == 1)
			count_1++;

	for (int i = 0; i < w*h; i++) {
		if (image[i] == BYTE(255)) // Because the objects are white.
			image[i] = BYTE(1);
		else
			image[i] = BYTE(0);
	}

	int m = 0,cnt=0;
	for (int a = 0; a < 1; a++) { // Erosion time. 
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if (image[y*w + x] == BYTE(1)) {
					m = 0, cnt = 0;
					for (int i = -1; i < 2; i++) {
						for (int j = -1; j < 2; j++) {
							if (y + i < 0 || x + j < 0 || y + i >= h || x + j >= w);
							else {
								if (image[(y + i)*w + (x + j)] == BYTE(1) && mask[m] == 1)
									cnt++;
							}
							m++;
						}
					}
					if (cnt == count_1)
						erosion_image[y*w + x] = BYTE(1);
					else
						erosion_image[y*w + x] = BYTE(0);
				}
				else
					erosion_image[y*w + x] = BYTE(0);
			}
		
		}
		for (int i = 0; i < w*h; i++)
			image[i] = erosion_image[i];
	}
	
	for (int i = 0; i < w*h; i++) {
		if (erosion_image[i] == BYTE(1))
			erosion_image[i] = BYTE(255);
		else
			erosion_image[i] = BYTE(0); 
		}

	return erosion_image;
}
int* Histogram(BYTE* image, int w, int h) {
	int* color_count = new int[256];

	for (int i = 0; i < 256; i++)
		color_count[i] = 0;

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			color_count[image[y*w + x]]++;
		}
	}

	return color_count;
}

BYTE* Not(BYTE* image, int w, int h) {
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			image[y*w + x] = 255 - image[y*w + x];
		}
	}
	return image;
}

BYTE* Convolution(BYTE* image, int w, int h,double* mask,int mask_size) { 
	BYTE* conv_image = new BYTE[(w + (mask_size - 1))*(h + (mask_size - 1))];
	BYTE* new_image = new BYTE[w*h];
	int x, y, i, j;
	double total = 0;
	
	// Set the zeros.
	for (y = 0; y < h + (mask_size - 1); y++) {
		for (x = 0; x < w + (mask_size - 1); x++) {
			if (mask_size / 2 > y || y >= h + (mask_size / 2))
				conv_image[y*(w + (mask_size - 1)) + x] = 0;
			else
				if (mask_size / 2 > x || x >= w + (mask_size / 2))
					conv_image[y*(w + (mask_size - 1)) + x] = 0;
				else
					conv_image[y*(w + (mask_size - 1)) + x] = image[(y - (mask_size / 2))*w + x - (mask_size / 2)];
		}
	}

	// Apply the mask.
	for (y = 0; y < h + (mask_size - 1); y++) {
		for (x = 0; x < w + (mask_size - 1); x++) {
			for (i = 0; i < mask_size; i++) {
				for (j = 0; j < mask_size; j++) {
					total += conv_image[(y + i) * (w + (mask_size - 1)) + (x + j)] * mask[i * mask_size + j]; 
				}
			}
			if (y < h && x < w) {
				new_image[y * w + x] = fabs(total);
				total = 0;
			}
		}
	}

	//delete image;
	delete conv_image;
	return new_image;
}

BYTE* Zoom(BYTE* cutted, int w, int h) {
	BYTE* zoom_image = new BYTE[(2 * w - 1)*(2 * h - 1)];

	// Horizantal
	for (int y_h = 0; y_h < (2 * h - 1); y_h += 2)
		for (int x_h = 0; x_h < (2 * w - 1); x_h++)
			if (x_h % 2 == 0)
				zoom_image[y_h*(2 * w - 1) + x_h] = cutted[(y_h / 2)*w + (x_h / 2)];
			else
				zoom_image[y_h*(2 * w - 1) + x_h] = (cutted[(y_h / 2)*w + (x_h / 2)] + cutted[(y_h / 2)*w + (x_h / 2) + 1]) / 2;;

	// Vertical
	for (int y_v = 1; y_v < (2 * h - 1); y_v += 2)
		for (int x_v = 0; x_v < (2 * w - 1); x_v++)
			zoom_image[y_v*(2 * w - 1) + x_v] = (zoom_image[(y_v - 1)*(2 * w - 1) + x_v] + zoom_image[(y_v + 1)*(2 * w - 1) + x_v]) / 2;

	return zoom_image;
}

BYTE* Cut(BYTE* image, int w, int h, int x1, int y1, int x4, int y4) {
	BYTE* cutted = new BYTE[(x4-x1)*(y4-y1)];
	int row = 0, col = 0;
	if ((x1 > 0 && x1 < w) && (y1 > 0 && y1 < h) && (x4 > 0 && x4 < w) && (y4 > 0 && y4 < h))
		for (int y = y1; y < y4; y++) {
			for (int x = x1; x < x4; x++) {
				cutted[row*(x4 - x1) + col] = image[y*w + x];
				col++;
			}
			col = 0;
			row++;
		}
	else 
		return image;

	return cutted;
}
BYTE* Draw_Line(BYTE* row, int w, int h, int x1, int y1, int x2, int y2) { //50, 70, 200, 300
	int y, b;
	int a;

	if (x1 != x2) {
		a = (y2 - y1) / (x2 - x1); 
	}
	if (x1 > 0 && x1 < w)
		if (x2 > 0 && x2 < w)
			if (y1 > 0 && y1 < h)
				if (y2 > 0 && y2 < h) {
					if (x2 == x1) {
						for (b = y1; b < y2; b++) { // x1==x2
							y = b;	// y=ax+b // a=0
							row[y*w + x1] = 0; 
						}
					}
					else {
						a = 1;	
						b = y1; 
						for (x1; x1 <= x2; x1++) { // x1!=x2
							y = a * x1 + b;
							row[y*w + x1] = 0;
						}
					}
				}
				else {
					return 0;
				}
	return row;
}

BYTE* LoadBMP(int% width, int% height, long% size, LPCTSTR bmpfile)
{
	// declare bitmap structures
	BITMAPFILEHEADER bmpheader;
	BITMAPINFOHEADER bmpinfo;
	// value to be used in ReadFile funcs
	DWORD bytesread;
	// open file to read from
	HANDLE file = CreateFile(bmpfile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);
	if (NULL == file)
		return NULL; // coudn't open file

	// read file header
	if (ReadFile(file, &bmpheader, sizeof(BITMAPFILEHEADER), &bytesread, NULL) == false) {
		CloseHandle(file);
		return NULL;
	}
	//read bitmap info
	if (ReadFile(file, &bmpinfo, sizeof(BITMAPINFOHEADER), &bytesread, NULL) == false) {
		CloseHandle(file);
		return NULL;
	}
	// check if file is actually a bmp
	if (bmpheader.bfType != 'MB') {
		CloseHandle(file);
		return NULL;
	}
	// get image measurements
	width = bmpinfo.biWidth;
	height = abs(bmpinfo.biHeight);

	// check if bmp is uncompressed
	if (bmpinfo.biCompression != BI_RGB) {
		CloseHandle(file);
		return NULL;
	}
	// check if we have 24 bit bmp
	if (bmpinfo.biBitCount != 24) {
		CloseHandle(file);
		return NULL;
	}

	// create buffer to hold the data
	size = bmpheader.bfSize - bmpheader.bfOffBits;
	BYTE* Buffer = new BYTE[size];
	// move file pointer to start of bitmap data
	SetFilePointer(file, bmpheader.bfOffBits, NULL, FILE_BEGIN);
	// read bmp data
	if (ReadFile(file, Buffer, size, &bytesread, NULL) == false) {
		delete[] Buffer;
		CloseHandle(file);
		return NULL;
	}
	// everything successful here: close file and return buffer
	CloseHandle(file);

	return Buffer;
}//LOADPMB

BYTE* ConvertBMPToIntensity(BYTE* Buffer, int width, int height)
{

	// first make sure the parameters are valid
	if ((NULL == Buffer) || (width == 0) || (height == 0))
		return NULL;

	// find the number of padding bytes

	int padding = 0;
	int scanlinebytes = width * 3;
	while ((scanlinebytes + padding) % 4 != 0)     // DWORD = 4 bytes
		padding++;
	// get the padded scanline width
	int psw = scanlinebytes + padding;

	// create new buffer
	BYTE* newbuf = new BYTE[width*height];

	// now we loop trough all bytes of the original buffer, 
	// swap the R and B bytes and the scanlines
	long bufpos = 0;
	long newpos = 0;
	for (int row = 0; row < height; row++)
		for (int column = 0; column < width; column++) {
			newpos = row * width + column;
			bufpos = (height - row - 1) * psw + column * 3;
			newbuf[newpos] = BYTE(0.11*Buffer[bufpos + 2] + 0.59*Buffer[bufpos + 1] + 0.3*Buffer[bufpos]);
		}

	return newbuf;
}//ConvetBMPToIntensity

BYTE* ConvertIntensityToBMP(BYTE* Buffer, int width, int height, long% newsize)
{
	// first make sure the parameters are valid
	if ((NULL == Buffer) || (width == 0) || (height == 0))
		return NULL;

	// now we have to find with how many bytes
	// we have to pad for the next DWORD boundary	

	int padding = 0;
	int scanlinebytes = width * 3;
	while ((scanlinebytes + padding) % 4 != 0)     // DWORD = 4 bytes
		padding++;
	// get the padded scanline width
	int psw = scanlinebytes + padding;
	// we can already store the size of the new padded buffer
	newsize = height * psw;

	// and create new buffer
	BYTE* newbuf = new BYTE[newsize];

	// fill the buffer with zero bytes then we dont have to add
	// extra padding zero bytes later on
	memset(newbuf, 0, newsize);

	// now we loop trough all bytes of the original buffer, 
	// swap the R and B bytes and the scanlines
	long bufpos = 0;
	long newpos = 0;
	for (int row = 0; row < height; row++)
		for (int column = 0; column < width; column++) {
			bufpos = row * width + column;     // position in original buffer
			newpos = (height - row - 1) * psw + column * 3;           // position in padded buffer
			newbuf[newpos] = Buffer[bufpos];       //  blue
			newbuf[newpos + 1] = Buffer[bufpos];   //  green
			newbuf[newpos + 2] = Buffer[bufpos];   //  red
		}

	return newbuf;
} //ConvertIntensityToBMP

bool SaveBMP(BYTE* Buffer, int width, int height, long paddedsize, LPCTSTR bmpfile)
{
	// declare bmp structures 
	BITMAPFILEHEADER bmfh;
	BITMAPINFOHEADER info;

	// andinitialize them to zero
	memset(&bmfh, 0, sizeof(BITMAPFILEHEADER));
	memset(&info, 0, sizeof(BITMAPINFOHEADER));

	// fill the fileheader with data
	bmfh.bfType = 0x4d42;       // 0x4d42 = 'BM'
	bmfh.bfReserved1 = 0;
	bmfh.bfReserved2 = 0;
	bmfh.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + paddedsize;
	bmfh.bfOffBits = 0x36;		// number of bytes to start of bitmap bits

	// fill the infoheader

	info.biSize = sizeof(BITMAPINFOHEADER);
	info.biWidth = width;
	info.biHeight = height;
	info.biPlanes = 1;			// we only have one bitplane
	info.biBitCount = 24;		// RGB mode is 24 bits
	info.biCompression = BI_RGB;
	info.biSizeImage = 0;		// can be 0 for 24 bit images
	info.biXPelsPerMeter = 0x0ec4;     // paint and PSP use this values
	info.biYPelsPerMeter = 0x0ec4;
	info.biClrUsed = 0;			// we are in RGB mode and have no palette
	info.biClrImportant = 0;    // all colors are important

	// now we open the file to write to
	HANDLE file = CreateFile(bmpfile, GENERIC_WRITE, FILE_SHARE_READ,
		NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (file == NULL) {
		CloseHandle(file);
		return false;
	}
	// write file header
	unsigned long bwritten;
	if (WriteFile(file, &bmfh, sizeof(BITMAPFILEHEADER), &bwritten, NULL) == false) {
		CloseHandle(file);
		return false;
	}
	// write infoheader
	if (WriteFile(file, &info, sizeof(BITMAPINFOHEADER), &bwritten, NULL) == false) {
		CloseHandle(file);
		return false;
	}
	// write image data
	if (WriteFile(file, Buffer, paddedsize, &bwritten, NULL) == false) {
		CloseHandle(file);
		return false;
	}

	// and close file
	CloseHandle(file);

	return true;
} // SaveBMP
