void draw_shapes(sf::RenderWindow &window, std::vector<Shape*> &shapes)
{
    for (auto shape : shapes)
    {
        if (!shape->draw)
            continue;

        if (Circle* c = dynamic_cast<Circle*>(shape))
        {   
            sf::CircleShape circle(c->radius);

            circle.setPosition(c->x, c->y);
            circle.setFillColor(sf::Color(c->rgb[0], c->rgb[1], c->rgb[2]));
    
            window.draw(circle);
        } else if (Rectangle* r = dynamic_cast<Rectangle*>(shape))
        {
            sf::RectangleShape rectangle(sf::Vector2f(r->width, r->height));
            
            rectangle.setPosition(r->x, r->y);
            rectangle.setFillColor(sf::Color(r->rgb[0], r->rgb[1], r->rgb[2]));
            
            window.draw(rectangle);
        }
    }
}
