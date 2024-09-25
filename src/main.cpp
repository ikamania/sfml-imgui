#include "include/imgui.h"
#include "include/imgui-SFML.h"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <vector>

#include "shapes.h"
#include "config.h"
#include "draw.h"
#include "physics.h"

int main() 
{
    Window params;
    std::vector<Shape*> shapes;

    int index = 0;

    readConfig(params, shapes);

    sf::RenderWindow window(sf::VideoMode(params.w, params.h), "SFML");
    window.setFramerateLimit(60);
    
    ImGui::SFML::Init(window);

    sf::Clock deltaClock;
    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }
        }
        
        ImGui::SFML::Update(window, deltaClock.restart());
        velocity(params, shapes);

        ImGui::Begin("ImGui");

        for (size_t i = 0; i < shapes.size(); i++)
        { 
            int j = static_cast<int>(i);

            if (ImGui::Selectable(shapes[i]->name.c_str(), index == j))
            {
                index = j;
            }
        }

        ImGui::Text("Current Selection: %s", shapes[index]->name.c_str());
        ImGui::Checkbox("Draw ", &shapes[index]->draw);
        
        if (Circle* circle = dynamic_cast<Circle*>(shapes[index]))
        {
            ImGui::SliderFloat("Radius", &circle->radius, 1.0f, 200.0f);
        } else if (Rectangle* rectangle = dynamic_cast<Rectangle*>(shapes[index]))
        {
            ImGui::SliderFloat("Width ", &rectangle->width, 1.0f, 200.0f);
            ImGui::SliderFloat("Height", &rectangle->height, 1.0f, 200.0f);
        }

        ImGui::SliderFloat("X_Velocity", &shapes[index]->sx, -10.0f, 10.0f);
        ImGui::SliderFloat("Y_Velocity", &shapes[index]->sy, -10.0f, 10.0f);

        if (ImGui::ColorEdit3("Color", shapes[index]->rgb)) 
        {
            shapes[index]->rgb[0] *= 255;
            shapes[index]->rgb[1] *= 255;
            shapes[index]->rgb[2] *= 255;
        }

        ImGui::End();
        window.clear();

        draw_shapes(window, shapes);
        ImGui::SFML::Render(window);
        
        window.display();
    }

    ImGui::SFML::Shutdown();
}
