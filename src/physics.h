void velocity(Window &params, std::vector<Shape*> &shapes)
{
    float rx;
    float dy;

    for (auto shape : shapes)
    {
        shape->x += shape->sx;
        shape->y += shape->sy;

        if (Circle* circle = dynamic_cast<Circle*>(shape))
        {
            rx = circle->x + circle->radius*2;
            dy = circle->y + circle->radius*2;
        } else if (Rectangle* rectangle = dynamic_cast<Rectangle*>(shape))
        {
            rx = rectangle->x + rectangle->width;
            dy = rectangle->y + rectangle->height;
        }
        
        if (rx > params.w || shape->x < 0)
        {
            shape->sx = -shape->sx;
        }
        if (dy > params.h || shape->y < 0)
        {
            shape->sy = -shape->sy;
        }
    }
};
