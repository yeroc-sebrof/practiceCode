#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) 
{ 
    FILE * currentFile; // Temporary File pointer
    vector<FILE *> allFiles; // File Pointer Storage

    //long lSize; // File size variable (Not currently needed as we are couting the size immediately)

    cout << "You have entered " << argc-1
         << " files to scan:" << "\n";
    
    // No point continuing without args
    if (argc<2)
        return 1;

    for (int i = 1; i < argc; i++) // For arg that isn't the executable being called
    {
        cout << "\n" << "Reading " << argv[i] << "\n";

        currentFile = fopen(argv[i], "rb");
        if (currentFile==NULL) // If file didn't open in prev line
        {
            cout << "File Error with: " << argv[i] << ", does this file exist here?";
            continue; // Next for loop
        }

        allFiles.push_back(currentFile); // Add file to vector
        /// This could be improved with pairs to keep the file name and a FILE pointer
        cout << "File " << argv[i] << " added successfully";
    }

    cout << "Continuing with " << allFiles.size() << " files" << "\n";
    
    // Get file sizes of those that exist
    for (int i=0; i < allFiles.size(); i++)
    {
        fseek (allFiles[i] , 0 , SEEK_END);
        cout << "File " << i+1 << " is of size: " << ftell (allFiles[i]) << " Bytes\n";
        rewind (allFiles[i]);
    }

    return 0; 
}
