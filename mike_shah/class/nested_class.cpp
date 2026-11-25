#include<iostream>
#include<vector>

class ParticleSystem{
  struct Particle{
    float x{0.0f};
    float y{0.0f};
    float z{0.0f};
    float speed{1.0f};
    float lifetime{50.0f};

    void move(){ /* Move Particle*/}
  };

  public:
    void simulation(){
      for(size_t i = 0; i < m_particle.size(); i++){
        m_particle[i].move();
      }
    }

  private:
      std::vector<Particle> m_particle;
};

int main(){
  ParticleSystem p;
  p.simulation();
  return 0;
}
