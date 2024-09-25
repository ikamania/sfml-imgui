class Shape
{
public:
    std::string name;
    bool draw = true;

    float x;
    float y;

    float sx;
    float sy;

    float rgb[3] = {0.0f, 0.0f, 0.0f};

    Shape() {}
    virtual ~Shape() {}

    void readBase(std::ifstream &values)
    {
        values >> name >> x >> y >> sx >> sy >> rgb[0] >> rgb[1] >> rgb[2];
    }
};

class Circle : public Shape
{
public:
    float radius;
    
    Circle(std::ifstream &values) 
    {
        readBase(values);
        values >> radius;
    }
};

class Rectangle : public Shape
{
public:
    float width;
    float height;
    
    Rectangle(std::ifstream &values) 
    {
        readBase(values);
        values >> width >> height;
    }
};
