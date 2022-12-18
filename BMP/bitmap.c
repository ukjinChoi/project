#include "BMP.h"
#include <string.h>
#include <stdlib.h>


void* loadBMP(const char* filename)
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("fail to open file : %s\n", filename);
        return 0;
    }
    BITMAPFILEHEADER bmFileHeader;
    BITMAPINFOHEADER bmInfoHeader;
    int ret = fread(&bmFileHeader, sizeof(BITMAPFILEHEADER), 1, fp);
    if (ret != 1) {
        printf("fail to read BITMAPFILEHEADER\n");
        fclose(fp);
        return NULL;
    }
    //printBitmapFileHeader(bmFileHeader);
    /*
    ret = fread(&bmInfoHeader, sizeof(BITMAPINFOHEADER), 1, fp);
    if (ret != 1) {
        printf("fail to read BITMAPINFOHEADER\n");
        return NULL;
    }*/
    BYTE* data = (BYTE*)malloc(bmFileHeader.bfSize * sizeof(BYTE));
    if (data == NULL) {
        printf("fail to malloc %u\n", bmFileHeader.bfSize);
        fclose(fp);
        return NULL;
    }
    fseek(fp, 0, SEEK_SET);
    ret = fread(data, sizeof(BYTE), bmFileHeader.bfSize, fp);
    if (ret != bmFileHeader.bfSize) {
        printf("fail to read BMP File\n");
        fclose(fp);
        free(data);
        return NULL;
    }
    fclose(fp);
    return data;
}

void saveBMP(void* data, const char* filename)
{
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("fail to open file : %s\n", filename);
        return;
    }
    BITMAPFILEHEADER bitmapFileHeader;
    memcpy(&bitmapFileHeader, data, sizeof(BITMAPFILEHEADER));
    int ret = fwrite(data, sizeof(BYTE), bitmapFileHeader.bfSize, fp);
    if (ret != bitmapFileHeader.bfSize) {
        printf("fail to write BMP\n");
        fclose(fp);
        return;
    }
    fclose(fp);
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
    BYTE* data = loadBMP(argv[1]);
    saveBMP(data, argv[2]);
    free(data);
    return 0;
}