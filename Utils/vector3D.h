/*
 * Archivo: montmelocircuit.h
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

// -*- mode: C++ -*-
// Copyright(c) 2013 Grafics per Computador 2
// All rights reserved.

#ifndef __Vector3D_H__
#define __Vector3D_H__

class Vector3D
{
public:
  // ================= Constructores/Destructores ======================
  Vector3D();
  Vector3D( float a_x, float a_y, float a_z );
  Vector3D( const Vector3D& a_vec );
  ~Vector3D();

  // ============================ Methods ===============================
  double angle( const Vector3D& a_vec );
  double module( void ) const;
  void makeContrary();
  void normalize();
  void setCoordinates(float a_x, float a_y, float a_z);
  void getCoordinates(float& a_x, float& a_y, float& a_z);
  float getX( void ) const;
  float getY( void ) const;
  float getZ( void ) const;

  // ============================ Operators ===================================
  bool operator==( const Vector3D& a_vec );
  double operator^( const Vector3D& a_vec );
  Vector3D operator^( const double& a_scalar );
  Vector3D operator*( const Vector3D& a_vec );

private:

  // =========================== Data Members =================================
  //! Coordinates
  float _x;
  float _y;
  float _z;

  // ============================== Methods ===================================
};

#endif  // __vector3D_H__
