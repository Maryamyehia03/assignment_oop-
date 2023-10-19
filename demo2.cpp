// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp  grayscale images
//          Program load a gray image and store in another file
// Author 1:  Mariam Mostafa Mostafa
// Author 2: Marwa Haron Saad
// Author 3: Ola Abdullah Hassan
// Date:    19 / 10 / 2023
// Version: 1.0

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

//_______________________________________________________________________________________________________________________________________________________

void doSomethingForImage() {
    cout<<"Choose \n1.Black and White Image \n2.Invert Image\n3.Merge Images\n4.Flip Image\n5.Rotate Image\n6.Darken or Lighten Image\n7. Detect Image Edges\n8. Enlarge Image\n9. Shrink Image\n10.Mirror Image\n11. Shuffle Image\n12. Blur Image\n13. Crop Image\n14. Skew Image\n0.Exit\n";
    int x;
    cin>>x;
    if (x==3)temp= true;
    switch (x) {
        case 1:
        {for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j< SIZE; j++) {
                    if(image[i][j] >= 128)
                        image[i][j] = 0;       //black and white image
                    else
                        image[i][j] = 255;
                }  }
            break;}
//***********************************************************************************************************************
        case 2:
        { for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j< SIZE; j++) {
                    image[i][j] = 255-image[i][j]; //inverse image
                }
            }
            break;}
//***********************************************************************************************************************
        case 3:
        {  loadImage2();
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    image[i][j] = (image[i][j] + image2[i][j]) / 2; //merge image
                }
            }
            break;}
//***********************************************************************************************************************
        case 4:
        {cout<<"Enter 1.horizontally \n2.vertically\n";
            int y;cin>>y;
            unsigned char copy[SIZE][SIZE];
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j< SIZE; j++) {       //take copy
                    copy[i][j]=image[i][j];
                }
            }

            //1

            if(y==1){
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j< SIZE; j++) {
                        image[i][255-j]=copy[i][j];  //horizontially
                    }
                }
            }
                //2

            else if(y==2){
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j< SIZE; j++) {
                        image[255-i][255-j]=copy[i][j];  //vertically
                    }
                }
            }
            break;}
//***********************************************************************************************************************
        case 5:{
            cout<<"enter the degree";
            int degree;
            cin>>degree;
            int image1[SIZE][SIZE];
            for (int x = 0; x < SIZE; x++) {
                for (int y = 0; y < SIZE; y++) {
                    image1[x][y] = image[x][y];
                }
            }

            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j< SIZE; j++) {
                    image1[i][j]=image[i][j];
                    if(degree==90){                                 //rotate 90 degree
                        image[i][j] = image1[SIZE-1-j][i];
                    }
                        // Rotate Image
                    else if(degree==180){
                        image[i][j]= image1[j][SIZE-i-1];          //rotate 180 degree
                        image[i][j]= image1[j][SIZE-i-1];


                    }
                    else if (degree==270){
                        image1[SIZE-i-1][j];                  //rotate 270 degree
                        image[i][j] = image1[SIZE-i-1][j];

                    }
                }
            }
            break;}
//***********************************************************************************************************************
        case 6:
        {cout << "1.Darker Image\n2.Lighten Image\n";
            int z;
            cin >> z;
            //1
            if (z == 1) {
                {
                    for (int i = 0; i < SIZE; i++) {
                        for (int j = 0; j < SIZE; j++) {
                            image[i][j] = image[i][j] / 3;             //darken image
                        }
                    }
                }
            }

                //2
            else if (z == 2) {
                {
                    for (int i = 0; i < SIZE; i++){
                        for (int j = 0; j< SIZE; j++){
                            if (image[i][j]<120)
                                image[i][j]= (image[i][j])+90;           //light image
                        }
                    }
                }
            }

            break;}
