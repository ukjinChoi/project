#include <stdio.h>

/**
 * @brief
 * char : 1Byte
 * short : 2Byte
 * int : 4Byte
 * long : 32bit linux -> 4Byte, 64bit linux -> 8Byte  window -> 4Byte;  
 * 
 */
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef unsigned char BYTE;
typedef int LONG;
#pragma pack(push,1)
typedef struct tagBITMAPFILEHEADER {
    WORD  bfType;              // bitmap 'BM' 
    DWORD bfSize;              // bitmap file size
    WORD  bfReserved1;         // reserved 0
    WORD  bfReserved2;         // reserved 0
    DWORD bfOffBits;           // offset data
} BITMAPFILEHEADER, *LPBITMAPFILEHEADER, *PBITMAPFILEHEADER;
typedef struct tagBITMAPINFOHEADER {
    DWORD biSize;              // structure size
    LONG  biWidth;             // BITMAP width
    LONG  biHeight;            // BITMAP height
    WORD  biPlanes;            // BITMAP Planes
    WORD  biBitCount;          // BITMAP bit count
    DWORD biCompression;       // -
    DWORD biSizeImage;         // 
    LONG  biXPelsPerMeter;
    LONG  biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} BITMAPINFOHEADER, *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;
#pragma pack(pop)

void printBitmapFileHeader(BITMAPFILEHEADER bmFileHeader)
{
    printf("bfType      : %hx\n", bmFileHeader.bfType      );
    printf("bfSize      : %x\n", bmFileHeader.bfSize      );
    printf("bfReserved1 : %x \n", bmFileHeader.bfReserved1 );
    printf("bfReserved2 : %x \n", bmFileHeader.bfReserved2 );
    printf("bfOffBits   : %x\n", bmFileHeader.bfOffBits   );
}
