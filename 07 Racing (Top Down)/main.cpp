#include <SFML/Graphics.hpp>
using namespace sf;
nt points[num][2] = {300, 610,
                      1270,430,
                      1380,2380,
                      1900,2460,
                      1970,1700,
                      2550,1680,
                      2560,3150,
                      500, 3300};

struct Car
{
  float x,y,speed,angle; int n;

  Car() {speed=2; angle=0; n=0;}
void move()
   {
    x += sin(angle) * speed;
    y -= cos(angle) * speed;
   }
