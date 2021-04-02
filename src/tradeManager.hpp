#include <raylib.h>
#include <vector>
#include <string>
using namespace std;


struct TradeManager
{
    vector<int> data;
    int  widthIntencity;
    int heightIntencity;

    int x_off;
    int y_off;

    int fontS = 3;

    Color colorU = GREEN;
    Color colorD = RED;
    Color colorN = BLUE;
    Color nColor= WHITE;

    int up = KEY_UP;
    int down = KEY_DOWN;
    int right = KEY_RIGHT;
    int left = KEY_LEFT;
    int zoomi = KEY_W;
    int zoomu = KEY_S;
    float cam_speed = 100;
    float cam_zoom_speed = 40;
    Camera2D cam =
    {
      (Vector2){0,0},
      (Vector2){0,0},
      0,
      1
    };

    void Update()
    {
        if (IsKeyDown(up))
        {
            cam.target.y -= cam_speed / GetFPS();
        }
        if (IsKeyDown(down))
        {
            cam.target.y += cam_speed / GetFPS();
        }
        if (IsKeyDown(left))
        {
            cam.target.x -= cam_speed / GetFPS();
        }
        if (IsKeyDown(right))
        {
            cam.target.x += cam_speed / GetFPS();
        }
        if (IsKeyDown(zoomi))
        {
            cam.zoom -= cam_zoom_speed / GetFPS();
        }
        if (IsKeyDown(zoomi))
        {
            cam.zoom += cam_zoom_speed / GetFPS();
        }
    }

    void DrawGraph()
    {
       BeginMode2D(cam);
       for(int i = 0 ; i < data.size()-1;i++)
       {
          Color drawColor;
          if (data[i]>data[i+1])
          {
             drawColor = colorD; //down color
          }
          if (data[i]<data[i+1])
          {
             drawColor = colorU; // up
          }
          if (data[i]==data[i+1])
          {
             drawColor = colorN; // neutral
          }
          //replace the 720's with get_windowH
          int x;
          int y;
          int x1;
          int y1;

          //DrawLine(x_off+(i*widthIntencity),720+y_off-(data[i] *heightIntencity) , (i+1)* widthIntencity,720+y_off-(data[i+1] *heightIntencity) , drawColor);
          //DrawText(s.data(),i*widthIntencity,720+y_off-(data[i]+1 *heightIntencity) ,fontS,nColor);

          x = x_off + ( i * widthIntencity ) ;
          y = GetScreenHeight() + y_off - ( data[i] * heightIntencity ) ;
          x1 = x_off + (( i + 1 ) * widthIntencity);
          y1 = GetScreenHeight() + y_off - ( data[i+1] * heightIntencity ) ;

          DrawLine(x,y,x1,y1,drawColor);

          string s = to_string(data[i]);
          DrawText(s.data(),x,y ,fontS,nColor);
       }
       DrawRectangle(-50,-50,100,100,RED);
       EndMode2D();
    }
};