//***********************************************************************************************************************
        case 7:{
            unsigned char image2[SIZE][SIZE];
            for(int i = 0;i<SIZE;i++){
                for(int j=0;j<SIZE;j++){
                    image2[i][j] = 255;
                }
            }
            for(int i = 0;i<SIZE;i++){
                for(int j=0;j<SIZE;j++){
                    if(image[i][j] >= 115)
                        image2[i][j] = 255;
                    else
                        image2[i][j] = 0;
                }
            }                                                    // Detect Image Edges
            for(int i = 0;i<SIZE;i++){
                for(int j=0;j<SIZE;j++){
                    if( image2[i+1][j] != image2[i-1][j])
                        image[i][j] = 0;
                    else if( image2[i][j+1] != image2[i][j-1])
                        image[i][j] = 0;
                    else
                        image[i][j] = 255;
                }
            }
            break;}
//***************************************************************************************************************************
        case 8:{
           unsigned char image2[SIZE][SIZE];
            cout << "enter n\n";
            int n;
            cin >> n;
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    image2[i][j] = image[i][j];
                }
            }
            if (n == 1) {                            //enlarge firt quarter
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        image2[i][j] = 255;                    //white background

                    }
                }
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        image2[i][j] = image[i / 2][j / 2];
                    }
                }
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        image[i][j] = image2[i][j];
                    }
                }
            }
            if (n == 2) {                               //enlarge second quarter
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        image2[i][j] = 255;

                    }
                }
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        image2[i][j] = image[i / 2][(j / 2) + 127];
                    }
                }
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        image[i][j] = image2[i][j];
                    }
                }
            }
            if (n == 3) {                                    //enlarge third quarter
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        image2[i][j] = 255;

                    }
                }
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        image2[i][j] = image[(i / 2) + 127][(j / 2)];
                    }
                }
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        image[i][j] = image2[i][j];
                    }
                }
            } else if (n == 4) {                            //enlarge fourth quarter
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        image2[i][j] = 255;

                    }
                }
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        image2[i][j] = image[(i / 2) + 127][(j / 2) + 127];
                    }
                }
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        image[i][j] = image2[i][j];
                    }

                }
            }

            break;}
//***************************************************************************************************************************
        case 9:
        {
            cout<<"choose shrink the image dimensions to \n1. 1/2\n2. 1/3 \n3. 1/4 \n";
            int m;cin>>m;
            unsigned char copy2[SIZE][SIZE];
            for (int i = 0; i < SIZE ; ++i) {
                for (int j = 0; j < SIZE ; ++j) {
                    copy2[i][j]=image[i][j];
                }
            }
            for (int i = 0; i < SIZE ; ++i) {
                for (int j = 0; j < SIZE ; ++j) {
                    image[i][j]=255;
                }
            }
            if (m==1){
                for (int i = 0; i < SIZE ; ++i) {
                    for (int j = 0; j < SIZE ; ++j) {
                        image[i/2][j/2]=copy2[i][j];                        //Shrink Image to 1/2
                    }}
            }                                                                                          //Shrink Image
            else if (m==2){
                for (int i = 0; i < SIZE ; ++i) {
                    for (int j = 0; j < SIZE ; ++j) {
                        image[i/3][j/3]=copy2[i][j];                       //Shrink Image to 1/3
                    }}
            }
            else if (m==3){
                for (int i = 0; i < SIZE ; ++i) {
                    for (int j = 0; j < SIZE ; ++j) {
                        image[i/4][j/4]=copy2[i][j];                         //Shrink Image to 1/4
                    }}
            }
            break;
        }
//***************************************************************************************************************************
        case 10:{
            cout<<"choose the image as seen here in order\n1. Left 1/2\n2. Right 1/2\n3. Upper 1/2 \n4. Lower 1/2";
            int z;cin>>z;
            unsigned char image2[SIZE][SIZE];
            for(int i = 0;i<SIZE;i++){
                for(int j=0;j<SIZE;j++){
                    image2[i][j] = image[i][j];
                }
            }
            if (z==1){
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j< SIZE; j++) {
                        if(j > 128)
                            image[i][j] = image2[i][255-j];                     //left
                        else
                            image[i][j] = image2[i][j];
                    }
                }}
            else if(z==2){
                // unsigned char image2[SIZE][SIZE];
                for(int i = 0;i<SIZE;i++){
                    for(int j=0;j<SIZE;j++){
                        image[i][j] = image[i][255-j];                      //right
                    }
                }
            }                                                                          //Mirror Image
            else if(z==3){
                for(int i = 0;i<SIZE;i++){
                    for(int j=0;j<SIZE;j++){
                        image2[i][j] = image[i][j];                    //lower
                    }
                }
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j< SIZE; j++) {
                        if(i > 128)
                            image[i][j] = image2[255-i][j];               //upper
                        else
                            image[i][j] = image2[i][j];
                    }
                }
            }
            else if(z==4){
                for(int i = 0;i<SIZE;i++){
                    for(int j=0;j<SIZE;j++){
                        image[i][j] = image[255-i][j];
                    }
                }
            }
            break;
        }
