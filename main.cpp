#include "Image_Class.h"
using namespace std;
void rotate90(Image image) {
    Image rotatedImage(image.height,image.width);
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int R = image.getPixel(i,j,0);
            int G = image.getPixel(i,j,1);
            int B = image.getPixel(i,j,2);
            rotatedImage.setPixel(rotatedImage.width-1-j,i,0,R);
            rotatedImage.setPixel(rotatedImage.width-1-j,i,1,G);
            rotatedImage.setPixel(rotatedImage.width-1-j,i,2,B);
        }
    }
    rotatedImage.saveImage("hello_world.jpg");
    cout<<"rotated 90"<<endl;
}
void rotate180(Image image) {
    Image rotatedImage(image.width, image.height);
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int R = image.getPixel(i, j, 0);
            int G = image.getPixel(i, j, 1);
            int B = image.getPixel(i, j, 2);
            rotatedImage.setPixel(image.width - i - 1, image.height - j - 1, 0, R);
            rotatedImage.setPixel(image.width - i - 1, image.height - j - 1, 1, G);
            rotatedImage.setPixel(image.width - i - 1, image.height - j - 1, 2, B);
        }
    }

    rotatedImage.saveImage("hello_world.jpg");
    cout << "rotated 180" << endl;
}
void rotate270(Image image) {
    Image rotatedImage(image.height, image.width);
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int R = image.getPixel(i, j, 0);
            int G = image.getPixel(i, j, 1);
            int B = image.getPixel(i, j, 2);
            rotatedImage.setPixel(j, rotatedImage.height - i - 1, 0, R);
            rotatedImage.setPixel( j, rotatedImage.height - i - 1, 1, G);
            rotatedImage.setPixel( j, rotatedImage.height - i - 1, 2, B);
        }
    }

    rotatedImage.saveImage("hello_world.jpg");
    cout << "rotated 270" << endl;
}
void invertImage(Image image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int R = image.getPixel(i,j,0);
            int G = image.getPixel(i,j,1);
            int B = image.getPixel(i,j,2);
            image.setPixel(i,j,0,255-R);
            image.setPixel(i,j,1,255-G);
            image.setPixel(i,j,2,255-B);
        }
    }
    image.saveImage("hello_world.jpg");
    cout<<"inverted Image"<<endl;
}
void rotation(Image image) {
    int choice;
    cout << "Do you want to rotate this image with how many degrees?" << endl;
    cout << "1- 90 degrees"<<endl;
    cout << "2- 180 degrees"<<endl;
    cout << "3- 270 degrees"<<endl;
    cin >> choice;
    switch (choice) {
        case 1:
            rotate90(image);
            break;
        case 2:
            rotate180(image);
            break;
        case 3: rotate270(image);
            break;
    }
}