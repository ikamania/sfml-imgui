struct Window
{
    int w;
    int h;
public:
    Window() {}
};

void readConfig(Window &params, std::vector<Shape*> &shapes)
{
    std::ifstream values("bin/config.txt");
    std::string option;

    while (values >> option)
    {
        if (option == "Window")
        {
            values >> params.w >> params.h;
        } else if (option == "Circle")
        {
            shapes.push_back(new Circle(values));
        } else if (option == "Rectangle")
        {
            shapes.push_back(new Rectangle(values));
        }
    }
}
