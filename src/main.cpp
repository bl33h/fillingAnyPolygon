    // coordinates array
    std::vector<vert> polygon = {
        vert(165.0f, 380.0f),
        vert(185.0f, 360.0f),
        vert(180.0f, 330.0f),
        vert(207.0f, 345.0f),
        vert(233.0f, 330.0f),
        vert(230.0f, 360.0f),
        vert(250.0f, 380.0f),
        vert(220.0f, 385.0f),
        vert(205.0f, 410.0f),
        vert(193.0f, 383.0f)
    };

    // white for the outline
    Color polygonColor(255, 255, 255);  
    // yellow fill
    Color polygonFill(0, 255, 255); // backwards config
    fillPolygon(polygon, polygonFill, framebuffer);
    polygonOutline(polygon, polygonColor, framebuffer);
    renderBuffer(framebuffer);
}