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
#include "Image_Class.h"
using namespace std;
void grayscale(Image image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int R =image.getPixel(i,j,0);
            int G = image.getPixel(i,j,1);
            int B = image.getPixel(i,j,2);
            int gray =  0.3 * R + 0.6 * G + 0.1 * B; //wikipedia colors ratio rounded
            image.setPixel(i,j,0,gray);
            image.setPixel(i,j,1,gray);
            image.setPixel(i,j,2,gray);
        }
    }
    image.saveImage("hello_world.jpg");
    cout<<"grayscale"<<endl;
};
void Darken_and_Lighten(Image image) {
    short response;
    cout << "to increase type 1 and to decrease type 2 ";
    cin >> response;
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int R = image.getPixel(i, j, 0);
            int G = image.getPixel(i, j, 1);
            int B = image.getPixel(i, j, 2);
            if (response == 1) {
                if (R + .5 * R >= 255) R = 255;
                else R = R + .5 * R;
                if (G + .5 * G >= 255) G = 255;
                else G = G + .5 * G;
                if (B + .5 * B >= 255) B = 255;
                else B = B + .5 * B;
                image.setPixel(i, j, 0, R);
                image.setPixel(i, j, 1, G);
                image.setPixel(i, j, 2, B);
            } else if (response == 2) {
                if (R - .5 * R <= 0) R = 0;
                else R = R - .5 * R;
                if (G - .5 * G <= 0) G = 0;
                else G = G - .5 * G;
                if (B - .5 * B <= 0) B = 0;
                else B = B - .5 * B;
                image.setPixel(i, j, 0, R);
                image.setPixel(i, j, 1, G);
                image.setPixel(i, j, 2, B);
            }
        }
    }
    image.saveImage("hello_world.jpg");
}
void black_and_white(Image image) {
    int black = 0, white = 255;
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int R = image.getPixel(i,j,0);
            int G = image.getPixel(i,j,1);
            int B = image.getPixel(i,j,2);
            int gray =  0.3 * R + 0.6 * G + 0.1 * B;
            if (gray >= 124) {
                image.setPixel(i,j,0, white);
                image.setPixel(i,j,1, white);
                image.setPixel(i,j,2, white);
            } else {
                image.setPixel(i,j,0, black);
                image.setPixel(i,j,1, black);
                image.setPixel(i,j,2, black);
            }
        }
    }
    image.saveImage("test2.jpg");
    cout<<"Black and white"<<endl;
}

void flip_horizontal(Image image) {
    Image flipped_image(image.width, image.height);
    for (int i = flipped_image.width; i >= 0; i--) {
        for (int j = 0; j < flipped_image.height; j++) {
            int R = image.getPixel(i,j,0);
            int G = image.getPixel(i,j,1);
            int B = image.getPixel(i,j,2);
            flipped_image.setPixel(flipped_image.width - i,j,0, R);
            flipped_image.setPixel(flipped_image.width - i,j,1, G);
            flipped_image.setPixel(flipped_image.width - i,j,2, B);
        }
    }
    flipped_image.saveImage("test3.jpg");
    cout<<"flip horizontally"<<endl;
}

void flip_vertical(Image image) {
    Image flipped_image(image.width, image.height);
    for (int i = 0; i < flipped_image.width; i++) {
        for (int j = flipped_image.height; j >= 0; j--) {
            int R = image.getPixel(i,j,0);
            int G = image.getPixel(i,j,1);
            int B = image.getPixel(i,j,2);
            flipped_image.setPixel(i, flipped_image.height - j,0, R);
            flipped_image.setPixel(i, flipped_image.height - j,1, G);
            flipped_image.setPixel(i, flipped_image.height - j,2, B);
        }
    }
    flipped_image.saveImage("test4.jpg");
    cout<<"flip vertically"<<endl;
}