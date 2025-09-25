#include "Image_Class.h"
using namespace std;
Image rotate90(Image image) {
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
    cout<<"rotated 90"<<endl;
    return rotatedImage;
}
Image rotate180(Image image) {
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
    cout << "rotated 180" << endl;
    return rotatedImage;
}
Image rotate270(Image image) {
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
    cout << "rotated 270" << endl;
    return rotatedImage;
}
Image invertImage(Image image) {
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
    cout<<"inverted Image"<<endl;
    return image;
}
Image rotate(Image image) {
    Image rotated_image;
    int choice;
    cout << "Do you want to rotate this image with how many degrees?" << endl;
    cout << "1- 90 degrees"<<endl;
    cout << "2- 180 degrees"<<endl;
    cout << "3- 270 degrees"<<endl;
    cout << "0- Back"<<endl;
    cin >> choice;
    switch (choice) {
        case 1:
            rotated_image = rotate90(image);
            break;
        case 2:
            rotated_image = rotate180(image);
            break;
        case 3:
            rotated_image = rotate270(image);
            break;
        case 0:
            return image;
        default:
            cout<<"Invalid Input Try Again."<<endl;
    }
    return rotated_image;
}
Image grayscale(Image image) {
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
    cout<<"grayscale"<<endl;
    return image;
}
Image dark(Image image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int R = image.getPixel(i, j, 0);
            int G = image.getPixel(i, j, 1);
            int B = image.getPixel(i, j, 2);
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
    return image;
}
Image light(Image image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int R = image.getPixel(i, j, 0);
            int G = image.getPixel(i, j, 1);
            int B = image.getPixel(i, j, 2);
            if (R + .5 * R >= 255) R = 255;
            else R = R + .5 * R;
            if (G + .5 * G >= 255) G = 255;
            else G = G + .5 * G;
            if (B + .5 * B >= 255) B = 255;
            else B = B + .5 * B;
            image.setPixel(i, j, 0, R);
            image.setPixel(i, j, 1, G);
            image.setPixel(i, j, 2, B);
        }
    }
    return image;
}
Image brightness(Image image) {
    Image new_image;
    int choice;
    cout << "1- Dark"<<endl;
    cout << "2- Light"<<endl;
    cout << "0- Back"<<endl;
    cin >> choice;
    switch (choice) {
        case 1:
            new_image = dark(image);
            break;
        case 2:
            new_image = light(image);
            break;
        case 0:
            return image;
        default:
            cout<<"Invalid Input Try Again."<<endl;
    }
    return new_image;
}
Image black_and_white(Image image) {
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
    cout<<"Black and white"<<endl;
    return image;
}
Image flip_horizontal(Image image) {
    Image flipped_image(image.width, image.height);
    for (int i = 0; i < flipped_image.width; i++) {
        for (int j = 0; j < flipped_image.height; j++) {
            int R = image.getPixel(i,j,0);
            int G = image.getPixel(i,j,1);
            int B = image.getPixel(i,j,2);
            flipped_image.setPixel(flipped_image.width - i,j,0, R);
            flipped_image.setPixel(flipped_image.width - i,j,1, G);
            flipped_image.setPixel(flipped_image.width - i,j,2, B);
        }
    }
    cout<<"flip horizontally"<<endl;
    return flipped_image;
}
Image flip_vertical(const Image& image) {
    Image flipped_image(image.width, image.height);
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int R = image.getPixel(i, j, 0);
            int G = image.getPixel(i, j, 1);
            int B = image.getPixel(i, j, 2);
            flipped_image.setPixel(i, image.height - 1 - j, 0, R);
            flipped_image.setPixel(i, image.height - 1 - j, 1, G);
            flipped_image.setPixel(i, image.height - 1 - j, 2, B);
        }
    }
    cout << "Flipped vertically" << endl;
    return flipped_image;
}
Image flip(Image image) {
    int choice;
    Image flipped_image;
    cout << "1- Flip Vertically."<<endl;
    cout << "2- Flip Horizontally"<<endl;
    cout << "0- Back"<<endl;
    cin >> choice;
    switch (choice) {
        case 1:
            flipped_image = flip_vertical(image);
            break;
        case 2:
            flipped_image = flip_horizontal(image);
            break;
        case 0:
            return image;
        default:
            cout<<"Invalid Input Try Again."<<endl;
    }
    return flipped_image;
}
int main() {
    string image_name, saved_image_name;
    int option;
    Image image;
    cout << "Load a new image: " << endl;
    while (true) {
        cin >> image_name;
        try {
            if (image.loadNewImage(image_name)) {
                break;
            }
        }
        catch (const exception& e) {
            cout << "Load a new image: " << endl;
        }
    }
    while (true) {
        cout << "Choose A Filter :" << endl;
        cout << "1. Grayscale Filter" << endl;
        cout << "2. Black and White Filter" << endl;
        cout << "3. Invert Image filter" << endl;
        cout << "4. Flip Image" << endl;
        cout << "5. Rotate Image" << endl;
        cout << "6. Brightness Filter" << endl;
        cout << "90.Load a new image:" << endl;
        cout << "0. Save Image" << endl;
        cout << "200. Exit" << endl;
        cin >> option;
        switch (option) {
            case 1:
                image = grayscale(image);
                break;
            case 2:
                image = black_and_white(image);
                break;
            case 3:
                image = invertImage(image);
                break;
            case 4:
                image = flip(image);
                break;
            case 5:
                image = rotate(image);
                break;
            case 6:
                image = brightness(image);
                break;
            case 90:
                cout << "load a new image;" << endl;
                while (true) {
                    cin >> image_name;
                    try {
                        if (image.loadNewImage(image_name)) {
                            break;
                        }
                    }
                    catch (const exception& e) {
                        cout << "Load a new image: " << endl;
                    }
                }
            break;
            case 0:
                cout<<"1.save on same image"<<endl;
                cout<<"2.save with a new name"<<endl;
            cin >> option;
            switch (option) {
                case 1:
                    image.saveImage(image_name);
                break;
                case 2:
                    cout << "Enter a name for the saved image: " << endl;
                while (true) {
                    cin >> saved_image_name;
                    try {
                        if (image.saveImage(saved_image_name)) {
                            break;
                        }
                    }
                    catch (const exception& e) {
                        cout << "Enter a valid extention " << endl;
                    }
                }
                break;
            }                cout<<"Image saved"<<endl;
                break;
            case 200:
                cout<<"do you want to save changes ?"<<endl;
            cout<<"1. Save Image"<<endl;
            cout<<"2. Exit"<<endl;
            cin>> option;
            switch (option) {
                case 1:
                    cout << "Enter a name for the saved image: " << endl;
                while (true) {
                    cin >> saved_image_name;
                    try {
                        if (image.saveImage(saved_image_name)) {
                            break;
                        }
                    }
                    catch (const exception& e) {
                        cout << "Enter a valid extention " << endl;
                    }
                }

                    cout<<"Image saved"<<endl;
                break;
            }
            cout<<"Process finished"<<endl;
                return 0;
            default:
                cout<<"Invalid Input Try Again."<<endl;
        }
    }
}