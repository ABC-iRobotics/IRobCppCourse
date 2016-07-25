#include <iostream> //used for talking to the screen
#include <sstream>  //for converting text to numbers
#include <fstream>  //for conversion flag checking

int main(int argc, char *argv[])
{
    // first we check if the algorythm was called with the right number of arguments
    if(argc != 2 && argc != 4)
    {
        std::cerr << "Incorrect number of arguments!\n";
        std::cerr << "For cube  use: " << argv[0] << " [edge lenght]\n";
        std::cerr << "for brick use: " << argv[0] << " [edge a] [edge b] [edge c]\n";
        // We used argv[0] instead of hardcoding the program name
        return 1; //return anything but 0 indicating that the program did not ended at a point where it was supposed to.
    }

    unsigned int edges[3]; //we have a maximum of 3 edge lenght (a,b,c) so just store them in an array

    for(int i(1); i < (argc); ++i){
        std::istringstream str(argv[i]); //convert the char array into something usable
        str >> edges[i-1]; // create number from the string

        if( str.rdstate() & std::ifstream::failbit ){
            std::cerr << "Edge lenght can only include integers. No other character accepted!" << std::endl;
            return 1;
        }
    }


    if(argc == 2){ //if it's a cube make all edges equal
        edges[1] = edges[2] = edges[0];
    }

    //Calculate the surface area
    unsigned int surface = 2*( (edges[0]*edges[1]) + (edges[0]*edges[2]) + (edges[1]*edges[2]) );
    unsigned int volume = edges[0]*edges[1]*edges[2];

    //display the results
    std::cout << "The surface of the object is: " << surface << '\n';
    std::cout << "The volume  of the object is: " << volume << std::endl;

    //We don't really want to rerun the program so we just exit here.
    return 0;
}
