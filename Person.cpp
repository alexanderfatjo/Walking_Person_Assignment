// Base class to hold all animations for "person"
#include <array>
#include <fstream>
#include <string>

class Person {
private:
    // Person probably has a ton of other stuff but let's just work on the model
    std::array<char, 3> model = {'\\', '@', '/'};
public:
    // our position variables (start at 0,0 or top right)
    // note: we use y,x not x,y cause array of array not true graph
    int y_pos = 0;
    int x_pos = 0;

    // set and get models
    void set_model(std::array<char, 3> model) { this->model = model; }
    void set_model(std::string model) {
        // sent a string so just set first 3 chars (index 0-2)
        for (int i=0; i<3; i++) {
            this->model[i] = model[i];
        }
    }
    std::array<char, 3> get_model() { return model; }

};
