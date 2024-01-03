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

  void findTarget()
  {
    float tx=points[n][0];
    float ty=points[n][1];
    float beta = angle-atan2(tx-x,-ty+y);
    if (sin(beta)<0) angle+=0.005*speed; else angle-=0.005*speed;
    if ((x-tx)*(x-tx)+(y-ty)*(y-ty)<25*25) n=(n+1)%num;
   }
};


int main()
{
    RenderWindow app(VideoMode(640, 480), "Car Racing Game!");
	app.setFramerateLimit(60);
       Texture t1,t2,t3;
    t1.loadFromFile("images/background.png");
    t2.loadFromFile("images/car.png");
    t1.setSmooth(true);
    t2.setSmooth(true);

    Sprite sBackground(t1), sCar(t2);
    sBackground.scale(2,2);

    sCar.setOrigin(22, 22);
    float R=22;

    const int N=5;
    Car car[N];
    for(int i=0;i<N;i++)
    {
      car[i].x=300+i*50;
      car[i].y=1700+i*80;
      car[i].speed=7+i;
    }
 float maxSpeed=12.0;
   float acc=0.2, dec=0.3;
   float turnSpeed=0.08;

   int offsetX=0,offsetY=0;

   while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }
  bool Up=0,Right=0,Down=0,Left=0;
    if (Keyboard::isKeyPressed(Keyboard::Up)) Up=1;
    if (Keyboard::isKeyPressed(Keyboard::Right)) Right=1;
    if (Keyboard::isKeyPressed(Keyboard::Down)) Down=1;
    if (Keyboard::isKeyPressed(Keyboard::Left)) Left=1;


