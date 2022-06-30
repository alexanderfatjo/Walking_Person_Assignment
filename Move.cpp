#include <iostream>
#include <thread>
#include <chrono>
#include "Screen.cpp"
#include "Person.cpp"

class Move{
private:
    int speed = 0;
    void move_down() {
        for (int i = 3; i < 12; i++) {
            i += speed;
            person.x_pos += speed + 1;
            screen.reset_screen();
            screen.add_char(i, 0, '-');
            screen.add_char(i, 1, '*');
            screen.add_char(i, 2, '-');
            screen.add_chars(person.x_pos, person.get_model());
            screen.print_screen();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    void move_up() {
        person.x_pos = 10;
        for (int i = 11; i < 12; i--) {
            i -= speed;
            //speed is decremented to both 'i' & 'model' to keep them together(same speed)
            person.x_pos -= speed + 1;
            screen.reset_screen();
            screen.add_char(i, 0, '-');
            screen.add_char(i, 1, '*');
            screen.add_char(i, 2, '-');
            screen.add_chars(person.x_pos, person.get_model());
            screen.print_screen();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    void move_right(){
        //'i' must be less than '10' because the models body is 3 char's wide
        for (int i = 0; i < 10; i++) {
            i += speed;
            screen.reset_screen();
            screen.add_char(2, i, '-');
            screen.add_char(2, i + 1, '*');
            screen.add_char(2, i + 2, '-');
            screen.add_chars(person.y_pos, i, person.get_model());
            screen.print_screen();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    void move_left(){
        for (int i = 9; i > -1; i--) {
            i -= speed + 1;
            screen.reset_screen();
            screen.add_char(2, i, '-');
            screen.add_char(2, i + 1, '*');
            screen.add_char(2, i + 2, '-');
            screen.add_chars(person.y_pos, i, person.get_model());
            screen.print_screen();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
public:
    Person person = Person();
    Screen screen = Screen();
    void set_speed(int speed){this->speed = speed;}
    void move_person(std::string direction) {
        if (direction == "down") {move_down();}
        if (direction == "up") {move_up();}
        if (direction == "right") {move_right();}
        if (direction == "left") {move_left();}
    }
};