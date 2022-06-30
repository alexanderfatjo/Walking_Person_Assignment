// Holds our background and its functions
#include <array>
#include <iostream>


class Screen {
private:
    // Our screen
    std::array<std::array<char, 12>, 12> screen;
public:
    Screen() {
        // fill each individual array with a space character
        reset_screen();
    }
    void reset_screen() {
        // use a reference to ensure filling our screen (change in memory)
        for (auto &a : screen) {
            // a.fill(' '); // we will use this for the real screen but to make seeing easier
            a.fill('.');
        }
    }
    // add_char just adds a char to existing screen (x&y reversed)
    // add_chars adds 3 characters to a line (only takes the horizontal)
    // add_chars with both points fill in array from that point
    // add_chars with 12 - adds a full line
    void add_char(int y, int x, char pixel) { screen[y][x] = pixel; }
    void add_chars(int y, std::array<char, 3> image) {
        for (int i=0; i<image.size(); i++) {
            screen[y][i] = image[i];
        }
    }
    void add_chars(int y, int x, std::array<char, 3> image) {
        for (int i=0; i<image.size(); i++) {
            if (x < 11 && x > -1) { screen[y][i+x] = image[i]; }
        }
    }
    void add_chars(int y, std::array<char, 12> image) {
        // overloaded with 12 over 3
        for (int i=0; i<image.size(); i++) {
            screen[y][i] = image[i];
        }
    }
    void print_screen() {
        for (auto a : screen) {
            for (auto pixel : a) {
                std::cout << pixel;
            }
            std::cout << "\n";
        }
    }
    void clear_screen() { std::cout << "\n\n\n\n\n\n\n"; }
};
