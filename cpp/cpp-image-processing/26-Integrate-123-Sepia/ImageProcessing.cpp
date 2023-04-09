/*
 * ImageProcessing.cpp
 *
 *  Created on: 26 de mai de 2020
 *      Author: rfarah
 */

#include <fstream>
#include <iostream>
#include "ImageProcessing.h"
#include <math.h>

namespace rfh {

ImageProcessing::ImageProcessing() {

}

ImageProcessing::~ImageProcessing() {

}

void ImageProcessing::readImage(string name) {
	ifstream inFile;

	inFile.open(name, ios::in | ios::binary);
	if (!inFile) {
		cout << "Error opening file" << endl;
		return;
	}

	for (auto &i : header) {
		i = inFile.get();
	}

	width = *(reinterpret_cast<int*>(&header[OFFSET_WIDTH]));
	height = *(reinterpret_cast<int*>(&header[OFFSET_HEIGHT]));
	bitDepth = static_cast<int>(header.at(OFFSET_BIT_DEPTH));

	if (bitDepth <= 8) {
		inFile.read(reinterpret_cast<char*>(colorTable.data()),
				colorTable.size());
	}

	buffer.resize(width * height);
	inFile.read(reinterpret_cast<char*>(buffer.data()), buffer.size());

	inFile.close();
	if (!inFile) {
		cout << "Error closing file" << endl;
		return;
	}
}

void ImageProcessing::writeImage(string name) {
	ofstream outFile;

	outFile.open(name, ios::out | ios::binary);
	if (!outFile) {
		cout << "Error opening file" << endl;
		return;
	}

	outFile.write(reinterpret_cast<char*>(header.data()), header.size());

	if (bitDepth <= 8) {
		outFile.write(reinterpret_cast<char*>(colorTable.data()),
				colorTable.size());
	}

	outFile.write(reinterpret_cast<char*>(buffer.data()), buffer.size());

	outFile.close();
	if (!outFile) {
		cout << "Error closing file" << endl;
		return;
	}
}

void ImageProcessing::binarizeImage(int threshold) {
	for (auto &i : buffer) {
		i = ((int) i > threshold) ? WHITE : BLACK;
	}
}

void ImageProcessing::changeBrightness(int brightness) {
	for (auto &i : buffer) {
		int temp = i + brightness;
		temp = (temp > MAX_COLOR) ? MAX_COLOR : temp;
		temp = (temp < MIN_COLOR) ? MIN_COLOR : temp;
		i = temp;
	}
}

void ImageProcessing::computeHistogram(string name) {
	ofstream outFile;

	outFile.open(name, ios::out);
	if (!outFile) {
		cout << "Error opening file" << endl;
		return;
	}

	array<double, TOTAL_COLORS> iHist { };

	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			int index = buffer.at(x + y * width);
			++(iHist[index]);
		}
	}

	for (int i = 0; i < TOTAL_COLORS; ++i) {
		histogram[i] = (iHist[i] / (width * height));
	}

	for (auto &i : histogram) {
		outFile << "\n" << i;
	}
	outFile.close();
	if (!outFile) {
		cout << "Error closing file" << endl;
		return;
	}
}

void ImageProcessing::equalizeHistogram(string name) {
	computeHistogram(name);
	array<int, TOTAL_COLORS> histogramEq { };

	for (int i = 0; i < TOTAL_COLORS; ++i) {
		float sum = 0.0;
		for (int j = 0; j < i; ++j) {
			sum += histogram[j];
		}
		histogramEq[i] = (int) ((TOTAL_COLORS - 1) * sum /*+ 0.5*/);
	}

	for (int i = 0; i < width * height; ++i) {
		buffer[i] = histogramEq[buffer[i]];
	}
	computeHistogram("eq_" + name);
}

void ImageProcessing::rotateRight() {
	vector<vector<unsigned char>> imgTemp(width,
			vector<unsigned char>(height, 0));

	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			imgTemp[j][height - 1 - i] = buffer[i * height + j];
		}
	}

	copyVector2DToBuffer(imgTemp);
}

void ImageProcessing::rotateLeft() {
	vector<vector<unsigned char>> imgTemp(width,
			vector<unsigned char>(height, 0));

	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			imgTemp[height - 1 - j][i] = buffer[i * height + j];
		}
	}

	copyVector2DToBuffer(imgTemp);
}

void ImageProcessing::rotateUpSideDown() {
	vector<vector<unsigned char>> imgTemp(width,
			vector<unsigned char>(height, 0));

	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			imgTemp[height - 1 - i][width - 1 - j] = buffer[i * height + j];
		}
	}

	copyVector2DToBuffer(imgTemp);
}

void ImageProcessing::copyVector2DToBuffer(
		vector<vector<unsigned char>> &imgTemp) {
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			buffer[i * height + j] = imgTemp[i][j];
		}
	}
}

void ImageProcessing::rotateImage(int rotation) {
	switch (rotation) {
	case 0:
		rotateRight();
		break;
	case 1:
		rotateLeft();
		break;
	case 2:
		rotateUpSideDown();
		break;
	}
}

