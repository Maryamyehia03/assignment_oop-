// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mohammad El-Ramly
// Date:    30 March 2018
// Version: 1.0
float pi=(22/7);
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
#include "bmplib.h"
bool temp = false;
using namespace std;
unsigned char image[SIZE][SIZE][RGB] ;
unsigned char image2[SIZE][SIZE][RGB];
//unsigned char image3[SIZE][SIZE];

void loadImage ();
void saveImage ();
void doSomethingForImage ();

int main()
{

    loadImage();
  doSomethingForImage();
  saveImage();
  return 0;
}

//___________________________________________________________________________________________________________________________________________________
void loadImage () {
    char imageFileName[150];

    // Get gray scale image file name
    cout << "Enter the image file name: ";
    cin >> imageFileName;
                                                                //load  image
    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
}

void loadImage2 () {
    char imageFileName2[100];

    // Get gray scale image file name
    cout << "Enter the  second image file name: ";
    cin >> imageFileName2;                                       //load second image if user choose marge image

    // Add to it .bmp extension and load image
        strcat(imageFileName2, ".bmp");
        readRGBBMP(imageFileName2, image2);
}
//______________________________________________________________________________________________________________________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;
                                                                    //save image
   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, image);
}

//_______________________________________________________________________________________________________________________________________________________

void doSomethingForImage() {
    cout<<"Choose \n1.Black and White Image \n2.Invert Image\n3.Merge Images\n4.Flip Image\n5.Rotate Image\n6.Darken or Lighten Image\n7. Detect Image Edges\n8. Enlarge Image\n9. Shrink Image\n10.Mirror Image\n11. Shuffle Image\n12. Blur Image\n13. Crop Image\n14. Skew Image\n0.Exit\n";
    int x;
    cin>>x;
    if (x==3)temp= true;
    switch (x) {
        case 1: {
          for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < 3; ++k) {
                        if (image[i][j][k] >= 128)
                            image[i][j][k] = 0;       //black and white image
                        else
                            image[i][j][k] = 255;
                    }
                }
            }
            break;
        }
//***********************************************************************************************************************
        case 2: {
         for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < 3; ++k) {
                        image[i][j][k] = 255 - image[i][j][k]; //inverse image
                    }
                }
            }

            break;
        }
//***********************************************************************************************************************
        case 3: {
            loadImage2();
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < 3; ++k) {
                        image[i][j][k] = (image[i][j][k] + image2[i][j][k]) / 2; //merge image
                    }
                }
            }
            break;
        }
//***********************************************************************************************************************
        case 4: {
             //filter 4
            cout<<"Enter 1 to flip horizontally & 2 to flip vertically \n ";
            int x;
            cin>>x;
            if(x == 1){ // flipping image horizontally
                unsigned char image2[SIZE][SIZE][RGB];
                for(int i = 0;i<SIZE;i++){
                    for(int j=0;j<SIZE;j++){
                            for(int k = 0;k<3;k++){
                                image2[i][j][k] = image[i][j][k]; // makes another copy for the image
                            }        }
                    }
                for(int i = 0;i<SIZE;i++){
                        for(int j=0;j<SIZE;j++){
                            for(int k = 0;k<3;k++){
                                image[i][j][k] = image2[255-i][j][k];   //flips the image    
                            }
                        }    }
                }
            else{
                //flipping image vertically
                   unsigned char image2[SIZE][SIZE][RGB];
                    for(int i = 0;i<SIZE;i++){        
                        for(int j=0;j<SIZE;j++){
                            for(int k = 0;k<3;k++){                
                                image2[i][j][k] = image[i][j][k]; // makes a copy for the image
                            }        }
                    }    for(int i = 0;i<SIZE;i++){
                        for(int j=0;j<SIZE;j++){            
                            for(int k = 0;k<3;k++){
                                image[i][j][k] = image2[i][255-j][k];      // flips it 
                            }
                        }    }
                }

            break;
        }
//***********************************************************************************************************************
        case 5: {
    cout << "enter the degree";
            int degree;
            cin >> degree;
            int image1[SIZE][SIZE][RGB];

            for (int x = 0; x < SIZE; x++) {
                for (int y = 0; y < SIZE; y++) {
                    for (int z = 0; z < 3; ++z) {
                        image1[x][y][z] = image[x][y][z];
                    }
                }
            }
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < 3; ++k) {
                        image1[i][j][k] = image[i][j][k];
                        if (degree == 90) {                                 //rotate 90 degree
                            image[i][j][k] = image1[SIZE - 1 - j][i][k];
                        }
                            // Rotate Image
                        else if (degree == 180) {
                            image[i][j][k] = image1[j][SIZE - i - 1][k];          //rotate 180 degree
                            image[i][j][k] = image1[j][SIZE - i - 1][k];


                        } else if (degree == 270) {
                            image1[SIZE - i - 1][j];                  //rotate 270 degree
                            image[i][j][k] = image1[SIZE - i - 1][j][k];

                        }
                    }
                }
            }


            break;
        }
