    // coordinates array
    std::vector<vert> polygon3 = {
    vert(377, 249),
    vert(411, 197),
    vert(436, 249)
};

    // white for the outline
    Color polygonColor3(255, 255, 255);  
    // red fill
    Color polygonFill3(0, 0, 255); // backwards config
    fillPolygon(polygon3, polygonFill3, framebuffer);
    polygonOutline(polygon3, polygonColor3, framebuffer);
    renderBuffer(framebuffer);
}