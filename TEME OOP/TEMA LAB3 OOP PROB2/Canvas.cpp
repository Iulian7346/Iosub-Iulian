#include "Canvas.h"

Canvas::Canvas(int width, int height)
{
    this->width = width;
    this->height = height;
    this->canvas = new char* [height];
    for (int i = 0; i < height; ++i)
    {
        this->canvas[i] = new char[width];
        for (int j = 0; j < width; ++j)
        {
            this->canvas[i][j] = ' ';
        }
    }
}



Canvas::~Canvas()
{
    for (int i = 0; i < height; ++i)
    {
        delete[] canvas[i];
    }
    delete[] canvas;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    for (int i = 0; i < this->width; ++i) {
        for (int j = 0; j < this->height; ++j)
        {
            float dist;
            dist = (i - x) * (i - x) + (j - y) * (j - y) - ray * ray;
            dist = abs(dist);
          
            if (dist < 3)
            {
                this->canvas[i][j] = ch;
            }
        }
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for (int i = 0; i < this->width; ++i) {
        for (int j = 0; j < this->height; ++j)
        {
            float dist;
            dist = (i - x) * (i - x) + (j - y) * (j - y) - ray * ray;
            
            if (dist <= 7)
            {
                this->canvas[i][j] = ch;
            }
            
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            if (i >= top && i <= bottom && j >= left && j <= right)
              if ((i == top || i == bottom) || (j == left || j == right))
              {
                this->canvas[i][j] = ch;
              }
        }
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            if (i >= top && i <= bottom && j >= left && j <= right)
            {
                this->canvas[i][j] = ch;
            }
        }

    }
}


void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx; if (x1 < x2) sx = 1; else sx = -1;
    int sy; if (y1 < y2) sy = 1; else sy = -1;
    int err = dx - dy;

    while (x1 != x2 || y1 != y2) {
        this->canvas[x1][y1] = ch;
        int err2 = 2 * err;
        if (err2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (err2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
    this->canvas[x1][y1] = ch;
}//

void Canvas::Print()
{
    for (int i = 0; i < this->height; ++i)
    {
        for (int j = 0; j < this->width; ++j)
        {
            cout << this->canvas[i][j]<<' ';
        }
        cout << endl;
    }
}

void Canvas::Clear() {
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            this->canvas[i][j] = ' ';
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch)
{
    this->canvas[x][y] = ch;
}