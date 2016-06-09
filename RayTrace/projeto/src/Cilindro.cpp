#include "Cilindro.h"
#include <cmath>

Cilindro::Cilindro(int _indice_textura, float _raio, float _altura, const Ponto_3D& _centro) : Objeto_3D ( _indice_textura )
{
  raio = _raio;
  centro =  _centro;
  altura = _altura/2;
}


//Foley capítulo 15.10, fórmula 15.17
Intersection Cilindro::Intercepta(const Raio& r_vis, IntersectionMode mode, float threshold)
{
  float a, b, c, delta,z1,z2;
  Intersection intersection;
  Intersection i1;
  Intersection i2;

  // valores intermediários
  Vetor_3D K = Vetor_3D(r_vis.X0() - centro.X(),
                        r_vis.Y0() - centro.Y(),
                        r_vis.Z0() - centro.Z());

  a= r_vis.Dx() *r_vis.Dx() + r_vis.Dz() * r_vis.Dz();
  b= 2 * (r_vis.Dx() * K.X() + r_vis.Dz() * K.Z());
  c= (K.X() * K.X() + K.Z() * K.Z()) - raio*raio;

  delta = b*b - 4*a*c;
  if (delta >= 0) {

      float y1,y2;

      float t1, t2;

      t1 = (-b - sqrt(delta)) /(2*a);
      t2 = (-b + sqrt(delta)) /(2*a);

      y1 = K.Y() + t1 * r_vis.Dy();
      y2 = K.Y() + t2 * r_vis.Dy();

      i1 = Intersection(this, t1);
      i2 = Intersection(this, t2);

      if((y1 <= altura && y1 >= -altura) || (y2 <= altura && y2 >= -altura))
      {
          intersection = Intersection::nearest(i1, i2, threshold);
      }


  }

  return intersection;
}

Vetor_3D Cilindro::normal( const Ponto_3D& ponto ) const
{
    //TODO FAZER NORMAL DO CILINDRO
    Vetor_3D tmp;
    Ponto_3D ponto_novo;
    ponto_novo.X(centro.X());
    ponto_novo.Y(ponto.Y());
    ponto_novo.Z(centro.Z());
    tmp = ponto - ponto_novo;
    tmp.normaliza();

    return tmp;
}

TexturePoint Cilindro::pontoTextura(const Ponto_3D& ponto) const
{
    float phi, theta;
    Vetor_3D tmp(ponto - centro);

    tmp.normaliza();

    phi  = acosf(tmp.Z());
    theta = acosf(tmp.X()/sin(phi));

    return TexturePoint((phi/M_PI), ((theta)/M_PI));
}
