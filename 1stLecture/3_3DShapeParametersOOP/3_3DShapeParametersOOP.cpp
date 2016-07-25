#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include "brickshape.h" //Include the header for the brick object, so we can use it

bool
acceptedNumberOfAurguments(const int count)
{
    return (count == 2 || count == 4);
}

int main(int argc, char *argv[])
{
    if( !acceptedNumberOfAurguments(argc) )
    {
        std::cerr << "Incorrect number of arguments!\n";
        std::cerr << "For cube  use: " << argv[0] << " [edge lenght]\n";
        std::cerr << "for brick use: " << argv[0] << " [edge a] [edge b] [edge c]\n";
        return 1;
    }

    unsigned int edges[3];

    for(int i(1); i < argc; ++i){
        std::istringstream str(argv[i]);
        str >> edges[i-1];

        if( str.rdstate() & std::ifstream::failbit ){
            std::cerr << "Edge lenght can only include integers. No other character accepted!" << std::endl;
            return 1;
        }
    }


    if(argc == 2){ //if it's a cube make all edges equal
        edges[1] = edges[2] = edges[0];
    }

    BrickShape brick(edges); //create a brick object and let is do it's job

    std::cout << "The surface of the object is: " << brick.getSurface() << '\n';
    std::cout << "The volume  of the object is: " << brick.getVolume() << std::endl;

    return 0;
}


