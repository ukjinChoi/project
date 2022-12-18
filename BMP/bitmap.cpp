#include "BMP.h"
#include <iostream>
#include <fstream>

void* loadBMP(const std::string& filename)
{
    std::ifstream fp;
    fp.open(filename, std::ios::in | std::ios::binary | std::ios::ate);
    if (!fp.is_open()) {
        printf("fail to open file : %s\n", filename.c_str());
        return 0;
    }
    int size = fp.tellg();
    char* data = new char [size];
    fp.seekg(0, std::ios::beg);
    fp.read(data, size);
    fp.close();
    return data;
}

void saveBMP(void* data, const std::string& filename)
{
    std::ofstream fp;
    fp.open(filename, std::ios::out | std::ios::binary);
    if (!fp.is_open()) {
        printf("fail to open file : %s\n", filename.c_str());
        return;
    }
    BITMAPFILEHEADER bitmapFileHeader;
    memcpy(&bitmapFileHeader, data, sizeof(BITMAPFILEHEADER));
    fp.write((char*)data, bitmapFileHeader.bfSize);
    fp.close();
    return;
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("input file name to load\n");
        return 0;
    }
    else if (argc < 3) {
        printf("input file to save\n");
        return 0;
    }
    char* data = (char*)loadBMP(std::string(argv[1]));
    saveBMP(data, std::string(argv[2]));
    delete[] data;
    return 0;
}