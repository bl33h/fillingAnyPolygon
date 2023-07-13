    // coordinates array
    std::vector<vert> polygon2 = {
     vert(321, 335),
    vert(288, 286),
    vert(339, 251),
    vert(374, 302)
};

    // white for the outline
    Color polygonColor2(255, 255, 255);  
    // blue fill
    Color polygonFill2(255, 0, 0); // backwards config
    fillPolygon(polygon2, polygonFill2, framebuffer);
    polygonOutline(polygon2, polygonColor2, framebuffer);
    renderBuffer(framebuffer);
}