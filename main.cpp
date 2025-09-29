//Name : Andro Hazem Samir     | Id : 20240093
//Name : Hazem Hosny Hamed     | Id : 20240150
//Name : Abdallah Sherif Sayed | Id : 20240327
// Andro has done grayscale filter (filter 1) and brightness filter (filter 7).
// Hazem has done black and white filter (filter 2) and flip filter (filter 5).
// Abdallah has done invert filter (filter 3) and rotation filter (filter 6).
#include "Image_Class.h"
using namespace std;
void rotate90(Image &image) {
    Image rotatedImage(image.height,image.width);
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int R = image.getPixel(i,j,0);
            int G = image.getPixel(i,j,1);
            int B = image.getPixel(i,j,2);
            rotatedImage.setPixel(image.height-1-j,i,0,R);
            rotatedImage.setPixel(image.height-1-j,i,1,G);
            rotatedImage.setPixel(image.height-1-j,i,2,B);
        }
    }
    cout<<"rotated 90"<<endl;
    image= rotatedImage;
}
void rotate180(Image &image) {
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
    image= rotatedImage;
}
void rotate270(Image &image) {
    Image rotatedImage(image.height, image.width);
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int R = image.getPixel(i, j, 0);
            int G = image.getPixel(i, j, 1);
            int B = image.getPixel(i, j, 2);
            rotatedImage.setPixel(j, image.width - i - 1, 0, R);
            rotatedImage.setPixel( j, image.width - i - 1, 1, G);
            rotatedImage.setPixel( j, image.width - i - 1, 2, B);
        }
    }
    cout << "rotated 270" << endl;
    image= rotatedImage;
}
void rotate(Image &image) {
    int choice;
    cout << "Do you want to rotate this image with how many degrees?" << endl;
    cout << "1- 90 degrees"<<endl;
    cout << "2- 180 degrees"<<endl;
    cout << "3- 270 degrees"<<endl;
    cout << "0- Back"<<endl;
    cin >> choice;
    switch (choice) {
        case 1:
             rotate90(image);
            break;
        case 2:
             rotate180(image);
            break;
        case 3:
             rotate270(image);
            break;
        case 0:
            return ;
        default:
            cout<<"Invalid Input Try Again."<<endl;
    }

}
void invertImage(Image &image) {
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

}
void grayscale(Image &image) {
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
}
void dark(Image &image) {
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

}
void light(Image &image) {
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

}
void brightness(Image &image) {
    Image new_image;
    int choice;
    cout << "1- Dark"<<endl;
    cout << "2- Light"<<endl;
    cout << "0- Back"<<endl;
    cin >> choice;
    switch (choice) {
        case 1:
            dark(image);
            break;
        case 2:
            light(image);
            break;
        case 0:
            return ;
        default:
            cout<<"Invalid Input Try Again."<<endl;
    }

}
void black_and_white(Image &image) {
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

}
void flip_horizontal(Image &image) {
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
    image = flipped_image;

}
void flip_vertical(Image &image) {
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
    image = flipped_image;

}
void flip(Image &image) {
    int choice;
    cout << "1- Flip Vertically."<<endl;
    cout << "2- Flip Horizontally"<<endl;
    cout << "0- Back"<<endl;
    cin >> choice;
    switch (choice) {
        case 1:
            flip_vertical(image);
            break;
        case 2:
            flip_horizontal(image);
            break;
        case 0:
            return;
        default:
            cout<<"Invalid Input Try Again."<<endl;
    }
}
void load_new(string &image_name,Image &image) {
    cout << "load a new image:" << endl;
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
}
void save_new(Image &image ,string &image_name) {
    string  saved_image_name;
    int option;
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
    }
    cout<<"Image saved"<<endl;
}
void menu() {
    string image_name;
    int option;
    Image image;
    load_new(image_name, image);
    while (true) {
        cout << "Choose A Filter :" << endl;
        cout << "1. Grayscale Filter" << endl;
        cout << "2. Black and White Filter" << endl;
        cout << "3. Invert Image filter" << endl;
        cout << "4. Flip Image" << endl;
        cout << "5. Rotate Image" << endl;
        cout << "6. Brightness Filter" << endl;
        cout << "90.Load a new image" << endl;
        cout << "0. Save Image" << endl;
        cout << "200. Exit" << endl;
        cin >> option;
        switch (option) {
            case 1:
                grayscale(image);
                break;
            case 2:
                black_and_white(image);
                break;
            case 3:
                invertImage(image);
                break;
            case 4:
                flip(image);
                break;
            case 5:
                rotate(image);
                break;
            case 6:
                brightness(image);
                break;
            case 90:
                load_new(image_name, image);
                break;
            case 0:
                save_new(image,image_name);
                break;
            case 200:
                cout<<"do you want to save changes ?"<<endl;
                cout<<"1. Save Image"<<endl;
                cout<<"2. Exit"<<endl;
                cin>> option;
                switch (option) {
                    case 1:
                        save_new(image,image_name);
                        return;
                    case 2:
                        cout<<"Process finished"<<endl;
                        return;
                    default:
                        cout<<"Invalid Input Try Again."<<endl;
                }
                break;
            default:
                cout<<"Invalid Input Try Again."<<endl;
        }
    }
}
int main() {
    menu();
}