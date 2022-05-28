#pragma once
#include <opencv2/opencv.hpp>
#include <glm/glm.hpp>

#define DIRECTIONDLL extern "C" __declspec(dllexport)

DIRECTIONDLL void VisualizeDirection(const char* output_file, float* color, cv::Point2f* Qx, cv::Point2f* Qy, int height, int width);
DIRECTIONDLL void ComputeWarping(int* integer_params, float delta, float* intrinsics, cv::Vec3f* Qx, cv::Vec3f* Qy, float* output_coords);
DIRECTIONDLL float orient2d(const cv::Point2f& a, const cv::Point2f& b, const cv::Point2f& c);
DIRECTIONDLL int min3(float v1, float v2, float v3);
DIRECTIONDLL int max3(float v1, float v2, float v3);
DIRECTIONDLL void rasterize(unsigned char* rgb1, unsigned char* rgb2, unsigned char* rgb3, cv::Point2f& v0, cv::Point2f& v1, cv::Point2f& v2, unsigned char* image, int height, int width, int solid);
DIRECTIONDLL void Rasterize(unsigned char* patch, cv::Point2f* coords, int patch_w, unsigned char* image, int height, int width, int solid);
DIRECTIONDLL float calculateSignedArea2(const glm::vec3& a, const glm::vec3& b, const glm::vec3& c);
DIRECTIONDLL void calculateBarycentricCoordinate(const glm::vec3& a, const glm::vec3& b, const glm::vec3& c, const glm::vec3& p, glm::vec3& bary);
DIRECTIONDLL bool isBarycentricCoordInBounds(const glm::vec3 barycentricCoord);
DIRECTIONDLL float getZAtCoordinate(const glm::vec3 barycentricCoord, const glm::vec3& a, const glm::vec3& b, const glm::vec3& c);
DIRECTIONDLL void DrawTriangle(glm::vec3* v1, glm::vec3* v2, glm::vec3* v3,
	glm::vec2* t1, glm::vec2* t2, glm::vec2* t3,
	glm::vec3* n1, glm::vec3* n2, glm::vec3* n3,
	unsigned char* tex_image, unsigned char* color_image, float* zbuffer,
	float* intrinsics, int tex_width, int tex_height, int width, int height);
