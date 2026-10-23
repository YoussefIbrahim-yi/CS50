#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int rgbAvg = round(
          (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) /
          3.0);
      image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed =
          rgbAvg;
    }
  }
  return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {

      int sepiaRed = (int)round(0.393 * image[i][j].rgbtRed +
                                0.769 * image[i][j].rgbtGreen +
                                0.189 * image[i][j].rgbtBlue);
      int sepiaGreen = (int)round(0.349 * image[i][j].rgbtRed +
                                  0.686 * image[i][j].rgbtGreen +
                                  0.168 * image[i][j].rgbtBlue);
      int sepiaBlue = (int)round(0.272 * image[i][j].rgbtRed +
                                 0.534 * image[i][j].rgbtGreen +
                                 0.131 * image[i][j].rgbtBlue);
      if (sepiaBlue > 255) {
        sepiaBlue = 255;
      }
      if (sepiaGreen > 255) {
        sepiaGreen = 255;
      }
      if (sepiaRed > 255) {
        sepiaRed = 255;
      }
      //   if (sepiaBlue > 255 || sepiaGreen > 255 || sepiaRed > 255) {
      //     sepiaBlue = 255;
      //     sepiaGreen = 255;
      //     sepiaRed = 255;
      image[i][j].rgbtBlue = sepiaBlue;
      image[i][j].rgbtGreen = sepiaGreen;
      image[i][j].rgbtRed = sepiaRed;
    }
  }
  return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width / 2; j++) {
      RGBTRIPLE tmp = image[i][j];
      image[i][j] = image[i][(width - j) - 1];
      image[i][(width - j) - 1] = tmp;
    }
  }
  return;
}

void calcAvgOfAdjPxls(int height, int width, int currentPxlY, int currentPxlX,
                      RGBTRIPLE image[height][width],
                      RGBTRIPLE copy[height][width]) {
  int sumRed = 0;
  int sumGreen = 0;
  int sumBlue = 0;
  float countPxl = 0.0;
  int avgRed;
  int avgBlue;
  int avgGreen;
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      int adjacentPxlY = (currentPxlY + i);
      int adjacentPxlX = (currentPxlX + j);
      if (adjacentPxlY < 0 || adjacentPxlY >= height || adjacentPxlX < 0 ||
          adjacentPxlX >= width) {
        continue;
      }
      sumRed += copy[adjacentPxlY][adjacentPxlX].rgbtRed;
      sumGreen += copy[adjacentPxlY][adjacentPxlX].rgbtGreen;
      sumBlue += copy[adjacentPxlY][adjacentPxlX].rgbtBlue;
      countPxl++;
    }
  }
  avgRed = (int)round(sumRed / countPxl);
  avgGreen = (int)round(sumGreen / countPxl);
  avgBlue = (int)round(sumBlue / countPxl);
  image[currentPxlY][currentPxlX].rgbtRed = avgRed;
  image[currentPxlY][currentPxlX].rgbtGreen = avgGreen;
  image[currentPxlY][currentPxlX].rgbtBlue = avgBlue;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) {
  RGBTRIPLE copy[height][width];
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      copy[i][j] = image[i][j];
    }
  }
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      calcAvgOfAdjPxls(height, width, i, j, image, copy);
    }
  }
  return;
}