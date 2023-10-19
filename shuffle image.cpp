#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
bool temp = false;
using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
//unsigned char shuffled[SIZE][SIZE];

void loadImage ();
void saveImage ();
void doSomethingForImage ();
//void shuffleImage();
int main()
{
    loadImage();
    doSomethingForImage();
    // shuffleImage();
    saveImage();
    return 0;
}
//___________________________________________________________________________________________________________________________________________________
void loadImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the image file name: ";
    cin >> imageFileName;
    //load  image
    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

void loadImage2 () {
    char imageFileName2[100];

    // Get gray scale image file name
    cout << "Enter the  second image file name: ";
    cin >> imageFileName2;                                       //load second image if user choose marge image

    // Add to it .bmp extension and load image
    strcat(imageFileName2, ".bmp");
    readGSBMP(imageFileName2, image2);
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
    writeGSBMP(imageFileName, image2);
}


void moveQuarter(int idx, int i, int j) {

    int temp = j;
    if (idx == 1)                                          //  first quarter
        for (int k = 0; k < SIZE / 2; i++, k++) {
            j = temp;
            for (int z = 0; z < SIZE / 2; j++, z++)
                image2[i][j] = image[k][z];
        }
    else if (idx == 2)                               //second quarter
        for (int k = 0; k < SIZE / 2; i++, k++) {
            j = temp;
            for (int z = SIZE / 2; z < SIZE; j++, z++)
                image2[i][j] = image[k][z];
        }
    else if (idx == 3)                                  //third quarter
        for (int k = SIZE / 2; k < SIZE; i++, k++) {
            j = temp;
            for (int z = 0; z < SIZE / 2; j++, z++)
                image2[i][j] = image[k][z];
        }
    else if (idx == 4)                                   //fourth quarter
        for (int k = SIZE / 2; k < SIZE; i++, k++) {
            j = temp;
            for (int z = SIZE / 2; z < SIZE; j++, z++)
                image2[i][j] = image[k][z];
        }
}
void doSomethingForImage() {
    int n;
    cerr << "Enter the order of quarters you want: ";
    for (int i = 0; i < 4; i++) {
        cin >> n;
        if (i == 0) moveQuarter(n, 0, 0);
        else if (i == 1) moveQuarter(n, 0, SIZE / 2);
        else if (i == 2) moveQuarter(n, SIZE / 2, 0);
        else if (i == 3) moveQuarter(n, SIZE / 2, SIZE / 2);
    }

}