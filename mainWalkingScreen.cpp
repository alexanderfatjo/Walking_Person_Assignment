#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "Screen.cpp"
#include "Person.cpp"
#include "Move.cpp"

int main() {
    // create instance variables
    Screen screen = Screen();
    Person person = Person();
    Move move = Move();
    // just check our person really quick
    //for (auto c: person.get_model()) { std::cout << c; }
    std::cout << "\n And that was person \n";

    // simple printout our person with a little border underneath
    screen.add_char(1,0,'-');
    screen.add_char(1,1,'*');
    screen.add_char(1,2,'-');
    screen.add_chars(person.x_pos, person.get_model());
    screen.print_screen();

    // And now let's move them down one level (of course this could be a direction)

    screen.reset_screen();
    screen.add_char(2,0,'-');
    screen.add_char(2,1,'*');
    screen.add_char(2,2,'-');
    screen.add_chars(person.x_pos, person.get_model());
    screen.print_screen();
    std::string();
    std::string direction = "foo";
    std::cout << "\nWhich direction do you want to go?";
    std::cin >> direction;
    //increments to 'i' to make 'person model' move more distance per loop.
    int speed = 0;
    std::cout << "Enter your speed" << std::endl;
    std::cin >> speed;
    move.set_speed(speed);
    move.move_person(direction);
    return 0;
}