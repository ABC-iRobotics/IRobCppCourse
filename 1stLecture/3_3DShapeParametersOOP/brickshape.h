#ifndef BRICKSHAPE_H
#define BRICKSHAPE_H
// The ifndef makes sure that there will be only one instance of this file.
// Look into it if you have never seen this before.

class BrickShape
{    
    unsigned int m_surface; //This should not be modified by anybody besides this class
    unsigned int m_volume; //This should not be modified by anybody besides this class

protected:
    void calculateSurface(unsigned int* edges); //We allow these to be overwritten in the future
    void calculateVolume(unsigned int* edges); //We allow these to be overwritten in the future

public:
    BrickShape(unsigned int edges[3]); //Public constructor. 
    //Truth to be told there shoud be a better way to ensure we only accept 3 elemnt long arrays.

    unsigned int getSurface() const; //the getter should pay as passive role as possible.
    unsigned int getVolume() const;  //this is the reason we declare it as a const function.


};

#endif // BRICKSHAPE_H