void ImageProcessing::negativeImage() {
	for (auto &i : buffer) {
		i = 255 - i;
	}
}

void ImageProcessing::convolve2D(const Mask &mask) {
	/* 2D Convolution mask
	 * -1 -1 -1 -1 -1
	 * -1 -1 -1 -1 -1
	 * -1 -1 24 -1 -1
	 * -1 -1 -1 -1 -1
	 * -1 -1 -1 -1 -1
	 * */

	vector<unsigned char> bufferOut { };

	bufferOut.resize(width * height);

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			int val = 0;
			for (int m = 0; m < mask.rows; ++m) {
				for (int n = 0; n < mask.cols; ++n) {
					int ms = mask.data[m * mask.rows + n];
					int idx = i - m;
					int jdx = j - n;
					int im = 0;
					if (idx > 0 && jdx > 0) {
						im = buffer[idx * height + jdx];
					}
					val += ms * im;
				}
			}
			if (val > 255) {
				val = 255;
			}
			if (val < 0) {
				val = 0;
			}
			bufferOut[i * height + j] = val;
		}
	}

	for (int i = 0; i < width * height; ++i) {
		buffer[i] = bufferOut[i];
	}
}

void ImageProcessing::lineDetector(const int mask[][3]) {
	vector<unsigned char> bufferOut { };

	bufferOut.resize(width * height);

	for (int y = 1; y < height; ++y) {
		for (int x = 1; x < width; ++x) {
			int sum = 0;
			for (int i = -1; i < 2; ++i) {
				for (int j = -1; j < 2; ++j) {
					sum += buffer[x + i + (y + j) * width]
							* mask[(i + 1)][j + 1];
				}
			}
			if (sum > 255) {
				sum = 255;
			}
			if (sum < 0) {
				sum = 0;
			}
			bufferOut[x + y * width] = sum;
		}
	}

	for (int i = 0; i < width * height; ++i) {
		buffer[i] = bufferOut[i];
	}
}

void ImageProcessing::generateGaussNoise(float var, float mean) {
	float noise, theta;
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			noise = sqrt(
					-2 * var * log(1.0 - (float) rand() / (RAND_MAX + 0.1)));
			theta = (float) rand() * 1.9175345e-4 - 3.14159265;
			noise = noise * cos(theta);
			noise = noise + (float) mean;
			if (noise > 255) {
				noise = 255;
			}
			if (noise < 0) {
				noise = 0;
			}
			buffer[x + y * width] = (unsigned char) (noise + 0.5);
		}
	}
}

void ImageProcessing::saltAndPepper(float prob) {
	const int TS = RAND_MAX / 2;
	int data = (int) (prob * TS);
	int data1 = data + TS;
	int data2 = TS - data;

	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			data = rand();
			if (data >= TS && data < data1) {
				buffer[x + y * width] = 0;
			}
			if (data >= data2 && data < TS) {
				buffer[x + y * width] = 255;
			}
		}
	}
}

void ImageProcessing::maximumFilter() {
	const int n = 3;
	int a[11][11];
	vector<unsigned char> bufferOut { };

	bufferOut.resize(width * height);

	for (int y = n / 2; y < height - n / 2; ++y) {
		for (int x = n / 2; x < width - n / 2; ++x) {
			int smax = 0;

			for (int j = -n / 2; j <= n / 2; ++j) {
				for (int i = -n / 2; i <= n / 2; ++i) {
					a[i + n / 2][j + n / 2] = buffer[x + i + (y + j) * width];
				}
			}

			for (int j = 0; j < n - 1; ++j) {
				for (int i = 0; i < n - 1; ++i) {
					if (a[i][j] > smax) {
						smax = a[i][j];
					}
				}
			}

			bufferOut[x + y * width] = smax;
		}
	}

	for (int i = 0; i < width * height; ++i) {
		buffer[i] = bufferOut[i];
	}
}

void ImageProcessing::medianFilter() {
	int ar[121];
	const int n = 7;
	vector<unsigned char> bufferOut { };

	bufferOut.resize(width * height);

	for (int y = n / 2; y < height - n / 2; ++y) {
		for (int x = n / 2; x < width - n / 2; ++x) {
			int z = 0;

			for (int j = -n / 2; j <= n / 2; ++j) {
				for (int i = -n / 2; i <= n / 2; ++i, ++z) {
					ar[z] = buffer[x + i + (y + j) * width];
				}
			}

			for (int j = 0; j < n * n - 1; ++j) {
				int a = ar[j];
				int i = j - 1;

				while (i >= 0 && ar[i] > a) {
					ar[i + 1] = ar[i];
					--i;
				}

				ar[i + 1] = a;
			}

			bufferOut[x + y * width] = ar[n * n / 2];
		}
	}

	for (int i = 0; i < width * height; ++i) {
		buffer[i] = bufferOut[i];
	}
}

