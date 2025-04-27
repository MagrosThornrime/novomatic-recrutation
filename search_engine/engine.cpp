#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

#include <iostream>

#include "Application.h"


int main() {
    Application app("config.json");
    app.run();

    return 0;
}
