/*---------------------------------------------------------------------------
Copyright (C), 2022-2023, Sara Echeverria (bl33h)
@author Sara Echeverria
FileName: main.cpp
@version: I
Creation: 11/07/2023
Last modification: 11/07/2023
*Some parts were made using the AIs Bard and ChatGPT
------------------------------------------------------------------------------*/

#include "framebuffer.h"
#include "point.h"
#include "colors.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

struct vert {
    float x;
    float y;
    vert(float xVal, float yVal) : x(xVal), y(yVal) {}
};

void writeInt(std::ofstream& file, int value) {
    file.put(value & 0xFF);
    file.put((value >> 8) & 0xFF);
    file.put((value >> 16) & 0xFF);
    file.put((value >> 24) & 0xFF);
}

// bmp file generator
void renderBuffer(const std::vector<Color>& framebuffer) {
    std::ofstream file("out.bmp", std::ios::binary);
    unsigned char fileHeader[] = {
        'B', 'M',
        0, 0, 0, 0, 
        0, 0,     
        0, 0,      
        54, 0, 0, 0
    };

    // header properties
    unsigned char infoHeader[] = {
        40, 0, 0, 0, 
        0, 0, 0, 0,  
        0, 0, 0, 0,  
        1, 0,         
        24, 0,       
        0, 0, 0, 0, 
        0, 0, 0, 0,  
        0, 0, 0, 0,   
        0, 0, 0, 0,  
        0, 0, 0, 0,   
        0, 0, 0, 0    
    };

    // screen size and header
    size_t imageSize = SCREEN_WIDTH * SCREEN_HEIGHT * 3;  // 3 bytes per pixel
    int fileSize = imageSize + sizeof(fileHeader) + sizeof(infoHeader);
    *(int*)&fileHeader[2] = fileSize;     
    *(int*)&fileHeader[10] = sizeof(fileHeader) + sizeof(infoHeader);
    *(int*)&infoHeader[4] = SCREEN_WIDTH;
    *(int*)&infoHeader[8] = SCREEN_HEIGHT;
    *(int*)&infoHeader[20] = imageSize;
    file.write(reinterpret_cast<char*>(fileHeader), sizeof(fileHeader));
    file.write(reinterpret_cast<char*>(infoHeader), sizeof(infoHeader));
    file.write(reinterpret_cast<const char*>(framebuffer.data()), framebuffer.size() * sizeof(Color));
    file.close();
}

void drawLine(vert start, vert end, const Color& color, std::vector<Color>& framebuffer) {
    int x0 = static_cast<int>(std::round(start.x));
    int y0 = static_cast<int>(std::round(start.y));
    int x1 = static_cast<int>(std::round(end.x));
    int y1 = static_cast<int>(std::round(end.y));
    int dx = std::abs(x1 - x0);
    int dy = std::abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        int pixelIndex = y0 * SCREEN_WIDTH + x0;
        framebuffer[pixelIndex] = color;

        if (x0 == x1 && y0 == y1)
            break;

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

// outline method
void polygonOutline(const std::vector<vert>& points, const Color& color, std::vector<Color>& framebuffer) {
    if (points.size() < 2) {
        return;  
    }

    for (size_t i = 0; i < points.size(); ++i) {
        size_t j = (i + 1) % points.size();
        drawLine(points[i], points[j], color, framebuffer);
    }
}

// filling outline method
void fillPolygon(const std::vector<vert>& vertices, const Color& color, std::vector<Color>& framebuffer) {
    if (vertices.size() < 3) {
        return;  
    }
    std::vector<int> scanline(SCREEN_HEIGHT, SCREEN_WIDTH);
    int minY = SCREEN_HEIGHT - 1;
    int maxY = 0;

    for (const vert& vertex : vertices) {
        int y = static_cast<int>(std::round(vertex.y));
        minY = std::min(minY, y);
        maxY = std::max(maxY, y);
    }

    for (int y = minY; y <= maxY; ++y) {
        std::vector<float> intersections;

        for (size_t i = 0; i < vertices.size(); ++i) {
            size_t j = (i + 1) % vertices.size();
            float y0 = vertices[i].y;
            float y1 = vertices[j].y;

            if ((y0 <= y && y1 > y) || (y0 > y && y1 <= y)) {
                float x = vertices[i].x + (y - y0) * (vertices[j].x - vertices[i].x) / (y1 - y0);
                intersections.push_back(x);
            }
        }

        std::sort(intersections.begin(), intersections.end());

        for (size_t i = 0; i < intersections.size(); i += 2) {
            int startX = std::max(0, static_cast<int>(std::ceil(intersections[i])));
            int endX = static_cast<int>(std::min(static_cast<float>(SCREEN_WIDTH - 1), std::floor(intersections[i + 1])));

            for (int x = startX; x <= endX; ++x) {
                framebuffer[y * SCREEN_WIDTH + x] = color;
            }
        }
    }
}

void render() {
    std::vector<Color> framebuffer(SCREEN_WIDTH * SCREEN_HEIGHT, Color(0, 0, 0));
    // coordinates array (4th polygon)
    std::vector<vert> polygon4 = {
        vert(413.0f, 177.0f),
        vert(448.0f, 159.0f),
        vert(502.0f, 88.0f),
        vert(553.0f, 53.0f),
        vert(535.0f, 36.0f),
        vert(676.0f, 37.0f),
        vert(660.0f, 52.0f),
        vert(750.0f, 145.0f),
        vert(761.0f, 179.0f),
        vert(672.0f, 192.0f),
        vert(659.0f, 214.0f),
        vert(615.0f, 214.0f),
        vert(632.0f, 230.0f),
        vert(580.0f, 230.0f),
        vert(597.0f, 215.0f),
        vert(552.0f, 214.0f),
        vert(517.0f, 144.0f),
        vert(466.0f, 180.0f)
    }; 

    // white outline
    Color polygonColor4(255, 255, 255);
    // green fill
    Color polygonFill4(0, 255, 0);
    fillPolygon(polygon4, polygonFill4, framebuffer);
    polygonOutline(polygon4, polygonColor4, framebuffer);

    // 5th polygon
    std::vector<vert> polygon5 = {
        vert(682.0f, 175.0f),
        vert(708.0f, 120.0f),
        vert(735.0f, 148.0f),
        vert(739.0f, 170.0f)
    };

    Color polygonColor5(255, 255, 255);  
    Color polygonFill5(0, 0, 0);
    fillPolygon(polygon5, polygonFill5, framebuffer);
    polygonOutline(polygon5, polygonColor5, framebuffer);
    renderBuffer(framebuffer);
}
 
int main() {
    clear();
    render();
    return 0;
}