#pragma once
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <array>
#include "env.hpp"
#include "forward.hpp"

class Camera {
 public:
  glm::vec3 pos;
  glm::vec3 dir;
  glm::vec3 right;
  glm::vec3 up;
  glm::mat4 proj;
  glm::mat4 view;
  int width;
  int height;
  bool mouseInit = false;
  float mouseXpos = 0;
  float mouseYpos = 0;
  float oldMouseXpos = 0;
  float oldMouseYpos = 0;
  float zNear;
  float zFar;

  Camera(glm::vec3 pos, glm::vec3 target, int width = 1024, int height = 1024);
  void update(Env &env, float deltaTime);

  void updateView(float deltaTime);
  void updateDirection(float deltaTime);

  void updateMouse(Env &env, float deltaTime);
  void updateKeyboard(Env &env, float deltaTime);

  void rotate(float hor, float ver);  // in radians
  float getAspectRatio();

 private:
  void updateMatrix(float deltaTime);
  bool mouseMoved = false;
  float horAngle;
  float verAngle;
  float speed;
  float lastVelocity = 0.0f;
};
