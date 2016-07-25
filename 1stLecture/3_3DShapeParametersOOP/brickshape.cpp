#include "brickshape.h"

BrickShape::BrickShape(unsigned int edges[3])
{
    this->calculateSurface(edges);
    this->calculateVolume(edges);
}

void
BrickShape::calculateSurface(unsigned int* edges)
{
    m_surface = 2*( (edges[0]*edges[1]) + (edges[0]*edges[2]) + (edges[1]*edges[2]) );
}

void
BrickShape::calculateVolume(unsigned int* edges)
{
    m_volume = edges[0]*edges[1]*edges[2];
}

unsigned int
BrickShape::getSurface() const
{
    return m_surface;
}

unsigned int
BrickShape::getVolume() const
{
    return m_volume;
}