void ImageProcessing::minimumFilter() {
	const int n = 5;
	int a[11][11];
	vector<unsigned char> bufferOut { };

	bufferOut.resize(width * height);

	for (int y = n / 2; y < height - n / 2; ++y) {
		for (int x = n / 2; x < width - n / 2; ++x) {
			int smin = 255;

			for (int j = -n / 2; j <= n / 2; ++j) {
				for (int i = -n / 2; i <= n / 2; ++i) {
					a[i + n / 2][j + n / 2] = buffer[x + i + (y + j) * width];
				}
			}

			for (int j = 0; j < n - 1; ++j) {
				for (int i = 0; i < n - 1; ++i) {
					if (a[i][j] < smin) {
						smin = a[i][j];
					}
				}
			}

			bufferOut[x + y * width] = smin;
		}
	}

	for (int i = 0; i < width * height; ++i) {
		buffer[i] = bufferOut[i];
	}
}

void ImageProcessing::print() {
	cout << "height: " << height << " width: " << width << " bitDepth: "
			<< bitDepth << endl;
}

/***********************************************************************************/
/***********************************************************************************/
/***********************************************************************************/

ImageProcessingColor::ImageProcessingColor() {

}

ImageProcessingColor::~ImageProcessingColor() {

}

void ImageProcessingColor::readImage(string name) {
	ifstream inFile;

	inFile.open(name, ios::in | ios::binary);
	if (!inFile) {
		cout << "Error opening file" << endl;
		return;
	}

	for (auto &i : header) {
		i = inFile.get();
	}

	width = *(reinterpret_cast<int*>(&header[OFFSET_WIDTH]));
	height = *(reinterpret_cast<int*>(&header[OFFSET_HEIGHT]));
	bitDepth = static_cast<int>(header.at(OFFSET_BIT_DEPTH));

	if (bitDepth <= 8) {
		inFile.read(reinterpret_cast<char*>(colorTable.data()),
				colorTable.size());
	}

	// Resize to number of pixels
	buffer.resize(width * height);
	for (auto &i : buffer) {
		// Resize color channels(3)
		i.resize(3);

		// Read all color channels of each pixel
		for (int j = 2; j >= 0; --j) {
			i[j] = inFile.get();
		}
	}

	inFile.close();
	if (!inFile) {
		cout << "Error closing file" << endl;
		return;
	}
}

void ImageProcessingColor::writeImage(string name) {
	ofstream outFile;

	outFile.open(name, ios::out | ios::binary);
	if (!outFile) {
		cout << "Error opening file" << endl;
		return;
	}

	outFile.write(reinterpret_cast<char*>(header.data()), header.size());

	if (bitDepth <= 8) {
		outFile.write(reinterpret_cast<char*>(colorTable.data()),
				colorTable.size());
	}

	// Write all color channels of each pixel
	for (auto &i : buffer) {
		for (int j = 2; j >= 0; --j) {
			outFile.put(i[j]);
		}
	}

	outFile.close();
	if (!outFile) {
		cout << "Error closing file" << endl;
		return;
	}
}

void ImageProcessingColor::blurImage() {
	float v = 1.0 / 9.0;
	float kernel[3][3] = { { v, v, v }, { v, v, v }, { v, v, v } };

	vector<vector<unsigned char>> bufferOut { };

	// Resize to number of pixels
	bufferOut.resize(width * height);
	for (auto &i : bufferOut) {
		// Resize color channels(3)
		i.resize(3);
	}

	for (int x = 1; x < height - 1; ++x) {
		for (int y = 1; y < width - 1; ++y) {
			float sum0 = 0.0;
			float sum1 = 0.0;
			float sum2 = 0.0;

			for (int i = -1; i <= 1; ++i) {
				for (int j = -1; j <= 1; ++j) {
					sum0 = sum0
							+ (float) kernel[i + 1][j + 1]
									* buffer[(x + i) * width + (y + j)][0];
					sum1 = sum1
							+ (float) kernel[i + 1][j + 1]
									* buffer[(x + i) * width + (y + j)][1];
					sum2 = sum2
							+ (float) kernel[i + 1][j + 1]
									* buffer[(x + i) * width + (y + j)][2];
				}
			}
			bufferOut[(x) * width + (y)][0] = sum0;
			bufferOut[(x) * width + (y)][1] = sum1;
			bufferOut[(x) * width + (y)][2] = sum2;
		}
	}

	for (int i = 0; i < width * height; ++i) {
		for (int j = 0; j < 3; ++j) {
			buffer[i][j] = bufferOut[i][j];
		}
	}
}

void ImageProcessingColor::sepia() {
	int r, g, b;

	for (auto &i : buffer) {
		r = (i[0] * 0.393) + (i[1] * 0.769) + (i[2] * 0.189);
		g = (i[0] * 0.349) + (i[1] * 0.686) + (i[2] * 0.168);
		b = (i[0] * 0.272) + (i[1] * 0.534) + (i[2] * 0.131);

		i[0] = (MAX_COLOR < r) ? MAX_COLOR : r;
		i[1] = (MAX_COLOR < g) ? MAX_COLOR : g;
		i[2] = (MAX_COLOR < b) ? MAX_COLOR : b;
	}
}

void ImageProcessingColor::print() {
	cout << "height: " << height << " width: " << width << " bitDepth: "
			<< bitDepth << endl;
}

} /* namespace rfh */
