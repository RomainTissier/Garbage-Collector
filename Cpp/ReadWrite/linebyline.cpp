#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

int main(){
	std::cout << "Print linebyline.cpp"<<std::endl;
	std::ifstream inputFileStream = std::ifstream("linebyline.cpp");
	std::string currentLine;
	int count=1;
	while (std::getline(inputFileStream, currentLine)) {
		std::cout << count << " : "<< currentLine<<std::endl;
		count++;
	}
	inputFileStream.close();
}
