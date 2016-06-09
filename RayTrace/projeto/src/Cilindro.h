#ifndef CILINDO_H
#define CILINDO_H

#include "Objeto_3d.h"

class Cilindro : public Objeto_3D {
protected:
  float altura;
public:

//* Construtor e Destrutor
  Cilindro( int _indice_textura, float _raio, float _altura, const Ponto_3D& _centro );
  ~Cilindro() {}
//* interseção e Normal
  Intersection Intercepta(const Raio& r_vis, IntersectionMode mode, float threshold) ;
  Vetor_3D normal( const Ponto_3D& ponto ) const ;
  TexturePoint pontoTextura(const Ponto_3D& ponto) const;
};
#endif // CILINDRO_H
