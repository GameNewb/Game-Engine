#include <stdio.h>
#include <SDL.h>
#include <GL/glew.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Tile.h"
#include "DrawUtils.h"

const int tileMaps[64][64] = 
{ 
	//      1	 2	  3    4    5    6    7    8    9   10   11   12    13    14    15    16    17    18    19    20    21    22    23    24    25    26    27    28    29    30    31    32    33    34    35    36    37    38    39    40    41    42    43    44    45    46    47    48    49    50    51    52    53    54    55    56    57    58    59    60    61    62    63    64
	{   9,  -1,	  3,   5,   1,   3,	  5,   1,   3,   5,   1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5},
	{  10,  -2,   4,   6,   2,   4,   6,   2,   4,   6,   2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6},
	{	9,  11,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   59},
	{  10,  12,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   50,   52,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60},
	{   9,  11,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   56,   58,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60},
	{  10,  12,   0,   0,   0,   0,  41,  43,   0,   0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   -3,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60},
	{	9,  11,   0,   0,   0,   0,  47,  49,   0,   0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   -6,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60},
	{  10,  12,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   59,   62,   62,   62,   62,   62,   65,   68,    0,    0,    0,    0,    0,   -7,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60},
	{	9,  11,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60,   63,   63,   63,   63,   63,   66,   69,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60},
	{  10,  12,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60,   63,   63,   63,   63,   63,   66,   69,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60},
	{	9,  11,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,   50,   52,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60,   63,   63,   63,   63,   63,   66,   69,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60},
	{  10,  12,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,   23,   26,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60,   63,   63,   63,   63,   63,   66,   69,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60},
	{	9,  11,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,   24,   27,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   61,   64,   64,   64,   64,   64,   67,   70,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60},
	{  10,  12,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,   25,   28,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   -9,  -10,  -10,  -10,  -10,  -10,  -11,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60},
	{	9,  11,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60},
	{  10,  12,   0,   0,   0,   0,   0,   0,   0,   0,  -4,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60},
	{   9,  11,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60},
	{  10,  12,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,   -4,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   50,   51,   52,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60},
	{	9,  11,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   53,   54,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60},
	{  10,  12,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   56,   57,   58,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60},
	{	9,  11,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60},
	{  10,  12,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60},
	{	9,  11,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //23
	{  10,  12,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //24
	{	9,  11,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //25
	{  10,  12,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //26
	{	9,  11,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //27
	{  13,  14,  15,  15,  15,  15,  16,  17,   0,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //28
	{	9,  11,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,   41,   42,   42,   42,   42,   42,   42,   43,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //29
	{  10,  12,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,   -3,   53,   55,    0,    0,    0,    0,   44,   45,   45,   45,   45,   45,   45,   46,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   -4,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //30
	{	9,  11,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,   -5,   -3,   -3,   -5,   53,   55,    0,    0,    0,    0,   44,   45,   45,   45,   45,   45,   45,   46,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60},  //31
	{  10,  12,   0,   0,   0,  50,  51,  51,  51,  51,  51,   51,   51,   51,   51,   51,   51,   54,   54,   51,   51,   51,   52,   44,   45,   45,   45,   45,   45,   45,   46,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //32
	{   9,  11,   0,  -8,   0,  53,  54,  54,  54,  54,  54,   54,   54,   54,   54,   54,   54,   54,   54,   54,   54,   54,   55,   44,   45,   45,   45,   45,   45,   45,   46,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //33 
	{  10,  12,   0,   0,   0,  56,  57,  57,  57,  57,  57,   57,   57,   57,   57,   57,   57,   54,   54,   57,   57,   57,   58,   44,   45,   45,   45,   45,   45,   45,   46,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //34
	{	9,  11,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,   -5,   -3,   -3,   -5,   53,   55,    0,    0,    0,    0,   44,   45,   45,   45,   45,   45,   45,   46,    0,    0,    0,    0,   -4,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //35
	{  10,  12,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,   -3,   53,   55,    0,    0,    0,    0,   44,   45,   45,   45,   45,   45,   45,   46,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //36
	{   9,  11,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,   47,   48,   48,   48,   48,   48,   48,   49,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //37
	{  18,  19,  20,  20,  20,  20,  21,  22,   0,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //38
	{   9,  11,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   50,   52,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //39
	{  10,  12,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //40
	{   9,  11,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //41
	{  10,  12,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   56,   58,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //42
	{   9,  11,   0,   0,   0,   0,   0,   0,  -4,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //43 
	{  10,  12,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   59,   62,   62,   62,   65,   68,    0,    0,    0,    0,   60}, //44
	{   9,  11,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,   -3,   53,   55,   -3,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   -6,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60,   63,   63,   63,   66,   69,    0,    0,    0,    0,   60}, //45
	{  10,  12,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,   -3,   53,   55,   -3,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   -7,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60,   63,   63,   63,   66,   69,    0,    0,    0,    0,   60}, //46
	{   9,  11,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,   -3,   53,   55,   -3,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   61,   64,   64,   64,   67,   70,    0,    0,    0,    0,   60}, //47
	{  10,  12,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   -9,  -10,  -10,  -10,  -11,    0,    0,    0,    0,   60}, //48
	{   9,  11,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //49
	{  10,  12,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,   50,   51,   52,    0,   53,   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   -4,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //50
	{   9,  11,   0,   0,   0,  -4,   0,   0,   0,   0,   0,    0,    0,   53,   54,   55,    0,   56,   58,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //51
	{  10,  12,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,   56,   57,   58,    0,   -5,   -5,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //52
	{   9,  11,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   -4,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   60}, //53
	{  10,  12,   0,   0, 	0,   0,   0,   0,   0,   0,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   61}, //54
	{   9,  -1,   3,   5, 	1,   3,   5,   1,   3,   5,   1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5,    1,    3,    5}, //55
	{  10,  -2,   4,   6, 	2,   4,   6,   2,   4,   6,   2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6,    2,    4,    6} //56
};

Tile::Tile()
{
	tileType = 0;
	TILE_WIDTH = 32;
	TILE_HEIGHT = 32;

}

void Tile::setTile(int i, int j)
{
	x = i*TILE_WIDTH;
	y = j*TILE_HEIGHT;
	w = TILE_WIDTH;
	h = TILE_HEIGHT;
	depth = 0; // Depth 1 means that player will appear behind the tile object

	switch(value)
	{
		/* MISCELLANEOUS */
		case -1:
			image = glTexImageTGAFile("Texture/Tiles/Trees/topLeftTreeShadow.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case -2:
			image = glTexImageTGAFile("Texture/Tiles/Trees/topRightTreeShadow.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case -3:
			image = glTexImageTGAFile("Texture/Tiles/Trees/bush.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			tileType = 1;
			break;
		case -4:
			image = glTexImageTGAFile("Texture/Tiles/Trees/stone.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			break;
		case -5:
			image = glTexImageTGAFile("Texture/Tiles/Trees/flower.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			tileType = 1;
			break;
		case -6:
			image = glTexImageTGAFile("Texture/Tiles/Trees/treeTrunkLeft.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case -7:
			image = glTexImageTGAFile("Texture/Tiles/Trees/treeTrunkRight.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case -8:
			image = glTexImageTGAFile("Texture/Tiles/grassCollidable.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case -9:
			image = glTexImageTGAFile("Texture/Tiles/shadowTop.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			break;
		case -10:
			image = glTexImageTGAFile("Texture/Tiles/shadowMid.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			break;
		case -11:
			image = glTexImageTGAFile("Texture/Tiles/shadowBottom.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			break;
		case -12:
			image = glTexImageTGAFile("Texture/Tiles/Trees/topLeftTreePlain.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			depth = 1;
			break;
		case -13:
			image = glTexImageTGAFile("Texture/Tiles/Trees/topRightTreePlain.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			depth = 1;
			break;
		case -14:
			image = glTexImageTGAFile("Texture/Misc/slab.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case -15:
			image = glTexImageTGAFile("Texture/Tiles/grass4.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			break;
		case -16:
			image = glTexImageTGAFile("Texture/Tiles/Field/flower2.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case -17:
			image = glTexImageTGAFile("Texture/Tiles/Field/fieldPillarEnd.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case -18:
			image = glTexImageTGAFile("Texture/Tiles/Field/slab2.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case -19:
			image = glTexImageTGAFile("Texture/Tiles/Field/shadow2Top.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			break;
		case -20:
			image = glTexImageTGAFile("Texture/Tiles/Field/shadow2Mid.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			break;
		case -21:
			image = glTexImageTGAFile("Texture/Tiles/Field/shadow2Bottom.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			break;

		/* TREES AND GRASS */
		case 0:
			image = glTexImageTGAFile("Texture/Tiles/grass2.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			break;
		case 1:
			image = glTexImageTGAFile("Texture/Tiles/Trees/topLeftTree.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 2:
			image = glTexImageTGAFile("Texture/Tiles/Trees/topRightTree.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 3:
			image = glTexImageTGAFile("Texture/Tiles/Trees/midLeftTree.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 4:
			image = glTexImageTGAFile("Texture/Tiles/Trees/midRightTree.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 5:
			image = glTexImageTGAFile("Texture/Tiles/Trees/bottomLeftTree.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 6:
			image = glTexImageTGAFile("Texture/Tiles/Trees/bottomRightTree.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 7:
			image = glTexImageTGAFile("Texture/Tiles/Trees/endLeftTree.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 8:
			image = glTexImageTGAFile("Texture/Tiles/Trees/endRightTree.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 9:
			image = glTexImageTGAFile("Texture/Tiles/Trees/stumpTopLeft.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 10:
			image = glTexImageTGAFile("Texture/Tiles/Trees/stumpTopRight.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 11:
			image = glTexImageTGAFile("Texture/Tiles/Trees/stumpBottomLeft.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			break;
		case 12:
			image = glTexImageTGAFile("Texture/Tiles/Trees/stumpBottomRight.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			break;

		/* PILLARS */
		case 13:
			image = glTexImageTGAFile("Texture/Walls/pillarStumpTopLeft.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 14:
			image = glTexImageTGAFile("Texture/Walls/pillarStumpBottomLeft.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 15:
			image = glTexImageTGAFile("Texture/Walls/pillarLeftMidConnector.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 16:
			image = glTexImageTGAFile("Texture/Walls/pillarLeftMid.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 17:
			image = glTexImageTGAFile("Texture/Walls/pillarLeftEnd.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			break;
		case 18:
			image = glTexImageTGAFile("Texture/Walls/pillarStumpTopRight.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 19:
			image = glTexImageTGAFile("Texture/Walls/pillarStumpBottomRight.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 20:
			image = glTexImageTGAFile("Texture/Walls/pillarRightMidConnector.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 21:
			image = glTexImageTGAFile("Texture/Walls/pillarRightMid.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 22:
			image = glTexImageTGAFile("Texture/Walls/pillarRightEnd.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			break;

		/* MORE TREES */
		case 23:
			image = glTexImageTGAFile("Texture/Tiles/Trees/deadTreeTopLeft.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 24:
			image = glTexImageTGAFile("Texture/Tiles/Trees/deadTreeMid.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 25:
			image = glTexImageTGAFile("Texture/Tiles/Trees/deadTreeTopRight.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 26:
			image = glTexImageTGAFile("Texture/Tiles/Trees/deadTreeBottomLeft.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 27:
			image = glTexImageTGAFile("Texture/Tiles/Trees/deadTreeEntrance.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 28:
			image = glTexImageTGAFile("Texture/Tiles/Trees/deadTreeBottomRight.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 29:
			image = glTexImageTGAFile("Texture/Tiles/Field/tree2TopLeftShadow.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 30:
			image = glTexImageTGAFile("Texture/Tiles/Field/tree2TopRightShadow.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 31:
			image = glTexImageTGAFile("Texture/Tiles/Field/tree2MidLeft.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 32:
			image = glTexImageTGAFile("Texture/Tiles/Field/tree2MidRight.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 33:
			image = glTexImageTGAFile("Texture/Tiles/Field/tree2BottomLeft.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 34:
			image = glTexImageTGAFile("Texture/Tiles/Field/tree2BottomRight.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 35:
			image = glTexImageTGAFile("Texture/Tiles/Field/tree2LeftRoot.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			break;
		case 36:
			image = glTexImageTGAFile("Texture/Tiles/Field/tree2RightRoot.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			break;
		case 37:
			image = glTexImageTGAFile("Texture/Tiles/Field/tree2TopLeftPlain.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 38:
			image = glTexImageTGAFile("Texture/Tiles/Field/tree2TopRightPlain.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 39:
			image = glTexImageTGAFile("Texture/Tiles/Field/tree2LeftRootPillar.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 40:
			image = glTexImageTGAFile("Texture/Tiles/Field/tree2RightRootPillar.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
			
		/* WATER */
		case 41: 
			image = glTexImageTGAFile("Texture/Tiles/Water/waterTopLeft.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			tileType = 1;
			break;
		case 42: 
			image = glTexImageTGAFile("Texture/Tiles/Water/waterLeftMid.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			tileType = 1;
			break;
		case 43: 
			image = glTexImageTGAFile("Texture/Tiles/Water/waterBottomLeft.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			tileType = 1;
			break;
		case 44: 
			image = glTexImageTGAFile("Texture/Tiles/Water/waterTopMid.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			tileType = 1;
			break;
		case 45: 
			image = glTexImageTGAFile("Texture/Tiles/Water/waterMid.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			tileType = 1;
			break;
		case 46: 
			image = glTexImageTGAFile("Texture/Tiles/Water/waterBottomMid.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			tileType = 1;
			break;
		case 47: 
			image = glTexImageTGAFile("Texture/Tiles/Water/waterTopRight.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			tileType = 1;
			break;
		case 48: 
			image = glTexImageTGAFile("Texture/Tiles/Water/waterRightMid.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			tileType = 1;
			break;
		case 49: 
			image = glTexImageTGAFile("Texture/Tiles/Water/waterBottomRight.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			tileType = 1;
			break;
		/* GROUND - SAND */
		case 50:
			image = glTexImageTGAFile("Texture/Tiles/Trees/groundTopLeft.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			tileType = 1;
			break;
		case 51:
			image = glTexImageTGAFile("Texture/Tiles/Trees/groundLeftMid.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			tileType = 1;
			break;
		case 52:
			image = glTexImageTGAFile("Texture/Tiles/Trees/groundBottomLeft.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			tileType = 1;
			break;
		case 53:
			image = glTexImageTGAFile("Texture/Tiles/Trees/groundTopMid.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			tileType = 1;
			break;
		case 54:
			image = glTexImageTGAFile("Texture/Tiles/Trees/groundMid.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			tileType = 1;
			break;
		case 55:
			image = glTexImageTGAFile("Texture/Tiles/Trees/groundBottomMid.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			tileType = 1;
			break;
		case 56:
			image = glTexImageTGAFile("Texture/Tiles/Trees/groundTopRight.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			tileType = 1;
			break;
		case 57:
			image = glTexImageTGAFile("Texture/Tiles/Trees/groundRightMid.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			tileType = 1;
			break;
		case 58:
			image = glTexImageTGAFile("Texture/Tiles/Trees/groundBottomRight.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = false;
			tileType = 1;
			break;

		/* WALLS */
		case 59:
			image = glTexImageTGAFile("Texture/Walls/wallTopLeft.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 60:
			image = glTexImageTGAFile("Texture/Walls/wallTopMid.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 61:
			image = glTexImageTGAFile("Texture/Walls/wallTopRight.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 62:
			image = glTexImageTGAFile("Texture/Walls/wallLeftMid.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 63:
			image = glTexImageTGAFile("Texture/Walls/wallMid.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 64:
			image = glTexImageTGAFile("Texture/Walls/wallRightMid.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 65:
			image = glTexImageTGAFile("Texture/Walls/wallBottomLeft.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 66:
			image = glTexImageTGAFile("Texture/Walls/wallBottomMid.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 67:
			image = glTexImageTGAFile("Texture/Walls/wallBottomRight.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 68:
			image = glTexImageTGAFile("Texture/Walls/wallEndLeft.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 69:
			image = glTexImageTGAFile("Texture/Walls/wallEndMid.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 70:
			image = glTexImageTGAFile("Texture/Walls/wallEndRight.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 71:
			image = glTexImageTGAFile("Texture/Walls/wallConnectorLeft.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 72:
			image = glTexImageTGAFile("Texture/Walls/wallConnectorRight.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 73:
			image = glTexImageTGAFile("Texture/Tiles/Field/wallTopLeft2.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 74:
			image = glTexImageTGAFile("Texture/Tiles/Field/wallTopMid2.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 75:
			image = glTexImageTGAFile("Texture/Tiles/Field/wallTopRight2.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 76:
			image = glTexImageTGAFile("Texture/Tiles/Field/wallEndLeft2.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 77:
			image = glTexImageTGAFile("Texture/Tiles/Field/wallEndMid2.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;
		case 78:
			image = glTexImageTGAFile("Texture/Tiles/Field/wallEndRight2.tga", &TILE_WIDTH, &TILE_HEIGHT);
			collidable = true;
			break;

	}
}

int getTileMap(int i, int j)
{
	return tileMaps[i][j];
}

