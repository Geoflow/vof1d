#include "mesh.h"

Mesh::Mesh(double a, double b, int N): m_a(a), m_b(b), m_N(N)
{
    m_h=(m_b-m_a)/m_N;

    m_Msh.reserve(N+1);

	m_X.push_back(m_a);
    Cell *C = new Cell(0,m_a, m_a+m_h);
    m_Msh.push_back(C);



    for (int i=1;i<=N; ++i)
	{
        double x = i*m_h + m_a;//Oublie pas l'offset

		m_X.push_back(x);

		Cell *C = new Cell(i, x - m_h, x);
        C->set_ctg(x-0.5*m_h);
        C->set_ctd(x+0.5*m_h);
		m_Msh.push_back(C);
	}


}

Mesh::~Mesh()
{
	while(!m_Msh.empty())
	{
		delete m_Msh.back();
		m_Msh.pop_back();
	}
}

Cell* Mesh:: get_cel(int i)  {

    return m_Msh[i] ;
}
//double Mesh:: get_mh(){
  //  return m_h;
//}