//***********************************************************************************************************************
        case 6: {
            cout << "1.Darker Image\n2.Lighten Image\n";
            int z;
            cin >> z;
            //1
            if (z == 1) {
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        for (int k = 0; k < 3; ++k) {
                            image[i][j][k] = image[i][j][k] / 3;             //darken image
                        }
                    }
                }
            }

                //2
            else if (z == 2) {
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        for (int k = 0; k < 3; ++k) {
                            if (image[i][j][k] + (image[i][j][k] / 2) >= 255)
                                image[i][j][k] = 255;                             //light image
                            else
                                image[i][j][k] += (image[i][j][k] / 2);
                        }
                    }
                }
            }

            break;
        }
//***********************************************************************************************************************
        case 7: {
            //filter 7
            for(int i = 0;i<SIZE-1;i++){
              for(int j=0;j<SIZE-1;j++){
                for(int k = 0;k<3;k++){
                  if (image2[i][j + 1][k] != image2[i][j - 1][k]) 
                    image[i][j][k] = 0;                         // makes pixel black if its above pixel and lower different 
                  else if (image2[i + 1][j][k] != image2[i - 1][j][k])
                    image[i][j][k] = 0;                         // makes pixel black if its right and left different
                  else
                    image[i][j][k] = 255;

            }
        }
    }



            break;
        }
//***************************************************************************************************************************
        case 8: {
  unsigned char image2[SIZE][SIZE][RGB];
            cout << "enter n\n";
            int n;
            cin >> n;
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < 3; ++k) {
                        image2[i][j][k] = image[i][j][k];
                    }
                }
            }
            if (n == 1) {                            //enlarge firt quarter
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        for (int k = 0; k < 3; ++k) {
                            //    image2[i][j][k] = 255;                    //white background
                        }
                    }
                }

                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        for (int k = 0; k < 3; ++k) {

                            image2[i][j][k] = image[i / 2][j / 2][k / 2];
                        }
                    }
                }

                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        for (int k = 0; k < 3; ++k) {

                            image[i][j][k] = image2[i][j][k];
                        }
                    }
                }
            }
            if (n == 2) {                               //enlarge second quarter
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {

                        for (int k = 0; k < 3; ++k) {
                            //  image2[i][j][k] = 255;
                        }
                    }
                }
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {

                        for (int k = 0; k < 3; ++k) {
                            image2[i][j][k] = image[i / 2][j / 2][(k / 2) + 127];
                        }
                    }
                }
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        for (int k = 0; k < 3; ++k) {

                            image[i][j][k] = image2[i][j][k];
                        }
                    }
                }
            }
            if (n == 3) {                                    //enlarge third quarter
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        for (int k = 0; k < 3; ++k) {

                            //    image2[i][j][k] = 255;
                        }
                    }
                }
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        for (int k = 0; k < 3; ++k) {

                            image2[i][j][k] = image[(i / 2) + 127][(j / 2)][(k / 2)];
                        }
                    }
                }
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        for (int k = 0; k < 3; ++k) {

                            image[i][j][k] = image2[i][j][k];
                        }
                    }
                }
            } else if (n == 4) {                            //enlarge fourth quarter
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        for (int k = 0; k < 3; ++k) {

                            //    image2[i][j][k] = 255;
                        }
                    }
                }
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        for (int k = 0; k < 3; ++k) {

                            image2[i][j][k] = image[(i / 2) + 127][(j / 2) + 127][(k / 2) + 127];
                        }
                    }
                }
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        for (int k = 0; k < 3; ++k) {

                            image[i][j][k] = image2[i][j][k];
                        }

                    }
                }

            }


            
            break;
        }
