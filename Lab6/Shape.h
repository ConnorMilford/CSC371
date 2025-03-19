#pragma once 

#include <string>
#include <array>

struct Point {
    double x;
    double y;
};

class Shape {
    private:
    public:
        Shape();
        virtual ~Shape();

        virtual std::string to_string() const = 0; 
        virtual void centre_at(double x, double y) = 0; 

};

class Circle : public Shape {
    private:
        double x;
        double y;
        double r;
    public:
        Circle(double x, double y, double r);
        ~Circle() override;  
        
        std::string to_string() const override; 
        void centre_at(double x, double y) override; 

        double getX() const;
        double getY() const;
        double getR() const;
        
        
};

class Rectangle : public Shape {
    private:
        double x0;
        double x1;
        double y0;
        double y1;

        public:
            Rectangle(double x0, double x1, double y0, double y1);
            ~Rectangle();

            std::string to_string() const override;
            void centre_at(double x, double y) override; 
};

class Triangle : public Shape {
    private:
        double x0; 
        double x1;
        double x2;

        double y0;
        double y1;
        double y2;

    public:

    Triangle(double x0, double x1, double x2, double y0,
                double y1, double y2);

    ~Triangle();

    std::string to_string() const override;
    void centre_at(double x, double y) override;

    double centroid();
    std::array<double, 3> calculateSideLengths();
    


};