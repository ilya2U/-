#include <stdio.h>
#include <tchar.h>
#include <string.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
#include <wchar.h>
#include "qrencode.h" //by libqrencode

#define QRCODE_TEXT            "http://ru.wikipedia.org/wiki/QR-%EA%EE%E4" // Text to encode into QRCode
#define OUT_FILE            "C:/test.bmp"     // Output file name
#define OUT_FILE_PIXEL_PRESCALER    8 // Number of pixels in bmp file for each QRCode pixel, on each dimension

#define PIXEL_COLOR_R            0 // Color of bmp pixels
#define PIXEL_COLOR_G            0
#define PIXEL_COLOR_B            0xff

typedef unsigned short    WORD;
typedef unsigned long    DWORD;
typedef signed long    LONG;

#define BI_RGB                0L

#pragma pack(push, 2)

typedef struct
{
    WORD    bfType;
    DWORD   bfSize;
    WORD    bfReserved1;
    WORD    bfReserved2;
    DWORD   bfOffBits;
} BITMAPFILEHEADER;

typedef struct
{
    DWORD      biSize;
    LONG       biWidth;
    LONG       biHeight;
    WORD       biPlanes;
    WORD       biBitCount;
    DWORD      biCompression;
    DWORD      biSizeImage;
    LONG       biXPelsPerMeter;
    LONG       biYPelsPerMeter;
    DWORD      biClrUsed;
    DWORD      biClrImportant;
} BITMAPINFOHEADER;

#pragma pack(pop)

int _tmain(int argc, _TCHAR** argv)
{
    char*       szSourceSring = QRCODE_TEXT;
    unsigned int   unWidth, x, y, l, n, unWidthAdjusted, unDataBytes;
    unsigned char* pRGBData, *pSourceData, *pDestData;
    QRcode*       pQRC;
    FILE*       f;

/*
 * Создание символа из строки. Библиотека автоматически
 * парсит входную строку и кодирует ее в символ QR-кода.
 * WARNING: Эта функция THREAD-UNSAFE, когда pthread отключен.
 * Параметры:
 * string: входная строка; должна завершаться нулем
 * version: версия символа; если 0, библиотека выбирает минимальную версию входных данных
 * level: уровень коррекции ошибок
 * hint: указывает библиотеке на то, как должны кодироваться не алфавитные символы
 *       QR_MODE_KANJI - иероглифы будут кодироваться как Shif-JIS
 *       QR_MODE_8 - все не алфавитные символы будут кодироваться как есть. Для UTF-8, выбирайте этот режим
 * casesensitive: case-sensitive(1) или нет(0).
 * return: экземпляр класса QRcode; при ошибке возвращается NULL и errno устанавливает ошибку
 *         EINVAL: некорректный входной объект
 *         ENOMEM: не удается выделить память для входных объектов
 *         ERANGE: входные данные слишком большие
 */

    // Вычисление QRcode
    if (pQRC = QRcode_encodeString(szSourceSring, 0, QR_ECLEVEL_H, QR_MODE_8, 1))
    {
        unWidth = pQRC->width;
        unWidthAdjusted = unWidth * OUT_FILE_PIXEL_PRESCALER * 3;
        if (unWidthAdjusted % 4)
            unWidthAdjusted = (unWidthAdjusted / 4 + 1) * 4;
        unDataBytes = unWidthAdjusted * unWidth * OUT_FILE_PIXEL_PRESCALER;

        if (!(pRGBData = (unsigned char*)malloc(unDataBytes)))
        {
            printf("Out of memory");
            exit(1);
        }

        memset(pRGBData, 0xff, unDataBytes);

        // Подготовка заголовков bmp
        BITMAPFILEHEADER kFileHeader;
        kFileHeader.bfType = 0x4d42;  // "BM"
        kFileHeader.bfSize =    sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + nDataBytes;
        kFileHeader.bfReserved1 = 0;
        kFileHeader.bfReserved2 = 0;
        kFileHeader.bfOffBits =    sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

        BITMAPINFOHEADER kInfoHeader;
        kInfoHeader.biSize = sizeof(BITMAPINFOHEADER);
        kInfoHeader.biWidth = unWidth * OUT_FILE_PIXEL_PRESCALER;
        kInfoHeader.biHeight = -((int)unWidth * OUT_FILE_PIXEL_PRESCALER);
        kInfoHeader.biPlanes = 1;
        kInfoHeader.biBitCount = 24;
        kInfoHeader.biCompression = BI_RGB;
        kInfoHeader.biSizeImage = 0;
        kInfoHeader.biXPelsPerMeter = 0;
        kInfoHeader.biYPelsPerMeter = 0;
        kInfoHeader.biClrUsed = 0;
        kInfoHeader.biClrImportant = 0;

        // Конвертирование битов QrCode в bmp пиксели
        pSourceData = pQRC->data;
        for(y = 0; y < unWidth; y++)
        {
            pDestData = pRGBData + unWidthAdjusted * y * OUT_FILE_PIXEL_PRESCALER;
            for(x = 0; x < unWidth; x++)
            {
                if (*pSourceData & 1)
                    for(l = 0; l < OUT_FILE_PIXEL_PRESCALER; l++)
                        for(n = 0; n < OUT_FILE_PIXEL_PRESCALER; n++)
                        {
                            *(pDestData + n * 3 + unWidthAdjusted * l) = PIXEL_COLOR_B;
                            *(pDestData + 1 + n * 3 + unWidthAdjusted * l) = PIXEL_COLOR_G;
                            *(pDestData + 2 + n * 3 + unWidthAdjusted * l) = PIXEL_COLOR_R;
                        }
                pDestData += 3 * OUT_FILE_PIXEL_PRESCALER;
                pSourceData++;
            }
        }

        if (!(fopen_s(&f, OUT_FILE, "wb")))
        {
            fwrite(&kFileHeader, sizeof(BITMAPFILEHEADER), 1, f);
            fwrite(&kInfoHeader, sizeof(BITMAPINFOHEADER), 1, f);
            fwrite(pRGBData, sizeof(unsigned char), unDataBytes, f);
            
            fclose(f);
        }
        else
        {
            printf("Unable to open file");
            exit(1);
        }

        free(pRGBData);
        QRcode_free(pQRC);
    }
    else
    {
        printf("NULL returned");
        exit(1);
    }

    return 0;
}