//***************************************************************************************************************************
        case 9: {
            cout << "choose shrink the image dimensions to \n1. 1/2\n2. 1/3 \n3. 1/4 \n";
            int m;
            cin >> m;
            unsigned char copy2[SIZE][SIZE][RGB];
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        copy2[i][j][k] = image[i][j][k];
                    }
                }
            }
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        image[i][j][k] = 255;
                    }
                }
            }
            if (m == 1) {
                for (int i = 0; i < SIZE; ++i) {
                    for (int j = 0; j < SIZE; ++j) {
                        for (int k = 0; k < 3; ++k) {
                            image[i / 2][j / 2][k] = copy2[i][j][k];                        //Shrink Image to 1/2
                        }
                    }
                }
            }                                                                                          //Shrink Image
            else if (m == 2) {
                for (int i = 0; i < SIZE; ++i) {
                    for (int j = 0; j < SIZE; ++j) {
                        for (int k = 0; k < 3; ++k) {
                            image[i / 3][j / 3][k] = copy2[i][j][k];                       //Shrink Image to 1/3
                        }
                    }
                }
            } else if (m == 3) {
                for (int i = 0; i < SIZE; ++i) {
                    for (int j = 0; j < SIZE; ++j) {
                        for (int k = 0; k < 3; ++k) {
                            image[i / 4][j / 4][k] = copy2[i][j][k];                         //Shrink Image to 1/4
                        }
                    }
                }
            }
            break;
        }
//***************************************************************************************************************************
        case 10: {

            break;
        }
//***************************************************************************************************************************
        case 12: {
            int avg = 0;
            for (int i = 0; i < SIZE - 3; ++i) {
                for (int j = 0; j < SIZE - 3; ++j) {
                    for (int k = 0; k < 3; ++k) {                                 //BLur Image
                        avg += image[i][j][k] + image[i + 1][j + 1][k] + image[i + 2][j + 2][k] +
                               image[i + 3][j + 3][k] + image[i + 4][j + 4][k] + image[i + 5][j + 5][k] +
                               image[i + 6][j + 6][k];
                        image[i][j][k] = avg / 7;
                        avg = 0;
                    }
                }
            }
            break;
        }
//***************************************************************************************************************************
        case 13: {

            break;
        }
//************************************************************************************************************************
        case 14: {
            cout << "choose Skew 1. Horizontally 2. Vertically ";
            int z;
            cin >> z;
            if (z == 1) {
 unsigned char copy[256][256][3];
                for (int i = 0; i < 256; ++i) {
                    for (int j = 0; j < 256; ++j) {
                        for (int k = 0; k < 3; ++k) {
                            copy[i][j][k] = 255;
                        }
                    }
                }
                double rad, deg;
                cout << "Enter degree\n";
                cin >> deg;
                rad = (deg * 22) / (180 * 7);
                double len = tan(rad);
                int x = 256 / (1 + tan(rad));
                for (int i = 0; i < 256; ++i) {
                    for (int j = 0; j < 256; j++) {
                        for (int k = 0; k < 3; ++k) {

                            copy[i][(j * x) / 256 ][k] = image[i][j][k]; //shrink by angle
                        }
                    }
                }
                for (int i = 0; i < 256; ++i) {
                    for (int j = 0; j < 256; ++j) {
                        for (int k = 0; k < 3; ++k) {
                            image[i][j][k] = 255;
                        }
                    }
                }
                double step = 256 - x;
                double move = step / 256;
                for (int i = 0; i < 256; ++i) {
                    for (int j = 0; j < 256; ++j) {
                        for (int k = 0; k < 3; ++k) {
                            image[i][j + int(step)][k] = copy[i][j][k]; //skew horizontially

                            step -= move;
                        }
                    }
                }
            }
            }
            else if (z == 2) {
                unsigned char copy2[256][256][3];
                float ang, x;
                cout << "Enter angle\n";
                cin >> ang;
                ang = (ang / 180 / 7 * 22);
                ang = tan(ang);
                x = 1 - ang;
                for (int i = 0; i < 256 * (x); ++i) {
                    for (int j = 0; j < 256; ++j) {
                        for (int k = 0; k < 3; ++k) {
                            copy2[i][j][k] = image[int(i / x)][j][k];           //shrink by angle
                        }
                    }
                }
                for (int i = 0; i < 256; ++i) {
                    for (int j = 0; j < 256; ++j) {
                        for (int k = 0; k < 3; ++k) {
                            image[i][j][k] = 255;
                        }
                    }
                }

                for (int i = 0; i < 256 * x; ++i) {
                    for (int j = 0; j < 256; ++j) {
                        for (int k = 0; k < 3; ++k) {
                            image[i + (int((256 - j) * ang))][j][k] = copy2[i][j][k];      //skew vertically
                        }
                    }
                }
            }
                break;
            }
//***************************************************************************************************************************
            default:
                break;
        }
    }
//------------------------------------------------------------------------------------------------------------------------
