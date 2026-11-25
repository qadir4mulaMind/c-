#include<iostream>

class IRenderer{
  public:
    // This is a pure virtual Funstion
    virtual void draw() = 0;
    virtual void update() = 0;
};

class OpenGL : public IRenderer{
  public:
    void draw() override{
      std::cout << "OpenGL Draw" << std::endl;
    }
    void update() override{
      std::cout << "OpenGl update" << std::endl;
    }
};

class Vulkan : public IRenderer{
  public:
    void draw() override{
      std::cout << "Vulkan Draw" << std::endl;
    }
    void update() override{
      std::cout << "Vukan update" << std::endl;
    }
};

int main(){
  IRenderer* ir = new OpenGL;
  ir->update();
  ir->draw();

  printf("\n");

  ir = new Vulkan;
  ir->draw();

  return 0;
}

