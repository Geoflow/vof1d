#ifndef MESH_H
#define MESH_H
#include <iostream>
#include <cmath>
#include <vector>

#include "cell.h"

class Mesh
{
public:
    //methodes
	Mesh(double a, double b, int N);
	~Mesh(); //Le fameux destructeur
    Cell* get_cel(int i);
    //double get_mh();
    double m_h  ;

private:
	//Attributs
	double m_a;//depart
	double m_b; // arrivee
	int m_N; //nombre cellules


	std::vector <Cell*> m_Msh ;
	std::vector <double> m_X ;
};
#endif // MESH_H
