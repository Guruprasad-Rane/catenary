/*
Catenary- Catenary Curve generator using span and rise.
Version 2.0               .
Copyright (C) 2022 Guruprasad Rane ( raneguruprasad at gmail . com )
                  .
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License.
along with this program.  If not, see <http://www.gnu.org/licenses/>.



Compile : gcc catenary.c -o catenary -lm
Usage : catenary -s <span> -r <rise> -d <divisions> -o <dxfFile> 
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

const char dxf1[]="  0\nSECTION\n  2\nHEADER\n  9\n$ACADVER\n  1\nAC1015\n  9\n$ACADMAINTVER\n 70\n     6\n  9\n$DWGCODEPAGE\n  3\nANSI_1252\n  0\nENDSEC\n  0\nSECTION\n  2\nCLASSES\n  0\nCLASS\n  1\nACDBDICTIONARYWDFLT\n  2\nAcDbDictionaryWithDefault\n  3\nObjectDBX Classes\n 90\n        0\n280\n     0\n281\n     0\n  0\nCLASS\n  1\nVISUALSTYLE\n  2\nAcDbVisualStyle\n  3\nObjectDBX Classes\n 90\n     4095\n280\n     0\n281\n     0\n  0\nCLASS\n  1\nTABLESTYLE\n  2\nAcDbTableStyle\n  3\nObjectDBX Classes\n 90\n     4095\n280\n     0\n281\n     0\n  0\nCLASS\n  1\nDICTIONARYVAR\n  2\nAcDbDictionaryVar\n  3\nObjectDBX Classes\n 90\n        0\n280\n     0\n281\n     0\n  0\nCLASS\n  1\nSCALE\n  2\nAcDbScale\n  3\nObjectDBX Classes\n 90\n     1153\n280\n     0\n281\n     0\n  0\nCLASS\n  1\nCELLSTYLEMAP\n  2\nAcDbCellStyleMap\n  3\nObjectDBX Classes\n 90\n     1152\n280\n     0\n281\n     0\n  0\nCLASS\n  1\nRASTERVARIABLES\n  2\nAcDbRasterVariables\n  3\nISM\n 90\n        0\n280\n     0\n281\n     0\n  0\nCLASS\n  1\nMATERIAL\n  2\nAcDbMaterial\n  3\nObjectDBX Classes\n 90\n     1153\n280\n     0\n281\n     0\n  0\nCLASS\n  1\nSUN\n  2\nAcDbSun\n  3\nSCENEOE\n 90\n     1153\n280\n     0\n281\n     0\n  0\nCLASS\n  1\nMLEADERSTYLE\n  2\nAcDbMLeaderStyle\n  3\nACDB_MLEADERSTYLE_CLASS\n 90\n     4095\n280\n     0\n281\n     0\n  0\nCLASS\n  1\nACDBPLACEHOLDER\n  2\nAcDbPlaceHolder\n  3\nObjectDBX Classes\n 90\n        0\n280\n     0\n281\n     0\n  0\nCLASS\n  1\nLAYOUT\n  2\nAcDbLayout\n  3\nObjectDBX Classes\n 90\n        0\n280\n     0\n281\n     0\n  0\nENDSEC\n  0\nSECTION\n  2\nTABLES\n  0\nTABLE\n  2\nVPORT\n  5\n8\n330\n0\n100\nAcDbSymbolTable\n 70\n     1\n  0\nVPORT\n  5\n29\n330\n8\n100\nAcDbSymbolTableRecord\n100\nAcDbViewportTableRecord\n  2\n*Active\n 70\n     0\n 10\n0.0\n 20\n0.0\n 11\n1.0\n 21\n1.0\n 12\n343.1928513717213\n 22\n148.9970322580646\n 13\n0.0\n 23\n0.0\n 14\n10.0\n 24\n10.0\n 15\n10.0\n 25\n10.0\n 16\n0.0\n 26\n0.0\n 36\n1.0\n 17\n-134.1869158878503\n 27\n0.0\n 37\n0.0\n 40\n385.2\n 41\n1.11214953271028\n 42\n50.0\n 43\n0.0\n 44\n0.0\n 50\n0.0\n 51\n0.0\n 71\n    16\n 72\n  1000\n 73\n     1\n 74\n     3\n 75\n     0\n 76\n     0\n 77\n     0\n 78\n     0\n281\n     0\n 65\n     1\n110\n0.0\n120\n0.0\n130\n0.0\n111\n1.0\n121\n0.0\n131\n0.0\n112\n0.0\n122\n1.0\n132\n0.0\n 79\n     0\n146\n0.0\n  0\nENDTAB\n  0\nTABLE\n  2\nLTYPE\n  5\n5\n330\n0\n100\nAcDbSymbolTable\n 70\n     1\n  0\nLTYPE\n  5\n14\n330\n5\n100\nAcDbSymbolTableRecord\n100\nAcDbLinetypeTableRecord\n  2\nByBlock\n 70\n     0\n  3\n\n 72\n    65\n 73\n     0\n 40\n0.0\n  0\nLTYPE\n  5\n15\n330\n5\n100\nAcDbSymbolTableRecord\n100\nAcDbLinetypeTableRecord\n  2\nByLayer\n 70\n     0\n  3\n\n 72\n    65\n 73\n     0\n 40\n0.0\n  0\nLTYPE\n  5\n16\n330\n5\n100\nAcDbSymbolTableRecord\n100\nAcDbLinetypeTableRecord\n  2\nContinuous\n 70\n     0\n  3\nSolid line\n 72\n    65\n 73\n     0\n 40\n0.0\n  0\nENDTAB\n  0\nTABLE\n  2\nLAYER\n  5\n2\n330\n0\n100\nAcDbSymbolTable\n 70\n     1\n  0\nLAYER\n  5\n10\n330\n2\n100\nAcDbSymbolTableRecord\n100\nAcDbLayerTableRecord\n  2\n0\n 70\n     0\n 62\n     7\n  6\nContinuous\n370\n    -3\n390\nF\n  0\nENDTAB\n  0\nTABLE\n  2\nSTYLE\n  5\n3\n330\n0\n100\nAcDbSymbolTable\n 70\n     1\n  0\nSTYLE\n  5\n11\n330\n3\n100\nAcDbSymbolTableRecord\n100\nAcDbTextStyleTableRecord\n  2\nStandard\n 70\n     0\n 40\n0.0\n 41\n1.0\n 50\n0.0\n 71\n     0\n 42\n2.5\n  3\narial.ttf\n  4\n\n1001\nACAD\n1000\nArial\n1071\n        0\n  0\nENDTAB\n  0\nTABLE\n  2\nVIEW\n  5\n6\n330\n0\n100\nAcDbSymbolTable\n 70\n     0\n  0\nENDTAB\n  0\nTABLE\n  2\nUCS\n  5\n7\n330\n0\n100\nAcDbSymbolTable\n 70\n     0\n  0\nENDTAB\n  0\nTABLE\n  2\nAPPID\n  5\n9\n330\n0\n100\nAcDbSymbolTable\n 70\n     2\n  0\nAPPID\n  5\n12\n330\n9\n100\nAcDbSymbolTableRecord\n100\nAcDbRegAppTableRecord\n  2\nACAD\n 70\n     0\n  0\nAPPID\n  5\nB9\n330\n9\n100\nAcDbSymbolTableRecord\n100\nAcDbRegAppTableRecord\n  2\nAcadAnnotative\n 70\n     0\n  0\nENDTAB\n  0\nTABLE\n  2\nDIMSTYLE\n  5\nA\n330\n0\n100\nAcDbSymbolTable\n 70\n     1\n100\nAcDbDimStyleTable\n  0\nDIMSTYLE\n105\n27\n330\nA\n100\nAcDbSymbolTableRecord\n100\nAcDbDimStyleTableRecord\n  2\nISO-25\n 70\n     0\n 41\n2.5\n 42\n0.625\n 43\n3.75\n 44\n1.25\n 73\n     0\n 74\n     0\n 77\n     1\n 78\n     8\n140\n2.5\n141\n-2.5\n143\n0.03937007874016\n147\n0.625\n171\n     3\n172\n     1\n178\n     0\n271\n     2\n272\n     2\n274\n     3\n278\n    44\n283\n     0\n284\n     8\n340\n11\n  0\nENDTAB\n  0\nTABLE\n  2\nBLOCK_RECORD\n  5\n1\n330\n0\n100\nAcDbSymbolTable\n 70\n     1\n  0\nBLOCK_RECORD\n  5\n1F\n330\n1\n100\nAcDbSymbolTableRecord\n100\nAcDbBlockTableRecord\n  2\n*Model_Space\n340\n22\n  0\nBLOCK_RECORD\n  5\n1B\n330\n1\n100\nAcDbSymbolTableRecord\n100\nAcDbBlockTableRecord\n  2\n*Paper_Space\n340\n1E\n  0\nBLOCK_RECORD\n  5\n23\n330\n1\n100\nAcDbSymbolTableRecord\n100\nAcDbBlockTableRecord\n  2\n*Paper_Space0\n340\n26\n  0\nENDTAB\n  0\nENDSEC\n  0\nSECTION\n  2\nBLOCKS\n  0\nBLOCK\n  5\n20\n330\n1F\n100\nAcDbEntity\n  8\n0\n100\nAcDbBlockBegin\n  2\n*Model_Space\n 70\n     0\n 10\n0.0\n 20\n0.0\n 30\n0.0\n  3\n*Model_Space\n  1\n\n  0\nENDBLK\n  5\n21\n330\n1F\n100\nAcDbEntity\n  8\n0\n100\nAcDbBlockEnd\n  0\nBLOCK\n  5\n1C\n330\n1B\n100\nAcDbEntity\n 67\n     1\n  8\n0\n100\nAcDbBlockBegin\n  2\n*Paper_Space\n 70\n     0\n 10\n0.0\n 20\n0.0\n 30\n0.0\n  3\n*Paper_Space\n  1\n\n  0\nENDBLK\n  5\n1D\n330\n1B\n100\nAcDbEntity\n 67\n     1\n  8\n0\n100\nAcDbBlockEnd\n  0\nBLOCK\n  5\n24\n330\n23\n100\nAcDbEntity\n  8\n0\n100\nAcDbBlockBegin\n  2\n*Paper_Space0\n 70\n     0\n 10\n0.0\n 20\n0.0\n 30\n0.0\n  3\n*Paper_Space0\n  1\n\n  0\nENDBLK\n  5\n25\n330\n23\n100\nAcDbEntity\n  8\n0\n100\nAcDbBlockEnd\n  0\nENDSEC\n  0\nSECTION\n  2\nENTITIES\n  0\nLWPOLYLINE\n  5\n19B\n330\n1F\n100\nAcDbEntity\n  8\n0\n100\nAcDbPolyline\n 90\n        4\n 70\n     0\n 43\n0.0\n";
const char dxf2[]="  0\nENDSEC\n  0\nSECTION\n  2\nOBJECTS\n  0\nDICTIONARY\n  5\nC\n330\n0\n100\nAcDbDictionary\n281\n     1\n  3\nACAD_DETAILVIEWSTYLE\n350\nB5\n  3\nACAD_GROUP\n350\nD\n  3\nACAD_IMAGE_VARS\n350\n6A\n  3\nACAD_LAYOUT\n350\n1A\n  3\nACAD_MLINESTYLE\n350\n17\n  3\nACAD_PLOTSETTINGS\n350\n19\n  3\nACAD_PLOTSTYLENAME\n350\nE\n  3\nACAD_SCALELIST\n350\n40\n  3\nACAD_SECTIONVIEWSTYLE\n350\nB6\n  3\nAcDbVariableDictionary\n350\n3D\n  3\nAPPDATA\n350\n71\n  3\nDimOffsetDictionary\n350\n198\n  3\nDWGPROPS\n350\n19C\n  0\nDICTIONARY\n  5\nB5\n102\n{ACAD_REACTORS\n330\nC\n102\n}\n330\nC\n100\nAcDbDictionary\n281\n     1\n  0\nDICTIONARY\n  5\nD\n102\n{ACAD_REACTORS\n330\nC\n102\n}\n330\nC\n100\nAcDbDictionary\n281\n     1\n  0\nRASTERVARIABLES\n  5\n6A\n102\n{ACAD_REACTORS\n330\nC\n102\n}\n330\nC\n100\nAcDbRasterVariables\n 90\n        0\n 70\n     1\n 71\n     1\n 72\n     1\n  0\nDICTIONARY\n  5\n1A\n102\n{ACAD_REACTORS\n330\nC\n102\n}\n330\nC\n100\nAcDbDictionary\n281\n     1\n  3\nModel\n350\n22\n  3\nSheet1\n350\n1E\n  3\nSheet2\n350\n26\n  0\nDICTIONARY\n  5\n17\n102\n{ACAD_REACTORS\n330\nC\n102\n}\n330\nC\n100\nAcDbDictionary\n281\n     1\n  3\nStandard\n350\n18\n  0\nDICTIONARY\n  5\n19\n102\n{ACAD_REACTORS\n330\nC\n102\n}\n330\nC\n100\nAcDbDictionary\n281\n     1\n  0\nACDBDICTIONARYWDFLT\n  5\nE\n102\n{ACAD_REACTORS\n330\nC\n102\n}\n330\nC\n100\nAcDbDictionary\n281\n     1\n  3\nNormal\n350\nF\n100\nAcDbDictionaryWithDefault\n340\nF\n  0\nDICTIONARY\n  5\n40\n102\n{ACAD_REACTORS\n330\nC\n102\n}\n330\nC\n100\nAcDbDictionary\n281\n     1\n  3\nA0\n350\n41\n  0\nDICTIONARY\n  5\nB6\n102\n{ACAD_REACTORS\n330\nC\n102\n}\n330\nC\n100\nAcDbDictionary\n281\n     1\n  0\nDICTIONARY\n  5\n3D\n102\n{ACAD_REACTORS\n330\nC\n102\n}\n330\nC\n100\nAcDbDictionary\n281\n     1\n  0\nDICTIONARY\n  5\n71\n102\n{ACAD_REACTORS\n330\nC\n102\n}\n330\nC\n100\nAcDbDictionary\n281\n     1\n  0\nDICTIONARY\n  5\n198\n102\n{ACAD_REACTORS\n330\nC\n102\n}\n330\nC\n100\nAcDbDictionary\n281\n     1\n  3\nDIMRAILSENABLED\n350\n19A\n  0\nXRECORD\n  5\n19C\n102\n{ACAD_REACTORS\n330\nC\n102\n}\n330\nC\n100\nAcDbXrecord\n280\n     1\n  1\nDWGPROPS COOKIE\n  2\n\n  3\n\n  4\n\n  6\n\n  7\n\n  8\n\n  9\n\n300\n=\n301\n=\n302\n=\n303\n=\n304\n=\n305\n=\n306\n=\n307\n=\n308\n=\n309\n=\n 40\n0.0\n 41\n2455022.637359514\n 42\n2458484.789939861\n  1\n\n 90\n        0\n  0\nLAYOUT\n  5\n22\n102\n{ACAD_REACTORS\n330\n1A\n102\n}\n330\n1A\n100\nAcDbPlotSettings\n  1\n\n  2\nnone_device\n  4\nISO_A3_(420.00_x_297.00_MM)\n  6\n\n 40\n7.5\n 41\n20.0\n 42\n7.5\n 43\n20.0\n 44\n420.0\n 45\n297.0\n 46\n20.78282828282826\n 47\n0.0\n 48\n0.0\n 49\n0.0\n140\n0.0\n141\n0.0\n142\n1.0\n143\n1.155642023346303\n 70\n  1204\n 72\n     1\n 73\n     0\n 74\n     1\n  7\nmonochrome.ctb\n 75\n     0\n147\n0.8653198653198654\n148\n-134.1869158878504\n149\n0.0\n100\nAcDbLayout\n  1\nModel\n 70\n     1\n 71\n     0\n 10\n0.0\n 20\n0.0\n 11\n420.0\n 21\n297.0\n 12\n0.0\n 22\n0.0\n 32\n0.0\n 14\n41.50606451612907\n 24\n50.3361290322581\n 34\n0.0\n 15\n184.6513548387097\n 25\n201.433935483871\n 35\n0.0\n146\n0.0\n 13\n0.0\n 23\n0.0\n 33\n0.0\n 16\n1.0\n 26\n0.0\n 36\n0.0\n 17\n0.0\n 27\n1.0\n 37\n0.0\n 76\n     0\n330\n1F\n331\n29\n  0\nLAYOUT\n  5\n1E\n102\n{ACAD_REACTORS\n330\n1A\n102\n}\n330\n1A\n100\nAcDbPlotSettings\n  1\n\n  2\nnone_device\n  4\n\n  6\n\n 40\n0.0\n 41\n0.0\n 42\n0.0\n 43\n0.0\n 44\n0.0\n 45\n0.0\n 46\n0.0\n 47\n0.0\n 48\n0.0\n 49\n0.0\n140\n0.0\n141\n0.0\n142\n1.0\n143\n1.0\n 70\n   688\n 72\n     0\n 73\n     0\n 74\n     5\n  7\n\n 75\n    16\n147\n1.0\n148\n0.0\n149\n0.0\n100\nAcDbLayout\n  1\nSheet1\n 70\n     1\n 71\n     1\n 10\n0.0\n 20\n0.0\n 11\n420.0\n 21\n297.0\n 12\n0.0\n 22\n0.0\n 32\n0.0\n 14\n1.000000000000000E+20\n 24\n1.000000000000000E+20\n 34\n1.000000000000000E+20\n 15\n-1.000000000000000E+20\n 25\n-1.000000000000000E+20\n 35\n-1.000000000000000E+20\n146\n0.0\n 13\n0.0\n 23\n0.0\n 33\n0.0\n 16\n1.0\n 26\n0.0\n 36\n0.0\n 17\n0.0\n 27\n1.0\n 37\n0.0\n 76\n     0\n330\n1B\n  0\nLAYOUT\n  5\n26\n102\n{ACAD_REACTORS\n330\n1A\n102\n}\n330\n1A\n100\nAcDbPlotSettings\n  1\n\n  2\nnone_device\n  4\n\n  6\n\n 40\n0.0\n 41\n0.0\n 42\n0.0\n 43\n0.0\n 44\n0.0\n 45\n0.0\n 46\n0.0\n 47\n0.0\n 48\n0.0\n 49\n0.0\n140\n0.0\n141\n0.0\n142\n1.0\n143\n1.0\n 70\n   688\n 72\n     0\n 73\n     0\n 74\n     5\n  7\n\n 75\n    16\n147\n1.0\n148\n0.0\n149\n0.0\n100\nAcDbLayout\n  1\nSheet2\n 70\n     1\n 71\n     2\n 10\n0.0\n 20\n0.0\n 11\n0.0\n 21\n0.0\n 12\n0.0\n 22\n0.0\n 32\n0.0\n 14\n0.0\n 24\n0.0\n 34\n0.0\n 15\n0.0\n 25\n0.0\n 35\n0.0\n146\n0.0\n 13\n0.0\n 23\n0.0\n 33\n0.0\n 16\n1.0\n 26\n0.0\n 36\n0.0\n 17\n0.0\n 27\n1.0\n 37\n0.0\n 76\n     0\n330\n23\n  0\nMLINESTYLE\n  5\n18\n102\n{ACAD_REACTORS\n330\n17\n102\n}\n330\n17\n100\nAcDbMlineStyle\n  2\nStandard\n 70\n     0\n  3\n\n 62\n   256\n 51\n90.0\n 52\n90.0\n 71\n     2\n 49\n0.5\n 62\n   256\n  6\nBYLAYER\n 49\n-0.5\n 62\n   256\n  6\nBYLAYER\n  0\nACDBPLACEHOLDER\n  5\nF\n102\n{ACAD_REACTORS\n330\nE\n102\n}\n330\nE\n  0\nSCALE\n  5\n41\n102\n{ACAD_REACTORS\n330\n40\n102\n}\n330\n40\n100\nAcDbScale\n 70\n     0\n300\n1:1\n140\n1.0\n141\n1.0\n290\n     1\n  0\nDICTIONARYVAR\n  5\n19A\n102\n{ACAD_REACTORS\n330\n198\n102\n}\n330\n198\n100\nDictionaryVariables\n280\n     0\n  1\n1\n  0\nENDSEC\n  0\nEOF\n";
const char usage[]="USAGE: catenary -s <span> -r <rise> -d <divisions> -o <dxfFile>";

double CatY (double X, double C) {
	return ((cosh(X / C) * C) - C );
}

int main(int argc, char **argv) {
  double Xval=0;
  double Yval=0;
  int div=0;

  char *outFile = "";
  int c;
  char *eptr;

  while ((c = getopt (argc, argv, "s:r:d:o:h")) != -1){
    switch (c){
      case 's':
        Xval = strtod(optarg,&eptr) / 2;
        break;
      case 'r':
        Yval = strtod(optarg,&eptr);
        break;
      case 'd':
        div = atoi(optarg);
        break;
      case 'o':
        outFile = optarg;
        break;
      case 'h':
        printf("%s\n",usage);
        exit(1);
        break;
      case '?':
        if (optopt == 's')
          fprintf (stderr, "Option -%c requires the span of Catenry.\n", optopt);
        else if (optopt == 'r')
          fprintf (stderr, "Option -%c requires the rise of Catenry.\n", optopt);
        else if (optopt == 'd')
          fprintf (stderr, "Option -%c requires the divisions of Catenry.\n", optopt);
        else if (optopt == 'o')
          fprintf (stderr, "Option -%c requires the output file of Catenry.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr, "Unknown option character `\\x%x'.\n",optopt);
        return 1;
      default:
        abort ();
    }
  }
  if((Xval == 0)||(Yval == 0)||(div == 0)||(strlen(outFile)==0)){
    printf("%s\n",usage);
    exit(1);
  }

  double Xseg = Xval / div;
  int maxItr = 1000;
  double i = 1;
  double j = 1;
  double C = 1;
  double dec = 0;
  int Itr = 0;

  while (( CatY(Xval, i) < Yval ) && (Itr < maxItr)){
  	Itr++;
  	dec--;
  	i = pow(10, dec);
  }
  while (( CatY(Xval, j) > Yval ) && (Itr < maxItr)){
    Itr++;
    dec++;
    j = pow(10, dec);
  }
	if(dec < 0){
		i = pow(10, dec);
		j = pow(10, dec + 1);
	}
  if(dec < 0){
    j = pow(10, dec);
    i = pow(10, dec -1);
    dec = dec -1;
  }
	while(dec > -10){
		while (( CatY(Xval, i) > Yval ) && (Itr < maxItr)){
			Itr++;
			i = i + pow(10, dec);
		}
		i = i - pow(10, dec);
		dec = dec - 1;
	}
	C = i;
  FILE *fptr;
  fptr = fopen(outFile, "w");

  if (fptr == NULL) {
    printf("Error!\n");
    exit(1);
  }

  fprintf(fptr, "%s", dxf1);

	j = div;
  double xcord,ycord;
	while(j > 0){
    xcord = j * Xseg;
    ycord = -1 * CatY(j * Xseg, C);
    j--;
    fprintf(fptr,"10\n%f\n20\n%f\n",xcord, ycord);
  }

  while(j <= div){
    xcord = j * Xseg * -1;
    ycord = -1 * CatY(j * Xseg, C);
    j++;
    fprintf(fptr,"10\n%f\n20\n%f\n",xcord, ycord);
  }

  fprintf(fptr, "%s", dxf2);
  fclose(fptr);
   return 0;
}
