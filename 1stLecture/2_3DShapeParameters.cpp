#include <iostream> //used for talking to the screen
#include <sstream>  //for converting text to numbers
#include <fstream>  //for conversion flag checking

bool acceptedNumberOfAurguments(const int count){
    return (count == 2 || count == 4);
}

int calculateSurface(unsigned int* edges); //these could be long functions
int calculateVolume(unsigned int* edges); //so we put the implementation somewhere else

int main(int argc, char *argv[])
{
    if( !acceptedNumberOfAurguments(argc) )
    {
        std::cerr << "Incorrect number of arguments!\n";
        std::cerr << "For cube  use: " << argv[0] << " [edge lenght]\n";
        std::cerr << "for brick use: " << argv[0] << " [edge a] [edge b] [edge c]\n";
        return 1; //return anything but 0 indicating that the program did not ended at a point where it was supposed to.
    }

    unsigned int edges[3];

    for(int i(1); i < (argc); ++i){
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

    //display the results
    std::cout << "The surface of the object is: " << calculateSurface(edges) << '\n';
    std::cout << "The volume  of the object is: " << calculateVolume(edges) << std::endl;

    return 0;
}

int calculateSurface(unsigned int* edges){
    return 2*( (edges[0]*edges[1]) + (edges[0]*edges[2]) + (edges[1]*edges[2]) );
}

int calculateVolume(unsigned int* edges){
    return edges[0]*edges[1]*edges[2];
}
