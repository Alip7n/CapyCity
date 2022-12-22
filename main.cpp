#include <iostream>
using namespace std;


void home() {
    cout << "Home" << endl;
    cout << "1) add building/clear" << endl;
    cout << "2) Map" << endl;
    cout << "3) Legend" << endl;
    cout << "0) Quit" << endl;
}

void building() {
    cout << "Building" << endl;
    cout << "0) empty" << endl;
    cout << "1) Water Energy" << endl;
    cout << "2) Wind Energy" << endl;
    cout << "3) Solar Energy" << endl;
}

void legend() {
    cout << "Legend" << endl;
    cout << "0) empty" << endl;
    cout << "1) Water Energy" << endl;
    cout << "2) Wind Energy" << endl;
    cout << "3) Solar Energy" << endl;
}

enum Buildings {
    Empty,
    WaterEnergy,
    WindEnergy,
    SolarEnergy,
};

void cleanMap(Buildings** area, int mapH, int mapW) {
    for (int i = 0; i < mapH; i++) {
        for (int j = 0; j < mapW; j++) {
            area[i][j] = Empty;
        }
    }
}
void printMap(Buildings** area, int mapH, int mapW) {
    for (int i = 0; i < mapH; i++) {
        for (int j = 0; j < mapW; j++) {
            cout << area[i][j] << " ";
        }
        cout << endl;
    }
}
void build(Buildings** area, int mapH, int mapW){
    int width, height, x, y, option;
    bool overlap = false;
    bool outOfBounds = false;
    building();
    cout << "Option: ";
    cin >> option;
    cout << "Enter x position: " << endl;
    cin >> x;
    cout << "Enter y position: " << endl;
    cin >> y;
    cout << "enter building height: " << endl;
    cin >> height;
    cout << "enter building width: " << endl;
    cin >> width;
    Buildings selected;

    switch (option) {
        case 0:
            selected = Empty;
            break;

        case 1:
            selected = WaterEnergy;
            break;

        case 2:
            selected = WindEnergy;
            break;

        case 3:
            selected = SolarEnergy;
            break;
    }

    for (int i = y; i < y + height; i++) {
        for (int j = x; j < x + width; j++) {
            if (area[i][j] != 0) {
                overlap = true;
            }
        }
    }

    if (x + width > mapW || y + height > mapH) {
        outOfBounds = true;
    }
    if (overlap) {
        cout << "Overlap!" << endl;
    }
    if (outOfBounds) {
        cout << "Out of bounds!" << endl;
    } else {
        for (int i = y; i < y + height; i++) {
            for (int j = x; j < x + width; j++) {
                area[i][j] = selected;
            }
        }
    }
}

int main() {
    int mapH, mapW, option;
    cout << "Enter Map height: " << endl;
    cin >> mapH;
    cout << "Enter Map width: " << endl;
    cin >> mapW;

    Buildings** area = new Buildings*[mapH];
    for (int i = 0; i < mapH; i++) {
        area[i] = new Buildings[mapW];
    }
    cleanMap(area, mapH, mapW);
    do {
        home();
        cout << "Option: ";
        cin >> option;
        switch (option) {
            case 1:
                build(area, mapH, mapW);
                break;
            case 2:
                printMap(area, mapH, mapW);
                break;
            case 3:
                legend();
        }
    } while (option != 0);
}