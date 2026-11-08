#ifndef SHAPEAPI_H
#define SHAPEAPI_H

#ifdef SHAPE_API_DLL
#define SHAPE_API __declspec(dllexport)
#else
#define SHAPE_API __declspec(dllimport)
#endif

#endif