//***************************************************************************************************************************
        case 11:{
            int n;
            cerr << "Enter the order of quarters you want: ";
            for (int i = 0; i < 4; i++) {
                cin >> n;
                if (i == 0) moveQuarter(n, 0, 0);
                else if (i == 1) moveQuarter(n, 0, SIZE / 2);
                else if (i == 2) moveQuarter(n, SIZE / 2, 0);
                else if (i == 3) moveQuarter(n, SIZE / 2, SIZE / 2);
            }
            break;
        }
//***************************************************************************************************************************
        case 12:{
            int avg=0;
            for (int i = 0; i < SIZE-3 ; ++i) {
                for (int j = 0; j < SIZE-3 ; ++j) {                                   // Blur Image
                    avg+=image[i][j]+image[i+1][j+1]+image[i+2][j+2]+image[i+3][j+3]+image[i+4][j+4]+image[i+5][j+5]+image[i+6][j+6];
                    image[i][j]=avg/7;
                    avg=0;
                }
            }
            break;
        }

//***************************************************************************************************************************
        case 13:{
            int x ,y ,len ,wid ;
            cout<<"Enter point x and y : ";
            cin>>x>>y;
            cout<<"Enter length and width : ";
            cin>>len>>wid;
            unsigned char image2[SIZE][SIZE];

            for(int i = 0;i<SIZE;i++){
                for(int j=0;j<SIZE;j++){
                    image2[i][j] = image[i][j];
                }
            }                                                                  //Crop Image

            for(int i = 0;i<SIZE;i++){
                for(int j=0;j<SIZE;j++){
                    image[i][j] = 255;
                }
            }

            for(int i = x;i<x+wid;i++){
                for(int j=y;j<y+len;j++){
                    image[i][j] = image2[i][j];
                }
            }
            break;
        }
//************************************************************************************************************************
        case 14:
        {
            cout<<"choose Skew 1. Horizontally 2. Vertically ";
            int z;cin>>z;
            if(z==1){
           unsigned char copy[256][256];
                for (int i = 0; i < 256; ++i) {
                    for (int j = 0; j < 256; ++j) {
                        copy[i][j] = 255;
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
                        copy[i][(j * x) / 256] = image[i][j]; //shrink by angle
                    }
                }
                for (int i = 0; i < 256; ++i) {
                    for (int j = 0; j < 256; ++j) {
                        image[i][j] = 255;
                    }
                }
                double step = 256 - x;
                double move = step / 256;
                for (int i = 0; i < 256; ++i) {
                    for (int j = 0; j < 256; ++j) {
                        image[i][j + int(step)] = copy[i][j]; //skew horizontially
                    }
                    step -= move;
                }


                
            }
            else if(z==2){
                unsigned char copy2[256][256];
                float ang,x;
                cout<<"Enter angle\n";
                cin>>ang;
                ang=(ang/180/7*22);
                ang= tan(ang);
                x=1-ang;
                for (int i = 0; i <256*(x) ; ++i) {
                    for (int j = 0; j <256 ; ++j) {
                        copy2[i][j]=image[int(i/x)][j];           //shrink by angle
                    }
                }
                for (int i = 0; i < 256; ++i) {
                    for (int j = 0; j < 256; ++j) {
                        image[i][j]=255;
                    }
                }

                for (int i = 0; i < 256*x; ++i) {
                    for (int j = 0; j <256 ; ++j) {
                        image[i+(int((256-j)*ang))][j]=copy2[i][j];      //skew vertically
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
