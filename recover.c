//Program to Recover bitmap Images

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define JAR 512

//making a struct
typedef unsigned char BYTE;

bool new_Jpeg_Start(BYTE buffer[]);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    BYTE buffer[JAR];

    //Open raw File
    FILE *outfile = NULL;
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Unable to open file");
        return 1;
    }

    // boolean to see if a Jpeg is found
    bool found =  false;

    // index of n numbers of jpeg found
    int index = 0;

    while (fread(buffer, JAR, 1, file))
    {
        if (new_Jpeg_Start(buffer))
        {
            if (!found)
            {
                found = true;
            }
            else
            {
                fclose(outfile);
            }
            //Creating Filename and assigning its value
            char filename[8];
            sprintf(filename, "%03i.jpg", index++);

            //opening the new outfile
            outfile = fopen(filename, "w");
            if (outfile == NULL)
            {
                return 1;
            }

            fwrite(buffer, JAR, 1, outfile);
        }
        else if (found)
        {
            fwrite(buffer, JAR, 1, outfile);
        }
    }
    fclose(file);
    fclose(outfile);
}

bool new_Jpeg_Start(BYTE buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}