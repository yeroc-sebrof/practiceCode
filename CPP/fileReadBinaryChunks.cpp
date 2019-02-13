#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

#define endl "\n"

#define DEBUG
//#define CLIARGS

using std::string;
using std::cout;
using std::vector;

int main(int argc, char** argv)
{
	FILE * fileToCarve; // File pointer
	size_t chunkSize = 100;
	char * buffer;
	string wrapper;

	long fSize; // File size variable

	#ifdef DEBUG
		#ifdef _WIN32
			cout << system("cd") << endl;
		#endif // _WIN32
	#endif // DEBUG

#ifdef CLIARGS
	cout << "Just looking at first file from CLI Args: ";

	// No point continuing without args
	if (argc < 2)
	{
		cout << "Which cant be seen!";
		return 1;
	}

	cout << argv[1] << endl;

	#pragma warning(suppress : 4996) // fopen isn't working I will replace after this
	fileToCarve = fopen(argv[1], "rb");
#else // CLIARGS
	#pragma warning(suppress : 4996)
	fileToCarve = fopen("TestFile.test", "rb");
#endif // CLIARGS

	if (fileToCarve == NULL) // If file didn't open in prev line
	{
#ifdef CLIARGS
		cout << "File Error with: " << argv[1] << endl << "Does this file exist here?" << endl;
#else
		cout << "File Error with: TestFile.test" << endl << "Does this file exist here?" << endl;
#endif // CLIARGS
		return 1;
	}

#ifdef DEBUG
	cout << endl << "Continuing with file" << endl;
#endif

	// Get file size
	fseek(fileToCarve, 0, SEEK_END);
	fSize = ftell(fileToCarve);
	
#ifdef CLIARGS
	cout << argv[1] << " is of size: " << fSize << " Bytes" << endl << endl;
#else
	cout << "TestFile.test is of size: " << fSize << " Bytes" << endl << endl;
#endif 

	rewind(fileToCarve);

	/// Start new code
	// http://www.cplusplus.com/reference/cstdio/fread/

	// allocate memory to contain the chunk:
	buffer = (char*) malloc(sizeof (char)*chunkSize);
	if (buffer == NULL) { fputs("Memory error", stderr); return 2; }
	
	// copy the file into the buffer:
	fread(buffer, chunkSize, 1, fileToCarve);

	wrapper = buffer;

	cout << wrapper.substr(0, 99);

	//fseek(fileToCarve, chunkSize, SEEK_CUR); // This skips a chunk

	fread(buffer, chunkSize, 1, fileToCarve);

	cout << buffer;
	/// End new code

	cout << endl;

	free(buffer);
	return 0;
}
